#pragma once

#ifdef HANDLE_CMD
  #undef HANDLE_CMD
#endif // HANDLE_CMD
#define HANDLE_CMD(x, y) do { \
  if (cmd.type == x) \
    result = y(cmd); \
} while (0)
