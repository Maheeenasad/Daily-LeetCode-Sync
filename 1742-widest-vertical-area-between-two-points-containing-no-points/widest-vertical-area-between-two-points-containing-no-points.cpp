class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Step 1: Extract x-coordinates from points
        std::vector<int> xCoordinates;
        for (const auto& point : points) {
            xCoordinates.push_back(point[0]);
        }
        
        // Step 2: Sort x-coordinates
        std::sort(xCoordinates.begin(), xCoordinates.end());
        
        // Step 3: Find maximum width
        int maxWidth = 0;
        for (int i = 1; i < xCoordinates.size(); ++i) {
            int width = xCoordinates[i] - xCoordinates[i - 1];
            if (width > maxWidth) {
                maxWidth = width;
            }
        }
        
        return maxWidth; 
    }
};