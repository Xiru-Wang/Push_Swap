/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:01:03 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/10 19:32:10 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	set_flag(t_stack *stack)
{
	int	i;
	int	middle;
	i = 0;
	middle = size(stack) / 2;
	while (stack)
	{
		stack->flag = TOP;//top half
		if (i > middle)
			stack->flag = BOTTOM;//bottom half
		i++;
		stack = stack->next;
	}
}

// void	free_strs(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

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
		printf("value: %d, cost: %d\n", stack->value, stack->cost);
		stack = stack->next;
	}
}
