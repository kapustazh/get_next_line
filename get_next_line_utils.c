/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:08:57 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/27 20:23:54 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_null(char *stash)
{
	free(stash);
	return (NULL);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*temp;
	ssize_t	b_read;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
	{
		free(stash);
		return (NULL);
	}
	b_read = 1;
	while (!find_the_n(stash) && b_read != 0)
	{
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (free_and_null(temp));
		}
		temp[b_read] = '\0';
		stash = join_and_free(stash, temp);
		if (!stash)
			return (stash = NULL, free_and_null(temp));
	}
	free(temp);
	return (stash);
}

char	*extract_line_from_stash(char *stash)
{
	size_t	line_len;
	char	*new_line_ptr;
	char	*line_to_return;

	if (!stash)
		return (NULL);
	new_line_ptr = find_the_n(stash);
	if (new_line_ptr)
		line_len = (new_line_ptr - stash) + 1;
	else
		line_len = ft_strlen(stash);
	if (line_len == 0)
		return (NULL);
	line_to_return = ft_substr(stash, 0, line_len);
	if (!line_to_return)
		return (NULL);
	return (line_to_return);
}

char	*find_the_n(const char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}
