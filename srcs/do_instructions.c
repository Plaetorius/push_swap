/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:31:13 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/12 19:33:35 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_rotate(t_stack *stack, int times, t_push_swap *vars)
{
	int	i;

	i = 0;
	while (i < times)
	{
		if (rotate(stack, vars))
			return (1);
		i++;
	}
	return (0);
}

int	do_rev_rotate(t_stack *stack, int times, t_push_swap *vars)
{
	int	i;

	i = 0;
	while (i < times)
	{
		if (rev_rotate(stack, vars))
			return (1);
		i++;
	}
	return (0);
}