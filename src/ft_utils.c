/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:47:17 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/22 00:59:54 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_stack(t_stack stack)
{
	int		min;
	size_t	i;

	i = 0;
	min = stack.arr[0];
	while (i < stack.len)
	{
		if (stack.arr[i] < min)
			min = stack.arr[i];
		i++;
	}
	return (min);
}

int	ft_max_stack(t_stack stack)
{
	int		max;
	size_t	i;

	i = 0;
	max = stack.arr[0];
	while (i < stack.len)
	{
		if (stack.arr[i] > max)
			max = stack.arr[i];
		i++;
	}
	return (max);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_min(int count, ...)
{
	va_list	args;
	int		min;
	int		tmp;

	va_start(args, count);
	min = va_arg(args, int);
	while (count-- > 1)
	{
		tmp = va_arg(args, int);
		if (tmp < min)
			min = tmp;
	}
	va_end(args);
	return (min);
}

int	ft_max(int count, ...)
{
	va_list	args;
	int		max;
	int		tmp;

	va_start(args, count);
	max = va_arg(args, int);
	while (count-- > 1)
	{
		tmp = va_arg(args, int);
		if (tmp > max)
			max = tmp;
	}
	va_end(args);
	return (max);
}
