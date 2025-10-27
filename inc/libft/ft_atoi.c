/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:48 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/10 07:33:52 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(const char *s, size_t i)
{
	if (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		return (1);
	return (0);
}

static int	issign(const char *s, size_t i, int *p_counter, int *n_counter)
{
	if (s[i] == '-')
	{
		*n_counter += 1;
		return (1);
	}
	if (s[i] == '+')
	{
		*p_counter += 1;
		return (1);
	}
	return (0);
}

static int	isnumber(const char *s, size_t i, int *result)
{
	if (ft_isdigit(s[i]))
	{
		*result = *result * 10 + (s[i] - '0');
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		result;
	int		p_counter;
	int		n_counter;
	size_t	i;

	result = 0;
	p_counter = 0;
	n_counter = 0;
	i = 0;
	while (isspace(nptr, i))
		++i;
	while (issign(nptr, i, &p_counter, &n_counter))
		++i;
	if (n_counter > 1 || p_counter > 1 \
		|| (n_counter >= 1 && p_counter >= 1))
		return (0);
	while (isnumber(nptr, i, &result))
		++i;
	if (n_counter == 1)
		return (-result);
	return (result);
}

// Todo: test
// int	ft_atoi(const char *nptr)
// {
// 	int		result;
// 	int		negative;
// 	size_t	i;

// 	result = 0;
// 	negative = 0;
// 	i = 0;
// 	while (nptr[i] == ' ' 
// 		|| (nptr[i] >= '\t' && nptr[i] <= '\r'))
// 		++i;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 		if (nptr[i++] == '-')
// 			++negative;
// 	while (nptr[i] >= '0' && nptr[i] <= '9')
// 		result = result + 10 * (nptr[i++] - '0');
// 	if (negative)
// 		return (-result);
// 	return (result);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (--ac)
// 	{
// 		printf("ft_atoi: %d\n", ft_atoi(av[i]));
// 		printf("atoi: %d\n---\n", atoi(av[i]));
// 		assert(ft_atoi(av[i]) == atoi(av[i]));
// 		++i;
// 	}
// 	return (0);
// }