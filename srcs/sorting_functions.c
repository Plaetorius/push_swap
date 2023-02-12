/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:24:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/12 16:24:07 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_elements_in_b(t_stack *stack_a, t_stack *stack_b, int sort_nb,
	t_push_swap *vars)
{
	int 	i;
	int		val;
	int		len_a;

	len_a = stack_a->len;
	i = 0;
	while (i < len_a)
	{
		if (stack_a->head->ind < len_a / SPLITS)
			val = rotate(stack_a, vars);
		else if (stack_a->head->ind >= len_a / SPLITS
			&& stack_a->head->ind < (len_a / SPLITS) * 2)
			val = push(stack_b, stack_a, vars);
		else
			val = push_bottom(stack_b, stack_a, vars);
		if (val == 1)
			return (1);
		i++;
	}
	return (0);
}

// int	actualize_ind(t_stack *stack, t_push_swap *vars)
// {
	
// }