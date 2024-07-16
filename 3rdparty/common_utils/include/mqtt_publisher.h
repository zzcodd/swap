// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2021-02-28 14:08:09
#pragma once

void mqtt_publisher_init(void);

int mqtt_publisher_connect(char *host, int port, char *username,
    char *password);

int mqtt_publisher_post(char *topic_name, char *payload, int size);

int mqtt_publisher_disconnect(void);

void mqtt_publisher_release(void);
