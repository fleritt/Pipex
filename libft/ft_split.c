/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:29:19 by rfleritt          #+#    #+#             */
/*   Updated: 2024/10/09 17:13:22 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **ptr, int i);
static size_t	ft_cd(char const *s, char c);
static char		**ft_split_malloc(char const *s, char c, char **split);

static char	**ft_free(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	free(ptr);
	return (NULL);
}

static size_t	ft_cd(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c)))
			j++;
		i++;
	}
	return (j);
}

static char	**ft_split_malloc(char const *s, char c, char **split)
{
	size_t	st;
	size_t	len;
	size_t	i;
	char	*substr;

	i = 0;
	st = 0;
	while (s[st])
	{
		if (s[st] != c && i < ft_cd(s, c))
		{
			len = 0;
			while (s[st + len] && s[st + len] != c)
				len++;
			substr = ft_substr(s, st, len);
			if (!substr)
				return (ft_free(split, i));
			split[i++] = substr;
			st += len;
		}
		else
			st++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc((ft_cd(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_split_malloc(s, c, split));
}

/*int main()
{
	char **result;
	size_t i;
	char str[] = "hola buenas tardes    hola buenas tardes";
	
	i = 0;
	result = ft_split(str, ' ');
	while (result[i])
	{
		printf("%zu %s\n", i, result[i]);
		i++;
	}
	return (0);
}*/
