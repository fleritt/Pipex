/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:34:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 13:34:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_nbr(int long n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		j++;
	while (n > 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	ft_print_unsig(unsigned int n)
{
	int	i;

	i = ft_count_nbr(n);
	if (n >= 10)
	{
		ft_print_unsig(n / 10);
		ft_print_char(n % 10 + '0');
	}
	if (n < 10)
		ft_print_char(n % 10 + '0');
	return (i);
}
