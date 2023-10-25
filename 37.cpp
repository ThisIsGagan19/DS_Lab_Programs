#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent a cell in the grid
struct Cell {
    int row, col;
    Cell(int r, int c) : row(r), col(c) {}
};

// Function to check if a cell is valid (within grid boundaries)
bool isValid(int row, int col, int numRows, int numCols) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

int rotOranges(vector<vector<int>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    int freshOranges = 0;
    queue<Cell> rotten;

    // Count the number of fresh oranges and initialize the rotten ones
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] == 2) {
                rotten.push(Cell(i, j));
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }

    int time = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!rotten.empty()) {
        int size = rotten.size();

        for (int i = 0; i < size; i++) {
            Cell curr = rotten.front();
            rotten.pop();

            for (int j = 0; j < 4; j++) {
                int newRow = curr.row + dx[j];
                int newCol = curr.col + dy[j];

                if (isValid(newRow, newCol, numRows, numCols) && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    freshOranges--;
                    rotten.push(Cell(newRow, newCol));
                }
            }
        }

        if (!rotten.empty()) {
            time++;
        }
    }

    return (freshOranges == 0) ? time : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int minTime = rotOranges(grid);

    if (minTime != -1) {
        cout << "Minimum time to rot all oranges: " << minTime << " minutes" << endl;
    } else {
        cout << "It's not possible to rot all oranges." << endl;
    }

    return 0;
}
