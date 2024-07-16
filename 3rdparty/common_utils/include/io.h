// Original Author: xhz<zhang.xh@cidi.ai>
#pragma once

#define GET_BIT(x, y)         ((x) >> (y) & 1)
#define SET_BIT(x, y)         (x |= 1 << (y))
#define CLEAR_BIT(x, y)       (x &= ~(1 << (y)))
#define REVERSETBIT_BIT(x, y) (x ^= 1 << (y))

/*
 * ie. value 9 print to:
 * 0000-0000 0000-0000 0000-0000 0000-1001
 *
 * @param  data   input data
 * @param  base   32(int)/16(short)/8(char)
 */
void print_binary(int data, int base)
{
  int i = base;
  while (i--) {
    if (data & (1<<i))
      printf("1");
    else
      printf("0");
    if (i % 4 == 0) {
      if (i % 8 == 0)
        printf(" ");
      else
        printf("-");
    }
  }
  putchar(10);
}
