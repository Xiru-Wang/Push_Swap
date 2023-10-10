/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:42:55 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/10 19:09:08 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
while (stack)
until stack == NULL, loop stops AFTER last node,
*/

/*
while (stack->next != NULL)
until stack->next == NULL, loop stops at last node
*/

int	size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	node_add_back(t_stack **a, t_stack	*new)
{
	t_stack	*temp;

	if (a == NULL || new == NULL)//pointer to point is empty || pointer to new node is empty
		return ;
	if (*a == NULL)//head pointer == NULL:empty list
	{
		*a = new;//new becomes 1st node
		return ;
	}
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
