/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:02:22 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/12 16:04:17 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	phase_1(void)
{
	return (0);
}

int phase_2(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int	sort_nb;

	sort_nb = 1;
	while (stack_a->len > 3)
	{
		push_elements_in_b(stack_a, stack_b, sort_nb, vars);
		// actualize_ind(stack_a, vars);
		sort_nb++;
	}
	return (0);
}