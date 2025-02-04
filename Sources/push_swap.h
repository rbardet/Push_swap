/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:21:04 by rbardet-          #+#    #+#             */
/*   Updated: 2025/02/03 05:10:55 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../LIBFT_V2/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_cost
{
	int				pos_in_a;
	int				pos_in_b;
	int				tmp_pos_a;
	int				tmp_pos_b;
}					t_cost;

typedef struct t_tab
{
	int				*group;
	int				*tab;
	int				nb;
	int				group_pos;
	int				group_value;
}					t_tab;

typedef struct t_stack
{
	int				value;
	struct t_stack	*next;
}					t_stack;

t_stack	*init_to_stack(t_stack **st_a, char **tab, int b);
t_stack	*init_to_stack2(t_stack **st_a, int argc, char **argv);
t_stack	*two_arg_case(t_stack *st_a, char **tab, int b);
t_stack	*push_to_stack(t_stack **st_a, t_stack *nb);
int		check_same_value(t_stack *st_a);
int		ft_is_sorted(t_stack *st_a);
int		ft_stack_size(t_stack *st);
int		ft_find_max_pos(t_stack *st);
int		ft_find_lowest_pos(t_stack *st);
t_stack	*ft_create_to_stack(int content);
int		ft_isdigital(char *str, char **tab);
int		ft_countword(char *argv);
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
void	ft_sort_three(t_stack **st);
void	move_to_top_a(t_stack **st, int a);
void	move_to_top_b(t_stack **st, int a);
int		ft_find_upper_pos(t_stack *st_a, int a);
void	free_stack(t_stack **st);
int		*sort_int_tab(int argc, t_stack *st);
int		*fill_tab(t_stack *st);
int		search_for_value(int *normalized_tab, int value, int argc);
void	init_sorting_value(t_stack **st_a, t_stack **st_b);
void	sort_in_b(t_stack **st_a, t_stack **st_b, t_tab tab);
int		*ft_number_per_group(t_stack *st);
int		*ft_number_per_group2(int a, int b, int stack_size, int *group);
void	sort_in_a(t_stack **st_a, t_stack **st_b, t_tab tab);
int		ft_check_if_highest(t_stack *st, int value);
char	**free_tab(char **tab);
void	ft_sort_two(t_stack **st);
void	special_case(t_stack **st_a, t_stack **st_b, int st_size, t_tab tab);
void	ft_sort_five(t_stack **st_a, t_stack **st_b);
t_cost	find_lowest_cost(t_stack *st_a, t_stack *st_b, t_cost cost);
int		ft_last_element(t_stack *lst);
int		check_side(t_stack *st, int a);
t_cost	rotate_both(t_stack **st_a, t_stack **st_b, t_cost cost);
int		check_distance(t_stack *st, int pos);
void	sort_in_b_big(t_stack **st_a, t_stack **st_b, t_tab tab);
int		search_for_value_big(int *normalized_tab, int value, int argc);
int		*ft_number_per_group_big(t_stack *st);
int		*ft_number_per_group2_big(int a, int b, int stack_size, int *group);

#endif
