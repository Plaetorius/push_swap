/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:38:02 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 11:40:43 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	ft_free_circular_nodes(t_node *node)
{
	t_node	*tmp;
	t_node	*ptr;

	if (!node)
		return ;
	ptr = node->next;
	while (ptr != node)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
	free(node);
	node = NULL;
}

void	ft_free_stack(t_instruct *stack)
{
	t_instruct	*ptr;
	t_instruct	*tmp;

	if (!stack)
		return ;
	ptr = stack;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
	stack = NULL;
}

void	memory_cleaning(t_push_swap *vars)
{
	if (!vars)
		return ;
	ft_free_circular_nodes(vars->stack_a->head);
	ft_free_circular_nodes(vars->stack_b->head);
	ft_free_stack(vars->insts);
}
