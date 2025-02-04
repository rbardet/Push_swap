/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:15:59 by rbardet-          #+#    #+#             */
/*   Updated: 2024/10/22 13:00:03 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char unsigned	*sc1;
	const char unsigned	*sc2;

	sc1 = (const char unsigned *) s1;
	sc2 = (const char unsigned *) s2;
	while (n != 0)
	{
		if (*sc1 != *sc2)
		{
			return (*sc1 - *sc2);
		}
		sc1++;
		sc2++;
		n--;
	}
	return (0);
}
// int main(void)
// {
// 	char chaine1[]="\0";
// 	char chaine2[]="\200";
// 	unsigned int taille = 2;

// 	printf("%d\n", ft_memcmp(chaine1, chaine2, taille));
// 	printf("%d\n", memcmp(chaine1, chaine2, taille));
// }
