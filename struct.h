/* -
*  E89 Pedagogical & Technical Lab
*  project: struct.h
*  created on:  2026-01-27 - 21:31 +0100
*  1st author:  sacha.juillard
*  description: header containing all structs and enum
*/

#ifndef STRUCT_H_
#define STRUCT_H_

enum dir {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

struct map {
    char    *buffer;
    int     width;
    int     height;
};

struct pos {
    int         x;
    int         y;
    enum dir    dir;
};

#endif
