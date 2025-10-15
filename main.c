/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:59:39 by mvachon           #+#    #+#             */
/*   Updated: 2025/10/15 10:00:37 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();                        // Initialiser la MLX
    win = mlx_new_window(mlx, 800, 600, "Ma Fenetre"); // Créer une fenêtre 800x600

    mlx_loop(mlx);                           // Boucle d'événement
    return (0);
}
