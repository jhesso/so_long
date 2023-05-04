/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:23:13 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 16:24:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	validate_characters()
*	check that the map consists of only allowed characters
*	return 1 if no invalid characters found, 0 otherwise
*/
static int	validate_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && \
				map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*	validate_vertical()
*	check that the top and bottom row only contains '1's
*	returns 1 if true, 0 if not
*/
static int	validate_vertical(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*	validate_shape()
*	checks that the given map is rectangular
*	and is surrounded by the wall char '1'
*	returns 1 if valid, 0 if not
*/
static int	validate_shape(t_map *map)
{
	int		i;

	map->cols = ft_strlen(map->map[0]);
	i = 0;
	if (!validate_vertical(map->map[i]))
		return (0);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != (size_t)map->cols)
			return (0);
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			return (0);
		i++;
	}
	i--;
	if (!validate_vertical(map->map[i]))
		return (0);
	return (1);
}

/*	check_required()
*	checks that the map contains all required components
*	1 Player start, 1 exit and at least 1 collectible
*	returns 1 if everything is found, 0 if not
*/
static int	check_required(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == 'C')
				map->collectibles++;
			else if (map->map[i][j] == 'P')
				map->start++;
			j++;
		}
		i++;
	}
	if (map->exit != 1 || map->start != 1 || map->collectibles < 1)
		return (0);
	return (1);
}

/*	map_validate()
*	validate given map
*	exits program cleanly if errors found
*/
void	map_validate(t_map *map, t_player *player)
{
	int	ret;

	ret = validate_characters(map->map);
	ret *= validate_shape(map);
	ret *= check_required(map);
	map->rows = get_rows(map->map);
	get_coordinates(map, player);
	ret *= flood_fill(map, player->pos, map->coordinate_map);
	if (ret == 0)
		clean_exit(error(3), map->map, NULL);
}
