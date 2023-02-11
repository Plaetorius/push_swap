/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:08:12 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/11 17:54:46 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *aux_push(t_stack *receiver, t_stack *sender)
{
	t_node	*node;
	t_node	*tmp;
	t_node	*second;	

	tmp = sender->head;
	second = sender->head->next;
	if (receiver->head)
	{
		node = ft_node_new(tmp->val, receiver->head, 
			receiver->head->prev, tmp->ind);
		if (!node)
			return (NULL);
		ft_node_endings(node, receiver->head, receiver->head->prev);
	}
	else
	{
		node = ft_node_new(tmp->val, NULL, NULL, tmp->ind);
		if (!node)
			return (NULL);
		ft_node_endings(node, node, node);
	}
	ft_node_endings(second, second->next, tmp->prev);
	return (node);	
}

int	push(t_stack *receiver, t_stack *sender, t_push_swap *vars)
{
	t_node		*node;
	t_node		*tmp;

	if (!sender || !(sender->head) || !vars)
		return (1);
	node = aux_push(receiver, sender);
	tmp = sender->head;
	receiver->head = node;
	sender->head = sender->head->next;
	sender->len -= 1;
	receiver->len += 1;
	free(tmp);
	tmp = NULL;
	if (vars->stack_a == receiver)
	{
		stack_association(receiver, sender, vars);
		vars->insts = new_instruct(PUSH_A, vars->insts);
	}
	else
	{
		stack_association(sender, receiver, vars);
		vars->insts = new_instruct(PUSH_B, vars->insts);
	}
	return (vars->insts == NULL);	
}