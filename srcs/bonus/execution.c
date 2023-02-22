/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:32 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 11:59:24 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	ss(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	if (check_swap(stack_a, vars) == 1)
		return (1);
	if (check_swap(stack_b, vars) == 1)
		return (1);
	return (0);
}

static int	rr(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	if (check_rotate(stack_a, vars) == 1)
		return (1);
	if (check_rotate(stack_b, vars) == 1)
		return (1);
	return (0);
}

static int	rrr(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	if (check_rev_rotate(stack_a, vars) == 1)
		return (1);
	if (check_rev_rotate(stack_b, vars) == 1)
		return (1);
	return (0);
}

static int	aux_execute_instructs(t_instruct *instruct, int val,
	t_push_swap *vars)
{
	if (instruct->val == ROTATE_A)
		val = check_rotate(vars->stack_a, vars);
	else if (instruct->val == ROTATE_B)
		val = check_rotate(vars->stack_b, vars);
	else if (instruct->val == REV_ROTATE_A)
		val = check_rev_rotate(vars->stack_a, vars);
	else if (instruct->val == REV_ROTATE_B)
		val = check_rev_rotate(vars->stack_b, vars);
	else if (instruct->val == SWAP_A)
		val = check_swap(vars->stack_a, vars);
	else if (instruct->val == SWAP_B)
		val = check_swap(vars->stack_b, vars);
	else if (instruct->val == PUSH_A)
		val = check_push(vars->stack_a, vars->stack_b, vars);
	else if (instruct->val == PUSH_B)
		val = check_push(vars->stack_b, vars->stack_a, vars);
	else if (instruct->val == RR)
		val = rr(vars->stack_a, vars->stack_b, vars);
	else if (instruct->val == RRR)
		val = rrr(vars->stack_a, vars->stack_b, vars);
	else if (instruct->val == SS)
		val = ss(vars->stack_a, vars->stack_b, vars);
	if (val == 1)
		return (1);
	return (0);
}

int	execute_instructs(t_push_swap *vars)
{
	t_instruct	*instruct;

	instruct = vars->insts;
	while (instruct)
	{
		if (aux_execute_instructs(instruct, 0, vars))
			return (1);
		instruct = instruct->next;
	}
	return (0);
}
