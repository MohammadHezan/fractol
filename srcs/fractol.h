/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:32:23 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 20:55:10 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>  
# include <unistd.h> 
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800

# define BLACK       0x000000  
# define WHITE       0xFFFFFF  
# define GREEN       0x00FF00  
# define BLUE        0x0000FF  

# define MAGENTA_BURST   0xFF00FF  
# define LIME_SHOCK      0xCCFF00  
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066  
# define AQUA_DREAM      0x33CCCC  
# define HOT_PINK        0xFF66B2  
# define ELECTRIC_BLUE   0x0066FF  
# define LAVA_RED        0xFF3300

typedef struct s_complex
{
    double			real;
    double			imag;
}					t_complex;

typedef struct	s_image
{
	void	*img_ptr; 
	char	*pixels_ptr; 
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;

typedef struct s_fractol
{
    void			*mlx;
    void			*win;
    t_image 		img;
    int				max_iter;
    double			zoom;
    double			offset_x;
    double			offset_y;
    t_complex		c;
    char			*name;
    int                escape;
}					t_fractol;

int         handle_mouse(int button, int x, int y, t_fractol *fractol);
int         close_window(t_fractol *fractol);
int         handle_keypress(int keycode, t_fractol *fractol);
void        fractal_render(t_fractol *fractol);
void        error(void);
void        init_fractol(t_fractol *fractol);
void        events_init(t_fractol *fractol);
void        image_data(t_fractol *fractol);
double      map(double num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum(t_complex z1, t_complex z2);
t_complex   square(t_complex z);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);
void        mandel_julia(t_complex *z, t_complex *c, t_fractol *fractol);
void	handle_pixel(int real, int imag, t_fractol *fractol);
void	fractol_render(t_fractol *fractol);
void	imag_pixel_put(int real, int imag, t_image *img, int color);

#endif
