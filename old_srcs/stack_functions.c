/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:43:15 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 11:26:23 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int val, t_stack *next, t_stack *prev, int ind)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->val = val;
	elem->next = next;
	elem->prev = prev;
	elem->ind = ind;
	return (elem);
}

void	ft_stack_endings(t_stack *elem, t_stack *next, t_stack *prev)
{
	if (!elem)
		return ;
	if (next)
	{
		elem->next = next;
		next->prev = elem;
	}
	if (prev)
	{
		elem->prev = prev;
		prev->next = elem;
	}
}

void	ft_free_circular_stack(t_stack *begin, size_t len)
{
	t_stack	*ptr;
	t_stack	*tmp;
	size_t	i;

	if (!begin)
		return ;
	i = 0;
	ptr = begin;
	while (i < len)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
		i++;
	}
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

// int ft_pop(t_stack **stack, size_t *len)
// {
// 	t_stack	*tmp;
// 	int	val;

// 	if (!stack || !*stack || !len)
// 		return (NULL);
// 	tmp = *stack;
// 	if (*len == 1)
// 	{
// 		val = tmp->val;
// 		*stack = NULL;
// 		free(tmp);
// 		return (val);
// 	}
// 	(*stack) = (*stack)->next;
// }

// t_stack	*ft_pop(t_stack **stack, size_t *len)
// {
// 	t_stack *elem;

// 	t_stack	*tmp1;
// 	t_stack	*tmp2;

// 	if (!stack || !*stack || !len)
// 		return (NULL);
// 	elem = ft_stack_new((*stack)->val, (*stack)->next, (*stack)->prev);
// 	ft_stack_endings(elem, elem, elem);
// 	// free(tmp1); free(tmp2);
// 	// free((*stack)->next);
// 	// free((*stack)->prev);
// 	(*stack)->prev->next = (*stack)->next;
// 	(*stack)->next->prev = (*stack)->prev;
// 	// free(*stack);
// 	ft_printf("NEXT VAL %d /NEXT VAL\n", (*stack)->next->val);
// 	(*stack) = (*stack)->next;
// 	(*len)--;
// 	// free(elem);
// 	return (elem);	
// }

void	ft_top(t_stack **stack, t_stack *elem, size_t *len)
{
	if (!elem || !len || !stack)
		return ;
	if (*stack == NULL)
		*stack = elem;
	ft_stack_endings(elem, *stack, (*stack)->prev);
	(*len)++;
}
