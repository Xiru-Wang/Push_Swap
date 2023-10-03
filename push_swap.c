/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:26:55 by xiwang            #+#    #+#             */
/*   Updated: 2023/10/03 19:18:59 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//after push 1 node to A, refresh target node, cost, price, best_price
static void	rotate_to_top(t_stack **stack, t_stack *top, char name);
static void	push_swap(t_stack **a, t_stack **b);

static void	refresh_stacks(t_stack **a, t_stack **b)
{
	set_target(*a, *b);
	set_flag(*a);
	set_flag(*b);
	calculate_price(*a, *b);//refresh cost, and calculate price
	find_best_price(*b);
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*min;

	push_below_average(a, b);
	sort_five(a, b);
	while (*b)
	{
		refresh_stacks(a, b);
		push_swap(a, b);
	}
	//Last step: put smallest to top
	min = find_min_node(*a);
	set_flag(*a);
	while ((*a) != min)
	{
		if (min->flag)//first half
			ra(a);
		else
			rra(a);//second half
	}
}

static void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*best_node;

	best_node = find_best_price(*b);

	if (best_node->flag && best_node->target->flag)
		rr(a, b, best_node);
	else if (!best_node->flag && !best_node->target->flag)
			rrr(a, b, best_node);
	set_flag(*a);//after rr/rrr, flag will change
	set_flag(*b);
	rotate_to_top(a, best_node->target, 'a');
	rotate_to_top(b, best_node, 'b');
	pa(a, b);
}

static void	rotate_to_top(t_stack **stack, t_stack *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->flag)//ture, top half
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->flag)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
