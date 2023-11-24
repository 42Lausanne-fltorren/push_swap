/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:31:24 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/22 01:00:25 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;

	if (argc < 2)
		return (0);
	a = (int *)malloc(sizeof(int) * (argc - 1));
	b = (int *)malloc(sizeof(int) * 0);
	if (!a || !b)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	solve(a, argc - 1, b, 0);
	return (0);
}
