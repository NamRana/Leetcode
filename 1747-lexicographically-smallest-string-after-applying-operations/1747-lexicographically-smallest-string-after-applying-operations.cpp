class Solution {
public:
    string addOperation(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        
        string smallest = s;
        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Update smallest
            if (curr < smallest) smallest = curr;

            // Generate next states
            string added = addOperation(curr, a);
            string rotated = rotateOperation(curr, b);

            // BFS traversal
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return smallest;
    }
};
