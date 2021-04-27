# fdf

**Objective**

*In this project you will discover the basics of graphic programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint. You will also discover your first graphic library: miniLibX. This library was developedninternally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse. This project also introduces you to “events” programming. Don’t forget to watch the e-learning videos!*

![screenshot](https://github.com/gutentag1026/fdf/blob/master/FdF_pyramide.png)

1.To run the program, go to fdf folder, do
./fdf maps/42.fdf

2.to run man minilibx, go to root folder
man ./minilibx/man/man1/mlx.1

3.to use the minilibx, you need updated version, don't use the library on subject page

https://github.com/qst0/ft_libgfx 
go to minilibx_macos_sierra folder and create a main.c

```
#include <mlx.h>

int main(void)
{
  void *mlx;
  void *window;
  
  mlx = mlx_init();//establish connection
  window = mlx_new_window(mlx, 1000, 1000, "Title");//width,height,whatever you wanna name your window
  
  mlx_loop(mlx);//takes whatever inputs from the mouse and keyboards and exposes as events and call a function associated with this event
  return (0);
}
```
make the library to get libmlx.a,
and compile it with gcc -Wall -Wextra -Werror libmlx.a -framework OpenGL -framework Appkit main.c
if you put them in separate folder, do 
gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c
-I for header file location, -L for library location, not the file itself -l for lib

4. to compile with lib offered by 42
cc main.c -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit
gcc -Wall -Wextra -Werror -I ./includes -I ./libs/minilibx -I ./libs/libft -L ./libs/minilibx -lmlx -L ./libs/libft -lft -framework OpenGL -framework AppKit ./src/*

5. reference book computer graphics, how to draw line,etc.
http://library.aceondo.net/ebooks/Computer_Science/computer_graphics_textbook.pdf
how to rotate coordinates of a point
![image](https://user-images.githubusercontent.com/16285490/116188459-0522e400-a75a-11eb-8e29-1167fb630006.png)


6.how to compile my read.c file
gcc read.c ./get_next_line/get_next_line.c -L ./libft/ -lft -L ./minilibx_macos/ -lmlx -I ./libft -I ./minilibx_macos -I ./get_next_line/get_next_line.h

gcc ./src/*.c  ./get_next_line/get_next_line.c -L ./libft/ -lft -L ./minilibx_macos/ -lmlx -I ./libft -I ./minilibx_macos -I ./get_next_line/get_next_line.h -I ./fdf.h -I ./minilibx_macos/ -framework OpenGL -framework AppKit

7. to run all maps
for file in test_maps/*.fdf; do ./fdf $file; done
![Alt text](Screen Shot 2018-10-21 at 7.58.34 PM.png "Optional title")
