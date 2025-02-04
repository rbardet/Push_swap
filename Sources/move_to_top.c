/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:59:47 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:17:30 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move_to_top_a(t_stack **st, int a)
{
	int	b;
	int	mid;

	if (a == 0)
		return ;
	b = ft_stack_size(*st);
	mid = b / 2;
	if (a <= mid)
	{
		while (a > 0)
		{
			ra(st);
			a--;
		}
	}
	else
	{
		while (a < b)
		{
			rra(st);
			a++;
		}
	}
}

void	move_to_top_b(t_stack **st, int a)
{
	int	b;
	int	mid;

	if (a == 0)
		return ;
	b = ft_stack_size(*st);
	mid = b / 2;
	if (a <= mid)
	{
		while (a > 0)
		{
			rb(st);
			a--;
		}
	}
	else
	{
		while (a < b)
		{
			rrb(st);
			a++;
		}
	}
}
