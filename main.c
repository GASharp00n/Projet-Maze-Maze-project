/*
 * E89 Pedagogical & Technical Lab
 * project:     main.c
 * created on:  2026-01-27 - 11:45 +0100
 * 1st author:  sacha.juillard
 * description: main that calls all functions to print and solve the map
 */
#include <stdlib.h>
#include "map.h"
#include "printers.h"
#include "solve.h"
#include "struct.h"

int main(int argc, char **argv)
{
    struct map map;
    int x;
    int y;

    if (argc != 2)
        return 1;
    if (validate_map(&map, &x, &y, argv[1]) != 0)
        return 1;
    print_start_coords(x, y);
    print_map_size(&map);

    if (solve_maze(&map) == 0)
        print_map(&map);
    free(map.buffer);
    return 0;
}
