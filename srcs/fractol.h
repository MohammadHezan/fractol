/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:32:23 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/14 00:42:18 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>  
# include <unistd.h> 
# include <math.h>
# include "../minilibx_linux/mlx.h"

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

# define XK_Escape 65307
# define XK_Left 65361
# define XK_Right 65363
# define XK_Up 65362
# define XK_Down 65364
# define XK_plus 65451
# define XK_minus 65453
# define XK_equal 61
# define XK_underscore 45

# define Button5 5
# define Button4 4

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3

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
    double          julia_real;
    double          julia_imag;
}					t_fractol;

int         handle_mouse(int mouse_button, int mouse_x, int mouse_y, t_fractol *fractol);
int         close_window(t_fractol *fractol);
int         handle_keypress(int keycode, t_fractol *fractol);

void        error(void);
void        init_fractol(t_fractol *fractol);
void        events_init(t_fractol *fractol);
void        image_data(t_fractol *fractol);
double      map(double num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum(t_complex z1, t_complex z2);
t_complex   square(t_complex z);
void        mandel_julia(t_complex *z, t_complex *c, t_fractol *fractol);
void	    handle_pixel(int real, int imag, t_fractol *fractol);
int	        fractol_render(t_fractol *fractol);
void	    imag_pixel_put(int real, int imag, t_image *img, int color);
int         ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
