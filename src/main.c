/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/24 17:28:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	main()
*	runs all of the modules of this program
*/
int	main(int ac, char **av)
{
	t_map	map;

	if (ac < 2)
		clean_exit(error(4), NULL, NULL);
	if (ac > 2)
		clean_exit(error(5), NULL, NULL);
	map.map = read_map(av[1]);
	if (!map.map)
		clean_exit(error(1), NULL, NULL);
	print_string_arr(map.map);
	map = map_validate(map);
	ft_printf("rows: %d\ncols: %d\nexit: %d\nstart: %d\ncollectibles: %d\n", map.rows, map.cols, map.exit, map.start, map.collectibles);
}
