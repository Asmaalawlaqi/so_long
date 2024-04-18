/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:25:18 by almedetb          #+#    #+#             */
/*   Updated: 2024/04/17 10:58:42 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map(t_game *game, char *read_map)
{
	int	i;

	i = 0;
	if (read_map[0] == '\n' || read_map[(ft_strlen(read_map) - 1)] == '\n') // Check if the first or last character of the read map is a newline character
		ft_error("Error\n Map not valid!");
	game->map = ft_split(read_map, '\n'); /// Split the read map data into individual lines using newline character as delimiter
	game->w = ft_strlen(game->map[0]);   //// Calculate the width of the game map (number of characters in the first line)

	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != game->w) //if the length of the current line is not equal to the width
			map_error(game, "Error\n Map invalid\n");
	}
	game->h = i; //set the height of the game map 
}

char	*ft_read_map(char *file)
{
	int		fd;
	char	*read_map;
	char	*temp_map;

	read_map = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\n Can't read map\n");
	temp_map = get_next_line(fd);
	if (temp_map == NULL)
		temp_map_error(temp_map, "Error\n Map invalid\n");
	while (temp_map != NULL)
	{
		if (temp_map != NULL && temp_map[0] == '\n')
			temp_map_error(temp_map, "Error\n Map invalid\n");
		read_map = ft_strjoin(read_map, temp_map);
		temp_map = get_next_line(fd);
	}
	if (temp_map != NULL)
		free(temp_map); 
	close (fd);
	return (read_map);
}

void	ft_check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' && file[len - 2] != 'e'
		&& file[len - 3] != 'b' && file[len - 4] != '.')      //check the len of the file and  if its end the  .ber
		ft_error("Error\n Invalid Map\n");
}

void	ft_parsing(t_game *game, char *file)
{
	ft_check_file_extension(file); //
	ft_check_map(game, ft_read_map(file)); // 
	check_walls(game); // 
	game_elements(game); //
	check_map_chars(game);   // 
}
