/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:38:33 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 13:02:09 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_stack **head, t_push_swap *vars)
{
	if (!head || !(*head) || !vars)
		return (1);
	if (*head == vars->head_a)
	{
		vars->inst_a = new_instruct(REV_ROTATE, vars->inst_a);
		if (!vars->inst_a)
			return (1);
	}
	else
	{
		vars->inst_b = new_instruct(REV_ROTATE, vars->inst_b);
		if (!vars->inst_b)
			return (1);
	}
	(*head) = (*head)->prev;
	return (0);
}

int	rotate(t_stack **head, t_push_swap *vars)
{
	if (!head || !(*head) || !vars)
		return (1);
	if (*head == vars->head_a)
	{
		vars->inst_a = new_instruct(ROTATE, vars->inst_a);
		if (!vars->inst_a)
			return (1);
	}
	else
	{
		vars->inst_b = new_instruct(ROTATE, vars->inst_b);
		if (!vars->inst_b)
			return (1);
	}
	(*head) = (*head)->next;
	return (0);
}
