
#include <stdio.h>
#include <math.h>

#define makefloat(s,e,f) (((s) & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)


typedef union { 
  float f;
  unsigned int i;
 } U;


float float2(float f)
{
	if(f == 0) return 0;
	U u;
	u.f = f;
	unsigned int x = u.i;
	unsigned int exp = (x >> 23) & 0xFF;
	exp++;
	if(exp >=  255)
	{
		if(f > 0) u.i =  makefloat(0,255,0);
		else u.i = makefloat(1,255,0);
	}
	else
	{
		u.i = (x & 0x807fffff) | (exp<<23);
	}
	return u.f;
	
}

float int2float(int i)
{
	if(i==0) return 0;
	int s, e = 0, f = 0;
	int temp;
	unsigned int i_uns;
	U u;
	if(i > 0) s = 0;
	else
	{ 
		s = 1;
		i = -i;
	}
	f = i;
	i_uns = i;
	while(i_uns != 0)
	{
		e++;
		i_uns = i_uns >> 1;
	}
	temp = (23 - e + 1);
	if(temp < 0) f = f >> (-temp);
	else f = f << temp;
	e = e + 127 -1;
	
	u.i = makefloat(s,e,f);
	
	return u.f;
}

int main(void)
{
	float f = 0.33333333333333333333;
	int i = -214748336;
	//float2	
	printf("%f\n", float2(f));
	f = -10;
	printf("%f\n", float2(f));
	f = 10;
	printf("%f\n", float2(f));
	f = 12334676456345667450.;
	printf("%f\n", float2(f));
	f = -12334676345665.;
	printf("%f\n", float2(f));
	
	//int2float
	printf("%f\n", int2float(i));
	i = 1;
	printf("%f\n", int2float(i));
	i = -1;
	printf("%f\n", int2float(i));
	i = 247653478;
	printf("%f\n", int2float(i));
	return 0;
}
