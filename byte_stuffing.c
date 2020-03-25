#include "byte_stuffing.h"
#include <stdio.h>

/**
 * Byte Stuffing Encoding routing
 *
 * @param inBuf     pointer to input buffer which contains raw data
 * @param len       length of input buffer
 * @param outBuf    pointer to output buffer which contains encoded data
 * @return data length of output buffer if encode successful
 * @return 0 if encode failed
 **/
size_t encoding(uint8_t *inBuf, size_t len, uint8_t *outBuf)
{
  uint16_t crc = crc-ccitt(inBuf, len);
  size_t outBuf_i = 0;
  outBuf[outBuf_i] = STA;
  for(size_t i = 0; i < len; i++)
  {
    if(inBuf[i] == STA || inBuf[i] == STP || inBuf == ESC)
    {
      outBuf[outBuf_i++] = ESC;
      outBuf[outBuf_i++] = inBuf[i] ^ 0x20;
    }
    else
      outBuf[outBuf_i++] = inBuf[i];
  }
  uint8_t *crc_arr = (uint8_t) crc;
  for(size_t i = 0; i < 2; i++)
  {
    if(crc_arr[i] == STA || crc_arr[i] == STP || crc_arr[i] == ESC)
    {
      outBuf[outBuf_i++] = ESC;
      outBuf[outBuf_i++] = crc_arr[i] ^ 0x20;
    }
    else
      outBuf[outBuf_i++] = crc_arr[i];
  }
  return outBuf_i;
}

/**
 * Byte Stuffing Decoding routing
 *
 * @param   inBuf       pointer to input buffer which contains encoded data
 * @param   len         length of input buffer
 * @param   outBuf      pointer to output buffer which contains raw data
 * @return  data length of output buffer if decode successful
 * @return  0 if decode failed
 **/
size_t decoding(uint8_t *inBuf, size_t len, uint8_t *outBuf)
{
  if(inBuf[0] != STA)
    return 0;
  else if (inBuf[len - 1] != STP)
    return 0;
  size_t outBuf_i = 0;
  for(size_t i = 0; i < len - 1; i++)
  {
    if(inBuf[i] == STA || inBuf[i] == STP)
      return 0;
    if(inBuf[i] == ESC)
    {
      if(i + 1 < len - 1)
      {
        uint8_t decode = inBuf[++i] ^ 0x20;
        if(decode == STA || decode == STP || decode == ESC)
          outBuf[outBuf_i++] = decode;
        else
          return 0;
      }
      else
        return 0;
    }
    else
      outBuf[outBuf_i++] = inBuf[i];
  }
  return outBuf_i;
}
