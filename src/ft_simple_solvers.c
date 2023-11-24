/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_solvers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:52:15 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/22 18:03:32 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_target(int n, t_stack stack)
{
	int	target;
	int	i;

	target = ft_min_stack(stack);
	if (n > ft_min_stack(stack) && n < ft_max_stack(stack))
	{
		target = ft_max_stack(stack);
		i = -1;
		while (++i < stack.len)
		{
			if (stack.arr[i] > n && stack.arr[i] < target)
				target = stack.arr[i];
		}
	}
	return (target);
}

int	solve_for_5(t_stack *a, t_stack *b)
{
	int	i;
	int	count;
	int	rot;
	int	rev_rot;

	count = pb(a, b, 2) + solve_for_3(a);
	i = -1;
	while (++i < 2)
	{
		rot = 0;
		while (a->arr[rot] != ft_target(b->arr[0], *a))
			rot++;
		rev_rot = 0;
		while (a->arr[((int)a->len - rev_rot) % a->len] != ft_target(b->arr[0],
				*a))
			rev_rot++;
		if (rot < rev_rot)
			count += ra(a, rot, 1);
		else
			count += rra(a, rev_rot, 1);
		count += pa(a, b, 1);
	}
	count += ft_final_rotate(a);
	return (count);
}

int	solve_for_3(t_stack *a)
{
	int	*c;

	c = a->arr;
	if (c[0] > c[1] && c[1] < c[2] && c[0] < c[2])
		sa(a);
	else if (c[0] < c[1] && c[2] < c[1] && c[0] > c[2])
		rra(a, 1, 1);
	else if (c[0] < c[1] && c[1] > c[2])
	{
		rra(a, 1, 1);
		sa(a);
		return (2);
	}
	else if (c[0] > c[1] && c[0] > c[2] && c[1] < c[2])
		ra(a, 1, 1);
	else if (c[0] > c[1] && c[1] > c[2])
	{
		sa(a);
		rra(a, 1, 1);
		return (2);
	}
	else
		return (0);
	return (1);
}
