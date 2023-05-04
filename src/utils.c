/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/04 16:00:44 by jhesso           ###   ########.fr       */
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
