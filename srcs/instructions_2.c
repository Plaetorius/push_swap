/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:30:13 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/13 10:09:21 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	First element becomes last
*/
int	rotate(t_stack *stack, t_push_swap *vars)
{
	if (!stack || !(stack->head) || !vars)
		return (1);
	if (stack->len == 1)
		return (0);
	stack->head = stack->head->next;
	if (vars->stack_a == stack)
		vars->insts = new_instruct(ROTATE_A, vars->insts);
	else
		vars->insts = new_instruct(ROTATE_B, vars->insts);
	return (vars->insts == NULL);
}

/*
	Last element becomes first
*/
int	rev_rotate(t_stack *stack, t_push_swap *vars)
{
	if (!stack || !(stack->head) || !vars)
		return (1);
	if (stack->len == 1)
		return (0);
	stack->head = stack->head->prev;
	if (vars->stack_a == stack)
		vars->insts = new_instruct(REV_ROTATE_A, vars->insts);
	else
		vars->insts = new_instruct(REV_ROTATE_B, vars->insts);
	return (vars->insts == NULL);
}

int	push_bottom(t_stack *receiver, t_stack *sender, t_push_swap *vars)
{
	if (push(receiver, sender, vars) == 1)
		return (1);
	if (rotate(receiver, vars) == 1)
		return (1);
	return (0);
}
