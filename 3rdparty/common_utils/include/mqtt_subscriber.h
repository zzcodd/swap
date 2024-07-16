// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2021-02-28 14:08:09
#pragma once

void mqtt_subscriber_init(void);

int mqtt_subscriber_connect(char *host, int port, char *username,
    char *password, char *topic_name);

int mqtt_subscriber_disconnect(void);

void mqtt_subscriber_release(void);
