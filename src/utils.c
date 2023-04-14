/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:57:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/04/14 16:21:47 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int err_code)
{
	if (err_code == 1)
		print_err("unkown error");
	else if (err_code == 2)
		print_err("memory allocation failed");
	else if (err_code == 3)
		print_err("map error");
	else_if (err_code == 4)
		print_err("");
	else_if (err_code == 5)
		print_err("");
	else_if (err_code == 6)
		print_err("");
}
