/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack_big.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:23:19 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/01 20:29:18 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_for_value_big2(int *normalized_tab, int value, int argc)
{
	int	a;
	int	stack_size;

	a = 0;
	while (normalized_tab[a] != value)
		a++;
	stack_size = argc / 10;
	if (a <= stack_size * 8)
		return (8);
	if (a <= stack_size * 9)
		return (9);
	else
		return (10);
}

int	search_for_value_big(int *normalized_tab, int value, int argc)
{
	int	a;
	int	stack_size;

	a = 0;
	while (normalized_tab[a] != value)
		a++;
	stack_size = argc / 10;
	if (a <= stack_size)
		return (1);
	if (a <= stack_size * 2)
		return (2);
	if (a <= stack_size * 3)
		return (3);
	if (a <= stack_size * 4)
		return (4);
	if (a <= stack_size * 5)
		return (5);
	if (a <= stack_size * 6)
		return (6);
	if (a <= stack_size * 7)
		return (7);
	else
		return (search_for_value_big2(normalized_tab, value, argc));
}

int	*ft_number_per_group_big(t_stack *st)
{
	int	a;
	int	b;
	int	stack_size;
	int	*number_per_group;

	a = ft_stack_size(st);
	b = 0;
	stack_size = (a / 10);
	number_per_group = malloc(sizeof(int) * (10));
	if (!number_per_group)
		return (NULL);
	return (ft_number_per_group2_big(a, b, stack_size, number_per_group));
}

static int	*ft_number_per_group3_big(int a, int b, int stack_size, int *group)
{
	while (b < a)
	{
		if (b <= stack_size)
			group[0]++;
		else if (b <= stack_size * 2)
			group[1]++;
		else if (b <= stack_size * 3)
			group[2]++;
		else if (b <= stack_size * 4)
			group[3]++;
		else if (b <= stack_size * 5)
			group[4]++;
		else if (b <= stack_size * 6)
			group[5]++;
		else if (b <= stack_size * 7)
			group[6]++;
		else if (b <= stack_size * 8)
			group[7]++;
		else if (b <= stack_size * 9)
			group[8]++;
		else
			group[9]++;
		b++;
	}
	return (group);
}

int	*ft_number_per_group2_big(int a, int b, int stack_size, int *group)
{
	group[0] = 0;
	group[1] = 0;
	group[2] = 0;
	group[3] = 0;
	group[4] = 0;
	group[5] = 0;
	group[6] = 0;
	group[7] = 0;
	group[8] = 0;
	group[9] = 0;
	return (ft_number_per_group3_big(a, b, stack_size, group));
}
