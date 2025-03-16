/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:04:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 13:04:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert_mem(unsigned long long n)
{
	if (n >= 16)
	{
		ft_convert_mem(n / 16);
		ft_convert_mem(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_char(n + '0');
		else
			ft_print_char(n - 10 + 'a');
	}
}

int	ft_print_mem(unsigned long long n)
{
	int	i;

	if (n == 0)
		return (ft_print_str("(nil)"));
	ft_print_str("0x");
	if (n != 0)
		ft_convert_mem(n);
	i = 2;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}
