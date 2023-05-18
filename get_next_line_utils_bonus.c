/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:45:13 by fprosper          #+#    #+#             */
/*   Updated: 2023/05/18 17:45:15 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	while (i <= j)
	{
		if (*(s + i) == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	lnstr;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	lnstr = ft_strlen(s1) + ft_strlen(s2) + 1;
	nstr = (char *)malloc(sizeof(char) * lnstr);
	if (!nstr)
		return (NULL);
	ft_memmove(nstr, s1, ft_strlen(s1));
	ft_memmove(nstr + ft_strlen(s1), s2, ft_strlen(s2));
	*(nstr + lnstr - 1) = '\0';
	free(s1);
	return (nstr);
}
