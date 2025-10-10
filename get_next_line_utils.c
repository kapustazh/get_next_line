/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:08:57 by atvii             #+#    #+#             */
/*   Updated: 2025/10/10 16:55:51 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t	copy_line(int fd, char *buf)
// {
// 	ssize_t	num;
// 	ssize_t	read_status;
// 	char	c;

// 	num = 0;
// 	while (num < BUFFER_SIZE - 1)
// 	{
// 		read_status = read(fd, &c, BUFFER_SIZE);
// 		if (read_status == 1)
// 		{
// 			buf[num] = c;
// 			if (c == '\n')
// 				break ;
// 			num++;
// 		}
// 		else if (read_status == 0)
// 			break ;
// 		else
// 			return (-1);
// 	}
// 	if (num == 0)
// 		return (0);
// 	buf[num] = '\0';
// 	return (num);
// }

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	ptr = result;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (result);
}
