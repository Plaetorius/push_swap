/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:57:47 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/09 15:33: by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int aux_shortest_a(t_stack **head, size_t ind, t_push_swap *vars)
{
	size_t	len;
	size_t	travelled;
	t_stack	*stack;
	int		result;

	len = vars->len_a;
	travelled = 0;
	stack = *head;
	while (travelled < len && stack->ind != ind)
	{
		++travelled;
		stack = stack->next;
	}
	if (travelled < len - travelled)
	{
		result = do_rotate(head, travelled, vars);
	}
	else
	{
		result = do_rev_rotate(head, len - travelled, vars);
		travelled = len - travelled;
	}
	if (!result)
		return (travelled);
	return (-1);
}

static int aux_shortest_b(t_stack **head, size_t ind, t_push_swap *vars)
{
	size_t	len;
	size_t	travelled;
	t_stack	*stack;
	int		result;

	len = vars->len_b;
	travelled = 0;
	stack = *head;
	// ft_printf("-------------HEAD VAL %d\n", (*head)->val);
	// ft_printf("-------------IND RESEARCHED %d\n", ind);
	while (travelled < len && stack->ind != ind)
	{
		// ft_printf("-------------IND CURRENT %d FOR VAL %d\n", stack->ind, stack->val);
		++travelled;
		stack = stack->next;
	}
	// ft_printf("TRAVELLED %d : %d LEN-TRAVELLED\n", travelled, len - travelled);
	if (travelled < len - travelled)
		result = do_rotate(head, travelled, vars);
	else
	{
		result = do_rev_rotate(head, len - travelled, vars);
		travelled = len - travelled;
	}
	if (!result)
		return (travelled);
	return (-1);
}

int	shortest_rotation_to_ind(t_stack **head, size_t ind, char stk,
	t_push_swap *vars)
{
	if (!head || !(*head) || !vars)
		return (-1);
	if (stk == 'a')
	{
		if (vars->len_a == 1)
			return (0);
		// ft_printf("=========================\n");
		// ft_printf("VALUE BEFORE %d /VALUE BEFORE\n", (*head)->val);
		// aux_shortest_a(head, ind, vars);
		// ft_printf("VALUE AFTER %d /VALUE AFTER\n", (*head)->val);
		// ft_printf("=========================\n");
		return (aux_shortest_a(head, ind, vars));
	}
	else if (stk == 'b')
	{
		if (vars->len_b == 1)
			return (0);
		// ft_printf("=========================\n");
		// ft_printf("VALUE BEFORE %d /VALUE BEFORE\n", (*head)->val);
		// aux_shortest_b(head, ind, vars);
		// ft_printf("VALUE AFTER %d /VALUE AFTER\n", (*head)->val);
		// ft_printf("=========================\n");
		return (aux_shortest_b(head, ind, vars));
	}
	return (-1);
}

int	clear_stack_a(t_stack **head_a, t_stack **head_b, size_t len_a,
	t_push_swap *vars)
{
	size_t	i;
	int		ret_val;

	i = 0;
	while (i < len_a)
	{
		if ((*head_a)->ind == len_a - 1)
		{
			ret_val = rotate(head_a, vars);

		}
		else
		{
			ret_val = push(head_b, head_a, 'a', vars);
		}
		if (ret_val == 1)
			return (1);
		i++;
	}
	return (0);
}

int send_back_to_a(t_stack **head_a, t_stack **head_b, size_t len_b,
	t_push_swap *vars)
{
	size_t	i;
	int		ret_value;

	t_stack *stack;
	stack = *head_a;
	ft_printf("Stack A\n");
	stack_burner_ind(stack);
	ft_printf("End Stack A\n");
	ft_printf("Stack B\n");
	stack = *head_b;
	stack_burner_ind(stack);
	stack = *head_b;
	stack_burner(stack);
	ft_printf("End Stack B\n");
	while (len_b > 0)
	{
		ret_value = shortest_rotation_to_ind(head_b, len_b, 'b', vars);
		push(head_a, head_b, 'b', vars);
		len_b--;
	}
	return (0);
}
