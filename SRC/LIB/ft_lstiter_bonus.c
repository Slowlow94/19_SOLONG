/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:51:09 by salowie           #+#    #+#             */
/*   Updated: 2023/04/19 17:37:06 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*actual_node;

	if (!lst || !f)
		return ;
	actual_node = lst;
	while (actual_node != NULL)
	{
		f(actual_node->content);
		actual_node = actual_node->next;
	}
}
