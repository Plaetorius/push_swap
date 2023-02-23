/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:31:13 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 15:44:02 by tgernez          ###   ########.fr       */
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

int	turn_correctly(t_stack *stack, t_push_swap *vars)
{
	int	to_top;

	to_top = shortest_to_top(stack, stack->len - 1);
	if (to_top < 0)
		return (do_rev_rotate(stack, ft_abs(to_top), vars));
	return (do_rotate(stack, to_top, vars));
}
