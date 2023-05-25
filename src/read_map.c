/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:50:57 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/24 18:54:27 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	validate_filename()
*	validates that the given map file has the .ber file extension
*/
static int	validate_filename(char *file)
{
	if (!ft_strcmp(file + (ft_strlen(file) - 4), ".ber"))
		return (1);
	return (0);
}

/*	check_newline()
*	checks that there are no empty lines in between the map
*/
static void	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			error(3);
		i++;
	}
}

static char	*ft_join(char *line, char *buf)
{
	char	*new_line;

	new_line = ft_strjoin(line, buf);
	free(line);
	return (new_line);
}

static char	*read_file(int fd, char *buf, int flag)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF);
		if (ret == -1)
		{
			free (buf);
			if (line)
				free(line);
			error(8);
		}
		buf[ret] = '\0';
		if (flag)
			line = ft_join(line, buf);
		else
		{
			line = ft_strdup(buf);
			flag = 1;
		}
	}
	free(buf);
	return (line);
}

/*	read_map()
*	reads the given file and saves it into a char**
*/
char	**read_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	char	*buf;

	if (!validate_filename(file))
		error(6);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(7);
	buf = ft_calloc(BUFF + 1, sizeof(char));
	if (!buf)
		error(2);
	line = read_file(fd, buf, 0);
	check_newline(line);
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
