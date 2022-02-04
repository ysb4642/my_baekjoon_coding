#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	unsigned char	src;
	size_t			i;

	dest = b;
	src = c;
	i = 0;
	while (i++ < len)
		*dest++ = src;
	return (b);
}