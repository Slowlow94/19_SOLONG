/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:05:29 by salowie           #+#    #+#             */
/*   Updated: 2023/04/19 17:37:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actual_node;

	if (!lst)
		return (NULL);
	actual_node = lst;
	while (actual_node->next != NULL)
		actual_node = actual_node->next;
	return (actual_node);
}
