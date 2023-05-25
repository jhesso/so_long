/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/25 11:52:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	get_rows()
*	calcualtes the amount of rows in our map
*/
int	get_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_map(char **map, int **coordinate_map)
{
	int	i;

	i = 0;
	while (map[i] && map)
	{
		free(map[i]);
		i++;
	}
	i = 0;
	while (coordinate_map[i] && coordinate_map)
	{
		free(coordinate_map[i]);
		i++;
	}
	free(map);
	free(coordinate_map);
}
