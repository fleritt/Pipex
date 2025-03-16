/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:49:44 by rfleritt          #+#    #+#             */
/*   Updated: 2024/09/27 12:56:46 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;
	size_t	ns;
	size_t	i;

	i = 0;
	if (num != 0 && size >= SIZE_MAX / num)
		return (NULL);
	ns = num * size;
	ptr = (char *)malloc(ns);
	if (ptr == NULL)
		return (NULL);
	while (i < ns)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*int main ()
{
    char *str = (char *)ft_calloc(10, 20);
    printf("%s",str);
    free(str);
    return (0);
}*/
