/*
 * E89 Pedagogical & Technical Lab
 * project:     coords.c
 * created on:  2026-01-27 - 11:29 +0100
 * 1st author:  sacha.juillard
 * description: functions that store the coordinates
 */
#include "coords.h"
#include "struct.h"

void get_left_coords(const struct pos *pos, int *lx, int *ly)
{
    *lx = pos->x;
    *ly = pos->y;
    if (pos->dir == NORTH) {
        *lx -= 1;
    } else if (pos->dir == SOUTH) {
        *lx += 1;
    } else if (pos->dir == EAST) {
        *ly -= 1;
    } else if (pos->dir == WEST) {
        *ly += 1;
    }

}
void get_front_coords(const struct pos *pos, int *fx, int *fy)
{
    *fx = pos->x;
    *fy = pos->y;
    if (pos->dir == NORTH) {
        *fy -= 1;
    } else if (pos->dir == SOUTH) {
        *fy += 1;
    } else if (pos->dir == EAST) {
        *fx += 1;
    } else if (pos->dir == WEST) {
        *fx -= 1;
    }
}
