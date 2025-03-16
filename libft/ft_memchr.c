/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:59:06 by rfleritt          #+#    #+#             */
/*   Updated: 2024/09/23 18:26:50 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = s;

	while (n--)
	{
		if (*ptr == ((unsigned char)c))
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*int main ()
{
	char *s = "Caracas";

	printf("%s", ft_memchr(s, 'c', 8));
	return (0);
}*/
