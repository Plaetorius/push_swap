/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:44:21 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/20 14:28:52 by tgernez          ###   ########.fr       */
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

void	old_instructions_shower(t_instruct *stack)
{
	ft_printf("Je suis dans OLD %p\n", stack);
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
	ft_printf("J'me barre ca pue\n");
}

static t_instruct	*new_cleaned_instruct(int val, t_instruct *head)
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
	// old_instructions_shower(head);
	
	return (head);
}



t_instruct	*instruction_optimizer(t_instruct *stack)
{
	t_instruct	*new;
	t_instruct	*cleaned;
	int			count_1;
	int			count_2; 

	new = stack;
	cleaned = NULL;
	// ft_free_stack(vars->insts);
	// ft_printf("Var Insts %p /Var Insts\n", vars->insts);
	while (stack)
	{
		count_1 = 0;
		count_2 = 0;
		while (stack && stack->val == ROTATE_A)
		{
			count_1 += 1;
			stack = stack->next;
		}
		while (stack && stack->val == ROTATE_B)
		{
			count_2 += 1;
			stack = stack->next;
		}
		// ft_printf("C1: %d, C2: %d\n", count_1, count_2);
		while (count_1 > 0 && count_2 > 0)
		{
			cleaned = new_cleaned_instruct(RR, cleaned);
			count_1--;
			count_2--;
		}
		while (count_1 > 0)
		{
			// ft_printf("J'ajoute la\n");
			cleaned = new_cleaned_instruct(ROTATE_A, cleaned);
			count_1--;
		}
		while (count_2 > 0)
		{
			cleaned = new_cleaned_instruct(ROTATE_B, cleaned);
			count_2--;
		}
		// old_instructions_shower(vars->insts, vars);
		count_1 = 0;
		count_2 = 0;
		while (stack && stack->val == REV_ROTATE_A)
		{
			count_1 += 1;
			stack = stack->next;
		}
		while (stack && stack->val == REV_ROTATE_B)
		{
			count_2 += 1;
			stack = stack->next;
		}
		// ft_printf("C1: %d, C2: %d\n", count_1, count_2);
		while (count_1 > 0 && count_2 > 0)
		{
			cleaned = new_cleaned_instruct(RRR, cleaned);
			count_1--;
			count_2--;
		}
		while (count_1 > 0)
		{
			// ft_printf("J'ajoute la\n");
			cleaned = new_cleaned_instruct(REV_ROTATE_A, cleaned);
			count_1--;
		}
		while (count_2 > 0)
		{
			cleaned = new_cleaned_instruct(REV_ROTATE_B, cleaned);
			count_2--;
		}
		if (stack)
		{
			cleaned = new_cleaned_instruct(stack->val, cleaned);
			stack = stack->next;
		}
	}
	// old_instructions_shower(cleaned);
	ft_free_stack(stack);
	return (cleaned);
}


//10 11 5 12 15 4 1 9 13 7 6 2 3 14 8 

void	instructions_shower(t_instruct *stack)
{
	t_instruct *tmp;
	
	stack = instruction_optimizer(stack);
	tmp = stack;
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
	ft_free_stack(tmp);
}