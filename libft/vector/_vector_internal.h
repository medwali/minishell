/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 02:25:05 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/14 20:47:42 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_INTERNAL_H
# define _VECTOR_INTERNAL_H
# include "../libft.h"
# include "vector.h"
void	_vector_grow(t_vector *vector);
void	_vector_shrink(t_vector *vector);
void	_vector_grow_above(t_vector *vector, size_t min_capacity);
#endif 