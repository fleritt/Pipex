/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:21:52 by rfleritt          #+#    #+#             */
/*   Updated: 2024/12/03 11:13:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	ns;

	i = 0;
	ns = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (ns + 1));
	if (!ptr || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[ns] = '\0';
	return (ptr);
}

/*int main ()
{
	char s1[] = "hola";
	char s2[] = " mundo";
	char *sc = ft_strjoin(s1, s2);

	printf("%s", sc);
	free(sc);
	return (0);
}*/
