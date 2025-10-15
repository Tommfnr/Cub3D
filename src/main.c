#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data;
    int     bpp;
    int     line_len;
    int     endian;
    int     x;
}   t_data;

void put_pixel(char *data, int line_len, int bpp, int x, int y, int color)
{
    char *dst;
    
    if (x < 0 || x >= 1500 || y < 0 || y >= 1000)
        return;
    dst = data + (y * line_len + x * (bpp / 8));
    *(unsigned int *)dst = color;
}

void draw_line(char *data, int line_len, int bpp, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1)
    {
        put_pixel(data, line_len, bpp, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx)  { err += dx; y0 += sy; }
    }
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307) /* ESC */
        exit(0);
    if (keycode == 119)   /* W */
        data->x++;
    if (keycode == 115)   /* S */
        data->x--;
    return 0;
}

int loop_hook(t_data *data)
{
    int img_size;
    int i;
    int j;
    
    img_size = data->line_len * 1000;
    memset(data->data, 0, img_size);
    
    i = 0;
    j = 0;
    while (j < 500)
    {
        draw_line(data->data, data->line_len, data->bpp, i, j, 1500, j, 0x00FF9851);
        draw_line(data->data, data->line_len, data->bpp, i, j + 500, 1500, j + 500, 0x00FF65354);
        j++;
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return 0;
}

int main(void)
{
    t_data data;

    // char map[5][5] = {
    //     {1, 1, 1, 1, 1},
    //     {1, 0, 0, 0, 1},
    //     {1, 0, 0, 0, 1},
    //     {1, 0, 'N', 0, 1},
    //     {1, 1, 1, 1, 1}
    // };


    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1500, 1000, "Ligne simple");
    data.img = mlx_new_image(data.mlx, 1500, 1000);
    data.data = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    data.x = 0;

    mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
    mlx_loop_hook(data.mlx, loop_hook, &data);
    mlx_loop(data.mlx);
    
    return 0;
}