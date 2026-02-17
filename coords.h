/* -
*  E89 Pedagogical & Technical Lab
*  project: coords.h
*  created on:  2026-01-27 - 21:25 +0100
*  1st author:  sacha.juillard
*  description: header for the coords file
*/

#ifndef COORDS_H_
#define COORDS_H_

struct pos;

void get_left_coords(const struct pos *pos, int *lx, int *ly);
void get_front_coords(const struct pos *pos, int *fx, int *fy);

#endif
