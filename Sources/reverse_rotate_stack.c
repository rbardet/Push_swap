/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:53:40 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/02 22:13:31 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move every element from st_a to the bot , the last element become the first
void	rra(t_stack **st_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stack_size(*st_a) < 2)
		return ;
	tmp = *st_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = *st_a;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *st_a;
	*st_a = tmp;
	ft_printf("rra\n");
}

// move every element from st_b to the bot , the last element become the first
void	rrb(t_stack **st_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stack_size(*st_b) < 2)
		return ;
	tmp = *st_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = *st_b;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *st_b;
	*st_b = tmp;
	ft_printf("rrb\n");
}

// do both rra and rrb;
void	rrr(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stack_size(*st_b) < 2)
		return ;
	tmp = *st_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = *st_b;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *st_b;
	*st_b = tmp;
	rrr2(st_a, st_b);
}

void	rrr2(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	(void)st_b;
	if (ft_stack_size(*st_a) < 2)
		return ;
	tmp = *st_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = *st_a;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *st_a;
	*st_a = tmp;
	ft_printf("rrr\n");
}
