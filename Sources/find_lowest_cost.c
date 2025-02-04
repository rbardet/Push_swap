/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:56:32 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:14:42 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_upper_pos(t_stack *st_a, int a)
{
	int		b;
	int		c;
	int		d;
	t_stack	*tmp;

	b = 0;
	c = 0;
	d = -1;
	tmp = st_a;
	while (tmp != NULL)
	{
		if (tmp->value > a)
		{
			if (d == -1 || (tmp->value - a) < (d - a))
			{
				d = tmp->value;
				b = c;
			}
		}
		c++;
		tmp = tmp->next;
	}
	return (b);
}

int	check_side(t_stack *st, int a)
{
	int	b;
	int	mid;

	b = ft_stack_size(st);
	mid = b / 2;
	if (a <= mid)
		return (0);
	else
		return (1);
}

int	check_distance(t_stack *st, int pos)
{
	int	size;
	int	count;

	count = 0;
	size = ft_stack_size(st);
	if (check_side(st, pos) == 0)
	{
		while (pos > 0)
		{
			pos--;
			count++;
		}
		return (count);
	}
	else
	{
		while (pos < ft_stack_size(st))
		{
			pos++;
			count++;
		}
		return (count);
	}
}

t_cost	find_lowest_cost(t_stack *st_a, t_stack *st_b, t_cost cost)
{
	t_stack	*tmp;
	int		tmp1;
	int		tmp2;

	cost.tmp_pos_b = 1;
	tmp = st_b;
	cost.pos_in_a = ft_find_upper_pos(st_a, tmp->value);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		cost.tmp_pos_a = ft_find_upper_pos(st_a, tmp->value);
		tmp1 = check_distance(st_a, cost.tmp_pos_a)
			+ check_distance(st_b, cost.tmp_pos_b);
		tmp2 = check_distance(st_a, cost.pos_in_a)
			+ check_distance(st_b, cost.pos_in_b);
		if ((tmp1 < tmp2))
		{
			cost.pos_in_a = cost.tmp_pos_a;
			cost.pos_in_b = cost.tmp_pos_b;
		}
		cost.tmp_pos_b++;
		tmp = tmp->next;
	}
	return (cost);
}
