/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:20:20 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/01/27 20:12:56 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp_s;
	long	whole_bites;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 0;
		size = 1;
	}
	if (INT_MAX / size < nmemb)
		return (0);
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (0);
	whole_bites = (long)(nmemb * size);
	tmp_s = ptr;
	while (whole_bites-- > 0)
		*tmp_s++ = 0;
	return (ptr);
}

char	*gnl_parse_buff(char *buff, long length)
{
	char	*head;
	long	first_nl;
	long	count;

	count = length;
	while (count < BUFFER_SIZE + 1)
		buff[count++] = '\0';
	if (ft_strchr(buff, '\n') == NULL)
	{
		head = ft_strdup(buff);
		count = 0;
		while (count < BUFFER_SIZE + 1)
			buff[count++] = '\0';
		return (head);
	}
	first_nl = ft_strchr(buff, '\n') - buff + 1;
	head = (char *) gnl_calloc((first_nl + 2), sizeof(char));
	if (head == NULL)
		return (NULL);
	ft_strlcpy(head, buff, first_nl + 1);
	ft_strlcpy(buff, buff + first_nl, BUFFER_SIZE - first_nl + 1);
	return (head);
}

char	*load_lines(long fd, char *buff)
{
	char	*line;
	char	*temp;
	char	*head;
	long	read_len;

	line = ft_strdup(buff);
	read_len = (long) read(fd, buff, BUFFER_SIZE);
	if (read_len < 0 || buff[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	while (ft_strchr(buff, '\n') == NULL && read_len == BUFFER_SIZE)
	{
		temp = line;
		line = ft_strjoin(temp, buff);
		free(temp);
		read_len = (long)read(fd, buff, BUFFER_SIZE);
	}
	head = gnl_parse_buff(buff, read_len);
	temp = line;
	line = ft_strjoin(temp, head);
	free(temp);
	free(head);
	return (line);
}

char	*get_next_line(long fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	if (!buff)
		buff = (char *) gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	if (ft_strchr(buff, '\n') != NULL)
		line = gnl_parse_buff(buff, BUFFER_SIZE);
	else
		line = load_lines(fd, buff);
	if (!line)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	return (line);
}

/*
int main(int argc, char** argv)
{
	int 	fd;
	char	*return_line = "";
	int 	count = 0;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while (read(fd, 0, 0) >= 0
		&& return_line != NULL)
	{
		return_line = get_next_line(fd);
		printf(" -Line %i	: %s\n", count, return_line);
		free(return_line);
	}
	return (0);
}
*/
