
const uint8_t STA = 0xC0;
const uint8_t STP = 0xC1;
const uint8_t ESC = 0x27;


/**
 * Byte Stuffing Encoding routing
 *
 * @param inBuf     pointer to input buffer which contains raw data
 * @param len       length of input buffer
 * @param outBuf    pointer to output buffer which contains encoded data
 * @return data length of output buffer if encode successful
 * @return 0 if encode failed
 **/
size_t encoding(uint8_t *inBuf, size_t len, uint8_t *outBuf);
 
 
/**
 * Byte Stuffing Decoding routing
 *
 * @param   inBuf       pointer to input buffer which contains encoded data
 * @param   len         length of input buffer
 * @param   outBuf      pointer to output buffer which contains raw data
 * @return  data length of output buffer if decode successful
 * @return  0 if decode failed
 **/
size_t decoding(uint8_t *inBuf, size_t len, uint8_t *outBuf);

/**
 * Generate 16-bit CRC value using crc-ccitt
 *
 * @param buf   pointer to input data buffer
 * @param len   data length of input data
 * @return 16-bit CRC value
 **/
uint16_t crc-ccitt(uint8_t *buf, size_t len);
