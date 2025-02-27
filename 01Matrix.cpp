// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// Did this code successfully run on Leetcode : Yes

//Approach:
// 1. Start by processing all the 0s in the matrix and add them to the queue.
// 2. Change all the 1s to INT_MAX.
// 3. Start BFS from the 0s and update the distance of the 1s from the 0s.
// 4. Continue this process until the queue is empty.

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            queue<pair<int, int>> q;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 0){
                        q.push({i,j});
                    }
                    else{
                        mat[i][j] = INT_MAX;
                    }
    
                }
            }
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
            while(!q.empty()){
                auto[r,c] = q.front();
                q.pop();
                for(auto[dr, dc]: directions){
                    int newRow = r + dr; 
                    int newCol = c + dc; 
                    if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n ||
                    mat[newRow][newCol] != INT_MAX){
                        continue;
                    }
                    mat[newRow][newCol] = mat[r][c] + 1;
                    q.push({newRow, newCol});
                }
            }
            return mat;
        }
    };