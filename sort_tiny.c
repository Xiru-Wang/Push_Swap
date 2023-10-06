/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:13:51 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/06 12:35:06 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_node(t_stack *a)
{
	int		max;
	t_stack	*temp;

	max = INT_MIN;
	while (a)
	{
		if (a->value > max)
		{
			max = a->value;
			temp = a;
		}
		a = a->next;
	}
	return (temp);
}

t_stack	*find_min_node(t_stack *a)
{
	int		min;
	t_stack	*temp;

	min = INT_MAX;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			temp = a;
		}
		a = a->next;
	}
	return (temp);
}

void	sort_three(t_stack **a)
{
	t_stack	*temp;

	temp = find_max_node(*a);
	if (*a == temp)
		ra(a);//if first is max, roate to bottom
	else if ((*a)->next == temp)
		rra(a);//if middle is max, rra so max goes to bottom
	if ((*a)->value > (*a)->next->value)
		sa(a);//if 1st > 2rd
}

// push smallest to b
void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = find_min_node(*a);
	if ((*a)->next == temp)
		sa(a);
	while (*a != temp)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = find_min_node(*a);
	if ((*a)->next == temp)
		sa(a);
	while (*a != temp)
		rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
