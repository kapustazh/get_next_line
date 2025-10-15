/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:08:57 by atvii             #+#    #+#             */
/*   Updated: 2025/10/15 22:35:19 by atvii            ###   ########.fr       */
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

	b_read = 1;
	while (!find_the_n(stash) && b_read != 0)
	{
		temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(temp);
			stash = free_and_null(stash);
		}
		temp[b_read] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	if (stash)
		stash = free_and_null(stash);
	return (stash);
}

char	*extract_line_from_stash(char *stash)
{
	size_t	line_len;
	char	*new_line_ptr;

	if (!stash)
		return (NULL);
	new_line_ptr = find_the_n(stash);
	if (new_line_ptr)
		line_len = (new_line_ptr - stash) + 1;
	else
		line_len = ft_strlen(stash);
	return (ft_substr(stash, 0, line_len));
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
