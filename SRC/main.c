/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/29 10:45:53 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_datas *datas, char *lib)
{
	datas->img = NULL;
	datas->is_exit = false;
	datas->yes_exit = false;
	datas->check_exit = false;
	datas->nbr_exit = 0;
	datas->nbr_of_collect = 0;
	datas->collect_cpy = 0;
	datas->nbr_of_moves = 0;
	datas->nbr_of_player = 0;
	datas->map = NULL;
	datas->map = malloc(sizeof(t_map));
	if (datas->map == NULL)
	{
		free(datas->map);
		free(datas);
		exit(1);
	}
	datas->map->map = NULL;
	datas->map->map = convert_ber(lib, datas);
}

void	check_arg(int argc, char *lib, t_datas *datas)
{
	if (argc != 2)
	{
		ft_putstr(ERROR_ARG);
		free(datas);
		exit(1);
	}
	if (check_format_ber(lib) != 0)
	{
		ft_putstr(ERROR_FILE);
		free(datas);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_datas	*datas;
	char	*lib;

	lib = argv[1];
	datas = malloc(sizeof(t_datas));
	if (datas == NULL)
	{
		free(datas);
		exit(1);
	}
	check_arg(argc, lib, datas);
	init_variables(datas, lib);
	check_map(datas);
	dupmap_init(datas);
	map_init(datas);
	return (0);
}
