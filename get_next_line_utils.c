/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:39:28 by unix              #+#    #+#             */
/*   Updated: 2021/10/19 18:02:59 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c % 256)
			return ((char *)s);
		s++;
	}
	if (*s == c % 256)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	if (!s)
		return (0);
	while (*s++)
		res++;
	return (res);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	n;

	n = 0;
	if (src == NULL)
	{
		*dst = '\0';
		return (0);
	}
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (*src && --size > 0 && n++ > -1)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(src - n));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	int			buff_size;

	d = dst;
	s = src;
	n = 0;
	buff_size = ft_strlen(src) + ft_strlen(dst);
	if (size < ft_strlen(dst))
		buff_size = ft_strlen(src) + size;
	while (*d && n++ < size)
		d++;
	if (n >= size)
		return (buff_size);
	while (*s)
	{
		if (n++ + 1 >= size)
			break ;
		*d++ = *s++;
	}
	*d = '\0';
	return (buff_size);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char			*temp;
	unsigned char	m;

	m = (unsigned char)c;
	temp = (char *)b;
	while (len > 0)
	{
		*temp = m;
		temp++;
		len--;
	}
	return (b);
}
