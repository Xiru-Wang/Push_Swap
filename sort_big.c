/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:05 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/02 18:00:05 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# define TOP 1
# define BOTTOM 2

void	set_target(t_stack *a, t_stack *b);
void	sort_big(t_stack **a, t_stack **b);
void	calculate_price(t_stack *a, t_stack *b);
void	set_flag(t_stack *stack);
void	set_cost_to_top(t_stack *stack);

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	//int		half;

	push_below_average(a, b);
	sort_five(a, b);
	set_target(*a, *b);// set target node
	while (*b)
	{
		calculate_price(a, b); // todo
	}
	//Last step: put biggest to the bottom
	temp = find_max_node(a);
	while (last(a) != temp)
	{
		set_flag(a);
		if (temp->flag == TOP)//first half
			ra(a);
		else
			rra(a);//second half
	}
}

//find the smallest big
//https://github.com/suspectedoceano/push_swap/blob/main/push_swap/push_swap_init.c

void	set_target(t_stack *a, t_stack *b)
{
	int		best_match;
	t_stack	*target;

	while (b)
	{
		best_match = INT_MAX;//make sure it will be replaced
		while (a)
		{
			if (a->value > b->value && a->value < best_match)
			{
				best_match = a->value;
				target = a;
			}
			a = a->next;
		}
		if (best_match == INT_MAX)// biggestB finds smallestA
			b->target = find_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_flag(t_stack *stack)//?
{
	int	i;
	int	middle;
	i = 0;
	middle = size(stack) / 2;
	while (stack)
	{
		//stack->position = i;
		stack->flag = TOP;
		stack = stack->next;
		i++;
		if (i > middle)
			stack->flag = BOTTOM;
	}
}

//cost to be on top  0 1 2 3 4|3 2 1(8/2 ==4)
void	set_cost_to_top(t_stack *stack)
{
	int	cost;
	int	middle;
	cost = 0;
	middle = size(stack) / 2;
	while (stack)
	{
		stack->cost = cost;
		stack = stack->next;
		if (cost <= middle)
			cost++;
		else
			cost--;
	}
}
// Stack a: a.cost to be on top
// Stack b:cost to be on top
// first half : b.position + target.position
// second half: size(b) - b.position + size(a) - target.position
void	calculate_price(t_stack *a, t_stack *b)
{
	set_cost_to_top(a);
	set_cost_to_top(b);
	// how many steps to be on top for A && B
	while (b)
	{
		b->price = b->cost + b->target->cost;;
		b = b->next;
	}
	// how many steps to be on top for A && B
}

void	find_best_price(t_stack *b)
{
	int		min;
	t_stack	*best_node;

	min = INT_MAX;
	if (b == NULL)
		return ;
	while (b)
	{
		if (b->best_price < min)
		{
			min = b->best_price;
			best_node = b;
		}
		b = b->next;
	}
	best_node->best_price = true;//TODO!!
}
