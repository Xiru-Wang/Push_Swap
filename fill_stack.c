/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:47:32 by xiruwang          #+#    #+#             */
/*   Updated: 2023/09/29 11:49:24 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack *fill_stack_value(int ac, char **av);

t_stack *fill_stack(int ac, char **av)
{
	t_stack	*a;

	a = fill_stack_value(ac, av);
	if (is_sorted(a) == 1)
	{
		free_stack(&a);
		exit(1);//display nothing
	}
	return (a);
}

static t_stack	*fill_stack_value(int ac, char **av)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;
	int		value;

	i = 1;
	value = 0;
	a = NULL;
	while(av[i])
	{
		value = atoi_range(av[i]);
		temp = new_node(value);
		node_add_back(&a, temp);
		i++;
	}
	return (a);
}

// static void	fill_stack_pos(t_stack **a)
// {
// 	t_stack *temp;
// 	int i;

// 	temp = *a;
// 	i = 0;
// 	while (temp)
// 	{
// 		temp->pos = i;
// 		temp = temp->next;
// 		i++;
// 	}
// }

//check if stack is sorted.
int	is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);//false
		a = a->next;
	}
	return (1);//true
}
