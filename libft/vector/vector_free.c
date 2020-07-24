/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/10 04:00:10 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vector_internal.h"

void		vector_free(t_vector *vector)
{
	size_t i;

	if (vector->free_element)
	{
		i = 0;
		while (i < vector->length)
			vector->free_element(vector->array + i++ * vector->element_size);
	}
	free(vector->array);
	free(vector);
}
