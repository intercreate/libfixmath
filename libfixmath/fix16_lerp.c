#include "fix16.h"
#include "int64.h"

fix16_t fix16_lerp8(fix16_t inArg0, fix16_t inArg1, uint8_t inFract)
{
	int64_t tempOut = int64_mul_i32_i32(inArg0, (((int32_t)1 << 8) - inFract));
	tempOut = int64_add(tempOut, int64_mul_i32_i32(inArg1, inFract));
	tempOut = int64_shift(tempOut, -8);
	return (fix16_t)int64_lo(tempOut);
}

fix16_t fix16_lerp16(fix16_t inArg0, fix16_t inArg1, uint16_t inFract)
{
	int64_t tempOut = int64_mul_i32_i32(inArg0, (((int32_t)1 << 16) - inFract));
	tempOut = int64_add(tempOut, int64_mul_i32_i32(inArg1, inFract));
	tempOut = int64_shift(tempOut, -16);
	return (fix16_t)int64_lo(tempOut);
}

fix16_t fix16_lerp32(fix16_t inArg0, fix16_t inArg1, uint32_t inFract)
{
	if(inFract == 0)
		return inArg0;
	int64_t inFract64 = int64_const(0, inFract);
	int64_t subbed = int64_sub(int64_const(1,0), inFract64);
	int64_t tempOut  = int64_mul_i64_i32(subbed,  inArg0);
	tempOut	= int64_add(tempOut, int64_mul_i64_i32(inFract64, inArg1));
	return int64_hi(tempOut);
}
