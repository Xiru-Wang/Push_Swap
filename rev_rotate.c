/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:11:53 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/02 14:22:30 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
https://www.youtube.com/watch?v=TpgxJupHATQ
last node -> 1st node
before: head->1->2->3->NULL
after : head->3->1->2->NULL
*/

static void	reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next != NULL)
	{
		second_last = last;//update the node before last node
		last = last->next;//then move the the last node
	}
	last->next = *head;
	*head = last;
	second_last->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
