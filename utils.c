/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:01:03 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/02 14:39:08 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_strs(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **head)
{
	t_stack *temp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		temp = (*head)->next;//holde next node
		free(*head);//free current node
		*head = temp; //next node becomes current node
	}
	*head = NULL;//avoid dangling pointer
}

void	print_stack(t_stack *stack)
{
	if (stack == NULL)
	{
		printf("empty stack\n");
		return ;
	}
	while (stack)
	{
		printf("value: %d\n", stack->value);
		stack = stack->next;
	}
}
