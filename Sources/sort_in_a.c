/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 04:10:50 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:11:13 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	rotate_both(t_stack **st_a, t_stack **st_b, t_cost cost)
{
	int	side_a;
	int	side_b;

	side_a = check_side(*st_a, cost.pos_in_a);
	side_b = check_side(*st_b, cost.pos_in_b);
	while ((cost.pos_in_a > 0 && cost.pos_in_b > 0) && side_a == side_b
		&& (cost.pos_in_a < ft_stack_size(*st_a)
			&& cost.pos_in_b < ft_stack_size(*st_b)))
	{
		if (side_a == 0)
		{
			rr(st_a, st_b);
			cost.pos_in_a--;
			cost.pos_in_b--;
		}
		else
		{
			rrr(st_a, st_b);
			cost.pos_in_a++;
			cost.pos_in_b++;
		}
	}
	return (cost);
}

void	sort_in_a(t_stack **st_a, t_stack **st_b, t_tab tab)
{
	t_cost	cost;

	free(tab.tab);
	free(tab.group);
	ft_sort_three(st_a);
	while (ft_stack_size(*st_b) != 0)
	{
		cost.pos_in_b = 0;
		cost = find_lowest_cost((*st_a), (*st_b), cost);
		cost = rotate_both(st_a, st_b, cost);
		move_to_top_a(st_a, cost.pos_in_a);
		move_to_top_b(st_b, cost.pos_in_b);
		pa(st_a, st_b);
	}
	if (ft_is_sorted(*st_a))
		move_to_top_a(st_a, ft_find_lowest_pos(*st_a));
	return ;
}
