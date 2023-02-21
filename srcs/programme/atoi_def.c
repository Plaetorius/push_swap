/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:04:17 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 15:41:49 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	aux_atoi_def(const char *str, long *nb, int is_neg, int i)
{
	while ('0' <= str[i] && str[i] <= '9')
	{
		*nb = *nb * 10 + str[i] - '0';
		if (((*nb > INT_MAX && !is_neg) || INT_MIN > -(*nb)))
			return (1);
		i++;
	}
	return (0);
}

long	atoi_def(const char *str, int *val)
{
	long	nb;
	int		i;
	int		is_neg;

	nb = 0;
	i = 0;
	is_neg = 0;
	while (str[i] == ' ' || (8 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		is_neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (aux_atoi_def(str, &nb, is_neg, i))
		return (1);
	if (is_neg)
		*val = -nb;
	else
		*val = nb;
	return (0);
}
