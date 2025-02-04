/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:27:55 by rbardet-          #+#    #+#             */
/*   Updated: 2024/10/22 14:36:01 by rbardet-         ###   ########.fr       */
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

static int	ft_find_d(char const *str1, char const *set)
{
	char	*str2;
	char	*set1;
	int		a;
	int		b;

	str2 = (char *) str1;
	set1 = (char *) set;
	a = 0;
	b = 0;
	while (set1[b] != '\0')
	{
		if (str2[a] == set1[b])
		{
			a++;
			b = 0;
		}
		else
			b++;
	}
	return (a);
}

static int	ft_find_f(char const *str1, char const *set)
{
	char	*str2;
	char	*set1;
	int		b;
	int		a;

	str2 = (char *) str1;
	set1 = (char *) set;
	b = ft_strleng(str1) - 1;
	a = 0;
	while (set1[a] != '\0')
	{
		if (str2[b] == set1[a])
		{
			b--;
			a = 0;
		}
		else
			a++;
	}
	return (b + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	int		c;
	int		longueur;
	char	*s2;

	a = ft_find_d(s1, set);
	b = ft_find_f(s1, set);
	c = 0;
	longueur = b - a;
	if (a >= b)
	{
		s2 = malloc(1);
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	s2 = malloc(sizeof(char) * (longueur + 1));
	if (!s2)
		return (NULL);
	while (a < b)
		s2[c++] = s1[a++];
	s2[c] = '\0';
	return (s2);
}

// int main(void)
// {
// 	char const str[] = "";
// 	char set[] = "cdef";
// 	printf("%s", ft_strtrim(str, set));
// 	return(0);
// }
