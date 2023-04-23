/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:40:55 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:40:59 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ray {
	double	tan_ra;
	double	posx;
	double	posy;
	double	ra;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	rx;
	double	ry;
}				t_ray;

typedef struct s_img {
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	char	*add[5];
	int		bits_per_pixel[5];
	int		line_length[5];
	int		endian[5];
}				t_img;

typedef struct s_pdp
{
	double	pa;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camerax;
	double	raydirx;
	double	raydiry;
}				t_pdp;

typedef struct s_flags
{
	int	flag0;
	int	flag1;
	int	flag2;
	int	flag3;
	int	i;
	int	j;
}				t_flag;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_gps
{
	char	*we;
	char	*no;
	char	*so;
	char	*ea;

}				t_gps;

typedef struct s_tool
{
	int		mx;
	int		my;
	int		dis;
	char	**map;
	char	player;
	int		width;
	int		height;
	t_gps	coordin;
	t_rgb	floor;
	t_rgb	ceiling;
	t_pdp	pdp;
	t_img	imgs;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}			t_tool;

#endif
