/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:18:21 by fprosper          #+#    #+#             */
/*   Updated: 2023/05/18 17:43:30 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_nstr_stc(char *str_stc)
{
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	while (str_stc[len] != '\n' && str_stc[len] != '\0')
		len++;
	if (!str_stc[len])
	{
		free(str_stc);
		return (NULL);
	}
	tmp = malloc(sizeof(char ) * ft_strlen(str_stc) - len + 1);
	if (!str_stc)
		return (NULL);
	i = 0;
	while (str_stc[len + 1 + i] != '\0')
	{
		tmp[i] = str_stc[len + 1 + i];
		i++;
	}
	tmp[i] = '\0';
	free(str_stc);
	return (tmp);
}

char	*get_line(char *str_stc)
{
	char	*str_tr;
	int		len;
	int		i;

	i = 0;
	if (!str_stc[i])
		return (NULL);
	len = 0;
	while (str_stc[len - 1] != '\n' && str_stc[len] != '\0')
		len++;
	str_tr = malloc(sizeof(char) * len + 1);
	if (!str_tr)
	{
		free(str_stc);
		return (NULL);
	}
	while (i < len)
	{
		str_tr[i] = str_stc[i];
		i++;
	}
	str_tr[i] = '\0';
	return (str_tr);
}

char	*get_file(char *str_stc, int fd)
{
	char	*tmp;
	size_t	c_read;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	c_read = 1;
	while (ft_strchr(str_stc, '\n') == NULL && c_read != 0)
	{
		c_read = read(fd, tmp, BUFFER_SIZE);
		if ((int) c_read == -1)
		{
			if (str_stc)
				free(str_stc);
			free(tmp);
			return (NULL);
		}
		tmp[c_read] = '\0';
		str_stc = ft_strjoin(str_stc, tmp);
	}
	free(tmp);
	return (str_stc);
}

char	*get_next_line(int fd)
{
	static char	*str_stc[4096];
	char		*str_tr;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str_stc[fd] = get_file(str_stc[fd], fd);
	if (!str_stc[fd])
		return (NULL);
	str_tr = get_line(str_stc[fd]);
	str_stc[fd] = get_nstr_stc(str_stc[fd]);
	return (str_tr);
}
