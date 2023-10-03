/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiruwang <xiruwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:36:43 by xiruwang          #+#    #+#             */
/*   Updated: 2023/10/02 08:26:03 by xiruwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac <= 2)
		return (1);
	printf("Before check_av\n");
	check_av(av);

	printf("Before fill_stack\n");
	a = NULL;
	b = NULL;
	a = fill_stack(ac, av);

    printf("Before:\n");
	print_stack(a);
	if (ac == 4)
		sort_three(&a);
	if (ac == 5)
		sort_four(&a, &b);
	if (ac == 6)
		sort_five(&a, &b);
	if (ac > 6)
		sort_big(&a, &b);
	printf("After\n");
	print_stack(a);

	printf("Before free_stack\n");
	free_stack(&a);

	printf("End of Program\n");
	return (0);
}

