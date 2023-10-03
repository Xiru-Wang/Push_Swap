/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:52:48 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/03 19:04:34 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	last(t_stack *head)
{
	int	value;

	while (head->next != NULL)
	{
		head = head->next;//last node
		value = head->value;//last.value
	}
	return (value);
}

/*
same logic like sort_three in tiny:
Principle: MAX to bottom
first is max:  3 2 1/3 1 2 ra -> 2 1 3/1 2 3
second is max: 1 3 2/2 3 1 rra-> 2 1 3/1 2 3
last is max:         2 1 3 sa -> 1 2 3
*/
static void	sort_three_low_high(t_stack **a)
{
	int	bottom;

	bottom = last(*a);
	if ((*a)->value > (*a)->next->value && (*a)->value > bottom)
		ra(a);//first is max, roate to bottom
	else if ((*a)->next->value > (*a)->value && (*a)->next->value > bottom)
		rra(a);//if middle is max, rra so max goes to third position
	if ((*a)->value > (*a)->next->value)
		sa(a);//if 1st > 2rd
}

static void	sort_three_high_low(t_stack **b)
{
	int	bottom;

	bottom = last(*b);
	if ((*b)->value < (*b)->next->value && (*b)->value < bottom)
		rb(b);//if first is min, roate to bottom
	else if ((*b)->next->value > (*b)->value && (*b)->next->value > bottom)
		rrb(b);//if second is min, rrb goes to third position
	if ((*b)->value < (*b)->next->value)
		sb(b);//if 1st > 2rd
}

//before push, simply sort the first, second and the last in stackA && stackB

static double	sum_stack(t_stack *a, int *i)
{
	long long	sum;
	//int			average;

	sum = 0;
	while (a)
	{
		sum = sum + a->value;
		a = a->next;
		(*i)++;//NOT i++！！pointer++
	}
	return (sum);
}

void	push_below_average(t_stack **a, t_stack **b)
{
	long long	sum;
	int			i;
	int			average;

	i = 0;
	sum = sum_stack(*a, &i);
	average = sum / i;
	while (size(*a) > 5)
	{
		sort_three_low_high(a);
		if (size(*b) >= 3)
			sort_three_high_low(b);
		if ((*a)->value < average)
		{
			pb(a, b);
			sum = sum - (*a)->value;
			i--;
			average = sum / i;
		}
		else
			ra(a);
	}
}

// void	push_below_average(t_stack **a, t_stack **b)
// {
// 	double	average;

// 	average = get_average(*a);
// 	while (size(*a) > 5)
// 	{
// 		sort_three_low_high(a);
// 		if (size(*b) >= 3)
// 			sort_three_high_low(b);
// 		if ((*a)->value < average)
// 		{
// 			pb(a, b);
// 			average = get_average(*a);
			//recalculate sum everytime, low performance
// 		}
// 		else
// 			ra(a);
// 	}
// }
