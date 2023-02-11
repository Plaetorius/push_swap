/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:44:21 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/11 17:56:46 by tgernez          ###   ########.fr       */
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
	vars->stack_a = stack_a;
	vars->stack_b = stack_b;
}

