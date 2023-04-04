/**
 * \file buffer.c
 * \brief Buffer class definition
 * \author Nicolas Boutin
 * \date 2024-05
 */

#include <stddef.h>

#include "buffer/buffer.h"

void buf_init(buf_t* buf, uint8_t* data, buf_size_t size)
{
  buf_reset(buf);
  if (buf != NULL)
  {
    buf->size = size;
    buf->data = data;
  }
}

void buf_reset(buf_t* buf)
{
  if (buf != NULL)
  {
    buf->read  = 0;
    buf->write = 0;
  }
}

buf_size_t buf_get_size(buf_t* buf)
{
  if (buf != NULL)
  {
    return buf->size;
  }
  return 0;
}

bool buf_is_empty(buf_t* buf)
{
  if (buf != NULL)
  {
    return buf->read == buf->write;
  }
  return true;
}

bool buf_is_full(buf_t* buf)
{
  if (buf != NULL)
  {
    return buf->write == buf->size;
  }
  return false;
}

buf_size_t buf_get_free_size(buf_t* buf)
{
  if (buf != NULL)
  {
    return buf->size - buf->write;
  }
  return 0;
}

buf_size_t buf_get_used_size(buf_t* buf)
{
  if (buf != NULL)
  {
    return buf->write;
  }
  return 0;
}

buf_size_t buf_get_to_read_size(buf_t* buf)
{
  if (buf != NULL)
  {
    return buf->write - buf->read;
  }
  return 0;
}

bool buf_write_u8(buf_t* buf, uint8_t data)
{
  if ((buf != NULL) && (buf_get_free_size(buf) > 0))
  {
    buf->data[buf->write] = data;
    buf->write++;
    return true;
  }
  return false;
}

uint8_t buf_read_u8(buf_t* buf)
{
  uint8_t data = 0;
  if ((buf != NULL) && (buf_get_to_read_size(buf) > 0))
  {
    data = buf->data[buf->read];
    buf->read++;
    return data;
  }
  return data;
}
