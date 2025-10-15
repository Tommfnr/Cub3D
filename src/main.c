/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:59:39 by mvachon           #+#    #+#             */
/*   Updated: 2025/10/15 13:07:03 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


#include "mlx.h"
#include <stdlib.h>
#include <math.h>

int key_hook(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
        exit(0);
    return 0;
}
// Met un pixel dans l'image
void put_pixel(char *data, int line_len, int bpp, int x, int y, int color)
{
    char *dst = data + (y * line_len + x * (bpp / 8));
    *(unsigned int *)dst = color;
}

// Ligne simple (Bresenham)
void draw_line(char *data, int line_len, int bpp, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        put_pixel(data, line_len, bpp, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx)  { err += dx; y0 += sy; }
    }
}

int main(void)
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1500, 1000, "Ligne simple");
    void *img = mlx_new_image(mlx, 1500, 1000);

    char *data = mlx_get_data_addr(img, &(int){0}, &(int){0}, &(int){0});
    int bpp, line_len, endian;
    data = mlx_get_data_addr(img, &bpp, &line_len, &endian);
    int i=0;
    mlx_key_hook(win, key_hook, NULL);
    int j = 0;
    while (i < 1000)
    {
        draw_line(data, line_len, bpp, i+ 5, 0, i, j, 0x00FF9851);
        if (i <500)
            j++;
        if (i > 500)
            j--;
        i++;
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
    return 0;
}
