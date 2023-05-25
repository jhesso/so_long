/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/24 18:53:26 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	main()
*	runs all of the modules of this program
*/
int	main(int ac, char **av)
{
	t_map		map;
	t_player	player;

	if (ac < 2)
		error(4);
	if (ac > 2)
		error(5);
	map.map = read_map(av[1]);
	if (map.map == NULL || map.map[0] == NULL || map.map[0][0] == '\0')
		error(8);
	map_validate(&map, &player);
	game_init(map, player);
	return (0);
}
