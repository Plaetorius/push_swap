/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:19:31 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/21 18:39:52 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int					val;
	struct s_node		*next;
	struct s_node		*prev;
	int					ind;
}	t_node;

typedef struct t_stack
{
	t_node				*head;
	size_t				len;
}	t_stack;

void	free_checker_lst(t_list *head);
int		*parsing_to_stack(int ac, char **av, t_stack *stack);
long	atoi_def(const char *str, int *val);

#endif
