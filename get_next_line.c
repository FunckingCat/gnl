/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:39:28 by unix              #+#    #+#             */
/*   Updated: 2021/10/27 13:19:33 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_move_to_nl(char	*rd)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!rd)
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (!rd[i])
	{
		free(rd);
		return (0);
	}
	res = malloc(sizeof(char) * ((ft_strlen(rd) - i) + 1));
	if (!res)
		return (0);
	i++;
	while (rd[i])
		res[j++] = rd[i++];
	res[j] = '\0';
	free(rd);
	return (res);
}

char	*ft_getres(char *rd)
{
	char	*res;
	int		i;

	i = 0;
	if (rd[i] == '\0')
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	ft_memmove(res, rd, i);
	if (rd[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_get_buffer(int fd, char *buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;
	char	*tmp;

	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
		{
			break ;
		}
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	res = ft_getres(buffer);
	buffer = ft_move_to_nl(buffer);
	return (res);
}
