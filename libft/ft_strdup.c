/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:01:59 by rfleritt          #+#    #+#             */
/*   Updated: 2024/09/27 11:11:31 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	ns;

	i = 0;
	ns = ft_strlen(s);
	if (s == NULL)
	{
		return (NULL);
	}
	ptr = malloc(ns + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < ns)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main ()
{
    char *str = (char *)ft_strdup("hola");
    printf("%s",str);
    free(str);
    return (0);
}*/
