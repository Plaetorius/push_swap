/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:27 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/11 17:4 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "push_swap_protos.h"
# include "push_swap_structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"
# ifndef SPLITS
#  define SPLITS 5
# endif

enum e_instructs
{
	SWAP_A,
	PUSH_A,
	ROTATE_A,
	REV_ROTATE_A,
	SWAP_B,
	PUSH_B,
	ROTATE_B,
	REV_ROTATE_B,
	RR,
	RRR
};
#endif
