/*
 * E89 Pedagogical & Technical Lab
 * project:     map.c
 * created on:  2026-01-27 - 12:00 +0100
 * 1st author:  sacha.juillard
 * description: file that stores the map related functions
 */

#include <stdlib.h>
#include "file.h"
#include "map.h"
#include "strlen_to_lf.h"
#include "struct.h"

int is_free(const struct map *map, int x, int y)
{
    int idx;

    if (!map || !map->buffer)
        return 0;
    if (x < 0 || y < 0)
        return 0;
    if (x >= map->width || y >= map->height)
        return 0;
    idx = y * (map->width + 1) + x;
    if (map->buffer[idx] == '#')
        return 0;
    return 1;
}

int map_width(const struct map *map)
{
    int width;
    int line_length;
    int index;

    if (!map || !map->buffer || !map->buffer[0])
        return -1;
    index = 0;
    width = strlen_to_lf(map->buffer);
    while (map->buffer[index]) {
        line_length = strlen_to_lf(&map->buffer[index]);
        if (line_length != width)
            return -1;
        index += line_length;
        if (map->buffer[index] == '\n')
            index += 1;
    }
    return width;
}

int map_height(struct map *map)
{
    int i;
    int height;

    if (!map || !map->buffer)
        return -1;
    i = 0;
    height = 0;
    while (map->buffer[i]) {
        if (map->buffer[i] == '\n')
            height += 1;
        i += 1;
    }
    if (i > 0 && map->buffer[i - 1] != '\n')
        height += 1;
    map->height = height;
    return height;
}

int find_start(const struct map *map, int *x, int *y)
{
    int         idx;
    struct pos  pos;

    pos.y = 0;
    while (pos.y < map->height) {
        pos.x = 0;
        while (pos.x < map->width) {
            idx = pos.y * (map->width + 1) + pos.x;
            if (map->buffer[idx] == 'S') {
                *x = pos.x;
                *y = pos.y;
                return 0;
            }
            pos.x += 1;
        }
        pos.y += 1;
    }
    return 1;
}

int validate_map(struct map *map, int *x, int *y, const char *filename)
{
    map->buffer = read_file(filename);
    if (!map->buffer)
        return 1;
    map->width = map_width(map);
    map->height = map_height(map);
    if (map->width < 0 || map->height < 0) {
        free(map->buffer);
        return 1;
    }
    if (find_start(map, x, y) != 0) {
        free(map->buffer);
        return 1;
    }
    return 0;
}

