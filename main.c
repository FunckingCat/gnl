/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:36:42 by unix              #+#    #+#             */
/*   Updated: 2021/10/18 20:52:39 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fp;
	char	*line;

	fp = open("./text1", 'r');
	if (!fp)
	{
		printf("FILE NAME IST HERE BRO\n");
		exit(0);
	}
	line = get_next_line(fp);
	printf("%s\n--------------------\n", line);
	// line = get_next_line(fp);
	// printf("%s\n--------------------\n", line);
	// line = get_next_line(fp);
	// printf("%s\n--------------------\n", line);
	// while (line)
	// {
	// 	printf("%s", line);
	// 	line = get_next_line(fp);
	// }
	close(fp);
	return (1);
}

// com()
// {
//     gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c && a.out
// }
