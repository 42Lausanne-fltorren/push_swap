/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:29:28 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/26 13:54:05 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# ifndef PRINT
#  define PRINT 1
# endif

typedef struct s_moves
{
	int	rb;
	int	ra;
	int	rr;
	int	rrb;
	int	rra;
	int	rrr;
	int	sum;
}			t_moves;

typedef struct s_stack
{
	int		*arr;
	size_t	len;
}		t_stack;

typedef struct s_rot
{
	int	rot_a;
	int	rot_b;
	int	rev_rot_a;
	int	rev_rot_b;
}		t_rot;

void	shift(t_stack *arr);
void	push(t_stack *arr, int num);
void	pop(t_stack *arr);
void	unshift(t_stack *arr, int num);

int		ra(t_stack *a, int repeat, int print);
int		rb(t_stack *b, int repeat, int print);
int		rr(t_stack *a, t_stack *b, int repeat);

int		rra(t_stack *a, int repeat, int print);
int		rrb(t_stack *b, int repeat, int print);
int		rrr(t_stack *a, t_stack *b, int repeat);

int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);

int		pa(t_stack *a, t_stack *b, int repeat);
int		pb(t_stack *a, t_stack *b, int repeat);

int		solve(int *a_arr, size_t a_len, int *b_arr, size_t b_len);
int		ft_final_rotate(t_stack *a);
int		solve_for_5(t_stack *a, t_stack *b);
int		solve_for_3(t_stack *a);
int		solve_for_lots(t_stack *a, t_stack *b);

int		ft_max_stack(t_stack arr);
int		ft_min_stack(t_stack arr);
int		ft_abs(int n);
int		ft_min(int count, ...);
int		ft_max(int count, ...);

void	ft_error_free(t_stack *a, t_stack *b);
int		ft_duplicates(t_stack *a);
int		ft_check_int(char *str);
void	ft_error(void);
#endif
