# FM24W256.h

## API

### FM24W256(deviceSelect)

__deviceSelect:uint8_t__ The device select number value controled via pins A0 - A2 on the chip.


### _void_ read(address, buffer, quantity)

__address:uint16_t__ 15 bit memory address. Values: 0x000 - 0x7FFF.
__buffer:uint8_t*__ Array with bytes to write.
__quantity:uint16_t__ Number of bytes to write.


### _void_ write(address, buffer, quantity)

__address:uint16_t__ 15 bit memory address. Values: 0x000 - 0x7FFF.
__buffer:uint8_t*__ Array pointer where to store the bytes.
__quantity:uint16_t__ Number of bytes to read.
