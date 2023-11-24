/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:41:27 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/22 18:05:05 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve(int *a_arr, size_t a_len, int *b_arr, size_t b_len)
{
	t_stack	a;
	t_stack	b;
	int		count;

	a.arr = a_arr;
	a.len = a_len;
	b.arr = b_arr;
	b.len = b_len;
	count = 0;
	if (a_len == 3)
		count = solve_for_3(&a);
	else if (a_len == 5)
		count = solve_for_5(&a, &b);
	else
		count = solve_for_lots(&a, &b);
	free(a.arr);
	free(b.arr);
	return (count);
}

int	ft_final_rotate(t_stack *a)
{
	int	rot;
	int	rev_rot;
	int	count;

	count = 0;
	rot = 0;
	while (a->arr[rot] != ft_min_stack(*a))
		rot++;
	rev_rot = 0;
	while (a->arr[((int)a->len - rev_rot) % a->len] != ft_min_stack(*a))
		rev_rot++;
	if (rot < rev_rot)
		count += ra(a, rot, 1);
	else
		count += rra(a, rev_rot, 1);
	return (count);
}
