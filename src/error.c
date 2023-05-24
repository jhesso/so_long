/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:14:45 by jhesso            #+#    #+#             */
/*   Updated: 2023/05/24 18:55:49 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	print_err()
*	prints "Error: "
*	and the given error message
*/
static void	print_err(char *err_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putchar_fd('\n', 2);
}

/*	error()
*	prints an error message based on the error code given
*/
void	error(int err_code)
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
	else if (err_code == 8)
		print_err("read failed");
	exit(1);
}
