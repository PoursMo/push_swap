#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	i = size;
	while (--i && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (srclen);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	if (!n)
		return (0);
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (*cs1 == *cs2 && --n)
	{
		cs1++;
		cs2++;
	}
	return (*cs1 - *cs2);
}
