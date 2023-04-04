/**
 * \file buffer.h
 * \brief Buffer class definition
 * \author Nicolas Boutin
 * \date 2024-05
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef uint16_t buf_size_t;

typedef struct {
  uint8_t read;
  uint8_t write;
  buf_size_t size;
  uint8_t* data;
} buf_t;

void buf_init(buf_t* buf, uint8_t* data, buf_size_t size);
void buf_reset(buf_t* buf);

buf_size_t buf_get_size(buf_t* buf);
bool buf_is_empty(buf_t* buf);
bool buf_is_full(buf_t* buf);
buf_size_t buf_get_free_size(buf_t* buf);
buf_size_t buf_get_used_size(buf_t* buf);
buf_size_t buf_get_to_read_size(buf_t* buf);

bool buf_write_u8(buf_t* buf, uint8_t data);
uint8_t buf_read_u8(buf_t* buf);
