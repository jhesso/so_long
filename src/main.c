/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:07:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/12 18:50:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_node_new(char *line)
{
	t_map *node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

t_map	*map_get_tail(t_map *map)
{
	while (map && map->next != NULL)
		map = map->next;
	return (map);
}

void	map_add_back(t_map **map, t_map *node)
{
	t_map	*tail;

	if (node == NULL)
		ft_printf("malloc failed\n");
	if (*map == NULL)
	{
		*map = node;
		return ;
	}
	tail = map_get_tail(*map);
	tail->next = node;
}

t_map	*read_map(char **av)
{
	t_map	*map;
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_printf("error opening file\n");
	line = get_next_line(fd);
	map_add_back(&map, map_node_new(line));
	while (line)
	{
		line = get_next_line(fd);
		map_add_back(&map, map_node_new(line));
	}
	return (map);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac < 2)
		ft_printf("no map given, to run: ./so_long map.ber\n");
	if (ac > 2)
		ft_printf("too many arguments\n");
	map = read_map(av);
	debug_print_map(map);
	return (0);
}
