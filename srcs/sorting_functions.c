/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:24:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/15 14:32:28 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_elements_in_b(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int		i;
	int		val;
	int		len_a;

	len_a = stack_a->len;
	i = 0;
	// ft_printf("\n\n\nLen A %d /Len A\n", len_a);
	while (i < len_a / 3)
	{
		// ft_printf("I %d /I\n", i); || stack_a->head->ind < 3
		// ft_printf("(Len A/SPLITS)		%d /(LEN A/SPLITS)\n", len_a / SPLITS);
		// ft_printf("(Len A/SPLITS)*2	%d /(LEN A/SPLITS)*2\n", (len_a / SPLITS) * 2);
		if (stack_a->head->ind < 3)
		{
			ft_printf("Small Ind Rotated Val:		%d of Rank:	%d\n", stack_a->head->val, stack_a->head->ind);  
			val = rotate(stack_a, vars);
		}
		else if (stack_a->head->ind < len_a / SPLITS
				&& stack_a->head->ind > 2)
		{
			ft_printf("Rotated Val:		%d of Rank:	%d\n", stack_a->head->val, stack_a->head->ind);  
			val = rotate(stack_a, vars);
		}
		else if (stack_a->head->ind >= len_a / SPLITS
			&& stack_a->head->ind < (len_a / SPLITS) * 2
			&& stack_a->head->ind > 2)
		{
			ft_printf("Pushed Val:		%d of Rank:	%d\n", stack_a->head->val, stack_a->head->ind);  
			val = push(stack_b, stack_a, vars);
		}
		else if (stack_a->head->ind >= (len_a / SPLITS) * 2
				&& stack_a->head->ind > 2)
		{
			ft_printf("Push Bottom-ed Val:	%d of Rank:	%d\n", stack_a->head->val, stack_a->head->ind);  
			val = push_bottom(stack_b, stack_a, vars);
		}
		if (val == 1)
			return (1);
		i++;
	}
	return (0);
}

int	sort_three(t_stack *stack, t_push_swap *vars)
{
	int	ind_1;
	int	ind_2;
	int ind_3;

	ind_1 = stack->head->ind;
	ind_2 = stack->head->next->ind;
	ind_3 = stack->head->next->next->ind;
	if (ind_1 < ind_2 && ind_2 < ind_3)
		return (0);
	else if (ind_2 < ind_1 && ind_1 < ind_3)
		return (rotate(stack, vars));
	else if (ind_3 < ind_2 && ind_2 < ind_1)
		return (do_rotate(stack, 2, vars));
	else if (ind_3 < ind_1 && ind_1 < ind_2)
		return (rev_rotate(stack, vars));
	else if (ind_1 < ind_3 && ind_3 < ind_2)
		return (rotate(stack, vars));
	// else if (ind_2 < ind_3 && ind_3 < ind_1)
	// {
	// 	if (rev_rotate(stack, vars) == 1)
	// 		return (1);
	// 	return (swap(stack, vars));
	// }	
	return (1);
}

int	shortest_to_ind(t_stack *stack, int ind, t_push_swap *vars)
{
	size_t	travelled;
	t_node	*node;
	int		var;

	node = stack->head;
	travelled = 0;
	while (travelled < stack->len && node->ind != ind)
	{
		travelled++;
		node = node->next;
	}
	if (travelled < stack->len - travelled)
		var = do_rotate(stack, travelled, vars);
	else
		var = do_rev_rotate(stack, stack->len - travelled, vars);
	if (var == 1)
		return (1);
	return (0);
}

int next_ind_present(t_stack *stack, int i)
{
	size_t	j;
	t_node	*node;

	if (!stack)
		return (0);
	i++;
	node = stack->head;
	j = 0;
	while (j < stack->len)
	{
		if (node->ind == i)
			return (1);
		node = node->next;	
		j++;
	}
	return (0);
}