/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:36:50 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 10:59:10 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same_sign(int a, int b)
{
	if (a * b < 0)
		return (0);
	return (1);	
}

int minimum(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}


int ft_abs(int a)
{
	if (a == INT_MIN)
		return (INT_MAX);
	if (a < 0)
		return (-a);
	return (a);
}

int zero_dist_max(int a, int b)
{
	if (same_sign(a, b))
	{
		if (a < 0)
			return (ft_abs(minimum(a, b)));
		return (ft_abs(maximum(a, b)));
	}
	return (ft_abs(a) + ft_abs(b));
	
}