/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:08:57 by atvii             #+#    #+#             */
/*   Updated: 2025/10/15 17:42:16 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*temp;
	ssize_t	b_read;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp || stash)
		return (NULL);
	b_read = 0;
	while (ft_strchr(stash, '\n') && read > 0)
	{
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp);
			free(stash);
			return (NULL);
		}
		temp[b_read] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	free(temp);
	if (stash)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}
char *get_line_from_stash(char *stash)
{
	
}

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
