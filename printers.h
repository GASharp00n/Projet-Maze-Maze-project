/* -
*  E89 Pedagogical & Technical Lab
*  project: printers.h
*  created on:  2026-01-27 - 21:29 +0100
*  1st author:  sacha.juillard
*  description: header for the printers file
*/

#ifndef PRINTERS_H_
#define PRINTERS_H_

struct map;

int  print_base10(int nb);
void print_start_coords(int x, int y);
void print_map_size(const struct map *map);
void print_map(const struct map *map);

#endif
