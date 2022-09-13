#include "../include/philo.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	char			*d_ptr;
	unsigned char	value;

	d_ptr = (char *)b;
	value = (unsigned char)c;
	while (len > 0)
	{
		*d_ptr = c;
		d_ptr++;
		len--;
	}
	return (b);
}