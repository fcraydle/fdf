/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:46:53 by fcraydle          #+#    #+#             */
/*   Updated: 2019/05/22 12:43:38 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_new_line(int fd, char **line, int ret, char **mem)
{
	char	*tmp;
	int		i;

	i = 0;
	while (mem[fd][i] != '\n' && mem[fd][i] != '\0')
		i++;
	if (mem[fd][i] == '\n')
	{
		*line = ft_strsub(mem[fd], 0, i);
		tmp = ft_strdup(mem[fd] + i + 1);
		free(mem[fd]);
		mem[fd] = tmp;
	}
	else if (mem[fd][0] == '\0')
		ft_strdel(&mem[fd]);
	else if (mem[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(mem[fd]);
		ft_strdel(&mem[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*mem[10000];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (mem[fd] == 0)
			mem[fd] = ft_strnew(1);
		tmp = ft_strjoin(mem[fd], buff);
		ft_strdel(&mem[fd]);
		mem[fd] = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (ft_strchr(mem[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (mem[fd] == 0 || mem[fd][0] == 0))
		return (0);
	return (ft_get_new_line(fd, line, ret, mem));
}
