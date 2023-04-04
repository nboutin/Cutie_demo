/**
 * \file test_buffer.cpp
 * \brief Buffer class test suite
 * \author Nicolas Boutin
 * \date 2024-05
 */

#include "cutie/mock.hpp"

extern "C" {
#include "buffer/buffer.h"
}

DECLARE_HOOKABLE(buf_reset);

void buf_reset_hook(buf_t* buffer)
{
  buffer->read  = 0;
  buffer->write = 0;
}

class buffer_ut : public ::testing::Test {
protected:
  buf_t buffer;
  constexpr static auto SIZE = 10U;
  std::uint8_t data[SIZE];
};

TEST_F(buffer_ut, buf_init)
{
  INSTALL_HOOK(buf_reset, buf_reset_hook);

  buf_init(&buffer, data, SIZE);
  buf_write_u8(&buffer, 1);
  buf_write_u8(&buffer, 2);
  buf_read_u8(&buffer);
  buf_init(&buffer, data, SIZE);
  EXPECT_EQ(buffer.read, 0);
  EXPECT_EQ(buffer.write, 0);
}
