/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:31:24 by fltorren          #+#    #+#             */
/*   Updated: 2024/03/22 13:07:47 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_get_tmp(int *argc, char **argv)
{
	char	**tmp;

	if (ft_strchr(argv[1], ' '))
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (NULL);
		*argc = ft_arr_len(tmp) + 1;
	}
	else
	{
		tmp = argv + 1;
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		i;
	char	**tmp;

	if (argc < 2)
		return (0);
	tmp = ft_get_tmp(&argc, argv);
	if (!tmp)
		return (0);
	a = (int *)malloc(sizeof(int) * (argc - 1));
	b = (int *)malloc(sizeof(int) * 0);
	if (!a || !b)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_check_int(tmp[i]))
			return (ft_free(a, b));
		a[i] = ft_atoi(tmp[i]);
		i++;
	}
	solve(a, argc - 1, b, 0);
	return (0);
}
