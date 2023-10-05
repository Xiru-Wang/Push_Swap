/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:12:42 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/04 11:24:44 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1st node -> last node
// before: head->1->2->3->NULL
// after : head->2->3->1->NULL

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;//save node1
	*head = (*head)->next;//head now point to node2
	last = *head;
	while (last->next != NULL)
		last = last->next;//found last node
	last->next = first;//last node -> node1
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_stack *top)
{
	while ((*a) != top->target && (*b) != top)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}
