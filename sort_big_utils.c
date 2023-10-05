/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:05 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/05 21:12:38 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://github.com/suspectedoceano/push_swap/blob/main/push_swap/push_swap_init.c
//find the smallest big
void	set_target(t_stack *a, t_stack *b)
{
	int		best_match;
	t_stack	*target;
	t_stack	*temp;

	while (b)
	{
		best_match = INT_MAX;//make sure it will be replaced
		temp = a;//!!reset a, otherwise
		while (temp)
		{
			if (temp->value > b->value && temp->value < best_match)
			{
				best_match = temp->value;
				target = temp;
			}
			temp = temp->next;
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
		stack->flag = TOP;//top half
		if (i > middle)
			stack->flag = BOTTOM;//bottom half
		i++;
		stack = stack->next;
	}
}

//cost to be on top  0 1 2 3 4|3 2 1(8/2 ==4)
static void	set_cost_to_top(t_stack *stack)
{
	int	cost;
	int	middle;
	cost = -1;
	middle = size(stack) / 2;
	while (stack)
	{
		if (cost <= middle)
			cost++;
		else
			cost--;
		stack->cost = cost;
		stack = stack->next;
	}
}

// first half : b.position + target.position
// how many steps to be on top for A && B
void	calculate_price(t_stack *a, t_stack *b)
{
	set_cost_to_top(a);
	set_cost_to_top(b);
	while (b)
	{
		b->price = b->cost + b->target->cost;
		b = b->next;
	}
}

t_stack	*find_cheapest_node(t_stack *b)
{
	int		min;
	t_stack	*best_node;

	best_node = NULL;
	min = INT_MAX;
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->price < min)
		{
			min = b->price;
			best_node = b;
		}
		b = b->next;
	}
	return (best_node);
}

static double	get_average(t_stack *a)
{
	long long	sum;
	int			i;

	sum = 0;
	i = size(a);
	while (a)
	{
		sum = sum + a->value;
		a = a->next;
	}
	return (sum / i);
}

void	push_below_average(t_stack **a, t_stack **b)//100 num: 698 steps
{
	int			average;

	average = get_average(*a);
	if ((*a)->value < average)
		pb(a, b);
	else
		ra(a);
}
