```c
#include "serial.h"
```

Emulates Serial port data flow.

**Warning**: currently only 8 data bits are supported.

### serial_cfg_t

Stores configuration for Serial emulator.
Fields:

`data_bits` - number of bits transmitted per packet. Possible values:
`DATA_BITS_5`, `DATA_BITS_6`, `DATA_BITS_7`, `DATA_BITS_8` and `DATA_BITS_9`.
Please check out warning above.

`parity` - type of parity bit used for integrity check. Possible values:
`PARITY_NONE`, `PARITY_ODD` and `PARITY_EVEN`.

`stop_bits` - number of stop bits. Possible values:
`STOP_BITS_1` and `STOP_BITS_2`.

### serial_encode()

```c
int serial_encode(bits_t *dst, bits_t *src, serial_cfg_t *cfg);
```

Encodes `src` bits to `dst` bits, simulating
Serial port data flow according to settings pointed by `cfg`.

### serial_decode()

```c
int serial_decode(bits_t *dst, bits_t *src, serial_cfg_t *cfg);
```

Decodes simulated Serial port data flow from `src` to `dst`
using settings pointed by `cfg`.