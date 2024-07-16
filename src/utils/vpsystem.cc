#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/vfs.h>
#include <sys/stat.h>
#include <thread>
#include <chrono>
#include "vpsystem.h"
#include "src/utils/log.h"

vpSystem *vpSystem::p_instance = nullptr;

vpSystem *vpSystem::Instance() {
  if (nullptr == p_instance)
    p_instance = new vpSystem();
  return p_instance;
}

void vpSystem::ReleaseInstance() {}

long vpSystem::vopen_max(void) {
  static long openmax = 0;
  if (openmax == 0) {   /* first time through */
    errno = 0;
    if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
      if (errno == 0)
        openmax = 1024;    /* it's indeterminate */
      else
        AERROR << "sysconf error for _SC_OPEN_MAX\n";
    }
  }
  return openmax;
}

FILE *vpSystem::vpopen(const char *cmdstring, const char *type) {
  int maxfd = 0;
  int pfd[2] = {0};
  pid_t pid = 0;
  FILE *fp = NULL;
  pid_t *childpid;

  /* only allow "r" or "w" */
  if (!cmdstring || !type || (type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
    errno = EINVAL;
    return NULL;
  }

  if (pChildpid == NULL) { /* first time through */
    maxfd = vopen_max(); /* allocate zeroed out array for child pids */
    if ((pChildpid = calloc(maxfd, sizeof(pid_t))) == NULL)
      return NULL;
  }

  childpid = (pid_t *) pChildpid;

  if (pipe(pfd) < 0)
    return (NULL);   /* errno set by pipe() */

  if ((pid = vfork()) < 0)
    return NULL;   /* errno set by fork() */
  else if (pid == 0) {  /* child */
    if (*type == 'r') {
      close(pfd[0]);
      if (pfd[1] != STDOUT_FILENO) {
        dup2(pfd[1], STDOUT_FILENO);
        close(pfd[1]);
      }
    } else {
      close(pfd[1]);
      if (pfd[0] != STDIN_FILENO) {
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);
      }
    }
    /* close all descriptors in childpid[] */
    for (int i = 0; i < maxfd; i++)
      if (childpid[i] > 0)
        close(i);

    execl("/bin/bash", "bash", "-c", cmdstring, (char *) 0);
    _exit(127);
  }
  /* parent */
  if (*type == 'r') {
    close(pfd[1]);
    if ((fp = fdopen(pfd[0], type)) == NULL)
      return NULL;
  } else {
    close(pfd[0]);
    if ((fp = fdopen(pfd[1], type)) == NULL)
      return NULL;
  }
  childpid[fileno(fp)] = pid; /* remember child pid for this fd */
  return fp;
}

int vpSystem::vpclose(FILE *fp) {
  int fd = 0;
  int stat = 0;
  pid_t pid = 0;
  pid_t *childpid;

  if (pChildpid == NULL)
    return -1;     /* popen() has never been called */

  childpid = (pid_t *) pChildpid;
  fd = fileno(fp);
  if ((pid = childpid[fd]) == 0)
    return -1;     /* fp wasn't opened by popen() */

  childpid[fd] = 0;
  if (fclose(fp) == EOF)
    return -1;

  while (waitpid(pid, &stat, 0) < 0)
    sync();
  std::this_thread::sleep_for(std::chrono::microseconds(1));
  return stat;   /* return child's termination status */
}

int vpSystem::call_cmd(std::string cmd, std::string &out_buffer, int type) {
  FILE *fp = NULL;
  char result[1024] = {0};
  int rc = -1;

  if (cmd.length() < 2)
    return -1;

  if (0 == type) {
    fp = vpopen(cmd.c_str(), "r");
  } else if (1 == type) {
    fp = vpopen(cmd.c_str(), "w");
  } else {
    return -1;
  }

  if (!fp)
    return -2;

  fread(result, 1, 1024, fp);
  rc = strlen(result);
  if (rc > 0) {
    out_buffer = result;
  }
  vpclose(fp);
  return rc;
}

