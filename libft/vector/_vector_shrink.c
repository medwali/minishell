/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_shrink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:32:59 by mel-idri          #+#    #+#             */
/*   Updated: 2020/06/14 20:42:42 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vector_internal.h"

void	_vector_shrink(t_vector *vector)
{
	void	*new_array;

	new_array = safe_malloc((vector->capacity / 4) * vector->element_size);
	ft_memcpy(new_array, vector->array, vector->length * vector->element_size);
	free(vector->array);
	vector->array = new_array;
	vector->capacity /= 4;
}
