#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int fr, fc;
int totalPaths;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int row, int col) {
    if (row == fr && col == fc) {
        totalPaths++;
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nr = row + dr[d];
        int nc = col + dc[d];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C
            && grid[nr][nc] == 0 && !visited[nr][nc]) {
            visited[nr][nc] = true;
            dfs(nr, nc);
            visited[nr][nc] = false; // backtrack
        }
    }
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    int sr, sc;
    cin >> sr >> sc >> fr >> fc;

    visited.assign(R, vector<bool>(C, false));
    totalPaths = 0;

    visited[sr][sc] = true;
    dfs(sr, sc);

    cout << totalPaths << endl;

    return 0;
}