#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)ft_memalloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (len--)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}