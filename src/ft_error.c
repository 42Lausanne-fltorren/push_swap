/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:35:14 by fltorren          #+#    #+#             */
/*   Updated: 2024/02/24 11:48:29 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	ft_error_free(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	if (a && a->arr)
		free(a->arr);
	if (b && b->arr)
		free(b->arr);
	return (-1);
}

int	ft_duplicates(t_stack *a)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < a->len)
	{
		j = i;
		while (++j < a->len)
		{
			if (a->arr[i] == a->arr[j])
			{
				ft_error_free(a, NULL);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_check_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || ft_strlen(str) > 11 || (ft_atoi(str) < 0
				&& str[0] != '-') || (ft_atoi(str) > 0 && str[0] == '-'))
		{
			ft_error();
			return (1);
		}
		i++;
	}
	return (0);
}
