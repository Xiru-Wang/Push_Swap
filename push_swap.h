/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:36:40 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/06 17:11:45 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

# define TOP 42
# define BOTTOM 24

typedef struct	s_stack
{
	int				value;
	//int				position;// 0 1 2 3 4...
	int				cost;//how many moves to be on top
	int				flag;// UP(1st half) or BOTTOM (the other half)
	int				price;//cost_A + cost_B
	//int				best_price;//cheapest
	struct s_stack *next;
	struct s_stack	*target;
}				t_stack;

//utils
void		free_strs(char **str);
void		handle_err(void);
void		free_stack(t_stack **head);
void		print_stack(t_stack *stack);
// check av
long int	atoi_range(char *s);
void		check_av(char **av);
//fill_stack
t_stack		*fill_stack(char **av);
int			is_sorted(t_stack *a);
// utils_node
int			size(t_stack *stack);
t_stack		*new_node(int value);
void		node_add_back(t_stack **a, t_stack *new);
//swap
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
//rotate
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b, t_stack *top);
//reverse rotate
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b, t_stack *top);
//sort_tiny
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
t_stack		*find_min_node(t_stack *a);
t_stack		*find_max_node(t_stack *a);
// pa pb
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
// count average and push
void		push_low_quarter(t_stack **a, t_stack **b);
void		push_below_average(t_stack **a, t_stack **b);
void		set_target(t_stack *a, t_stack *b);
void		calculate_price(t_stack *a, t_stack *b);
void		set_flag(t_stack *stack);
t_stack		*find_cheapest_node(t_stack *b);
void		sort_big(t_stack **a, t_stack **b);
void		set_cost_to_top(t_stack *stack);

# endif
