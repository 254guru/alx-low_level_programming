#!/usr/bin/python3
"""
function def island_perimeter(grid):
that returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
    - grid: A list of lists of integers where
    0 represents water and 1 represents land.

    Returns:
    - The perimeter of the island.

    Constraints:
    - Grid cells are connected horizontally/vertically (not diagonally).
    - Grid is rectangular, with a width and height not exceeding 100.
    - Grid is completely surrounded by water,
    and there is one island (or nothing).
    - The island doesn't have "lakes" (water inside that isn't
    connected to the water around the island).
    """
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4  # Start with 4 sides for a land cell

                # Check adjacent cells (up, down, left, and right)
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1  # Remove one side
                if i < len(grid) - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < len(grid[i]) - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter
