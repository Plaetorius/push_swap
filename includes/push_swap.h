/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:27 by tgernez           #+#    #+#             */
/*   Updated: 2023/02/10 23:12:29 by tgernez          ###   ########.fr       */
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
#  define SPLITS 3
# endif

enum e_instructs
{
	SWAP,
	PUSH,
	ROTATE,
	REV_ROTATE,
};
#endif
