/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:05 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/03 19:13:44 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_flag(t_stack *stack)
{
	int	i;
	int	middle;
	i = 0;
	middle = size(stack) / 2;
	while (stack)
	{
		//stack->position = i;
		stack->flag = true;//top half
		if (i > middle)
			stack->flag = false;//bottom half
		i++;
		stack = stack->next;
	}
}

//cost to be on top  0 1 2 3 4|3 2 1(8/2 ==4)
static void	set_cost_to_top(t_stack *stack)
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

t_stack	*find_best_price(t_stack *b)
{
	int		min;
	t_stack	*best_node;

	min = INT_MAX;
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->best_price < min)
		{
			min = b->best_price;
			best_node = b;
		}
		b = b->next;
	}
	best_node->best_price = 1;
	return (best_node);
}
