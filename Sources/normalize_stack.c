/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:31:04 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/01 20:07:32 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_tab(t_stack *st)
{
	int	*normalize_tab;
	int	a;
	int	tab_size;

	if (!st)
		return (NULL);
	a = ft_stack_size(st);
	tab_size = 0;
	normalize_tab = malloc(sizeof(int) * (a));
	if (normalize_tab == NULL)
		return (NULL);
	while (st != NULL)
	{
		normalize_tab[tab_size] = st->value;
		st = st->next;
		tab_size++;
	}
	return (normalize_tab);
}

int	*sort_int_tab(int argc, t_stack *st)
{
	int		a;
	int		b;
	int		*normalize_tab;
	int		temp;

	normalize_tab = fill_tab(st);
	a = 0;
	while (argc > a)
	{
		b = a + 1;
		while (argc > b)
		{
			if ((normalize_tab[a] - normalize_tab [b]) > 0)
			{
				temp = normalize_tab[a];
				normalize_tab[a] = normalize_tab[b];
				normalize_tab[b] = temp;
			}
			b++;
		}
		a++;
	}
	return (normalize_tab);
}

int	search_for_value(int *normalized_tab, int value, int argc)
{
	int	a;
	int	stack_size;

	a = 0;
	while (normalized_tab[a] != value)
		a++;
	stack_size = argc / 4;
	if (a <= stack_size)
		return (1);
	if (a <= stack_size * 2)
		return (2);
	if (a <= stack_size * 3)
		return (3);
	else
		return (4);
}

int	*ft_number_per_group(t_stack *st)
{
	int	a;
	int	b;
	int	stack_size;
	int	*number_per_group;

	a = ft_stack_size(st);
	b = 0;
	stack_size = (a / 4);
	number_per_group = malloc(sizeof(int) * (4));
	if (!number_per_group)
		return (NULL);
	return (ft_number_per_group2(a, b, stack_size, number_per_group));
}

int	*ft_number_per_group2(int a, int b, int stack_size, int *group)
{
	group[0] = 0;
	group[1] = 0;
	group[2] = 0;
	group[3] = 0;
	while (b < a)
	{
		if (b <= stack_size)
			group[0]++;
		else if (b <= stack_size * 2)
			group[1]++;
		else if (b <= stack_size * 3)
			group[2]++;
		else
			group[3]++;
		b++;
	}
	return (group);
}
