class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> pathLen; // depth -> length of path till this depth
        pathLen[0] = 0;
        int maxLen = 0;

        stringstream ss(input);
        string line;

        // Split input by newline
        while (getline(ss, line, '\n')) {
            // Count depth (# of tabs)
            int depth = 0;
            while (line[depth] == '\t') depth++;

            // Get actual name (remove tabs)
            string name = line.substr(depth);

            if (name.find('.') != string::npos) {
                // It's a file → compute full path length
                int totalLen = pathLen[depth] + name.size();
                maxLen = max(maxLen, totalLen);
            } else {
                // It's a directory → store cumulative length
                // +1 for "/" separator
                pathLen[depth + 1] = pathLen[depth] + name.size() + 1;
            }
        }

        return maxLen;
    }
};
