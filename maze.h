#ifndef SOLVER_H_
#define SOLVER_H_

typedef enum e_dir {
    NORTH,
    EAST,
    SOUTH,
    WEST
}   e_dir;
typedef struct s_map {
    char    *buffer;
    int     width;
    int     height;
}   s_map;
typedef struct s_pos {
    int     x;
    int     y;
    e_dir   dir;
}   s_pos;
int             solve_maze(s_map *map);
int             map_width(const char *map);
int             map_height(s_map *map);
void            print_map(const s_map *map);
int             is_free(const s_map *map, int x, int y);
void            get_left_coords(const s_pos *pos, int *lx, int *ly);
void            get_front_coords(const s_pos *pos, int *fx, int *fy);
void            turn_left(s_pos *pos);
void            turn_right(s_pos *pos);
void            advance(s_pos *pos);
int             print_base10(int nb);
char            *read_file(const char *filename);
unsigned int    strlen_to_lf(const char *str);
void print_start_coords(int x, int y);
void print_map_size(const s_map *map);
int validate_map(s_map *map, int *x, int *y, const char *filename);
int find_start(const s_map *map, int *x, int *y);
#endif
