/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:45:55 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/09/09 12:51:05 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "./libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ROTRIGHT 65363
# define ROTLEFT 65361
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define TABSIZE 8

typedef struct s_iso_res {
	float	x;
	float	y;
	float	z;
}		t_iso_res;

typedef struct s_color {
	float	c0;
	float	c1;
	float	step;
}		t_color;

enum e_texEnum{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_teximg {
	void	*img;
	int		*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_teximg;

typedef struct s_data {
	void			*mlx;
	void			*mlx_win;
	void			*img;
	int				w_img;
	int				h_img;
	char			*addr;
	int				bpp;
	int				line_l;
	int				endian;
	int				w_map;
	int				h_map;
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			camera_x;
	float			raydir_x;
	float			raydir_y;
	int				map_x;
	int				map_y;
	float			deltadistx;
	float			deltadisty;
	float			sidedistx;
	float			sidedisty;
	float			perpwalldist;
	int				hit;
	int				side;
	int				stepx;
	int				stepy;
	char			dir;
	float			fov;
	int				lineheight;
	int				drawstart;
	int				drawend;
	float			floorcolor;
	float			ceilingcolor;
	int				dirwall;
	int				tex_w;
	int				tex_h;
	int				**tex;
	float			wallhit;
	int				tex_x;
	int				tex_y;
	float			tex_step;
	float			tex_pos;
	int				left;
	int				right;
	int				up;
	int				down;
	int				rotleft;
	int				rotright;
	t_teximg		no_ptr;
	t_teximg		so_ptr;
	t_teximg		we_ptr;
	t_teximg		ea_ptr;
	char			**rgb;
	char			**generic;
	char			**elements;
	char			**file_map;
	char			**map_cp;
	char			**map_flood;
	char			*line;
	void			*no_vptr;
	void			*so_vptr;
	void			*we_vptr;
	void			*ea_vptr;
	char			*file;
	int				file_size;
	int				bg_line;
	int				bg_column;
	int				p_spawn;
	int				p_posx;
	int				p_posy;
	int				map_start;
	int				magic[6];
	unsigned char	f_r;
	unsigned char	f_g;
	unsigned char	f_b;
	unsigned char	c_r;
	unsigned char	c_g;
	unsigned char	c_b;
}		t_data;

typedef struct s_copy
{
	int		*i;
	int		*j;
	bool	r_wall;
	char	*src;
	char	*dst;
}		t_copy;

// --> draw_utils.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			check_limits(t_data *img, int x, int y);
void		draw_points(t_data *img, t_iso_res res0, t_iso_res res1, t_color c);

// --> free.c
void		ft_free_table(char **table);
void		ft_free_data_print_exit(t_data *data, char *msg);
void		ft_free_data(t_data *data);
void		ft_free_tex(t_data *data);

// --> general.c
bool		ft_abs_compare(char *s1, char *s2);
bool		ft_is_line_space(char *str);
bool		ft_reach_map(char *str);
bool		ft_element_done(int *table);
char		*ft_first_last_line(char *line, int size);

// --> general_2.c
int			ft_real_size(char *str);
void	ft_print_map(char **map);

// --> init_1.c
void		init_data_pointers(t_data *data);
void		init_data_structure(t_data *data, char *file);
void		init_dir_e_w(t_data *data);
void		init_dir_n_s(t_data *data);
void		init_dir(t_data *data);

// --> init_2.c
void		init_data(t_data	*data);
void		init_tex(t_data *img);
int			*get_addr_tex_img(t_data *img, t_teximg *dir_ptr);

// --> keys.c
int			check_keys_press(int key, t_data *img);
int			check_keys_release(int key, t_data *img);
int			deal_key_press(int key, void *data);
int			deal_key_release(int key, void *data);

// --> keys_aux.c
void		op_move_release(int key, t_data *img);
void		op_move_press(int key, t_data *img);

// --> main.c
int			ft_close(t_data *vars);
int			render_next_frame(t_data *data);

// --> map_copy.c
void		ft_handle_map_cp(t_data *data);

// --> move_player.c
void		rotate_vec(t_data *img, int side);
void		move_for_back_vec(t_data *img, int side);
void		move_right_left_vec(t_data *img, int side);
void		check_wall_hit(t_data *img, float tmp_x, float tmp_y);
int			op_move(t_data *img);

// --> raycast_1.c
void		draw_raycaster(t_data *img);
void		calc_vert_line_draw(t_data *img);
void		update_tex(t_data *img, int h);
void		draw_tex(t_data *img, int x);

// --> raycast_2.c
float		get_color_rgb(int R, int G, int B);
void		get_wall_dir(t_data *img);
void		dda_algorithm(t_data *img);
void		config_dda(t_data *img);
void		init_ray(t_data *img, int x);

// --> validation.c
void		ft_check_fd(t_data *data);
void		ft_check_map_extension(t_data *data, const char *extension);
void		ft_map_start_line(t_data *data);
void		ft_validation(t_data *data);

// --> validation_element.c
void		ft_check_map_elements(t_data *data);
void		ft_check_value_elements(t_data *data);

//--> validation_image.c
void		*ft_load_image(t_data *data, char *file);
void		ft_validation_fc_rgb(t_data *data);

// --> validation_map.c
void		ft_check_map_size(t_data *data, int fd);
void		ft_check_map_tiles(t_data *data);
void		ft_copy_table(t_data *data);
void		ft_flood_fill(t_data *data, int x, int y, char *elements);

#endif
