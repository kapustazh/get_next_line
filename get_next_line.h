/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:09:00 by atvii             #+#    #+#             */
/*   Updated: 2025/10/15 22:34:20 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// max count of fd's
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*find_the_n(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*extract_line_from_stash(char *stash);
char	*read_and_stash(int fd, char *stash);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*free_and_null(char *stash);
size_t	ft_strlen(const char *s);
char	*clean_stash(char *stash);

#endif