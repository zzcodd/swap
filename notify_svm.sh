#! /bin/bash

dingTalkUrl="https://oapi.dingtalk.com/robot/send?access_token=e7f45f113a57b303e86378f75d07bc3392c9727a3608e113a48b84c812584998"
dingTalkSecret="SEC097bde871fb37048a9368536ad52d44670b3d09fb7baf8c3f7f091635d8249b8"

msg="$1""_""$2"
detail=$3

# xhz
#curl "https://sctapi.ftqq.com/SCT92267Ttt62DEULGzR9APtTC2dPM17m.send?title=$msg&desp=$detail"
# pengqing
# curl "https://sctapi.ftqq.com/SCT141855TJnF5mrJsfuKpVdxRYVVziqMo.send?title=$msg&desp=$detail"

msg="$1$3"
python3 dingdingrobot.py $dingTalkUrl $dingTalkSecret $msg
