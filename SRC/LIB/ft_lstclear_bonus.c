/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:50:32 by salowie           #+#    #+#             */
/*   Updated: 2023/04/26 10:09:51 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;
	t_list	*temp;

	if (!del || !lst)
		return ;
	actual = *lst;
	while (actual != NULL)
	{
		temp = actual->next;
		del(actual->content);
		free(actual);
		actual = temp;
	}
	*lst = NULL;
}
