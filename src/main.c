/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/15 18:26:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	main()
*	runs all of the modules of this program
*/
int	main(int ac, char **av)
{
	char	**map;

	if (ac < 2)
		clean_exit(error(4), NULL, NULL);
	if (ac > 2)
		clean_exit(error(5), NULL, NULL);
	map = read_map(av[1]);
	if (!map)
		clean_exit(error(1), NULL, NULL);
	print_string_arr(map);
	map_validate(map);
}
