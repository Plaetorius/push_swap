/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_optimizer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:22 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 16:45:24 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	instruction_counter(t_instruct **stack, int instruction_searched)
{
	int	count;

	count = 0;
	while ((*stack) && (*stack)->val == instruction_searched)
	{
		count += 1;
		(*stack) = (*stack)->next;
	}
	return (count);
}

static t_instruct	*double_instruction_adder(t_instruct **cleaned,
	int instruct, int *count_1, int *count_2)
{
	while (*count_1 > 0 && *count_2 > 0)
	{
		*cleaned = new_cleaned_instruct(instruct, *cleaned);
		if (!(*cleaned))
			return (ft_free_stack(*cleaned), NULL);
		(*count_1)--;
		(*count_2)--;
	}
	return (*cleaned);
}

static t_instruct	*simple_instruction_adder(t_instruct **cleaned,
	int instruct, int *count)
{
	while (*count > 0)
	{
		*cleaned = new_cleaned_instruct(instruct, *cleaned);
		if (!(*cleaned))
			return (ft_free_stack(*cleaned), NULL);
		(*count)--;
	}
	return (*cleaned);
}

t_instruct	*instruction_optimizer(t_instruct *stack)
{
	t_instruct	*cleaned;
	int			count_1;
	int			count_2;

	cleaned = NULL;
	while (stack)
	{
		count_1 = instruction_counter(&stack, ROTATE_A);
		count_2 = instruction_counter(&stack, ROTATE_B);
		cleaned = double_instruction_adder(&cleaned, RR, &count_1, &count_2);
		cleaned = simple_instruction_adder(&cleaned, ROTATE_A, &count_1);
		cleaned = simple_instruction_adder(&cleaned, ROTATE_B, &count_2);
		count_1 = instruction_counter(&stack, REV_ROTATE_A);
		count_2 = instruction_counter(&stack, REV_ROTATE_B);
		cleaned = double_instruction_adder(&cleaned, RRR, &count_1, &count_2);
		cleaned = simple_instruction_adder(&cleaned, REV_ROTATE_A, &count_1);
		cleaned = simple_instruction_adder(&cleaned, REV_ROTATE_B, &count_2);
		if (stack)
		{
			cleaned = new_cleaned_instruct(stack->val, cleaned);
			stack = stack->next;
		}
	}
	ft_free_stack(stack);
	return (cleaned);
}
