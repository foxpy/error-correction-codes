#pragma once
#include <stdint.h>

typedef union rnd_state_t {
	uint64_t s64;
	uint32_t s32[2];
	uint16_t s16[4];
	uint8_t s8[8];
	double fp64;
	float fp32[2];
} rnd_state_t;

void rnd_init(rnd_state_t *state);
uint8_t rnd8(rnd_state_t *state);
uint16_t rnd16(rnd_state_t *state);
uint32_t rnd32(rnd_state_t *state);
uint64_t rnd64(rnd_state_t *state);
double rnd_fp64(rnd_state_t *state);
float rnd_fp32(rnd_state_t *state);
double normal_distribution(double mu, double sigma, rnd_state_t *state);
