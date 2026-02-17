/*
 * E89 Pedagogical & Technical Lab
 * project:     solve.c
 * created on:  2026-01-27 - 12:00 +0100
 * 1st author:  sacha.juillard
 * description: stores all functions that solve the maze
 */
#include <unistd.h>
#include "coords.h"
#include "direction.h"
#include "map.h"
#include "printers.h"
#include "solve.h"
#include "struct.h"

static int has_reached_goal(const struct map *map, const struct pos *pos)
{
    int idx;

    idx = pos->y * (map->width + 1) + pos->x;
    if (map->buffer[idx] == 'G')
        return 1;
    return 0;
}
static void mark_path(struct map *map, const struct pos *pos)
{
    int idx;

    idx = pos->y * (map->width + 1) + pos->x;
    if (map->buffer[idx] == '.')
        map->buffer[idx] = ' ';
}
static int init_start_pos(const struct map *map, struct pos *pos)
{
    int x;
    int y;

    if (find_start(map, &x, &y) != 0)
        return 1;
    pos->x = x;
    pos->y = y;
    pos->dir = SOUTH;
    return 0;
}
static void solver_step(struct map *map, struct pos *pos)
{
    int lx;
    int ly;
    int fx;
    int fy;

    get_left_coords(pos, &lx, &ly);
    get_front_coords(pos, &fx, &fy);
    if (is_free(map, lx, ly)) {
        turn_left(pos);
        advance(pos);
    } else if (is_free(map, fx, fy)) {
        advance(pos);
    } else {
        turn_right(pos);
    }
}
static void step_and_mark(struct map *map, struct pos *pos)
{
    solver_step(map, pos);
    mark_path(map, pos);
}
int solve_maze(struct map *map)
{
    struct pos pos;
    int        steps;
    int        max_steps;

    if (!map || !map->buffer)
        return 1;
    if (init_start_pos(map, &pos) != 0) {
        write(1, "No start found\n", 15);
        return 1;
    }
    steps = 0;
    max_steps = map->width * map->height * 2;
    while (steps < max_steps) {
        if (has_reached_goal(map, &pos))
            return 0;
        step_and_mark(map, &pos);
        steps += 1;
    }
    print_map(map);
    write(1, "No solution to maze.\n", 21);
    return 1;
}
