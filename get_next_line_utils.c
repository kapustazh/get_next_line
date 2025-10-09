/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:08:57 by atvii             #+#    #+#             */
/*   Updated: 2025/10/10 00:21:19 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	copy_line(int fd, char *buf, ssize_t max_len)
{
	ssize_t	num;
	ssize_t	read_status;
	char	c;

	num = 0;
	while (num < max_len - 1)
	{
		read_status = read(fd, &c, 1);
		if (read_status == 1)
		{
			buf[num++] = c;
			if (c == '\n')
				break ;
		}
		else if (read_status == 0)
			break ;
		else
			return (-1);
	}
	if (num == 0)
		return (0);
	buf[num] = '\0';
	return (num);
}
