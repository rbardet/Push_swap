/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_arg_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:09:53 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 05:11:15 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*two_arg_case(t_stack *st_a, char **tab, int b)
{
	int	a;

	a = 0;
	while (tab[a] != NULL)
	{
		ft_isdigital(tab[a], tab);
		a++;
	}
	st_a = init_to_stack(&st_a, tab, b);
	return (st_a);
}
