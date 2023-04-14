/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/14 15:53:21 by jhesso           ###   ########.fr       */
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
		error(4);
	if (ac > 2)
		error(5);
	map = read_map(av[1]);
	if (!map)
		error(1);

}
