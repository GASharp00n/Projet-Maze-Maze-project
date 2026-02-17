/*
 * E89 Pedagogical & Technical Lab
 * project: file.c
 * created on:  2026-01-27 - 11:42 +0100
 * 1st author:  sacha.juillard
 * description: function read file that reads the map using stat
 * to read any size of map
 */
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "file.h"

char *read_file(const char *filename)
{
    int fd;
    char *buffer;
    struct stat st;

    if (lstat(filename, &st) != 0)
        return 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return 0;
    buffer = malloc(st.st_size + 1);
    if (!buffer) {
        close(fd);
        return 0;
    }
    if (read(fd, buffer, st.st_size) != st.st_size) {
        free(buffer);
        close(fd);
        return 0;
    }
    buffer[st.st_size] = '\0';
    close(fd);
    return buffer;
}
