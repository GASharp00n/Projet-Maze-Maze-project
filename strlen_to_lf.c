/*
 * E89 Pedagogical & Technical Lab
 * project:     strlen_to_lf.c
 * created on:  2026-01-27 - 11:58 +0100
 * 1st author:  sacha.juillard
 * description: strlen function rewritten
 */
#include "strlen_to_lf.h"

unsigned int strlen_to_lf(const char *str)
{
    unsigned int i;

    i = 0;
    while (str[i] && str[i] != '\n') {
        i += 1;
    }
    return i;
}
