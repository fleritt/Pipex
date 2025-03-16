/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:15:23 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 11:15:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_format(char const str, va_list args)
{
	if (str == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (str == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_print_mem(va_arg(args, unsigned long long)));
	else if (str == 'd' || str == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (str == 'u')
		return (ft_print_unsig(va_arg(args, unsigned int)));
	else if (str == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (str == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (str == '%')
		return (ft_print_char('%'));
	else
		return (ft_print_char('%'), ft_print_char(str));
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			size += ft_check_format(str[i], args);
		}
		else
		{
			size += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (size);
}

/*int main (void)
{
	int i;
	int x;
	int y;
	char *h = "hola";
	char n = 'h';
	char *p = 0;

	i = 123456789;
	x = ft_printf("esta es mi funcion: %p, %c\n", h, n);
	y = printf("esta es mi funcion: %p, %c\n", h, n);
	printf("%d %d", x, y);
	return (0);
}*/