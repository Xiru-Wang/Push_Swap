/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:52:48 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/05 21:16:46 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

// static int	last(t_stack *head)
// {
// 	int	value;

// 	while (head->next != NULL)
// 	{
// 		head = head->next;//last node
// 		value = head->value;//last.value
// 	}
// 	return (value);
// }

/*Forget it, terrible performance with more than 100 numbers
same logic like sort_three in tiny:
Principle: MAX to bottom
first is max:  3 2 1/3 1 2 ra -> 2 1 3/1 2 3
second is max: 1 3 2/2 3 1 rra-> 2 1 3/1 2 3
last is max:         2 1 3 sa -> 1 2 3
*/
// static void	sort_three_low_high(t_stack **a)
// {
// 	int	bottom;

// 	bottom = last(*a);
// 	if ((*a)->value > (*a)->next->value && (*a)->value > bottom)
// 		ra(a);//first is max, roate to bottom
// 	else if ((*a)->next->value > (*a)->value && (*a)->next->value > bottom)
// 		rra(a);//if middle is max, rra so max goes to third position
// 	if ((*a)->value > (*a)->next->value)
// 		sa(a);//if 1st > 2rd
// }

// static void	sort_three_high_low(t_stack **b)
// {
// 	int	bottom;

// 	bottom = last(*b);
// 	if ((*b)->value < (*b)->next->value && (*b)->value < bottom)
// 		rb(b);//if first is min, roate to bottom
// 	else if ((*b)->next->value > (*b)->value && (*b)->next->value > bottom)
// 		rrb(b);//if second is min, rrb goes to third position
// 	if ((*b)->value < (*b)->next->value)
// 		sb(b);//if 1st > 2rd
// }

// static double	get_average(t_stack *a)
// {
// 	long long	sum;
// 	int			i;

// 	sum = 0;
// 	i = size(a);
// 	while (a)
// 	{
// 		sum = sum + a->value;
// 		a = a->next;
// 	}
// 	return (sum / i);
// }

// void	push_below_average(t_stack **a, t_stack **b)//100 num: 698 steps
// {
// 	int			average;

// 	average = get_average(*a);
// 	if ((*a)->value < average)
// 		pb(a, b);
// 	else
// 		ra(a);
// }
