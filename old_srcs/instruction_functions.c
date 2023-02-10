/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:56:32 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/08 16:18:47 by tgernez          ###   ########.fr       */
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

static int	optimized_instructs(t_instruct *first, t_instruct *second, char stk)
{
	if (first->val == SWAP)
	{
		if (second && second->val == SWAP)
			return (ft_printf("ss\n"), 2);
		return (ft_printf("s%c\n", stk), 1);
	}
	else if (first->val == PUSH)
		return (ft_printf("p%c\n", stk), 1);
	else if (first->val == ROTATE)
	{
		if (second && second->val == ROTATE)
			return (ft_printf("rr\n"), 2);
		return (ft_printf("r%c\n", stk), 1);
	}
	else if (first->val == REV_ROTATE)
	{
		if (second && second->val == REV_ROTATE)
			return (ft_printf("rrr\n"), 2);
		return (ft_printf("rr%c\n", stk), 1);
	}
	return (0);
}

int	instructions_destacker(t_instruct *first, t_instruct *second, char stk)
{
	int		val;

	if (!first)
		return (1);
	while (first)
	{
		val = optimized_instructs(first, second, stk);
		if (val == 0)
			return (1);
		else if (val == 2)
			second = second->next;
		first = first->next;
	}
	return (0);
}

t_instruct	*instructions_adder(int instruction, int number, t_instruct *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
	{
		stack = new_instruct(instruction, NULL);
		if (!stack)
			return (NULL);
		i++;
	}
	while (i < number)
	{
		stack = new_instruct(instruction, stack);
		if (!stack)
			return (NULL);
		i++;
	}
	return (stack);
}
