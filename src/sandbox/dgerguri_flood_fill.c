/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dgerguri_flood_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:57:43 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/25 14:57:45 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    flood_fill(t_components *components, t_vector position, char **map)
{
    if (map[position.y][position.x] == '1')
        return (0);
    else if (map[position.y][position.x] == 'E')
        components->exit = 2;
    else if (map[position.y][position.x] == 'C')
        components->C++;
    map[position.y][position.x] = '1';
    flood_fill(components, (t_vector){position.y, position.x + 1}, map);
    flood_fill(components, (t_vector){position.y, position.x - 1}, map);
    flood_fill(components, (t_vector){position.y + 1, position.x}, map);
    flood_fill(components, (t_vector){position.y - 1, position.x}, map);
    if (components->C == components->collectibles && components->exit == 2)
        return (1);
    return (0);
}
