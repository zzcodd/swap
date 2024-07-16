#! /bin/sh

ulimit -c unlimited

do_start()
{
    CMD="./build/web_server"

    if [ $1 ] && [ "$1" = "as" ]; then
      while [ ! -f /tmp/stop_cdv ]; do
          ${CMD}
      done
    else
      eval "nohup ${CMD}"
    fi
}

do_start as &
