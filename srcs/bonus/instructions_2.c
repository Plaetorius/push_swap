/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:30:13 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 11:35:11 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	First element becomes last
*/
int	check_rotate(t_stack *stack, t_push_swap *vars)
{
	if (!stack || !(stack->head) || !vars)
		return (1);
	if (stack->len == 1)
		return (0);
	stack->head = stack->head->next;
	return (0);
}

/*
	Last element becomes first
*/
int	check_rev_rotate(t_stack *stack, t_push_swap *vars)
{
	if (!stack || !(stack->head) || !vars)
		return (1);
	if (stack->len == 1)
		return (0);
	stack->head = stack->head->prev;
	return (0);
}

void	stack_association(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	if (!vars)
		return ;
	if (stack_a)
		vars->stack_a = stack_a;
	if (stack_b)
		vars->stack_b = stack_b;
}
