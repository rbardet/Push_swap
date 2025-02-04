/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:37:06 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:24:48 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_same_value(t_stack *st_a)
{
	int		a;
	t_stack	*tmp;

	while (st_a != NULL)
	{
		a = st_a->value;
		st_a = st_a->next;
		tmp = st_a;
		while (tmp != NULL)
		{
			if (tmp->value == a)
			{
				write(2, "Error\n", 7);
				return (1);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ft_is_sorted(t_stack *st_a)
{
	int		a;
	t_stack	*tmp;

	while (st_a != NULL)
	{
		a = st_a->value;
		st_a = st_a->next;
		tmp = st_a;
		while (tmp != NULL)
		{
			if (tmp->value < a)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ft_stack_size(t_stack *st)
{
	int	a;

	a = 0;
	while (st)
	{
		st = st -> next;
		a++;
	}
	return (a);
}

int	ft_find_max_pos(t_stack *st)
{
	int	a;
	int	c;
	int	b;

	if (st == NULL)
		return (-1);
	a = st->value;
	b = 0;
	c = 1;
	st = st->next;
	while (st != NULL)
	{
		if (a < st->value)
		{
			b = c + 1;
			a = st->value;
		}
		c++;
		st = st->next;
	}
	return (b);
}

int	ft_find_lowest_pos(t_stack *st)
{
	int	a;
	int	c;
	int	b;

	a = st->value;
	b = 0;
	c = 1;
	st = st->next;
	while (st != NULL)
	{
		if (a > st->value)
		{
			a = st->value;
			b = c;
		}
		c++;
		st = st->next;
	}
	return (b);
}
