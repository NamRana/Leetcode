class DetectSquares {
public:
    // Stores frequency of each exact (x,y) point.
    map<pair<int,int>, int> cnt;

    // Stores for each x -> map of y-coordinates and their counts.
    unordered_map<int, unordered_map<int, int>> rows;

    DetectSquares() {}

    // -----------------------------------------
    // Add a new point (x, y)
    // -----------------------------------------
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        // Count exact point
        cnt[{x, y}]++;

        // Add to row dictionary
        rows[x][y]++;
    }

    // -----------------------------------------
    // Count how many squares can be formed where
    // (qx, qy) is one of the corners.
    // -----------------------------------------
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];

        int result = 0;

        // Iterate over all y2 where (qx, y2) exists
        // This finds all possible vertical partners.
        for (auto &p : rows[qx]) {

            int y2 = p.first;
            int verticalCount = p.second;

            // Vertical side length must be > 0
            if (y2 == qy) continue;

            int d = abs(qy - y2);  // possible side length

            // ------------------------------
            // SQUARE ON THE RIGHT (qx + d)
            // ------------------------------
            int xr = qx + d;

            // We need:
            // (xr, qy) and (xr, y2)
            result += verticalCount *
                      cnt[{xr, qy}] *
                      cnt[{xr, y2}];

            // ------------------------------
            // SQUARE ON THE LEFT (qx - d)
            // ------------------------------
            int xl = qx - d;

            result += verticalCount *
                      cnt[{xl, qy}] *
                      cnt[{xl, y2}];
        }

        return result;
    }
};
