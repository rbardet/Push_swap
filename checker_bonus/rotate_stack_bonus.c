/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:53:25 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/02 21:25:12 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// move every element from st_a to the top , the first element become the last
void	ra(t_stack **st_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stack_size(*st_a) < 2)
		return ;
	tmp = *st_a;
	*st_a = (*st_a)->next;
	tmp2 = *st_a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp->next = NULL;
	tmp2->next = tmp;
}

// move every element from st_b to the top , the first element become the last
void	rb(t_stack **st_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_stack_size(*st_b) < 2)
		return ;
	tmp = *st_b;
	*st_b = (*st_b)->next;
	tmp2 = *st_b;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp->next = NULL;
	tmp2->next = tmp;
}

// Do both ra and rb
void	rr(t_stack **st_a, t_stack **st_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;
	t_stack	*tmp4;

	if (ft_stack_size(*st_a) < 2)
		return ;
	tmp = *st_a;
	*st_a = (*st_a)->next;
	tmp2 = *st_a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	if (ft_stack_size(*st_b) < 2)
		return ;
	tmp3 = *st_b;
	*st_b = (*st_b)->next;
	tmp4 = *st_b;
	while (tmp4->next != NULL)
		tmp4 = tmp4->next;
	tmp3->next = NULL;
	tmp4->next = tmp3;
}
