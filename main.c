/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:36:43 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/06 17:12:18 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://github.com/gemartin99/Push-Swap-Tester

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	check_av(av);
	//printf("after check_av\n");
	a = NULL;
	b = NULL;
	a = fill_stack(av);
	set_cost_to_top(a);
	print_stack(a);
	//printf("after fill_stack\n");
	if (ac <= 4)
		sort_three(&a);
	if (ac == 5)
		sort_four(&a, &b);
	if (ac == 6)
		sort_five(&a, &b);
	if (ac > 6)
		sort_big(&a, &b);
	print_stack(a);
	free_stack(&a);
	return (0);
}

