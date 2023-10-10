/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiwang <xiwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:05:33 by xiwang            #+#    #+#             */
/*   Updated: 2023/10/10 19:06:02 by xiwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//atoi will handle range, exit if number out of int range
long int	atoi_range(char *s)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s < '0' || *s > '9')// if av[1]=="+",check if next *s is number
		handle_err();
	while(*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	if (*s && (*s < '0' || *s > '9'))
		handle_err();
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		handle_err();
	return (res * sign);
}
//WRONG：if (res > INT_MAX || res * sign < INT_MIN)
//2147483648 > INT_MAX will not return -2147483648

//check dup
void	check_av(char **av)
{
	int	i;
	int	k;
	int	value_i;
	int	value_k;

	i = 1;
	if (!av[1])
		handle_err();
	while (av[i])
	{
		value_i = atoi_range(av[i]);
		k = i + 1;
		while(av[k])
		{
			value_k = atoi_range(av[k]);
			if (value_i == value_k)
				handle_err();
			k++;
		}
		i++;
	}
}
