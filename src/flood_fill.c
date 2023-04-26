/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:52:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 19:46:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	flood_fill()
*	I use the flood fill algorithm to check if there is a valid path on the map
*	returns -1 if no valid path is found and 1 if one is found
*
*	what we need to do
*	1. find the player start position on the map
*	2. check each direction starting from above
*	3. if we run into a wall, return negative
*	4. if it is a valid place to move, start all over again from that spot (first move up, then right, down and left)
*		if non of those spots are valid, go back to the starting position and move to the next spot (right in the first case)
*	5. keep checking all valid spots until:
*		- we have found all collectibles and the exit on the map
*		- we have checked all possible moves on the map and have not found all collectibles/exit
*	6. return 1 if we found a valid path (all collectibles and the exit), 0 if we did not
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
