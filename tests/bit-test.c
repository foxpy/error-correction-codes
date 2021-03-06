#ifdef NDEBUG
#undef NDEBUG
#endif

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "bit-array.h"

int main() {
	bits_t bits;
	bits_t bits_copy;
	unsigned char memory[4] = { 0xc3, 0xa9, 0x87, 0x2b };
	bit check_memory[32] = {
		1, 1, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 1, 0, 1, 0, 1,
		1, 1, 1, 0, 0, 0, 0, 1,
		1, 1, 0, 1, 0, 1, 0, 0,
	};
	bitarray_alloc(&bits);
	assert(bitarray_empty(&bits) == true);

	bitarray_push_back(&bits, 1);
	assert(bitarray_empty(&bits) == false);
	assert(bitarray_size(&bits) == 1);
	assert(bitarray_back(&bits) == 1);
	assert(bitarray_front(&bits) == 1);

	bitarray_push_front(&bits, 0);
	assert(bitarray_size(&bits) == 2);
	assert(bitarray_back(&bits) == 1);
	assert(bitarray_front(&bits) == 0);

	bitarray_push_front(&bits, 1);
	assert(bitarray_size(&bits) == 3);
	assert(bitarray_back(&bits) == 1);
	assert(bitarray_front(&bits) == 1);

	bitarray_push_back(&bits, 0);
	assert(bitarray_size(&bits) == 4);
	assert(bitarray_back(&bits) == 0);
	assert(bitarray_front(&bits) == 1);

	for (int i = 0; i < 6; ++i) {
		bitarray_push_front(&bits, i % 2);
	}
	assert(bitarray_size(&bits) == 10);

	for (int i = 0; i < 6; ++i) {
		bitarray_push_back(&bits, i % 2);
	}
	assert(bitarray_size(&bits) == 16);

	bitarray_push_front(&bits, 0);
	bitarray_push_back(&bits, 0);
	bitarray_copy(&bits_copy, &bits);
	assert(bitarray_size(&bits) == 18);
	assert(bitarray_back(&bits) == 0);
	assert(bitarray_front(&bits) == 0);
	assert(bitarray_size(&bits_copy) == 18);
	assert(bitarray_back(&bits_copy) == 0);
	assert(bitarray_front(&bits_copy) == 0);

	for (int i = 0; i < 9; ++i) {
		bitarray_pop_back(&bits);
	}
	assert(bitarray_empty(&bits) == false);
	assert(bitarray_size(&bits) == 9);

	for (int i = 0; i < 9; ++i) {
		bitarray_pop_front(&bits);
	}
	assert(bitarray_empty(&bits) == true);
	assert(bitarray_size(&bits) == 0);

	bit b;
	bitarray_fill_from_memory(&bits, memory, 22);
	for (int i = 0; i < 22; ++i) {
		b = bitarray_front(&bits);
		bitarray_pop_front(&bits);
		assert(b == check_memory[i]);
	}
	assert(bitarray_empty(&bits) == true);

	bitarray_fill_from_memory(&bits, memory, 32);
	size_t nbits, nbytes;
	char *new_memory = bitarray_to_memory(&bits, &nbits, &nbytes);
	assert(bitarray_empty(&bits) == true);
	assert(memcmp(memory, new_memory, 4) == 0);
	assert(nbits == 32);
	assert(nbytes == 4);

	bitarray_push_back(&bits, 1);
	bitarray_clear(&bits);
	assert(bitarray_empty(&bits) == true);

	free(new_memory);
	bitarray_free(&bits);
	bitarray_free(&bits_copy);
	return EXIT_SUCCESS;
}
