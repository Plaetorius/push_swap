/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:44:21 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/13 10:01:27 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruct	*new_instruct(int val, t_instruct *next)
{
	t_instruct	*instruct;

	instruct = malloc(sizeof(t_instruct));
	if (!instruct)
		return (NULL);
	instruct->val = val;
	instruct->next = next;
	return (instruct);
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

void	instructions_shower(t_instruct *stack)
{
	while (stack)
	{
		if (stack->val == PUSH_A)
			ft_printf("pa\n");
		else if (stack->val == SWAP_A)
			ft_printf("sa\n");
		else if (stack->val == ROTATE_A)
			ft_printf("ra\n");
		else if (stack->val == REV_ROTATE_A)
			ft_printf("rra\n");
		else if (stack->val == SWAP_B)
			ft_printf("sb\n");
		else if (stack->val == PUSH_B)
			ft_printf("pb\n");
		else if (stack->val == ROTATE_B)
			ft_printf("rb\n");
		else if (stack->val == REV_ROTATE_B)
			ft_printf("rrb\n");
		else if (stack->val == RR)
			ft_printf("rr\n");
		else if (stack->val == RRR)
			ft_printf("rrr\n");
		stack = stack->next;
	}
}
