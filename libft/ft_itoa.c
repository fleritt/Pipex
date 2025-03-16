/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:14:48 by rfleritt          #+#    #+#             */
/*   Updated: 2024/10/03 15:44:51 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cn(int long n)
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

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	long int	cn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	cn = ft_cn(n);
	ptr = malloc(sizeof(char) * cn + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[cn] = '\0';
	if (n < 0)
	{
		ptr[i] = '-';
		n *= -1;
		i++;
	}
	while (cn > i)
	{
		ptr[cn - 1] = (n % 10) + '0';
		n /= 10;
		cn--;
	}
	return (ptr);
}

/*int main ()
{
	printf("%s", ft_itoa(0));
	return (0);
}*/
