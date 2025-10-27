/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:27:10 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/27 10:22:50 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/so_long.h"

int main(int ac, char **av)
{
	(void)ac;
	char	*file_ext = NULL;
	if (!av || !av[1])
	{
		ft_putendl_fd("El programa debe recibir un archivo .ber", 2);
		return (0);
	}
	file_ext = ft_strrchr(av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 4) != 0)
	{
		ft_putendl_fd("El programa debe recibir un archivo .ber", 2);
		return (0);
	}
	ft_putendl_fd(ft_strrchr(av[1], '.'), 1);
	return (0);
}