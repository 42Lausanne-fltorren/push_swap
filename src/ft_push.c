/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:59:57 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/24 11:28:09 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *a, t_stack *b, int repeat)
{
	int	tmp;
	int	i;

	i = repeat;
	while (i-- > 0)
	{
		tmp = b->arr[0];
		shift(b);
		unshift(a, tmp);
		if (PRINT)
			write(1, "pa\n", 3);
	}
	return (repeat);
}

int	pb(t_stack *a, t_stack *b, int repeat)
{
	int	tmp;
	int	i;

	i = repeat;
	while (i-- > 0)
	{
		tmp = a->arr[0];
		shift(a);
		unshift(b, tmp);
		if (PRINT)
			write(1, "pb\n", 3);
	}
	return (repeat);
}

int	sa(t_stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	if (PRINT)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *b)
{
	int	tmp;

	tmp = b->arr[0];
	b->arr[0] = b->arr[1];
	b->arr[1] = tmp;
	if (PRINT)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	if (PRINT)
		write(1, "ss\n", 3);
	return (1);
}
