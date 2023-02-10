/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:19 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 11:22:06 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int do_push(t_stack **receiver, t_stack **sender, size_t times, 
	t_push_swap *vars)
{
	size_t	i;
	char	from_stk;
	
	i = 0;
	if (*sender == vars->head_a)
		from_stk = 'a';
	else
		from_stk = 'b';
	while (i < times)
	{
		if (push(receiver, sender, from_stk, vars) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	do_rotate(t_stack **head, size_t times, t_push_swap *vars)
{
	size_t	i;

	i = 0;
	// ft_printf("START OF ROTATION VALUE OF HEAD %d \n",(*head)->val);
	while (i < times)
	{
		// ft_printf("ROTATING\n");
		if (rotate(head, vars) == 1)
			return (1);
		i++;
	}
	// ft_printf("END OF ROTATION VALUEOF HEAD %d \n",(*head)->val);
	return (0);
}

int	do_rev_rotate(t_stack **head, size_t times, t_push_swap *vars)
{
	size_t	i;

	i = 0;
	// ft_printf("START OF ROTATION VALUEOF HEAD %d \n",(*head)->val);

	while (i < times)
	{
		// ft_printf("REV ROTATING\n");
		if (rev_rotate(head, vars) == 1)
			return (1);
		i++;
	}
	// ft_printf("END OF ROTATION VALUEOF HEAD %d \n",(*head)->val);

	return (0);
}