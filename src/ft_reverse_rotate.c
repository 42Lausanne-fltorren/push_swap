/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:58:52 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/24 11:28:44 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *a, int repeat, int print)
{
	int	tmp;
	int	i;

	i = repeat;
	while (i-- > 0)
	{
		tmp = a->arr[a->len - 1];
		pop(a);
		unshift(a, tmp);
		if (print && PRINT)
			write(1, "rra\n", 4);
	}
	return (repeat);
}

int	rrb(t_stack *b, int repeat, int print)
{
	int	tmp;
	int	i;

	i = repeat;
	while (i-- > 0)
	{
		tmp = b->arr[b->len - 1];
		pop(b);
		unshift(b, tmp);
		if (print && PRINT)
			write(1, "rrb\n", 4);
	}
	return (repeat);
}

int	rrr(t_stack *a, t_stack *b, int repeat)
{
	int	i;

	rra(a, repeat, 0);
	rrb(b, repeat, 0);
	i = repeat;
	if (PRINT)
	{
		while (i-- > 0)
			write(1, "rrr\n", 4);
	}
	return (repeat);
}
