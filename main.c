/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:42 by unix              #+#    #+#             */
/*   Updated: 2021/10/20 15:09:40 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fp;
	char	*line;
	int		i = 0;

	fp = open("./text", 'r');
	if (!fp)
	{
		printf("FILE NAME IST HERE BRO\n");
		exit(0);
	}
	line = get_next_line(fp);
	while (line)
	{
		printf("%d. %s\n", 1 + i++, line);
		free(line);
		line = get_next_line(fp);
	}
	free(line);
	close(fp);
	sleep(200000);
	return (1);
}

// com()
// {
//     gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c && a.out
// }
