/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:19:31 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 12:01:25 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "push_swap.h"

int		check_rotate(t_stack *stack, t_push_swap *vars);
int		check_rev_rotate(t_stack *stack, t_push_swap *vars);
int		check_push(t_stack *receiver, t_stack *sender, t_push_swap *vars);
int		check_swap(t_stack *stack, t_push_swap *vars);
int		init(char **av, int ac, t_push_swap *vars);

int		execute_instructs(t_push_swap *vars);

#endif
