/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:33:27 by rfleritt          #+#    #+#             */
/*   Updated: 2024/09/26 14:40:55 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s;

	i = 0;
	j = 0;
	s = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0')
		j++;
	if (size == 0 || i >= size)
		return (size + j);
	while (src[s] != '\0' && i + s < size - 1)
	{
		dst[i + s] = src[s];
		s++;
	}
	if (i < size)
		dst[i + s] = '\0';
	return (i + j);
}

/*int main()
{
    char d[20] = "hola";
    char s[20] = "buenas";
    int valor;
//    int valor2;

    valor = ft_strlcat(d,s,2);
//    valor2 = strlcat(d,s,20);
    printf("%d\n", valor);
//    printf("%d", valor2);
    return (0);
}*/
