/*
 * E89 Pedagogical & Technical Lab
 * project:     direction.c
 * created on:  2026-01-27 - 11:38 +0100
 * 1st author:  sacha.juillard
 * description: functions to turn and advance depending on directions
 */
#include "direction.h"
#include "struct.h"

void turn_left(struct pos *pos)
{
    pos->dir = (pos->dir + 3) % 4;
}
void turn_right(struct pos *pos)
{
    pos->dir = (pos->dir + 1) % 4;
}
void advance(struct pos *pos)
{
    if (pos->dir == NORTH) {
        pos->y -= 1;
    } else if (pos->dir == SOUTH) {
        pos->y += 1;
    } else if (pos->dir == EAST) {
        pos->x += 1;
    } else {
        pos->x -= 1;
    }
}
