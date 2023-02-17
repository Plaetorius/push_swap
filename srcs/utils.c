/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:36:50 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/17 11:39:01 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_negative(int a, int b)
{
	if (a * b < 0)
		return (1);
	return (0);	
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
