/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:58:28 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:58:29 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int key, t_tool *hero)
{
	// hero->pdp.pa = 90;
	// if (key == 0 || key == 123)
	// {
	// 	move_a(hero);
	// }
	// else if (key == 1 || key == 125)
	// {
	// 	move_s(hero);
	// }
	// else if (key == 2 || key == 124)
	// {
	// 	move_d(hero);
	// }
	if (key == 13 || key == 126)
	{
		move_w(hero);
	}
	else if (key == 53)
	{
		exit(0); //exit_game(hero);
	}
	return (0);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	check_nwse(t_tool *hero)
{
	int	n;

	n = 1;
	if (hero->pdp.side == 1 && hero->pdp.raydiry < 0)
		n = 3;
	else if (hero->pdp.side == 1 && hero->pdp.raydiry > 0)
		n = 4;
	else if (hero->pdp.side == 0 && hero->pdp.raydirx > 0)
		n = 2;
	else if (hero->pdp.side == 0 && hero->pdp.raydirx < 0)
		n = 1;
	return (n);
}

int	ft_texx(t_tool *hero, int n)
{
	int		texx;
	double	wallx;

	wallx = 0.0;
	if (hero->pdp.side == 0)
		wallx = hero->pdp.posy + hero->pdp.perpwalldist \
		* hero->pdp.raydiry;
	else
		wallx = hero->pdp.posx + hero->pdp.perpwalldist \
		* hero->pdp.raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)hero->imgs[n].width);
	if (hero->pdp.side == 0 && hero->pdp.raydirx > 0)
		texx = hero->imgs[n].width - texx - 1;
	if (hero->pdp.side == 1 && hero->pdp.raydiry < 0)
		texx = hero->imgs[n].width - texx - 1;
	return (texx);
}

int	draw_walls(t_tool *hero, char *dest, char *dest_2, int texx)
{
	double	step;
	double	texpos;
	int		texy;
	int		i;
	int		n;

	(void)texy;
	n = check_nwse(hero);
	i = hero->pdp.drawstart;
	texx = (int)ft_texx(hero, n);
	step = 1.0 * hero->imgs[n].width / hero->pdp.lineheight;
	texpos = (hero->pdp.drawstart - HEIGHT / 2 + \
	hero->pdp.lineheight / 2) * step;
	while (i < hero->pdp.drawend)
	{
		texy = (int)texpos & hero->imgs[n].width;
		texpos += step;
		dest = hero->imgs[0].img + (i * hero->imgs[0].size_line + \
		hero->index * (hero->imgs[0].bpp / 8));
		dest_2 = hero->imgs[n].img + ((int)texpos * \
		hero->imgs[n].size_line + texx * (hero->imgs[n].bpp / 8));
		*(int *)dest = *(int *)dest_2;
		i++;
	}
	return (0);
}

void	draw_floor_and_celling(t_tool *hero, char *dest)
{
	int	i;

	i = -1;
	while (++i < HEIGHT / 2)
	{
			dest = hero->imgs[0].img + (i * hero->imgs[0].size_line + \
			hero->index * hero->imgs[0].bpp / 8);
			*(int *)dest = hero->c;
	}
	while (++i < HEIGHT)
	{
			dest = hero->imgs[0].img + (i * hero->imgs[0].size_line + \
			hero->index * hero->imgs[0].bpp / 8);
			*(int *)dest = hero->f;
	}
}

void	norm_init_win_3(t_tool *hero)
{
	if (hero->pdp.side == 0)
		hero->pdp.perpwalldist = (hero->pdp.sidedistx - \
		hero->pdp.deltadistx);
	else
		hero->pdp.perpwalldist = (hero->pdp.sidedisty - \
		hero->pdp.deltadisty);
	hero->pdp.lineheight = (int)(HEIGHT / \
	hero->pdp.perpwalldist);
	hero->pdp.drawstart = -hero->pdp.lineheight / \
	2 + HEIGHT / 2;
	if (hero->pdp.drawstart < 0)
		hero->pdp.drawstart = 0;
	hero->pdp.drawend = hero->pdp.lineheight / 2 + HEIGHT / 2;
	if (hero->pdp.drawend >= HEIGHT)
		hero->pdp.drawend = HEIGHT - 1;
	draw_floor_and_celling(hero, 0);
	draw_walls(hero, 0, 0, 0);
}

void	norm_init_win_2(t_tool *hero)
{
	hero->pdp.hit = 0;
	while (hero->pdp.hit == 0)
	{
		if (hero->pdp.sidedistx < hero->pdp.sidedisty)
		{
			hero->pdp.sidedistx += hero->pdp.deltadistx;
			hero->pdp.mapx += hero->pdp.stepx;
			hero->pdp.side = 0;
		}
		else
		{
			hero->pdp.sidedisty += hero->pdp.deltadisty;
			hero->pdp.mapy += hero->pdp.stepy;
			hero->pdp.side = 1;
		}
		if (hero->map[hero->pdp.mapx] \
		[hero->pdp.mapy] != '0')
			hero->pdp.hit = 1;
	}
	norm_init_win_3(hero);
}

void	norm_init_win(t_tool *hero)
{
	if (hero->pdp.raydiry < 0)
	{
		hero->pdp.stepy = -1;
		hero->pdp.sidedisty = (hero->pdp.posy - \
		hero->pdp.mapy) * hero->pdp.deltadisty;
	}
	else
	{
		hero->pdp.stepy = 1;
		hero->pdp.sidedisty = (hero->pdp.mapy + 1.0 - \
		hero->pdp.posy) * hero->pdp.deltadisty;
	}
	norm_init_win_2(hero);
}

void	continue_init_win(t_tool *hero)
{
	if (hero->pdp.raydirx == 0)
		hero->pdp.deltadistx = 1e30;
	else
		hero->pdp.deltadistx = ft_abs(1 / hero->pdp.raydirx);
	if (hero->pdp.raydiry == 0)
		hero->pdp.deltadisty = 1e30;
	else
		hero->pdp.deltadisty = ft_abs(1 / hero->pdp.raydiry);
	if (hero->pdp.raydirx < 0)
	{
		hero->pdp.stepx = -1;
		hero->pdp.sidedistx = (hero->pdp.posx - \
		hero->pdp.mapx) * hero->pdp.deltadistx;
	}
	else
	{
		hero->pdp.stepx = 1;
		hero->pdp.sidedistx = (hero->pdp.mapx + 1.0 - \
		hero->pdp.posx) * hero->pdp.deltadistx;
	}
	norm_init_win(hero);
}

void	init_win(t_tool *hero)
{
	(void)hero;
	int	i;

	i = 0;
	// find_pos_player(hero);
	hero->imgs[0].ptr = mlx_new_image(hero->mlx, WIDTH, HEIGHT);
	hero->imgs[0].img = mlx_get_data_addr(hero->imgs[0].ptr, \
	&hero->imgs[0].bpp, &hero->imgs[0].size_line, &hero->imgs[0].endian);
	get_addr(hero);
	while (i < WIDTH)
	{
		hero->index = i;
		hero->pdp.camerax = 2 * i / (double)WIDTH - 1;
		hero->pdp.raydirx = hero->pdp.dirx + \
		hero->pdp.planex * hero->pdp.camerax;
		hero->pdp.raydiry = hero->pdp.diry + \
		hero->pdp.planey * hero->pdp.camerax;
		hero->pdp.mapx = (int)hero->pdp.posx;
		hero->pdp.mapy = (int)hero->pdp.posy;
		continue_init_win(hero);
		i++;
	}
	mlx_put_image_to_window(hero->mlx, hero->mlx_win, \
	hero->imgs[0].ptr, 0, 0);
}

void	game(t_tool *hero)
{
	// char	*addr;
	// char	dst;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;

	// hero.pdp.dirx = -1;
	// hero.pdp.diry = 0;
		// printf("hello/n");
	// hero->pdp.planex = 0;
	// hero->pdp.planey = 0.66;
	// hero->pdp.time = 0;
	// hero->pdp.oldtime = 0;
	// hero->angle = 60.0 / 1000;
	//map_to_window(hero-> hero->mlx, mlx_win);
	// hero->pdp.dirx = cos(hero->pdp.pa);
	// hero->pdp.diry = -1 * sin(hero->pdp.pa);
	// printf("%f\n", hero->pdp.diry);
	init_structs(hero);
	// hero->mlx = mlx_init();
	// hero->mlx_win = mlx_new_window(hero->mlx, WIDTH, HEIGHT, "Cub3D");
	xpm_to_image(hero);
	init_win(hero);
	// hero->img = mlx_new_image(hero->mlx, 1000, 512);
			// printf("%f\n", hero->angle);

	// mlx_pixel_put(hero->mlx, hero->mlx_win, hero->pdp.posx, hero->pdp.posy, 0x00FF0000);
	// mlx_hook(hero->mlx_win, 17, 0, exit_game, hero);
	// mlx_hook(hero->mlx_win, 2, 0, move_player, hero);
	// mlx_loop_hook(hero->mlx, start, hero);
	mlx_loop(hero->mlx);
}