/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:05 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/10 19:29:43 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//cost to be on top 0 1 2 3 4 3 2 1   (8/2 == 4)
//cost to be on top 0 1 2 3 4 4 3 2 1 (9/2 == 4)
void	set_cost_to_top(t_stack *stack)
{
	int		cost;
	int	middle;
	int		count;

	cost = 0;
	count = 0;
	int size_list = size(stack);
	middle = size_list / 2;
	while (stack)
	{
		stack->cost = cost;
		if (count < middle)
			cost++;
		else if (count == middle && size_list % 2)
			count++;
		else
			cost--;
		count++;
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

static int	get_average(t_stack *a)
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
	int	average;

	average = get_average(*a);
	if ((*a)->value < average)
		pb(a, b);
	else
		ra(a);
}
