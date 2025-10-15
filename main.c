/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:59:39 by mvachon           #+#    #+#             */
/*   Updated: 2025/10/15 10:45:05 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlx.h"
#include <stdlib.h>

int key_hook(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
        exit(0);
    return 0;
}

int main(void)
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "Touche ESC pour quitter");
    
    mlx_key_hook(win, key_hook, NULL);
    mlx_loop(mlx);
    return 0;
}

