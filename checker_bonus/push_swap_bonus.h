/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:21:04 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/02 20:20:37 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../LIBFT_V2/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_stack
{
	int				value;
	struct t_stack	*next;
}					t_stack;

void	sa(t_stack **st_a);
void	sb(t_stack **st_b);
void	ss(t_stack **st_a, t_stack **st_b);
void	pa(t_stack **st_a, t_stack **st_b);
void	pb(t_stack **st_a, t_stack **st_b);
void	ra(t_stack **st_a);
void	rb(t_stack **st_b);
void	rr(t_stack **st_a, t_stack **st_b);
void	rra(t_stack **st_a);
void	rrb(t_stack **st_b);
void	rrr(t_stack **st_a, t_stack **st_b);
void	rrr2(t_stack **st_a, t_stack **st_b);
void	checker(t_stack **st_a, t_stack **st_b);
void	check_result(t_stack *st_a, t_stack *st_b);
int		ft_is_sorted(t_stack *st_a);
int		ft_stack_size(t_stack *st);
int		ft_isdigital(char *str, char **tab);
int		check_same_value(t_stack **st_a);
int		ft_countword(char *argv);
t_stack	*two_arg_case(t_stack *st_a, char **tab, int b);
void	check_tab(char **tab);
t_stack	*check_tab2(char **argv, t_stack *st_a, int argc);
void	free_stack(t_stack **st);
char	**free_tab(char **tab);
t_stack	*init_to_stack2(t_stack **st_a, int argc, char **argv);
t_stack	*init_to_stack(t_stack **st_a, char **tab, int b);
int		do_cmd(char *str, t_stack **st_a, t_stack **st_b);
int		do_cmd2(char *str, t_stack **st_a, t_stack **st_b, int check);
int		do_cmd3(char *str, t_stack **st_a, t_stack **st_b, int check);

#endif
