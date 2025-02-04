/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:58:22 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 05:13:19 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**free_tab(char **tab)
{
	int	a;

	a = 0;
	while (tab[a] != NULL)
	{
		free(tab[a]);
		a++;
	}
	free (tab);
	return (tab);
}

void	free_stack(t_stack **st)
{
	t_stack	*tmp;

	while (*st)
	{
		tmp = *st;
		*st = (*st)->next;
		free(tmp);
	}
}
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
