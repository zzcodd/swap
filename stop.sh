#! /bin/sh

touch /tmp/stop_cdv
kill -s 9 `pidof web_server`
rm -f /tmp/stop_cdv
