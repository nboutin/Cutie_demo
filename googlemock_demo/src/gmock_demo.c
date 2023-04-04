#include "gmock_demo.h"

STATIC char func_1(int a);
STATIC void func_2(const char* s, int a);

void main_1(void)
{
  func_1(5);
  func_2("hello", 0);
}

STATIC char func_1(int a)
{
  if (a > 5)
    return 'a';
  else
    return 'b';
}

STATIC void func_2(const char* s, int a)
{
  (void) s;
  (void) a;
}
