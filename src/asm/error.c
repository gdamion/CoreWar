/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 13:25:55 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

//here we clean all lists and allocated info
void	free_info(t_data *data)
{

}

void	error(char *err_place, int str_no, int col_no, t_data *data)
{
	//ft_printf("Error: %s, string %d col %d\n", err_place, str_no, col_no);
	print_error(err_place);
	fclose(data->fd); //close file
	free_info(data);
	exit(1);
}

void	errorr(char *err_place, int str_no, int col_no)
{
	//ft_printf("Error: %s, string %d col %d\n", err_place, str_no, col_no);
	// print_error(err_place);
	// fclose(data->fd); //close file
	// free_info(data);
	exit(1);
}
