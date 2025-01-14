/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** loop_bis
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

int loose(char **boat)
{
    int nb_hit = 0;
    int y = 2;

    for (; boat[y] != NULL; y++)
        for (int x = 0; boat[y][x] != 0; x++)
            if (boat[y][x] == 'x')
                nb_hit += 1;
    if (nb_hit == 14)
        return (-1);
    else
        return 0;
}

int second_loop(int **pos, char *rd, char ***enemy)
{
    int fire;

    pos[0] = transform_input(rd, pos[0]);
    fire = send_all(pos[0], pos[2][0]);
    *enemy = update_enemy_board(*enemy, fire, pos[0]);
    usleep(10000);
    free(rd);
    if (loose(*enemy) == -1)
        return (-1);
    return (0);
}
