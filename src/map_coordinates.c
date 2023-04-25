/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:12:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/25 16:53:41 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	**allocate_coordinate_map(t_map map)
{
	int	**coordinate_map;
	int	y;

	coordinate_map = malloc(sizeof(int *) * map.rows);
	y = 0;
	while (y < map.rows)
	{
		coordinate_map[y] = malloc(sizeof(int) * map.cols);
		y++;
	}
	return (coordinate_map);
}

/*	parse_map()
*	convert our char **map into a int **map representation
*	0 = empty space
*	1 = wall
*	2 = collectible
*	3 = Exit
*	4 = Player Start
*/
static int	**parse_map(t_map *map, int x, int y)
{
	int	**coordinate_map;

	coordinate_map = allocate_coordinate_map(*map);
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->map[y][x] == '1')
				coordinate_map[y][x] = 1;
			else if (map->map[y][x] == '0')
				coordinate_map[y][x] = 0;
			else if (map->map[y][x] == 'C')
				coordinate_map[y][x] = 2;
			else if (map->map[y][x] == 'E')
				coordinate_map[y][x] = 3;
			else if (map->map[y][x] == 'P')
				coordinate_map[y][x] = 4;
			x++;
		}
		y++;
	}
	return (coordinate_map);
}

/*	get_player_start_location()
*	find the player starting location and save it to our player struct
*/
static void	get_player_start_location(t_player *player, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->coordinate_map[y][x] == 4)
			{
				player->pos.x = x;
				player->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

/*	get_coordinates()
*	parse the char** map into an int** map that we can use as a coordinate map
*	also find the player position on the map and save the coordinates to
*	our player struct
*/
void	get_coordinates(t_map *map, t_player *player)
{
	map->coordinate_map = parse_map(map, 0, 0);
	get_player_start_location(player, map);
	ft_printf("player start x: %d, y: %d\n", player->pos.x, player->pos.y);
}
