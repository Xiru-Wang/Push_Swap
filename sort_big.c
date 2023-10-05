/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:26:55 by xiwang            #+#    #+#             */
/*   Updated: 2023/10/05 21:17:02 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//after push 1 node to A, refresh target node, cost, price, best_price
static void	rotate_to_top(t_stack **stack, t_stack *top, char name);
static void	push_swap(t_stack **a, t_stack **b);

//只修改参数不会修改头节点
static void	refresh_stacks(t_stack *a, t_stack *b)
{
	set_target(a, b);
	set_flag(a);
	set_flag(b);
	calculate_price(a, b);//refresh cost, and calculate price
}

static void	rotate_to_top(t_stack **stack, t_stack *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->flag == TOP)//ture, top half
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->flag == TOP)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*best_node;

	best_node = find_cheapest_node(*b);
	if (best_node->flag == TOP && best_node->target->flag == TOP)
		rr(a, b, best_node);
	else if (best_node->flag == BOTTOM && best_node->target->flag == BOTTOM)
		rrr(a, b, best_node);
	set_flag(*a);
	set_flag(*b);
	rotate_to_top(a, best_node->target, 'a');
	rotate_to_top(b, best_node, 'b');
	pa(a, b);
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (size(*a) > 5)
		push_below_average(a, b);
	// printf("only 5 nodes left in a\n");
	sort_five(a, b);
	while (*b)
	{
		refresh_stacks(*a, *b);
		push_swap(a, b);
	}
	//Last step: put smallest to top
	set_flag(*a);
	min = find_min_node(*a);
	if (min->flag == TOP)
		while ((*a) != min)
			ra(a);
	else
		while ((*a) != min)
			rra(a);
}
