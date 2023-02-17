/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:47:17 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/17 18:55:18 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	best_choice(int **tab)
{
	int	i;
	int	best_ind;
	int	best_val;
	int	tmp;
	
	best_ind = 0;
	best_val = zero_dist_max(tab[0][0], tab[0][1]);
	i = 1;
	while (tab[i])
	{
		tmp = zero_dist_max(tab[i][0], tab[i][1]);
		if (tmp < best_val)
		{
			best_val = tmp;
			best_ind = i;
		}
		i++;
	}
	return (best_ind);
}

int	instruction_executer(t_stack *stack_a, t_stack *stack_b, int **tab,
	t_push_swap *vars)
{
	int best_ind;
	int	val;

	if (!stack_a || !stack_b || !tab || !(*tab) || !vars)
		return (1);
	best_ind = best_choice(tab);
	if (tab[best_ind][0] > 0)
		do_rotate(stack_a, ft_abs(tab[best_ind][0]), vars);
	else if (tab[best_ind][0] < 0)
		do_rev_rotate(stack_a, ft_abs(tab[best_ind][0]), vars);
	if (tab[best_ind][1] > 0)
		do_rotate(stack_b, ft_abs(tab[best_ind][1]), vars);
	else if (tab[best_ind][1] < 0)
		do_rev_rotate(stack_b, ft_abs(tab[best_ind][1]), vars);
	ft_free_ints(tab);
	return (push(stack_a, stack_b, vars));
}