/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:10:57 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/28 14:47:32 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Extracts substring from string s starting at position start with length len
 Handles edge cases: NULL string, start beyond string length */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/* Joins stash and temp into new string, frees old stash
   Returns NULL and frees stash if malloc fails */
char	*join_and_free(char *stash, char *temp)
{
	char	*new_stash;

	new_stash = ft_strjoin(stash, temp);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (new_stash);
}

/* Removes extracted line from stash, keeps only data after newline
   Returns NULL if no newline found (last line was read) */
char	*clean_stash(char *stash)
{
	int		i;
	char	*remaining_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	remaining_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (remaining_stash);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Reads one line from file descriptor fd
   Returns line with newline if present, NULL at EOF or error
   Supports multiple file descriptors simultaneously (bonus) */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (stash[fd] = NULL, NULL);
	line = extract_line_from_stash(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		lines_read;

// 	fd = open("test2.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);

// 	lines_read = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 		if (lines_read == 5)
// 		{
// 			while ((line = get_next_line(fd)) != NULL)
// 				free(line);
// 			break ;
// 		}
// 	}
// 	close(fd);
// 	return (0);
// }