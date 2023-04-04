
#include "mock.hpp"

extern "C" {
#include "gmock_demo.h"

extern char func_1(int a);
extern void func_2(const char* s, int a);
}

using namespace testing;

DECLARE_MOCKABLE(func_1, 1);
DECLARE_MOCKABLE(func_2, 2);

TEST(GMockDemo, main_1)
{
  int val_func_2 = 0;

  INSTALL_MOCK(func_1);
  INSTALL_MOCK(func_2);

  CUTIE_EXPECT_CALL(func_1, 5).WillOnce(Return('a'));
  // CUTIE_EXPECT_CALL(func_2, "hello", val_func_2);

  main_1();
}
