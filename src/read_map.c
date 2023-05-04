/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:50:57 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 16:00:17 by jhesso           ###   ########.fr       */
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
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			clean_exit(error(3), NULL, NULL);
		i++;
	}
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
	int		ret;
	int		flag;

	if (!validate_filename(file))
		clean_exit(error(6), NULL, NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		clean_exit(error(7), NULL, NULL);
	ret = 1;
	flag = 0;
	buf = ft_calloc(BUFF + 1, sizeof(char));
	if (!buf)
		clean_exit(error(2), NULL, NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF);
		if (ret == -1)
		{
			free (buf);
			if (line)
				free(line);
			clean_exit(error(1), NULL, NULL);
		}
		buf[ret] = '\0';
		if (flag)
			line = ft_strjoin(line, buf);
		else
		{
			line = ft_strdup(buf);
			flag = 1;
		}
	}
	free(buf);
	check_newline(line);
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
