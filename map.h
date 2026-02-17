/* -
*  E89 Pedagogical & Technical Lab
*  project: map.h
*  created on:  2026-01-27 - 21:29 +0100
*  1st author:  sacha.juillard
*  description: header for the map file
*/

#ifndef MAP_H_
#define MAP_H_

struct map;

int map_width(const struct map *map);
int map_height(struct map *map);
int is_free(const struct map *map, int x, int y);
int validate_map(struct map *map, int *x, int *y, const char *filename);
int find_start(const struct map *map, int *x, int *y);

#endif
