/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_top_element_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:04:57 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/02 21:25:19 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// swap the 2 first element of st_a
void	sa(t_stack **st_a)
{
	t_stack	*tmp;

	if (ft_stack_size(*st_a) < 2)
		return ;
	tmp = *st_a;
	*st_a = (*st_a)->next;
	tmp->next = (*st_a)->next;
	(*st_a)->next = tmp;
}

// swap the 2 first element of st_b
void	sb(t_stack **st_b)
{
	t_stack	*tmp;

	if (ft_stack_size(*st_b) < 2)
		return ;
	tmp = *st_b;
	*st_b = (*st_b)->next;
	tmp->next = (*st_b)->next;
	(*st_b)->next = tmp;
}

// do both st_a and st_b
void	ss(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stack_size(*st_b) < 2)
		return ;
	tmp = *st_b;
	*st_b = (*st_b)->next;
	tmp->next = (*st_b)->next;
	(*st_b)->next = tmp;
	if (ft_stack_size(*st_a) < 2)
		return ;
	tmp2 = *st_a;
	*st_a = (*st_a)->next;
	tmp2->next = (*st_a)->next;
	(*st_a)->next = tmp;
}
