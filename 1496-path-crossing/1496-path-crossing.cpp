#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;

        // Store visited positions as "x,y"
        unordered_set<string> visited;
        visited.insert("0,0");  // starting point

        for (char move : path) {
            if (move == 'N') y++;
            else if (move == 'S') y--;
            else if (move == 'E') x++;
            else if (move == 'W') x--;

            string pos = to_string(x) + "," + to_string(y);

            // If already visited, path crosses itself
            if (visited.count(pos)) {
                return true;
            }

            visited.insert(pos);
        }

        return false;
    }
};
