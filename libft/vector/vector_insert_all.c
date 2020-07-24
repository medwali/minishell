/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 00:20:21 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/18 02:49:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vector_internal.h"

int	vector_insert_all(t_vector *vector, t_vector *inserted_vec, size_t index)
{
	if (!vector || !inserted_vec || vector->element_size !=
			inserted_vec->element_size)
		return (-1);
	if (vector->length + inserted_vec->length > vector->capacity)
		_vector_grow_above(vector, vector->length + inserted_vec->length);
	if (index > vector->length)
		index = vector->length;
	if (index < vector->length)
		ft_memmove(vector->array + (index + inserted_vec->length) *
			vector->element_size,
			vector->array + index * vector->element_size,
			(vector->length - index) * vector->element_size);
	ft_memcpy(vector->array + index * vector->element_size, inserted_vec->array,
		inserted_vec->length * inserted_vec->element_size);
	vector->length += inserted_vec->length;
	return (0);
}