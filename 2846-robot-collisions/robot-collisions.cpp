struct Robot {
    int position;
    int health;
    char direction;
    int index;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
            int n = positions.size();
    vector<Robot> robots;
    
    // Create robots with all necessary details
    for (int i = 0; i < n; ++i) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }
    
    // Sort robots by their positions
    sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
        return a.position < b.position;
    });
    
    stack<Robot> rightMoving; // Stack to keep track of robots moving right
    vector<int> result(n, -1); // Initialize result with -1 indicating robots that are destroyed
    
    for (auto& robot : robots) {
        if (robot.direction == 'R') {
            // Add right moving robot to the stack
            rightMoving.push(robot);
        } else {
            // Current robot is moving left
            while (!rightMoving.empty() && robot.health > 0) {
                Robot& rightRobot = rightMoving.top();
                if (rightRobot.health > robot.health) {
                    // Right moving robot wins
                    rightRobot.health -= 1;
                    robot.health = 0;
                } else if (rightRobot.health < robot.health) {
                    // Left moving robot wins
                    robot.health -= 1;
                    rightMoving.pop();
                } else {
                    // Both robots have the same health and destroy each other
                    rightMoving.pop();
                    robot.health = 0;
                }
            }
            if (robot.health > 0) {
                // If left moving robot survives, add it to the result
                result[robot.index] = robot.health;
            }
        }
    }
    
    // Add remaining right moving robots to the result
    while (!rightMoving.empty()) {
        Robot robot = rightMoving.top();
        rightMoving.pop();
        result[robot.index] = robot.health;
    }
    
    // Filter out the destroyed robots from the result
    vector<int> survivors;
    for (int health : result) {
        if (health != -1) {
            survivors.push_back(health);
        }
    }
    
    return survivors;
}

// Main function for testing
int main() {
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 10, 15, 12};
    string directions = "RLRL";
    vector<int> result = survivedRobotsHealths(positions, healths, directions);
    for (int health : result) {
        cout << health << " ";
    }
    return 0;

    }
};