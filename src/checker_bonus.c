/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:47:00 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/27 16:39:19 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_init_stack(t_stack *stack, int len, char **argv)
{
	size_t	i;

	stack->len = len;
	stack->arr = (int *)malloc(sizeof(int) * (stack->len));
	if (!stack->arr)
		return (0);
	i = -1;
	while (++i < stack->len)
		stack->arr[i] = ft_atoi(argv[i]);
	return (1);
}

static int	ft_operation(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(op, "sa", 2))
		return (sa(a));
	else if (!ft_strncmp(op, "sb", 2))
		return (sb(b));
	else if (!ft_strncmp(op, "ss", 2))
		return (ss(a, b));
	else if (!ft_strncmp(op, "pa", 2))
		return (pa(a, b, 1));
	else if (!ft_strncmp(op, "pb", 2))
		return (pb(a, b, 1));
	else if (!ft_strncmp(op, "ra", 2))
		return (ra(a, 1, 0));
	else if (!ft_strncmp(op, "rb", 2))
		return (rb(b, 1, 0));
	else if (!ft_strncmp(op, "rr", 2))
		return (rr(a, b, 1));
	else if (!ft_strncmp(op, "rra", 3))
		return (rra(a, 1, 0));
	else if (!ft_strncmp(op, "rrb", 3))
		return (rrb(b, 1, 0));
	else if (!ft_strncmp(op, "rrr", 3))
		return (rrr(a, b, 1));
	else
		return (0);
}

static int	ft_checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strlen(line) == 1 || !ft_operation(line, a, b))
		{
			ft_error_free(a, b);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static int	ft_is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (!ft_init_stack(&a, argc - 1, argv + 1))
	{
		ft_error();
		return (0);
	}
	if (ft_duplicates(&a))
		return (0);
	if (!ft_init_stack(&b, 0, NULL))
	{
		ft_error_free(&a, &b);
		return (0);
	}
	if (!ft_checker(&a, &b))
		return (0);
	if (ft_is_sorted(&a) && !b.len)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(a.arr);
	free(b.arr);
	return (0);
}
