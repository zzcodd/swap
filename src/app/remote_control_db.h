#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "base_db.h"

class remote_control_db
{
	remote_control_db(){};
	virtual ~remote_control_db(){};

public:

  int Process(
      char *project_name,
      char *vehicle_type,
      char *vehicle_info,
      char *device_name,
      char *hw_sign,
      char *username,
      char *protocol,
      std::vector<std::string> &data);

  int Disconnect(void);

	static remote_control_db* Instance(void);
	static void ReleaseInstance(void);

private:
	static remote_control_db *p_instance;
};
