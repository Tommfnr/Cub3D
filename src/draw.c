/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:04:08 by marvin            #+#    #+#             */
/*   Updated: 2025/10/15 16:04:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void put_pixel(char *data, int line_len, int bpp, int x, int y, int color)
{
    char *dst;
    
    if (x < 0 || x >= 1500 || y < 0 || y >= 1000)
        return;
    dst = data + (y * line_len + x * (bpp / 8));
    *(unsigned int *)dst = color;
}

void draw_background(char *data, int line_len, int bpp, int width, int height)
{
    int x;
    int y;
    
    y = 0;
    while (y < height / 2)
    {
        x = 0;
        while (x < width)
        {
            put_pixel(data, line_len, bpp, x, y, 0x87CEEB);
            x++;
        }
        y++;
    }
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            put_pixel(data, line_len, bpp, x, y, 0xD3D3D3 );
            x++;
        }
        y++;
    }
}

void draw_line(char *data, int line_len, int bpp, int x0, int y0, int x1, int y1, int color)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    
    err = dx - dy;
    while (1)
    {
        put_pixel(data, line_len, bpp, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
