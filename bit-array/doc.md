```c
#include "bit-array.h"
```

This library provides `bits_t` object with several functions defined,
e.g. pushing bit to front/back and popping bit from front/back.

### bits_t

Should be initialized by `bitarray_alloc()` before using
and freed by `bitarray_free()` in the end.

### bitarray_alloc()

```c
void bitarray_alloc(bits_t *bits);
```

Initializes `bits_t` object pointed to by `bits`.
Blows up the whole program on memory allocation failure.

### bitarray_free()

```c
void bitarray_free(bits_t *bits);
```

Destroys `bits_t` object pointed to by `bits`.
Double free is undefined behaviour.

### bitarray_size()

```c
size_t bitarray_size(bits_t *bits);
```

Returns the number of bits stored in `bits_t` object pointed to by `bits`.

### bitarray_empty()

```c
bool bitarray_empty(bits_t *bits);
```

Returns `true` is pointed object does not store any bits,
`false` otherwise.

### push/pop back/front functions

```c
void bitarray_push_front(bits_t *bits, bit b);
void bitarray_push_back(bits_t *bits, bit b);
void bitarray_pop_front(bits_t *bits);
void bitarray_pop_back(bits_t *bits);
```

Function names are self-explanatory.
Popping from `bits_t` object for which `bitarray_empty()` returns `true`
is undefined behaviour.

### bitarray_front()

```c
bit bitarray_front(bits_t *bits);
```

Returns first bit stored.
Accessing first bit of `bits_t` object for which `bitarray_empty()`
returns `true` is undefined behaviour.

### bitarray_back()

```c
bit bitarray_back(bits_t *bits);
```

Returns last bit stored.
Accessing last bit of `bits_t` object for which `bitarray_empty()`
returns `true` is undefined behaviour.