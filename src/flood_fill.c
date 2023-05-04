/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:52:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 15:51:13 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	flood_fill()
*	I use the flood fill algorithm to check if there is a valid path on the map
*	returns -1 if no valid path is found and 1 if one is found
*/
int	flood_fill(t_map *map, t_vector player, int **coord_map)
{
	if (coord_map[player.y][player.x] == 1)
		return (0);
	else if (coord_map[player.y][player.x] == 3)
		map->exit = 2;
	else if (coord_map[player.y][player.x] == 2)
		map->c++;
	coord_map[player.y][player.x] = 1;
	flood_fill(map, (t_vector){player.x + 1, player.y}, coord_map);
	flood_fill(map, (t_vector){player.x - 1, player.y}, coord_map);
	flood_fill(map, (t_vector){player.x, player.y + 1}, coord_map);
	flood_fill(map, (t_vector){player.x, player.y - 1}, coord_map);
	if (map->c == map->collectibles && map->exit == 2)
		return (1);
	return (0);
}
