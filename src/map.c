/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:50:57 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/14 15:57:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_filename(char *file)
{
	if (!ft_strcmp(file + (ft_strlen(file) - 4), ".ber"))
		return (1);
	return (0);
}

char	**read_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;

	if (!validate_filename(file))
		error(6);
}
