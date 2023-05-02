/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:40:07 by tyenokya          #+#    #+#             */
/*   Updated: 2023/04/23 16:40:09 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define POSSIBCHARS "01WNSE"
# define SPACES  " \n\t"
# define CHARS  "01NSWE"
# define HERO  "NSWE"
# define PI 3.14159
# define RD 0.0174533
# define WIDTH 1024
# define HEIGHT 512
# define MOVE_SPEED 0.2

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "structs.h"
# include <mlx.h>
// # include "./mlxopengl/mlx.h"

t_tool	parser(char *path);
void	check_path(char *path);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		ft_strrchr(char *s, char c);
char	*ft_strchr(char *s, int c);
char	**read_file(char *path);
int		is_digit(char c);
int		is_space(char c);
int		count_com(char *str, int i);
char	**ft_split(char const *s, char c);
char	*ft_substr(char *s, int start, int len);
int		ft_atoi(char *str);
int		is_corr_texture(char *s, int i);
void	ft_free_matrix(char **matr);
int		get_map_height(char **info);
int		get_map_width(char **info);
void	check_info(char **info);
void	check_map(char **info);
void	exit_false_text_param(void);
void	exit_false_map_form(void);
void	exit_false_map(void);
t_tool	init_hero(char **info);
void	dupes(char **info);
void	check_count(char **info);
void	*ft_calloc(size_t count, size_t size);
t_gps	init_coordin(char **info);
t_rgb	init_colors(char **info, char c);
char	*get_texture(char *info);
void	ignor_space(char *info, int	*i);
void	game(t_tool *hero);
void	draw_map(t_tool *hero);
double	deg_to_rad(double degr);
void	move_a(t_tool *hero);
void	move_s(t_tool *hero);
void	move_d(t_tool *hero);
void	move_w(t_tool *hero);
char	get_sym(int mx, int my, t_tool *hero);
void	put_sym(int mx, int my, t_tool *hero, char c);
void	print_hero(t_tool hero);
double		fix_angle(double a);
void	xpm_to_image(t_tool *hero);
double	ray_dist(t_ray *ray);
int     start(t_tool *hero);
double degToRad(int a);
void	create_map(t_tool *hero);
void	raycasting(t_tool *hero, t_ray *ray);
void	draw_line(t_tool *hero, int i);
int		exit_game(t_tool *hero);
int		create_trgb(int r, int g, int b);
void	get_addr(t_tool *hero);
void	init_structs(t_tool *hero);


#endif
