/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:41:25 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/21 15:31:29 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift(t_stack *stack)
{
	int		*tmp;
	size_t	i;

	i = 0;
	stack->len -= 1;
	tmp = (int *)malloc(sizeof(int) * (stack->len));
	if (!tmp)
		return ;
	while (i < stack->len)
	{
		tmp[i] = stack->arr[i + 1];
		i++;
	}
	free(stack->arr);
	stack->arr = tmp;
}

void	push(t_stack *stack, int num)
{
	int		*tmp;
	size_t	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack->len + 1));
	if (!tmp)
		return ;
	while (i < stack->len)
	{
		tmp[i] = stack->arr[i];
		i++;
	}
	tmp[i] = num;
	stack->len += 1;
	free(stack->arr);
	stack->arr = tmp;
}

void	unshift(t_stack *stack, int num)
{
	int		*tmp;
	size_t	i;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack->len + 1));
	if (!tmp)
		return ;
	tmp[0] = num;
	while (i < stack->len)
	{
		tmp[i + 1] = stack->arr[i];
		i++;
	}
	stack->len += 1;
	free(stack->arr);
	stack->arr = tmp;
}

void	pop(t_stack *stack)
{
	int		*tmp;
	size_t	i;

	i = 0;
	stack->len -= 1;
	tmp = (int *)malloc(sizeof(int) * (stack->len));
	if (!tmp)
		return ;
	while (i < stack->len)
	{
		tmp[i] = stack->arr[i];
		i++;
	}
	free(stack->arr);
	stack->arr = tmp;
}
