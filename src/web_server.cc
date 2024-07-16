#include "web_server.h"
#include <handy/include/handy.h>
#include <iostream>
#include "request_handler.h"

using namespace std;
using namespace handy;

// 0 is no limit
static EventBase base(2);
extern MainConfig config;

static int ConnectionHandler(bool is_post, const HttpConnPtr &con)
{
  string v = con.getRequest().version;
  Slice body = con.getRequest().getBody();
  //std::string arg_type = con.getRequest().getArg("cmd_type"); 

  Command cmd;
//  AINFO << "Incoming: " << body.data() << std::endl;
  if (is_post)
    BufferParser::Instance()->ParseHttpPostData((char*)body.data(),
        body.size(), cmd);
  else
    BufferParser::Instance()->ParseMapedData(con.getRequest().args, cmd);

  cmd.app_name = config.app_name;

  std::string result = RequestHandler::Instance()->Handle(cmd);
  HttpResponse resp;
  resp.body = Slice(result);
  con.sendResponse(resp);
  if (v == "HTTP/1.0")
    con->close();
  return 0;
}

void WebServer::Initialize(void)
{
}

int WebServer::Start(void)
{
  setloglevel("ERROR");
  HttpServer sample(&base);
  int r = sample.bind("", config.port);
//  AINFO << "listen port: " << config.port << std::endl;
  exitif(r, "bind failed %d %s", errno, strerror(errno));

  sample.onRequest("GET", config.app_path, [](const HttpConnPtr&con) {
    ConnectionHandler(false, con);
  });

  sample.onRequest("POST", config.app_path, [](const HttpConnPtr&con) {
    ConnectionHandler(true, con);
  });

  Signal::signal(SIGINT, [&] { base.exit(); });
  base.loop();
  return 0;
}

void WebServer::Stop(void)
{
  base.exit();
}

void WebServer::Loop(void)
{
}
