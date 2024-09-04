class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
           // Direction vectors for north, east, south, west
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Convert obstacles into a set for quick lookup
        std::unordered_set<std::string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(std::to_string(obstacle[0]) + "," + std::to_string(obstacle[1]));
        }
        
        int x = 0, y = 0, directionIndex = 0;  // Start at (0, 0) facing north
        int maxDistanceSquared = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left: Counterclockwise turn
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) {
                // Turn right: Clockwise turn
                directionIndex = (directionIndex + 1) % 4;
            } else {
                // Move forward
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[directionIndex].first;
                    int nextY = y + directions[directionIndex].second;
                    
                    // Check if the next position is an obstacle
                    if (obstacleSet.find(std::to_string(nextX) + "," + std::to_string(nextY)) != obstacleSet.end()) {
                        break; // Stop if there's an obstacle
                    }
                    
                    // Update position
                    x = nextX;
                    y = nextY;
                    
                    // Update the maximum distance squared
                    maxDistanceSquared = std::max(maxDistanceSquared, x * x + y * y);
                }
            }
        }
        
        return maxDistanceSquared; 
    }
};