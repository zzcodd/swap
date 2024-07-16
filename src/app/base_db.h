#pragma once

class base_db
{
public:	

  int Connect(char *configPath);

  int Disconnect(void);
	
private:

  bool is_connected = false;
};
