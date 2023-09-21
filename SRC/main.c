/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/21 18:01:21 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char c)
{
	if (c == 'f')
		ft_printf("Smalleh, ERROR !\nCause : wrong format of text file\n");
	else if (c == 'i')
		ft_printf("Smalleh, ERROR !\nCause : image can't download\n");
	else if (c == 'l')
		ft_printf("Smalleh, ERROR !\nCause : the MinilibX is fucked up\n");
	else if (c == 'w')
		ft_printf("Smalleh, ERROR !\nCause : the window is fucked up\n");
	else if (c == 'm')
		ft_printf("Smalleh, ERROR !\nCause : Wrong map bitch\n");
	else if (c == 'a')
		ft_printf("Smalleh, ERROR !\nCause : Wrong number of arguments\n");
	else if (c == 'o')
		ft_printf("Smalleh, ERROR !\nCause : opening of fd failed\n");
	else if (c == 'c')
		ft_printf("Smalleh, ERROR !\nCause : opening of fd failed\n");
	else
		return (0);
	return (1);
}

void	free_map(int i, char **map)
{
	while (i >= 0)
	{
		free(map[i]);
		--i;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	t_datas *datas;
	char	*lib;

	datas = malloc(sizeof(t_datas));
	if (datas == NULL)
		exit(1);
	datas->map = malloc(sizeof(t_map));
    if (datas->map == NULL)
    {
        free(datas);
        exit(1);
    }
	if (argc != 2)
		return (ft_error('f'));
	if (check_format_ber(argv[1]) != 0)
		return (ft_error('f'));
	lib = argv[1];
	datas->map->map = convert_ber(lib);
	count_map(datas->map);
	map_init(datas);
	return (0);
}
