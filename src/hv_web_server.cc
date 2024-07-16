/*
 * sample http server
 * more detail see examples/httpd
 *
 */

#include "HttpServer.h"
#include "hthread.h"    // import hv_gettid
#include "hasync.h"     // import hv::async

#include "hv_web_server.h"
#include "request_handler.h"
#include "config.h"

using namespace hv;

/*
 * #define TEST_HTTPS 1
 *
 * @build   ./configure --with-openssl && make clean && make
 *
 * @server  bin/http_server_test 8080
 *
 * @client  curl -v http://127.0.0.1:8080/ping
 *          curl -v https://127.0.0.1:8443/ping --insecure
 *          bin/curl -v http://127.0.0.1:8080/ping
 *          bin/curl -v https://127.0.0.1:8443/ping
 *
 */
#define TEST_HTTPS 0

extern MainConfig config;

void HVWebServer::Initialize(void)
{
}

static std::string DataHandler(std::string &data)
{
  Command cmd;
//  AINFO << "Incoming: " << body.data() << std::endl;
  BufferParser::Instance()->ParseHttpPostData((char*)data.data(), data.size(),
      cmd);

  cmd.app_name = config.app_name;

  return RequestHandler::Instance()->Handle(cmd);
}

int HVWebServer::Start(void)
{
  HV_MEMCHECK;

  HttpService router;

  // curl -v http://ip:port/echo -d "hello,world!"
  router.POST("/cidi_debug", [](const HttpContextPtr& ctx) {
      return ctx->send(ctx->body(), ctx->type());
      });

  // curl -v http://ip:port/echo -d "hello,world!"
  router.POST("/apiserver/cmd", [](const HttpContextPtr& ctx) {
      return ctx->sendString(DataHandler(ctx->body()));
      });

  // middleware
  router.AllowCORS();
  router.Use([](HttpRequest* req, HttpResponse* resp) {
      resp->SetHeader("X-Request-tid", hv::to_string(hv_gettid()));
      return HTTP_STATUS_NEXT;
      });

  HttpServer server;
  server.service = &router;
  server.port = config.port;
#if TEST_HTTPS
  server.https_port = 8443;
  hssl_ctx_opt_t param;
  memset(&param, 0, sizeof(param));
  param.crt_file = "cert/server.crt";
  param.key_file = "cert/server.key";
  param.endpoint = HSSL_SERVER;
  if (server.newSslCtx(&param) != 0) {
    fprintf(stderr, "new SSL_CTX failed!\n");
    return -20;
  }
#endif

  // uncomment to test multi-processes
  // server.setProcessNum(4);
  // uncomment to test multi-threads
  // server.setThreadNum(4);

  server.start();

  // press Enter to stop
  while (getchar() != '\n')
    std::this_thread::sleep_for(std::chrono::seconds(1));
  hv::async::cleanup();
  return 0;
}

void HVWebServer::Stop(void)
{
  hv::async::cleanup();
}

void HVWebServer::Loop(void)
{
}
