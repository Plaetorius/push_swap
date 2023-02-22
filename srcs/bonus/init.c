/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:25:10 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 12:01:05 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	init(char **av, int ac, t_push_swap *vars)
{
	t_node	*node;
	int		*table;

	if (!av || ac == 1 || !vars)
		return (1);
	table = parsing(ac, av, vars);
	if (!table)
		return (1);
	node = convert(table, vars->stack_a->len, vars);
	if (!node)
		return (free(table), 1);
	vars->stack_a->head = node;
	free(table);
	return (0);
}
