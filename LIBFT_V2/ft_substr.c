/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:13:41 by rbardet-          #+#    #+#             */
/*   Updated: 2024/10/22 14:42:24 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strleng(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_subsubstr(int start, size_t len, char *source, char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (start != 0)
	{
		a++;
		start--;
	}
	while (len != 0)
	{
		str[b] = source[a];
		a++;
		b++;
		len--;
	}
	str[b] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*source;
	char			*str;
	int				a;
	int unsigned	b;

	a = 0;
	b = ft_strleng(s);
	source = (char *)s;
	if (start >= b)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[a] = '\0';
		return (str);
	}
	if (len > b - start)
		len = b - start;
	str = malloc(sizeof(char) *(len + 1));
	if (!str)
		return (NULL);
	str = ft_subsubstr(start, len, source, str);
	return (str);
}
// int main(void)
// {
// 	char const str1[] = "Lille OSC";
// 	printf("%s", ft_substr(str1, 0, 5));
// 	return(0);
// }
