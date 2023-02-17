/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:17:58 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/17 14:59:36 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int case_1(t_stack *stack_a, t_node	*node, int **pos_element, t_push_swap *vars);
static int case_2(t_stack *stack_a, t_stack *node, int **pos_element, t_push_swap *vars);
static int case_3(t_stack *stack_a, t_stack *node, int **pos_element, t_push_swap *vars);
static int case_4(t_stack *stack_a, t_stack *stack_b, int **pos_element, t_push_swap *vars);

static int case_1(t_stack *stack_a, t_node *node , int **pos_element, t_push_swap *vars)
{
	int	last_of_a;
	int	first_of_a;
	int	elem_of_b;

	last_of_a = stack_a->head->prev->val;
	first_of_a = stack_a->head->val;
	elem_of_b = node->val;
	if ((first_of_a < elem_of_b && elem_of_b < last_of_a)
		|| (last_of_a < elem_of_b && elem_of_b < first_of_a))
	{
		(*pos_element)[0] = 0;
		(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
	}
	return (1);
}

static int case_2(t_stack *stack_a, t_node *node, int **pos_element, t_push_swap *vars)
{
	int		i;
	int		first_val;
	int		second_val;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	while (i <= stack_a->len / 2)
	{
		if ((tmp->val < node->val && node->val < tmp->next->val)
			|| (tmp->next->val < node->val && node->val < tmp->val))
		{
			(*pos_element)[0] = i;
			(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
		}
		tmp = tmp->next;
		i++;
	}
}

static int case_3(t_stack *stack_a, t_node *node, int **pos_element, t_push_swap *vars)
{
	int		i;
	int		first_val;
	int		second_val;
	t_node	*tmp;

	i = stack_a->len - 1;
	tmp = stack_a->head;
	while (i > stack_a->len / 2)
	{
		if ((tmp->val < node->val && node->val < tmp->next->val)
			|| (tmp->next->val < node->val && node->val < tmp->val))
		{
			(*pos_element)[0] = i - stack_a->len;
			(*pos_element)[1] = shortest_to_top(vars->stack_b, node->ind);
		}
		tmp = tmp->next;
		i--;
	}
}

static int case_4(t_stack *stack_a, t_node *node, int **pos_element, t_push_swap *vars)
{
	
}

// static int case_4(t_stack *stack_a, t_stack *stack_b, int **pos_element, t_push_swap *vars)
// {
// 	t_node *current;
// 	t_node *prev;

// 	current = stack_a->head;
// 	prev = stack_a->head->prev;
// 	if ((prev->val < node->val && node->val < current->val)
// 		|| (prev->val > node->val && node->val > current->val))
// 		(*pos_element)[0] = 0;
// 		(*pos_element)[1] = 9;
// 		//CALCUL 	
// 	return (1);
// }

int **case_test(t_stack *stack_a, t_stack *stack_b, t_push_swap *vars)
{
	int		**pos;
	int		i;
	t_node	*node;

	if (!stack_a || !stack_b || !vars)
		return (NULL);
	pos = ft_ints(stack_b->len, 2);
	if (!pos)
		return (NULL);
	i = 0;
	node = stack_b->head;
	while (i < stack_b->len)
	{
		if (!case_1(stack_a, stack_b, pos + i, vars))
			return (ft_free_int(pos), NULL);
		// else if (!case_2(stack_a, stack_b,  pos + i, vars))
		// 	return (ft_free_int(pos), NULL);
		// else if (!case_3(stack_a, stack_b, pos + i, vars))
		// 	return (ft_free_int(pos), NULL);
		// else if (!case_4(stack_a, stack_b, pos + i, vars))
		// 	return (ft_free_int(pos), NULL);
		node = node->next;
		i++;

	}
	return (pos);
}
