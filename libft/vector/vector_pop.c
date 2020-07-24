/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/10 03:11:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vector_internal.h"

int			vector_pop(t_vector *vector, void *element)
{
	if (!vector || !element || vector->length == 0)
		return (-1);
	ft_memcpy(element, 
		vector->array + (vector->length - 1) * vector->element_size,
		vector->element_size);
	vector->length--;
	if (vector->length > 16 && vector->length <= vector->capacity / 4)
		_vector_shrink(vector);
	return (0);
}
