/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:52:36 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 01:01:43 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_isdigital(char *str, char **tab)
{
	int	a;

	a = 0;
	if (((str[a] == '-' || str[a] == '+') && ft_isdigit(str[1])))
		a++;
	else if (((str[a] == '-' || str[a] == '+') && !ft_isdigit(str[1])))
	{
		write(2, "Error\n", 7);
		if (tab)
			free_tab(tab);
		exit(EXIT_FAILURE);
	}
	while (str[a] != '\0')
	{
		if (!ft_isdigit(str[a]))
		{
			if (tab)
				free_tab(tab);
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		a++;
	}
	return (0);
}

int	check_same_value(t_stack **st_a)
{
	int		a;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = (*st_a);
	while (tmp2 != NULL)
	{
		a = tmp2->value;
		tmp2 = tmp2->next;
		tmp = tmp2;
		while (tmp != NULL)
		{
			if (tmp->value == a)
			{
				write(2, "Error\n", 7);
				free_stack(st_a);
				exit(EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ft_countword(char *argv)
{
	int	a;
	int	countword;

	a = 0;
	countword = 0;
	while (argv[a] == ' ')
		a++;
	if ((argv[0] >= '0' && argv[0] <= '9') || (argv[0] == '-'
			|| argv[0] <= '+'))
	{
		countword++;
		a++;
	}
	while (argv[a] != ' ' && argv[a] != '\0')
		a++;
	while (argv[a] != 0)
	{
		if (argv[a] == ' ')
			a++;
		if ((argv[a - 1] == ' ') && ((argv[a] >= '0' && argv[a] <= '9')
				|| (argv[a] == '-' || argv[a] == '+')))
			countword++;
		a++;
	}
	return (countword);
}
