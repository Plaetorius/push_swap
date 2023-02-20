/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:44:21 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 16:43:16 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_instruct(int val, t_push_swap *vars)
{
	t_instruct	*instruct;
	t_instruct	*tmp;

	instruct = malloc(sizeof(t_instruct));
	if (!instruct)
		return (1);
	instruct->val = val;
	instruct->next = NULL;
	tmp = vars->insts;
	if (vars->insts == NULL)
		vars->insts = instruct;
	else
	{
		while (vars->insts->next)
			vars->insts = vars->insts->next;
		vars->insts->next = instruct;
		vars->insts = tmp;
	}
	return (0);
}

t_instruct	*new_cleaned_instruct(int val, t_instruct *head)
{
	t_instruct	*instruct;
	t_instruct	*tmp;

	instruct = malloc(sizeof(t_instruct));
	if (!instruct)
		return (NULL);
	instruct->val = val;
	instruct->next = NULL;
	tmp = head;
	if (head == NULL)
		head = instruct;
	else
	{
		while (head->next)
			head = head->next;
		head->next = instruct;
		head = tmp;
	}
	return (head);
}

void	instructions_shower_aux(t_instruct *stack)
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

void	instructions_shower(t_instruct *stack)
{
	stack = instruction_optimizer(stack);
	if (!stack)
		return ;
	instructions_shower_aux(stack);
	ft_free_stack(stack);
}
