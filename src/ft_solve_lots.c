/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_lots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:58:51 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/22 18:04:46 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_target(int n, t_stack stack)
{
	int	target;
	int	i;

	target = ft_max_stack(stack);
	if (n > ft_min_stack(stack) && n < ft_max_stack(stack))
	{
		target = ft_min_stack(stack);
		i = -1;
		while (++i < stack.len)
		{
			if (stack.arr[i] < n && stack.arr[i] > target)
				target = stack.arr[i];
		}
	}
	return (target);
}

static t_moves	ft_min_moves(t_rot rot)
{
	int	res;
	int	min;

	res = ft_min(4, (rot.rot_a + rot.rev_rot_b), (rot.rot_b + rot.rev_rot_a),
			ft_max(2, rot.rot_a, rot.rot_b),
			ft_max(2, rot.rev_rot_a, rot.rev_rot_b));
	if (res == rot.rot_b + rot.rev_rot_a)
		return ((t_moves){rot.rot_b, 0, 0, 0, rot.rev_rot_a, 0, rot.rot_b});
	else if (res == rot.rot_a + rot.rev_rot_b)
		return ((t_moves){0, rot.rot_a, 0, rot.rev_rot_b, 0, 0});
	else if (res == ft_max(2, rot.rot_b, rot.rot_a))
	{
		min = ft_min(2, rot.rot_b, rot.rot_a);
		if (rot.rot_b < rot.rot_a)
			return ((t_moves){0, rot.rot_a - min, min, 0, 0, 0});
		else
			return ((t_moves){rot.rot_b - min, 0, min, 0, 0, 0});
	}
	min = ft_min(2, rot.rev_rot_b, rot.rev_rot_a);
	if (rot.rev_rot_b < rot.rev_rot_a)
		return ((t_moves){0, 0, 0, 0, rot.rev_rot_a - min, min});
	else
		return ((t_moves){0, 0, 0, rot.rev_rot_b - min, 0, min});
}

static t_moves	ft_count_moves(int n, t_stack a, t_stack b)
{
	int		target;
	t_rot	rot;

	rot = (t_rot){0, 0, 0, 0};
	target = ft_target(n, b);
	while (b.arr[rot.rot_b] != target)
		rot.rot_b++;
	while (b.arr[ft_abs(((int)b.len - rot.rev_rot_b) % b.len)] != target)
		rot.rev_rot_b++;
	while (a.arr[rot.rot_a] != n)
		rot.rot_a++;
	while (a.arr[ft_abs(((int)a.len - rot.rev_rot_a) % a.len)] != n)
		rot.rev_rot_a++;
	return (ft_min_moves(rot));
}

static int	ft_move_stacks(t_stack *a, t_stack *b, t_moves moves)
{
	int	count;

	count = 0;
	count += rr(a, b, moves.rr);
	count += rrr(a, b, moves.rrr);
	count += ra(a, moves.ra, 1);
	count += rb(b, moves.rb, 1);
	count += rra(a, moves.rra, 1);
	count += rrb(b, moves.rrb, 1);
	return (count);
}

int	solve_for_lots(t_stack *a, t_stack *b)
{
	int		i;
	int		count;
	t_moves	min_moves;
	t_moves	tmp;

	count = pb(a, b, 2);
	while (a->len > 0)
	{
		min_moves = (t_moves){0, 0, 0, 0, 0, 0, 2147483647};
		i = -1;
		while (++i < a->len)
		{
			tmp = ft_count_moves(a->arr[i], *a, *b);
			tmp.sum = tmp.ra + tmp.rb + tmp.rr + tmp.rra + tmp.rrb + tmp.rrr;
			if (tmp.sum < min_moves.sum)
				min_moves = tmp;
		}
		count += ft_move_stacks(a, b, min_moves) + 1;
		pb(a, b, 1);
	}
	count += pa(a, b, b->len) + ft_final_rotate(a);
	return (count);
}
