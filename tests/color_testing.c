#include <stdio.h>

int main(void)
{
    printf("x: %d\n", 0x00FFEEEE);
    printf("x: %d\n", 0x00EECCCC);
    printf("x: %d\n", 0x00FFEEEE - 0x00EECCCC);


    printf("x: %d\n", 0x00DDAAAA);
    printf("x: %d\n", 0x00EECCCC - 0x00DDAAAA);
    printf("x: %d\n", 0x00CC8888);
    printf("x: %d\n", 0x00DDAAAA - 0x00BB6666);
    printf("x: %d\n", 0x00BB6666);
    printf("x: %d\n", 0x00BB6666 - 0x00AA4444);

    printf("x: %d\n", 0x00AA4444);
    printf("x: %d\n", 0x00992222);
    printf("x: %d\n", 0x00880000);

    printf("diff = %d\n", 0x00112222 );



		// if (x < 50)
		// 	color = 0x00FFEEEE; // innner ring
		// else if (x < 100)
		// 	color = 0x00EECCCC;
		// else if (x < 150)
		// 	color = 0x00DDAAAA;
		// else if (x < 200)
		// 	color = 0x00CC8888;
		// else if (x < 250)
		// 	color = 0x00BB6666;
		// else if (x < 300)
		// 	color = 0x00AA4444;
		// else if (x < 350)
		// 	color = 0x00992222;
		// else if (x < 400)
		// 	color = 0x00880000;	// outer most ring

}

// create test function to make a nice color palette when pressing 't'
void	create_colors(t_mlx_data *mlx)
{
	t_image		img;
	int			x;
	int			y;
	int			color;

	img = mlx->img;
	x = 0;
	while (x < mlx->width)
	{
		// note: the diff between the rings is: 0x00112222
		// printf("x: %d\n", x);
		if (x < 50)
			color = 0x00FFEEEE; // innner ring
		else if (x < 100)
			color = 0x00EECCCC;
		else if (x < 150)
			color = 0x00DDAAAA;
		else if (x < 200)
			color = 0x00CC8888;
		else if (x < 250)
			color = 0x00BB6666;
		else if (x < 300)
			color = 0x00AA4444;
		else if (x < 350)
			color = 0x00992222;
		else if (x < 400)
			color = 0x00880000;	// outer most ring -> means out of circle 4
		else
			color = 0x00000000; // inside fractal
		y = 0;
		while (y < mlx->heigth)
		{
			add_pixel(&img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, mlx->img.img_p, 0, 0);
}
