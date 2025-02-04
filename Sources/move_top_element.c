/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:12:02 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/02 22:12:42 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move the first element of st_b on top of st_a
void	pa(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;

	if (ft_stack_size(*st_b) == 0)
		return ;
	tmp = (*st_b);
	*st_b = (*st_b)->next;
	tmp->next = *st_a;
	*st_a = tmp;
	ft_printf("pa\n");
}

// move the first element of st_a on top of st_b
void	pb(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;

	if (ft_stack_size(*st_a) == 0)
		return ;
	tmp = (*st_a);
	*st_a = (*st_a)->next;
	tmp->next = *st_b;
	*st_b = tmp;
	ft_printf("pb\n");
}
