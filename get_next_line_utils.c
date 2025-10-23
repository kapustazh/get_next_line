/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:08:57 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/17 19:11:00 by mnestere         ###   ########.fr       */
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
		return (free_and_null(stash));
	b_read = 1;
	while (!find_the_n(stash) && b_read > 0)
	{
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(temp);
			return (free_and_null(stash));
		}
		if (b_read == 0)
			break ;
		temp[b_read] = '\0';
		stash = join_and_free(stash, temp);
		if (!stash)
			return (free_and_null(stash));
	}
	free(temp);
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
	size_t	s1_len;

	if (!s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
