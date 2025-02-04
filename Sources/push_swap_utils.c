/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:41:17 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 04:46:53 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_last_element(t_stack *lst)
{
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst->value);
}

int	ft_check_if_highest(t_stack *st, int value)
{
	int	a;

	a = 0;
	while (st != NULL)
	{
		if (st->value > value)
			a++;
		st = st->next;
	}
	return (a);
}

char	**free_tab(char **tab)
{
	int	a;

	a = 0;
	while (tab[a] != NULL)
	{
		free(tab[a]);
		a++;
	}
	free (tab);
	return (tab);
}
