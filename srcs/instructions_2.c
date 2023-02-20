/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:30:13 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 16:44:24 by tgernez          ###   ########.fr       */
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
		return (new_instruct(ROTATE_A, vars));
	else
		return (new_instruct(ROTATE_B, vars));
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
		return (new_instruct(REV_ROTATE_A, vars));
	else
		return (new_instruct(REV_ROTATE_B, vars));
}

int	push_bottom(t_stack *receiver, t_stack *sender, t_push_swap *vars)
{
	if (push(receiver, sender, vars) == 1)
		return (1);
	if (rotate(receiver, vars) == 1)
		return (1);
	return (0);
}

int	splits_number(size_t len, t_push_swap *vars)
{
	if (!vars)
		return (1);
	if (len < 101)
		vars->splits = 3;
	else if (len < 301)
		vars->splits = 3;
	else if (len < 501)
		vars->splits = 3;
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
