/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 17:27:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (!map.map)
		clean_exit(error(1), NULL, NULL);
	map_validate(&map, &player);
	print_string_arr(map.map);
	game_init(map, player);
	return (0);
}
