class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int m = image.size(), n = image[0].size();
            int originalColor = image[sr][sc];
            if(originalColor == color){return image;}
    
            queue<pair<int, int>> q;
            q.push({sr, sc});
            image[sr][sc] = color; 
    
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
            while(!q.empty()){
                auto[r,c] = q.front();
                q.pop();
                for(auto [dr, dc] : directions) {
                    int newRow = r + dr; 
                    int newCol = c + dc; 
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && image[newRow][newCol] == originalColor){
                        image[newRow][newCol] = color; 
                        q.push({newRow, newCol});
                    }
                }
            }
            return image;
        }
    };