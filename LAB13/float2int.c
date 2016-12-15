#include <limits.h>

typedef union {
  float f;
  unsigned int i;
} U; 


int float2int(float f)
{
	U u;
	u.f = f;
	unsigned int mantissa = (u.i & 0x7FFFFF);
	int exp = (u.i & 0x7F800000) - 127;
	if(exp > 0)
	{
		mantissa = mantissa | (1 << 23);
		mantissa = mantissa >> (24 - exp);
		if(u.i & 0x80000000) mantissa = -mantissa;
		return mantissa;
	}
	else return 0;	
}
