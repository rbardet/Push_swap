/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:17:25 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 05:29:59 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_create_to_stack(int content)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->value = content;
	st->next = NULL;
	return (st);
}

t_stack	*push_to_stack(t_stack **st_a, t_stack *nb)
{
	t_stack	*st_a2;

	st_a2 = *st_a;
	while (st_a2->next != NULL)
		st_a2 = st_a2->next;
	st_a2->next = nb;
	return (*st_a);
}

t_stack	*init_to_stack(t_stack **st_a, char **tab, int b)
{
	long int	nb;
	int			a;

	a = 0;
	while (a != b)
	{
		nb = ft_atol(tab[a]);
		if (nb > INT_MAX || nb < INT_MIN || ft_strlen(tab[a]) > 12)
		{
			write(2, "Error\n", 7);
			free_tab(tab);
			free_stack(st_a);
			exit(EXIT_FAILURE);
		}
		if (a == 0)
			*st_a = ft_create_to_stack((int)nb);
		else
			*st_a = push_to_stack(st_a, ft_create_to_stack((int)nb));
		a++;
	}
	return (*st_a);
}

t_stack	*init_to_stack2(t_stack **st_a, int argc, char **argv)
{
	long int	nb;
	int			a;

	a = 1;
	while (a < argc)
	{
		ft_isdigital(argv[a], argv);
		nb = ft_atol(argv[a]);
		if (nb > INT_MAX || nb < INT_MIN || ft_strlen(argv[a]) > 12)
		{
			write(2, "Error\n", 7);
			free_stack(st_a);
			exit(EXIT_FAILURE);
		}
		if (a == 1)
			*st_a = ft_create_to_stack((int)nb);
		else
			*st_a = push_to_stack(st_a, ft_create_to_stack((int)nb));
		a++;
	}
	return (*st_a);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	char	**tab;
	int		b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		b = ft_countword(argv[1]);
		tab = ft_split(argv[1], ' ');
	}
	st_a = NULL;
	st_b = NULL;
	if (argc == 2)
		st_a = two_arg_case(st_a, tab, b);
	else
		st_a = init_to_stack2(&st_a, argc, argv);
	check_same_value(&st_a);
	checker(&st_a, &st_b);
	check_result(st_a, st_b);
	free_stack(&st_a);
	return (0);
}
