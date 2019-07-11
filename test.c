#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define VAR_TO_STR_BIN(x) obj_to_bin((char [sizeof(x)*8 + 1]){""}, &(x), sizeof (x))

void print_bytes(void *ptr, int size)
{
    unsigned char *p = ptr;
    int i;
    for (i=0; i<size; i++) {
        printf("%02hhX ", p[i]);
    }
    printf("\n");
}

char *obj_to_bin(char *dest, void *object, size_t osize)
{
  const unsigned char *p = (const unsigned char *) object;
  p += osize;
  char *s = dest;
  while (osize-- > 0) {
    p--;
    unsigned i = 8;
    while (i-- > 0) {
      *s++ = ((*p >> i) & 1) + '0';
    }
  }
  *s = '\0';
  return dest;
}

char					*ft_itoa_base_min(short dec, int base, int up)
{
	char *nbr;
	short a;
	nbr = NULL;
int igr = 0;
	int i = sizeof(dec) * 8;

	dec *= -1;
	printf("mem1: %s\n", VAR_TO_STR_BIN(dec));

	a = 1;
	while (i--)
	{
		dec = dec ^ a;
		a = a << 1;
	}
	printf("mem2: %s\n", VAR_TO_STR_BIN(dec));

	dec += 1;
	printf("mem2: %s\n", VAR_TO_STR_BIN(dec));
	printf("dec = %d\n",(int)dec);


	igr = igr | 1;
	i = sizeof(dec) * 8;
	a = 1;
	while (i--)
	{
		if (dec & 1)
			igr = igr | a;
		dec = dec << 1;
		a = a << 1;
	}
	printf("igr: %s\n", VAR_TO_STR_BIN(igr));
	printf("igr = %d\n",igr);
	//nbr = ft_itoa_base((int)(*f), base, up);
	return (nbr);
}

int main()
{
	printf("65517 = %d\n", (short)65517);
	char *res = ft_itoa_base_min(-19, 16, 0);
	printf("%s - result\nffed - required\n",res);
	return (0);
}
