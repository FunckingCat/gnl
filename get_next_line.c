/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:39:28 by unix              #+#    #+#             */
/*   Updated: 2021/10/19 18:54:15 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_set_buffer(void)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	return (buff);
}

char	*ft_add(char *src, char *new, size_t len)
{
	char	*res;
	
	res = malloc(ft_strlen(src) + len + 1);
	if (!res)
		return (NULL);
	if (!new)
		return (src);
	if (!src)
		ft_strlcpy(res, new, len + 1);
	else
	{
		ft_strlcpy(res, src, ft_strlen(src) + 1);
		ft_strlcpy(res + ft_strlen(res), new, len + 1);
		free(src);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*buf;
	char	*res;
	int		read_res;

	if (!buffer)
		buffer = ft_set_buffer();
	if (!buffer)
		return (NULL);
	if (!ft_strchr(buf, '\n'))
	{
		res = ft_add(NULL, buf, ft_strlen(buf));
		ft_memset(buffer, 0, BUFFER_SIZE);
		while (1)
		{
			if (read(fd, buffer, BUFFER_SIZE) < 1)
			{
				if (ft_strlen(res) > 0)
					return (ft_add(res, "\n", 1));
				else
					return (NULL);
			}
			if (!ft_strchr(buffer, '\n'))
				res = ft_add(res, buffer, BUFFER_SIZE);
			else
			{
				buf = buffer;
				break ;
			}
		}
	}
	else
		res = NULL;
	res = ft_add(res, buf, ft_strchr(buf, '\n') - buf + 1);
	buf += ft_strchr(buf, '\n') - buf + 1;
	return (res);
}
