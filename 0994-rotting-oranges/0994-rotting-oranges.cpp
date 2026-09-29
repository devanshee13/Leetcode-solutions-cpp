class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> rotten;

        // Step 1: Count fresh oranges
        // and put all initially rotten oranges in queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        int minutes = 0;

        // Step 2: BFS minute by minute
        while (!rotten.empty() && fresh > 0) {

            int size = rotten.size();

            // Process only oranges rotten at start of this minute
            for (int i = 0; i < size; i++) {

                int r = rotten.front().first;
                int c = rotten.front().second;

                rotten.pop();

                // UP
                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    fresh--;
                    rotten.push({r - 1, c});
                }

                // DOWN
                if (r + 1 < n && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    fresh--;
                    rotten.push({r + 1, c});
                }

                // LEFT
                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    fresh--;
                    rotten.push({r, c - 1});
                }

                // RIGHT
                if (c + 1 < m && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    fresh--;
                    rotten.push({r, c + 1});
                }
            }

            // One complete BFS level = one minute
            minutes++;
        }

        // Fresh oranges remain → impossible
        if (fresh != 0) {
            return -1;
        }

        return minutes;
    }
};