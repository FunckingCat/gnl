/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:39:28 by unix              #+#    #+#             */
/*   Updated: 2021/10/18 21:08:08 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_set_buffer(void)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE] = '\0';
	return (buff);
}

int	ft_read_buff(int fd, char *buff, int size)
{
	return (0);
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
	static char	*res;

	if (!buffer)
		buffer = ft_set_buffer();
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buf, '\n')) // пока в буффере нет /n читаем в результат
	{
		printf("Нет \\n, копирую буфер\n");
		if (read(fd, buffer, BUFFER_SIZE) < 1)
			return (NULL);
		printf("Скопировал\n");
		if (!ft_strchr(buffer, '\n'))
		{
			printf("Скопировал вот буфер - {%s}\n", buffer);
			res = ft_add(res, buffer, BUFFER_SIZE);
			printf("И в результат записал - {%s}\n", res);
		}
		else
			printf("Нашел, ничего не пишу\n");
		buf = buffer;
	}
	printf("\\n есть надо скопировать до него - {%s}\n", buf);
	res = ft_add(res, buf, ft_strchr(buf, '\n') - buf + 1);
	printf("Скопировал - {%s}\n", res);
	buf += ft_strchr(buf, '\n') - buf + 1;
	printf("Теперь буф - {%s}\n", buf);
	return (res);
}
