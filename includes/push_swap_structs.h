/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:41 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/22 17:18:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H
# include "push_swap.h"
# include <stddef.h>

typedef struct s_node
{
	int					val;
	struct s_node		*next;
	struct s_node		*prev;
	int					ind;
}	t_node;

typedef struct s_stack
{
	t_node				*head;
	size_t				len;
}	t_stack;

typedef struct s_instruct
{
	int					val;
	struct s_instruct	*next;
}	t_instruct;

typedef struct s_push_swap
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_instruct			*insts;
	int					splits;
}	t_push_swap;

#endif
