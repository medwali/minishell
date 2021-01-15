/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 02:25:05 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/14 21:54:44 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INTERNAL_H
# define VECTOR_INTERNAL_H
# include "../../libft.h"
# include "../vector.h"

void	vector_grow(t_vector *vector);
void	vector_shrink(t_vector *vector);
void	vector_grow_above(t_vector *vector, size_t min_capacity);

#endif
