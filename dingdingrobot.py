# -*- coding: UTF-8 -*-
import requests
import json
import time
import hmac
import hashlib
import base64
import urllib.parse
import sys

#print(sys.argv)
# DingTalk config
dingTalkUrl = sys.argv[1]
dingTalkSecret = sys.argv[2]
#具体发送的内容
msg = sys.argv[3]

def getDingTalkUrl(url, secret):
  timestamp = str(round(time.time() * 1000))
  secret_enc = secret.encode('utf-8')
  string_to_sign = '{}\n{}'.format(timestamp, secret)
  string_to_sign_enc = string_to_sign.encode('utf-8')
  hmac_code = hmac.new(secret_enc, string_to_sign_enc,
                       digestmod=hashlib.sha256).digest()
  sign = urllib.parse.quote_plus(base64.b64encode(hmac_code))
  return url + "&timestamp=" + timestamp + "&sign=" + sign


def sendDingMsg(url, msg):
  headers = {"Content-Type": "application/json"}
  sendMsg = {"content": msg}
  sendBody = {"msgtype": "text", "text": sendMsg,"at":{"atMobiles":[
            "+86-15616230526","+86-18129973639","+86-18008446212"],"isAtAll":"false"}}
  res = requests.post(url=url, data=json.dumps(sendBody), headers=headers)
  print("#Send DingTalk robot res:" + str(res.text))


if __name__ == "__main__":
  url = getDingTalkUrl(dingTalkUrl, dingTalkSecret)
  sendDingMsg(url, msg)
