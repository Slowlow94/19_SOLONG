/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:19:54 by salowie           #+#    #+#             */
/*   Updated: 2023/04/19 17:38:23 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lenght;
	t_list	*actual_node;

	lenght = 0;
	if (!lst)
		return (0);
	actual_node = lst;
	while (actual_node != NULL)
	{
		lenght++;
		actual_node = actual_node->next;
	}
	return (lenght);
}
