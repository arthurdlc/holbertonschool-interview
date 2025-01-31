#ifndef SANDPILES_H
#define SANDPILES_H

/**
 * File: sandpiles.h
 * Description: Header file containing function prototypes
 * for sandpiles operations.
 */

void print_grid_sandpile(int grid[3][3]);
int is_stable(int grid[3][3]);
void toppling_round(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
