/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almedetb <almedetb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:24:36 by almedetb          #+#    #+#             */
/*   Updated: 2024/01/31 15:29:09 by almedetb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flag_1_moves(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == '0')   // Check for empty space

	{
		game->map[next_y][next_x] = 'P'; //  / Move player to next position
		game->map[game->p_pos_y][game->p_pos_x] = 'E'; //  // Update previous position
		game->flag = 2;
	}
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectible--; //// Decrement count of collectibles
		game->map[next_y][next_x] = 'P'; //   // Move player to collectible position
		game->map[game->p_pos_y][game->p_pos_x] = 'E'; //// Update previous position
		game->flag = 2; //// Update game state flag
	}
	if (game->map[next_y][next_x] == 'E')
	{
		game->map[next_y][next_x] = 'P'; //  // Move player to exit position
		game->map[game->p_pos_y][game->p_pos_x] = 'E';  //// Update previous position
		game->flag = 3; //// Update game state flag
	}
}

void	flag_0_moves(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == '0') //// Check for empty space
	{
		game->map[next_y][next_x] = 'P';  /// Move player to next position
		game->map[game->p_pos_y][game->p_pos_x] = '0'; // // Update previous position
	}
	//// Check for collectible
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectible--; //  // Decrement count of collectibles
		game->map[next_y][next_x] = 'P'; //       // Move player to collectible position                  
		game->map[game->p_pos_y][game->p_pos_x] = '0';  //// Update previous position
	}
}

void	next_move(t_game *game, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = game->p_pos_x + x;   //// Calculate next position
	next_y = game->p_pos_y + y;  //
	if (game->map[next_y][next_x] == '1') //// Check for obstacle
		return ;
	if (game->flag == 0)
		flag_0_moves(game, next_x, next_y); // // Handle movement based on game state flag  //// Handle movement in game state 0
	if (game->flag == 1)  // // Handle movement in game state 1
		flag_1_moves(game, next_x, next_y);
	exiting_game(game, next_x, next_y); // close
	rendering_move(game, next_x, next_y);  // apdait 
	ft_printf("step %d\n", ++(game->steps));   // count the steps
}

int	player_moves(int key, t_game *game)
{
	if (key == 13)
		next_move(game, 0, -1);  // upwards 
	if (key == 1)
		next_move(game, 0, 1); // downwards
	if (key == 0)
		next_move(game, -1, 0); // the lef
	if (key == 2)
		next_move(game, 1, 0); // right 
	if (key == 53)
		closing_window(game);  esc the window
	return (0);
}
