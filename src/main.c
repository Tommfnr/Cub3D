/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:59:39 by mvachon           #+#    #+#             */
/*   Updated: 2025/10/15 11:55:07 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(void)
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "");
    
    int i = ft_strlen("prout");
    printf("i=%d\n", i);
    mlx_key_hook(win, key_hook, NULL);
    mlx_loop(mlx);
    return 0;
}

