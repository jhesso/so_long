/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 17:11:30 by jhesso           ###   ########.fr       */
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
		clean_exit(error(4), NULL, NULL);
	if (ac > 2)
		clean_exit(error(5), NULL, NULL);
	map.map = read_map(av[1]);
	if (map.map == NULL || map.map[0] == NULL || map.map[0][0] == '\0')
		clean_exit(error(8), NULL, NULL);
	map_validate(&map, &player);
	game_init(map, player);
	return (0);
}
