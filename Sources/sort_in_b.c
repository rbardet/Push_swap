/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:41:34 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:11:26 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sorting_value(t_stack **st_a, t_stack **st_b)
{
	t_tab	tab;

	tab.group_pos = 0;
	tab.group_value = 1;
	tab.nb = ft_stack_size(*st_a);
	if ((tab.nb < 4) || (tab.nb > 199))
	{
		special_case(st_a, st_b, tab.nb, tab);
		return ;
	}
	tab.tab = sort_int_tab(tab.nb, (*st_a));
	tab.group = ft_number_per_group((*st_a));
	if (tab.tab == NULL || tab.group == NULL)
		return ;
	sort_in_b(st_a, st_b, tab);
}

void	sort_in_b(t_stack **st_a, t_stack **st_b, t_tab tab)
{
	while(tab.group_pos != 4)
	{
		while (tab.group[tab.group_pos] != 0 && ft_stack_size(*st_a) != 3)
		{
			if (ft_check_if_highest((*st_a), (*st_a)->value) == 0)
				ra(st_a);
			if (search_for_value(tab.tab, (*st_a)->value, tab.nb) == tab.group_value)
			{
				pb(st_a, st_b);
				tab.group[tab.group_pos]--;
			}
			else
				ra(st_a);
		}
		tab.group_pos++;
		tab.group_value++;
	}
	sort_in_a(st_a, st_b, tab);
}

void	sort_in_b_big(t_stack **st_a, t_stack **st_b, t_tab tab)
{
	tab.tab = sort_int_tab(tab.nb, (*st_a));
	tab.group = ft_number_per_group_big((*st_a));
	if (tab.tab == NULL || tab.group == NULL)
		return ;
	while(tab.group_pos != 10)
	{
		while (tab.group[tab.group_pos] != 0 && ft_stack_size(*st_a) != 3)
		{
			if (ft_check_if_highest((*st_a), (*st_a)->value) == 0)
				ra(st_a);
			if (search_for_value_big(tab.tab, (*st_a)->value, tab.nb) == tab.group_value)
			{
				pb(st_a, st_b);
				tab.group[tab.group_pos]--;
			}
			else
				ra(st_a);
		}
		tab.group_pos++;
		tab.group_value++;
	}
	sort_in_a(st_a, st_b, tab);
}
