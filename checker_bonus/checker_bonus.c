/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:27:52 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 01:50:24 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_cmd(char *str, t_stack **st_a, t_stack **st_b)
{
	int	check;

	check = 0;
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
	{
		sa(st_a);
		check++;
	}
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
	{
		sb(st_a);
		check++;
	}
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
	{
		ss(st_a, st_b);
		check++;
	}
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
	{
		rr(st_a, st_b);
		check++;
	}
	return (check);
}

int	do_cmd2(char *str, t_stack **st_a, t_stack **st_b, int check)
{
	if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
	{
		pa(st_a, st_b);
		check++;
	}
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
	{
		pb(st_a, st_b);
		check++;
	}
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
	{
		ra(st_a);
		check++;
	}
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
	{
		rb(st_b);
		check++;
	}
	return (check);
}

int	do_cmd3(char *str, t_stack **st_a, t_stack **st_b, int check)
{
	if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
	{
		rra(st_a);
		check++;
	}
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
	{
		rrb(st_b);
		check++;
	}
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
	{
		rrr(st_a, st_b);
		check++;
	}
	return (check);
}

void	check_result(t_stack *st_a, t_stack *st_b)
{
	if (ft_is_sorted(st_a) == 0 && ft_stack_size(st_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	checker(t_stack **st_a, t_stack **st_b)
{
	char	*str;
	int		check;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		check = do_cmd(str, st_a, st_b);
		if (check == 0)
			check = do_cmd2(str, st_a, st_b, check);
		if (check == 0)
			check = do_cmd3(str, st_a, st_b, check);
		if (check == 0)
		{
			get_next_line(-1);
			write(2, "Error\n", 7);
			free_stack(st_a);
			free_stack(st_b);
			free(str);
			exit(EXIT_FAILURE);
		}
		free(str);
	}
	return ;
}
