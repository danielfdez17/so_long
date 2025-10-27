/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:29 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/27 11:54:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_lstsize(t_list *lst)
// {
// 	t_list	*ptr;
// 	int		size;

// 	size = 0;
// 	ptr = lst;
// 	while (ptr != NULL)
// 	{
// 		ptr = ptr->next;
// 		++size;
// 	}
// 	return (size);
// }

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	return (lst->size);
}
