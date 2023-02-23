/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:36:50 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 16:48:43 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	same_sign(int a, int b)
{
	return ((a < 0 && b < 0) || (a >= 0 && b >= 0));
}

int	minimum(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a == INT_MIN)
		return (INT_MAX);
	if (a < 0)
		return (-a);
	return (a);
}

int	zero_dist_max(int a, int b)
{
	if (same_sign(a, b))
	{
		if (a < 0)
			return (ft_abs(minimum(a, b)));
		return (ft_abs(maximum(a, b)));
	}
	return (ft_abs(a) + ft_abs(b));
}
