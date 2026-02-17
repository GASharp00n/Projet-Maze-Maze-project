/*
 * E89 Pedagogical & Technical Lab
 * project:     printers.c
 * created on:  2026-01-27 - 11:58 +0100
 * 1st author:  sacha.juillard
 * description: printing functions for the map and positions
 */
#include <unistd.h>
#include "printers.h"
#include "struct.h"


int print_base10(int nb)
{
    char digits[10];
    int i;
    int count;
    int n;

    i = 0;
    count = 0;
    if (nb < 0) {
        write(1, "-", 1);
        nb = 0 - nb;
        count = count + 1;
    }
    n = nb;
    if (n == 0)
        return write(1, "0", 1) + count;
    while (n > 0) {
        digits[i] = (n % 10) + '0';
        n = n / 10;
        i = i + 1;
    }
    while (i > 0) {
        i = i - 1;
        write(1, &digits[i], 1);
        count = count + 1;
    }
    return count;
}
void print_start_coords(int x, int y)
{
    write(1, "Start: (", 8);
    print_base10(x);
    write(1, ", ", 2);
    print_base10(y);
    write(1, ")\n", 2);
}
void print_map_size(const struct map *map)
{
    write(1, "width: ", 7);
    print_base10(map->width);
    write(1, ", height: ", 10);
    print_base10(map->height);
    write(1, "\n", 1);
}
void print_map(const struct map *map)
{
    int i;

    if (!map || !map->buffer)
        return;
    i = 0;
    while (map->buffer[i]) {
        write(1, &map->buffer[i], 1);
        i += 1;
    }
    write(1, "\n", 1);
}
