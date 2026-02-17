/* -
*  E89 Pedagogical & Technical Lab
*  project: direction.h
*  created on:  2026-01-27 - 21:26 +0100
*  1st author:  sacha.juillard
*  description: header for the direction file
*/

#ifndef DIRECTION_H_
#define DIRECTION_H_

struct pos;

void turn_left(struct pos *pos);
void turn_right(struct pos *pos);
void advance(struct pos *pos);

#endif
