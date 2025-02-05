/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:36 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/05 20:26:26 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit("Erorr\nFailed to open file\n");
	tmp = ft_strdup("");
	line = get_next_line(fd);
	printf("File opened\n");

	while (line != NULL)
	{
		tmp = join_strings(tmp, line);
		if (line != NULL)
			free(line);
		line = get_next_line(fd);
	}
	if (check_double_nl(tmp) == 0)
		error_exit("Error\nInvalid map\n");
	close(fd);
	map = ft_split(tmp, '\n');
	free(tmp);
	return (map);
}

void	check_map_validity(t_game *game)
{
	if (check_walls(game) == 0)
		error_exit("Error\nInvalid map\n");
	if (game->rows < 3 || game->columns < 3)
		error_exit("Error\nInvalid map\nMap is too small\n");
	if (check_elements(game) == 0)
		error_exit("Error\nInvalid elements\n");
	if (check_invalid_chars(game) == 0)
		error_exit("Error\nMap contains invalid characters\n");
	if (check_valid_path(game) == 0)
		error_exit("Error\nInvalid map, exit inaccessible\n");
}

t_point	find_player(char **map, char c)
{
	t_point	coords;
	int		i;
	int		j;

    coords.x = 0;
    coords.y = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				coords.x = j;
				coords.y = i;
				return (coords);
			}
		}
	}
	return (coords);
}

int	check_double_nl(char *map)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			count++;
	}
	if (count == 0)
		return (1);
	return (0);
}