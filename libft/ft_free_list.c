/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 00:48:34 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/09 22:41:11 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list *head)
{
	t_list *tmp;

	tmp = head;
	while (head)
	{
		head = head->next;
		free(tmp->content);
		free(tmp);
		tmp = head;
	}
}