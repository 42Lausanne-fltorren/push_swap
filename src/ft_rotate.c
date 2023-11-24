/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:53:37 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/24 11:29:06 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *a, int repeat, int print)
{
	int	tmp;
	int	i;

	i = repeat;
	while (i-- > 0)
	{
		tmp = a->arr[0];
		shift(a);
		push(a, tmp);
		if (print && PRINT)
			write(1, "ra\n", 3);
	}
	return (repeat);
}

int	rb(t_stack *b, int repeat, int print)
{
	int	tmp;
	int	i;

	i = repeat;
	while (i-- > 0)
	{
		tmp = b->arr[0];
		shift(b);
		push(b, tmp);
		if (print && PRINT)
			write(1, "rb\n", 3);
	}
	return (repeat);
}

int	rr(t_stack *a, t_stack *b, int repeat)
{
	int	i;

	ra(a, repeat, 0);
	rb(b, repeat, 0);
	i = repeat;
	if (PRINT)
	{
		while (i-- > 0)
			write(1, "rr\n", 3);
	}
	return (repeat);
}
