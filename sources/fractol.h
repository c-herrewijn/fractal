/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 20:06:50 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/09 13:43:53 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <float.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef int	(*t_color_func)(int);

typedef struct s_image
{
	void	*img_p;
	char	*pixel_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_grid
{
	long double	re_min;
	long double	re_max;
	long double	im_min;
	long double	im_max;
}	t_grid;

typedef struct s_cplx
{
	long double	re;
	long double	im;
}	t_cplx;

// fractal_nr 1: Mandelbrot, fractal_nr 2: Julia
typedef struct s_mlx_data
{
	int				width;
	int				heigth;
	int				fractal_nr;
	int				color_func_nr;
	int				color;
	void			*mlx_p;
	void			*win_p;
	t_cplx			julia_coord;
	t_image			img;
	t_grid			grid;
}	t_mlx_data;

t_mlx_data		define_mlx_window(void);
t_grid			define_grid(long double re_min, long double re_max,
					long double im_min, long double im_max);
t_image			define_img(void *mlx_p, int width, int height);
int				mouse_event_handler(int button, int x, int y, t_mlx_data *mlx);
int				key_event_handler(int keycode, t_mlx_data *mlx);
void			add_pixel(t_image *img, int x, int y, int color);
void			calc_fractal(t_mlx_data *mlx);
void			calc_mandelbrot(t_mlx_data *mlx, int (*f_color)(int));
void			calc_julia(t_mlx_data *mlx, int (*f_color)(int), t_cplx c);
void			clear_image(t_mlx_data *mlx);
void			zoom_grid(t_mlx_data *mlx, char direction);
void			move_grid(t_mlx_data *mlx, char direction);
void			pos_zoom_grid(t_mlx_data *mlx, int x, int y, char direction);
int				close_window(t_mlx_data *mlx);
void			set_default_grid(t_mlx_data *mlx);
int				col_mod(int i);
int				col_grad(int i);
int				col_mod_grad(int i);
int				is_valid_julia_coord(char *str);
long double		ft_atof_ld(char *str);
t_cplx			create_julia_cplx(char *str_re, char *str_im);
t_color_func	get_color_func(int i);
void			rotate_color(t_mlx_data *mlx);
void			rotate_fractal(t_mlx_data *mlx);
t_cplx			get_center_coord(t_mlx_data *mlx);
#endif
