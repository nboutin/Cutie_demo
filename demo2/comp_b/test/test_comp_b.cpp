
#include "mock.hpp"

extern "C" {
#include "comp_b.h"
}

TEST(CompB, use_comp_a_add)
{
  EXPECT_EQ(use_comp_a_add(1, 2), 3);
}
