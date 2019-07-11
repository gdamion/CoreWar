#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int reverseBits(short num)
{
    unsigned int  NO_OF_BITS = sizeof(short) * 8;
    unsigned int reverse_num = 0, i, temp;

    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
    return reverse_num;
}

char					*ft_itoa_base_min(int dec, int base, int up)
{
	char				*nbr;
	char *buf;
	int a;
	int b = 1;

	dec *= -1;
	printf("dec 1 = %d\n", dec);
	a = dec;
	dec = a ^ b;
	printf("dec 2 = %d\n", dec);
	dec += 1;
	printf("dec 3 = %d\n", dec);
	nbr = ft_itoa_base(dec, base, up);
	return (nbr);
}

int main()
{
	char *res = ft_itoa_base_min(-19, 16, 0);
	printf("%s - result\nffed - required\n",res);
	return (0);
}
