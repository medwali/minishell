/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/10 03:11:38 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vector_internal.h"

int			vector_push(t_vector *vector, void *element)
{
	if (!vector || !element)
		return (-1);
	if (vector->length == vector->capacity)
		_vector_grow(vector);
	ft_memcpy(vector->array + vector->length * vector->element_size, element,
		vector->element_size);
	vector->length++;
	return (0);
}
