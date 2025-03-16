/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:23:28 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 16:23:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert_hex(unsigned int n, unsigned int word)
{
	if (n >= 16)
	{
		ft_convert_hex(n / 16, word);
		ft_convert_hex(n % 16, word);
	}
	else
	{
		if (n < 10)
			ft_print_char(n + '0');
		else
		{
			if (word == 0)
				ft_print_char(n - 10 + 'a');
			else
				ft_print_char(n - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int n, unsigned int word)
{
	int	i;

	if (n == 0)
		return (ft_print_char('0'));
	else
		ft_convert_hex(n, word);
	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}
