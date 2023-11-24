/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:43:30 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/24 11:41:06 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

static void	shuffle(int *arr, size_t n)
{
	size_t	i;
	size_t	j;
	int		t;

	if (n > 1)
	{
		srand(time(NULL));
		i = 0;
		while (i < n - 1)
		{
			j = i + rand() / (RAND_MAX / (n - i) + 1);
			t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
			i++;
		}
	}
}

static int	*random_array(size_t len)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = i;
		i++;
	}
	shuffle(arr, len);
	return (arr);
}

static float	ft_avg(int *arr, size_t arr_len)
{
	int		i;
	float	sum;

	i = 0;
	sum = 0;
	while (i < arr_len)
	{
		sum += arr[i];
		i++;
	}
	return (sum / arr_len);
}

void	*test_n(t_stack moves, int n)
{
	int	i;
	int	*a;
	int	*b;

	i = 0;
	while (i < moves.len)
	{
		a = random_array(n);
		b = (int *)malloc(sizeof(int) * 0);
		moves.arr[i] = solve(a, n, b, 0);
		if (i % (moves.len / 50) == 0)
			printf("%d: %ld%%\n", n, i / (moves.len / 100));
		i++;
	}
}

int	main(void)
{
	t_stack	moves_100;
	t_stack	moves_500;

	moves_100.len = 1000;
	moves_500.len = 0;
	moves_100.arr = (int *)malloc(sizeof(int) * moves_100.len);
	moves_500.arr = (int *)malloc(sizeof(int) * moves_500.len);
	test_n(moves_100, 100);
	printf("Average moves for 100: %f\n", ft_avg(moves_100.arr, moves_100.len));
	printf("Min: %d\n", ft_min_stack(moves_100));
	printf("Max: %d\n", ft_max_stack(moves_100));
	test_n(moves_500, 500);
	printf("Average moves for 500: %f\n", ft_avg(moves_500.arr, moves_500.len));
	printf("Min: %d\n", ft_min_stack(moves_500));
	printf("Max: %d\n", ft_max_stack(moves_500));
	free(moves_100.arr);
	free(moves_500.arr);
	return (0);
}
