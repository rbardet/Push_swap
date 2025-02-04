/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:24:26 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:05:50 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **st)
{
	int	a;

	a = ft_find_max_pos(*st);
	if (ft_is_sorted(*st) == 0)
		return ;
	if (a == 0 && (*st)->next->value < (*st)->next->next->value)
		ra(st);
	else if (a == 0 && (*st)->next->value > (*st)->next->next->value)
	{
		ra(st);
		sa(st);
	}
	else if (a == 2 && (*st)->value < (*st)->next->next->value)
	{
		rra(st);
		sa(st);
	}
	else if (a == 2 && (*st)->value > (*st)->next->next->value)
		rra(st);
	else if (a == 3 && (*st)->value > (*st)->next->value)
		sa(st);
	return ;
}

void	ft_sort_two(t_stack **st)
{
	if (ft_is_sorted(*st) == 0)
		return ;
	ra(st);
	return ;
}

void	ft_sort_five(t_stack **st_a, t_stack **st_b)
{
	while (ft_stack_size(*st_a) != 3)
		pb(st_a, st_b);
	ft_sort_three(st_a);
	while (ft_stack_size(*st_b) != 0)
	{
		move_to_top_a(st_a, ft_find_upper_pos((*st_a), (*st_b)->value));
		pa(st_a, st_b);
	}
	move_to_top_a(st_a, ft_find_lowest_pos(*st_a));
}

void	special_case(t_stack **st_a, t_stack **st_b, int st_size, t_tab tab)
{
	if (tab.nb > 199)
		sort_in_b_big(st_a, st_b, tab);
	else if (st_size == 2)
		ft_sort_two(st_a);
	else if (st_size == 3)
		ft_sort_three(st_a);
}
