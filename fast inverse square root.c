#include <stdio.h>

// https://en.wikipedia.org/wiki/Fast_inverse_square_root
// https://betterexplained.com/articles/understanding-quakes-fast-inverse-square-root/
// https://stackoverflow.com/questions/11513344/how-to-implement-the-fast-inverse-square-root-in-java/11513345
float Q_rsqrt( float number )
{
    // this union helps accessing the bits of the floating point number
	union {
		float f;
		long i;
	} conv;
	// https://www.youtube.com/watch?v=4nShTeUEJIQ
	const float threehalfs = 1.5F;
	float x2 = number * 0.5F;
	
	conv.f  = number;
	conv.i  = 0x5f3759df - ( conv.i >> 1 ); // this is playing with the bits of the power inside the floating point number
	conv.f  = conv.f * ( threehalfs - ( x2 * conv.f * conv.f ) ); // newton iteration
	return conv.f;
}

int main()
{
    float a = Q_rsqrt(16);
    
    printf("%f \n", a);

    return 0;
}
