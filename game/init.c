#include "cub3d.h"

void	init_struct_game(t_tool *hero)
{
	// hero = malloc(sizeof(t_tool));
	hero->c = 0;
	hero->f = 0;
	hero->index = 0;
	hero->mlx = 0;
	hero->mlx_win = 0;
	hero->no = 0;
	hero->so = 0;
	hero->ea = 0;
	hero->we = 0;
	// hero->game->x = 0;
	// hero->game->y = 0;
}

// void	init_struct_index(t_tool *hero)
// {
// 	hero->index = malloc(sizeof(t_index));
// 	hero->index->index_no = 0;
// 	hero->index->index_so = 0;
// 	hero->index->index_ea = 0;
// 	hero->index->index_we = 0;
// 	hero->index->index_c = 0;
// 	hero->index->index_f = 0;
// }

void	init_struct_img(t_tool *hero)
{
	int	i;

	i = -1;
	hero->imgs = malloc(sizeof(t_img) * 5);
	while (++i < 5)
	{
		hero->imgs[i].ptr = 0;
		hero->imgs[i].img = 0;
		hero->imgs[i].bpp = 0;
		hero->imgs[i].width = 0;
		hero->imgs[i].height = 0;
		hero->imgs[i].size_line = 0;
		hero->imgs[i].endian = 0;
	}
}

void	init_struct_raycasting(t_tool *hero)
{
	// hero->pdp. malloc(sizeof(t_raycasting));
	hero->pdp.perpwalldist = 0;
	hero->pdp.deltadistx = 0;
	hero->pdp.lineheight = 0;
	hero->pdp.deltadisty = 0;
	hero->pdp.sidedistx = 0;
	hero->pdp.sidedisty = 0;
	hero->pdp.drawstart = 0;
	hero->pdp.drawend = 0;
	hero->pdp.camerax = 0;
	hero->pdp.raydirx = 0;
	hero->pdp.raydiry = 0;
	hero->pdp.planex = 0;
	hero->pdp.planey = 0;
	hero->pdp.stepx = 0;
	hero->pdp.stepy = 0;
	hero->pdp.dirx = 0;
	hero->pdp.diry = 0;
	hero->pdp.posx = 0;
	hero->pdp.posy = 0;
	hero->pdp.side = 0;
	hero->pdp.mapx = 0;
	hero->pdp.mapy = 0;
	hero->pdp.hit = 0;
}

void	init_structs(t_tool *hero)
{

	init_struct_raycasting(hero);
	// init_struct_index(hero);
	init_struct_game(hero);
	init_struct_img(hero);
}