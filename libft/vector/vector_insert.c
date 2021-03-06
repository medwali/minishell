/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/14 21:56:35 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

int			vector_insert(t_vector *vector, void *element, size_t index)
{
	if (!vector || !element)
		return (-1);
	if (vector->length == vector->capacity)
		vector_grow(vector);
	if (index > vector->length)
		index = vector->length;
	if (index < vector->length)
		ft_memmove(vector->array + (index + 1) * vector->element_size,
			vector->array + index * vector->element_size,
			(vector->length - index) * vector->element_size);
	ft_memcpy(vector->array + index * vector->element_size, element,
		vector->element_size);
	vector->length++;
	return (0);
}
