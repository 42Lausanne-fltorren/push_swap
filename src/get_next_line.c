/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:11 by fltorren          #+#    #+#             */
/*   Updated: 2023/11/27 16:21:03 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp || !tmp[i])
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static void	ft_offset(char *buffer, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
		i++;
	while (tmp[i] != '\0')
	{
		buffer[j] = tmp[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

static char	*ft_free(char *tmp, char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	free(tmp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			res;
	char		*tmp;
	char		*line;

	res = 1;
	tmp = (char *) ft_strdup(buffer);
	if (fd < 0 || BUFFER_SIZE <= 0 || tmp == NULL)
		return (ft_free(tmp, buffer));
	while (res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (ft_free(tmp, buffer));
		buffer[res] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_strchr(tmp, '\n') || tmp == NULL)
			break ;
	}
	line = ft_get_line(tmp);
	ft_offset(buffer, tmp);
	free(tmp);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	line = get_next_line(fd);
	printf("1. %s", line);
	free(line);
	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("2. %s", line);
	free(line);
	close(fd);
	line = get_next_line(fd);
	printf("3. %s", line);
	free(line);
	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("4. %s", line);
	free(line);
	line = get_next_line(fd);
	printf("5. %s", line);
	free(line);
	close(fd);
	return (0);
}
*/
