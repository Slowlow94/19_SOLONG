/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:12:12 by salowie           #+#    #+#             */
/*   Updated: 2023/04/25 10:11:09 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy_lst;
	t_list	*new_node;
	void	*ptr_new;

	if (!lst || !f || !del)
		return (NULL);
	copy_lst = NULL;
	while (lst != NULL)
	{
		ptr_new = f(lst->content);
		new_node = ft_lstnew(ptr_new);
		if (!new_node)
		{
			del(ptr_new);
			ft_lstclear(&copy_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&copy_lst, new_node);
		lst = lst->next;
	}
	return (copy_lst);
}
