/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:38:33 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 14:45:11 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_aux(t_stack *head, t_stack *first, t_push_swap *vars)
{
	if (head == vars->head_a)
	{
		vars->head_a = first;
		vars->inst_a = new_instruct(SWAP, vars->inst_a);
		return (vars->inst_a == NULL);
	}
	else
	{
		vars->head_b = first;
		vars->inst_b = new_instruct(SWAP, vars->inst_b);
		return (vars->inst_b == NULL);
	}
}

int	swap(t_stack **head, t_push_swap *vars)
{
	t_stack	*third;
	t_stack	*first;

	if (!head || !(*head) || !vars)
		return (1);
	first = (*head)->next;
	third = (*head)->next->next;
	(*head)->prev->next = first;
	first->prev = (*head)->prev;
	first->next = (*head);
	(*head)->prev = first;
	(*head)->next = third;
	third->prev = (*head);
	(*head) = first;
	return (swap_aux(*head, first, vars));
}

// static int	push_a(t_stack **receiver, t_stack **sender, t_push_swap *vars)
// {
// 	t_stack	*tmp;
// 	t_stack	*elem;
// 	t_stack	*last;
// 	t_stack	*second;

// 	(vars->len_b)--;
// 	(vars->len_a)++;
// 	tmp = *sender;
// 	elem = ft_stack_new((*sender)->val, NULL, NULL, 10000);
// 	// ft_printf("SENDER'S VALUE %d /SENDER'S VALUE\n", (*sender)->val);
// 	// ft_printf("SENDER'S INDICE %d /SENDER'S INDICE\n", (*sender)->ind);
// 	// ft_printf("TMP'S INDICE %d /TMP'S INDICE\n", (tmp)->ind);
// 	last = (*sender)->prev;
// 	second = (*sender)->next;
// 	second->prev = last;
// 	last->next = second;
// 	free(tmp);
// 	tmp = NULL;
// 	vars->head_b = second;
// 	*sender = second;
// 	if (*receiver == NULL)
// 		*receiver = elem;
// 	ft_stack_endings(elem, *receiver, (*receiver)->prev);
// 	vars->head_a = elem;
// 	*receiver = elem;
// 	vars->inst_a = new_instruct(PUSH, vars->inst_a);
// 	return (vars->inst_a == NULL);
// }


/*
	PUSH ON B
*/
// static int	push_b(t_stack **receiver, t_stack **sender, t_push_swap *vars)
// {
// 	t_stack	*tmp;
// 	t_stack	*elem;
// 	t_stack	*last;
// 	t_stack	*second;

// 	(vars->len_a)--;
// 	(vars->len_b)++;
// 	tmp = *sender;
// 	ft_printf("SENDER VALUE %d /SENDER VALUE\n", tmp->val);
// 	elem = ft_stack_new((*sender)->val, NULL, NULL, 10000);
// 	if (!elem)
// 		return (1);
// 	last = (*sender)->prev;
// 	second = (*sender)->next;
// 	second->prev = last;
// 	last->next = second;
// 	free(tmp);
// 	tmp = NULL;
// 	vars->head_a = second;
// 	*sender = second;
// 	ft_printf("ELEM VALUE %d /ELEM VALUE\n", elem->val);
// 	if (*receiver == NULL)
// 	{
// 		*receiver = elem;
// 		ft_printf("RECEIVER ADDRESS %p /RECEIVER ADDRESS FOR VAL %d\n", *receiver, (*receiver)->val);
// 		ft_stack_endings(elem, *receiver, (*receiver)->prev);
// 		vars->head_b = elem;
// 		vars->inst_b = new_instruct(PUSH, vars->inst_b);
// 	}
// 	else
// 	{
// 		ft_printf("2 RECEIVER ADDRESS %p /RECEIVER ADDRESS FOR VAL %d\n", *receiver, (*receiver)->val);
// 		ft_stack_endings(elem, *receiver, (*receiver)->prev);
// 		vars->head_b = elem;
// 		vars->inst_b = new_instruct(PUSH, vars->inst_b);
// 		*receiver = elem;
// 	}
// 	return (vars->inst_b == NULL);
// }
//FIXME optimize push aux, protect the stack new

static int	push_a(t_stack **receiver, t_stack **sender, t_push_swap *vars)
{
	t_stack *tmp;
	t_stack	*elem;

	// ft_printf("In PUSH\n");
	// ft_printf("RECEIVER AND ITS NEXT %d->%d\n", (*receiver)->val,(*receiver)->next->val);
	(vars->len_b)--;
	(vars->len_a)++;
	tmp = *sender;
	elem = ft_stack_new(tmp->val, NULL, NULL, (tmp->ind));
	(*sender)->next->prev = (*sender)->prev;
	(*sender)->prev->next = (*sender)->next;
	if (!elem)
		return (1);
	ft_stack_endings(elem, elem, elem);
	if (*receiver == NULL)
		*receiver = elem;
	ft_stack_endings(elem, *receiver, (*receiver)->prev);
	*sender = (*sender)->next;
	*receiver = elem;
	free(tmp);
	tmp = NULL;
	vars->head_b = *sender;
	vars->head_a = *receiver;
	vars->inst_a = new_instruct(PUSH, vars->inst_a);
	return (vars->inst_a == NULL);
}

static int	push_b(t_stack **receiver, t_stack **sender, t_push_swap *vars)
{
	t_stack *tmp;
	t_stack	*elem;

	// ft_printf("In PUSH\n");
	// ft_printf("RECEIVER AND ITS NEXT %d->%d\n", (*receiver)->val,(*receiver)->next->val);
	(vars->len_a)--;
	(vars->len_b)++;
	tmp = *sender;
	elem = ft_stack_new(tmp->val, NULL, NULL, (tmp->ind));
	(*sender)->next->prev = (*sender)->prev;
	(*sender)->prev->next = (*sender)->next;
	if (!elem)
		return (1);
	ft_stack_endings(elem, elem, elem);
	if (*receiver == NULL)
		*receiver = elem;
	ft_stack_endings(elem, *receiver, (*receiver)->prev);
	*sender = (*sender)->next;
	*receiver = elem;
	free(tmp);
	tmp = NULL;
	vars->head_a = *sender;
	vars->head_b = *receiver;
	vars->inst_b = new_instruct(PUSH, vars->inst_b);
	return (vars->inst_b == NULL);
}


int	push(t_stack **receiver, t_stack **sender, char from_stk, t_push_swap *vars)
{
	if (!receiver || !sender || !(*sender) || !vars)
		return (1);
	if (from_stk == 'b')
		return (push_a(receiver, sender, vars));
	else if (from_stk == 'a')
		return (push_b(receiver, sender, vars));
	return (1);
}
