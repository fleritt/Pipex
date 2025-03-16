/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:31:44 by rfleritt          #+#    #+#             */
/*   Updated: 2024/10/09 15:28:10 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*d;
	char				*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int main ()
{
	char str[10] = "holaa";
	char x[10] = {0};
         ft_memmove(str,str,4); 
    printf("%s\n", str);
    ft_memmove(x,str,3);
    printf("%s\n",x);
	 ft_memmove(str + 4,str,4);
	printf("%s",str);
    return (0);
}*/
