/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:37:29 by rfleritt          #+#    #+#             */
/*   Updated: 2024/10/03 16:11:22 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	x;
	size_t	i;

	if (s == NULL)
		return (NULL);
	x = ft_strlen(s);
	if (start >= x)
		return (ft_calloc(1, 1));
	if (x - start < len)
		len = x - start;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main ()
{
	char *str;
	char str2[] = "hola";

	str = ft_substr(str2, 1, 4);
	printf("%s", str);
	return (0);
}*/
