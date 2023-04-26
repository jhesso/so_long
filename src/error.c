/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:14:45 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/26 15:14:56 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_err(char *err_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putchar_fd('\n', 2);
}

int	error(int err_code)
{
	if (err_code == 1)
		print_err("unkown error");
	else if (err_code == 2)
		print_err("memory allocation failed");
	else if (err_code == 3)
		print_err("map error");
	else if (err_code == 4)
		print_err("no map given");
	else if (err_code == 5)
		print_err("too many arguments");
	else if (err_code == 6)
		print_err("map file should end in .ber");
	else if (err_code == 7)
		print_err("file not found");
	return (err_code);
}

/*	clean_exit()
*	when ran into an error, free all allocated memory, print an error message
*	and cleanly stop running the program
*/
void	clean_exit(int err_code, char **map, t_mlx *mlx)
{
	// free everything
	if (map)
		free(map);
	if (mlx)
		free(mlx);
	exit (err_code);
}