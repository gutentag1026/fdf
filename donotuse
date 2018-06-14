#include "mlx.h"

typedef struct s_grid
{
	int		increment_w;
	int 	increment_h;
}			   t_grid;

t_grid	 *grid(int *h, int *w, int *grid_w, int *grid_h)
{
	t_grid	*increment;
	increment = (t_grid *)malloc(sizeof(t_grid)); 
	increment->increment_w = *grid_w / *w;
	increment->increment_h = *grid_h / *h;
	return(increment);
}
int main(void)
{
  void *mlx;
  void *window;
  int	h;
  int	w;
  int	increment_h;
  int	increment_wumn;
  
  h = 300;;
  w = 300;
  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 1000, "Super FDF");
  while (w <= 600)
  {
  	h = 300;
  	while (h++ <= 600)
  	{ 
	 	 mlx_pixel_put(mlx, window, w, h, 0xFFFFFF);
  	}
	w += 50;
  }	

  h = 300;
  w = 300;
 
  while (h <= 600)
  {
  	w = 300;
  	while (w++ <= 600)
  	{ 
	 	 mlx_pixel_put(mlx, window, w, h, 0xFFFFFF);
  	}
	h += 50;
  }	
 /* h = 300;
  w = 350;
  while (h++ <= 600)
  { 
	  mlx_pixel_put(mlx, window, w, h, 0xFFFFFF);
  }
 h = 300;
  w = 300;
  while (w <= 800)
  { 
	  while(h <= 400)
	{
	  	mlx_pixel_put(mlx, window, w, h, 0xFFFFFF);
	  	h += 5;
  	}
	  h = 300;		  
	  mlx_pixel_put(mlx, window, w, h, 0xFFFFFF);
	  w += 20;
  }
 */
  
  mlx_loop(mlx);
  return (0);
}
