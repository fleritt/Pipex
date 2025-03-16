/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:20:15 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 13:20:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_nbr(int long n)
{
	size_t	j;

	j = 0;
	if (n <= 0)
	{
		n *= -1;
		j++;
	}
	while (n > 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	ft_print_nbr(int n)
{
	int	i;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	i = ft_count_nbr(n);
	if (n < 0)
	{
		ft_print_char('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_print_nbr(n / 10);
		ft_print_char(n % 10 + '0');
	}
	if (n < 10)
		ft_print_char(n % 10 + '0');
	return (i);
}
