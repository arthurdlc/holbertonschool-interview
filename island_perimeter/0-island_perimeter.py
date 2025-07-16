#!/usr/bin/python3
"""
0-isalnd_perimeter
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Start with 4 sides
                perimeter += 4

                # Check top
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # shared edge with top cell

                # Check left
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # shared edge with left cell

    return perimeter
