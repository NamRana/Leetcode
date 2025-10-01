class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        // allowed business lines with order mapping
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<pair<int,string>, string>> valid; 
        // store ((businessLineOrder, code), code)

        for (int i = 0; i < n; i++) {
            // must be active
            if (!isActive[i]) continue;

            // businessLine must be valid
            if (order.find(businessLine[i]) == order.end()) continue;

            // check code validity: non-empty + only [A-Za-z0-9_]
            if (code[i].empty()) continue;
            bool ok = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    ok = false; break;
                }
            }
            if (!ok) continue;

            // push valid coupon
            valid.push_back({{order[businessLine[i]], code[i]}, code[i]});
        }

        // sort by businessLine order then code lexicographically
        sort(valid.begin(), valid.end());

        // extract result
        vector<string> result;
        for (auto &p : valid) result.push_back(p.second);

        return result;
    }
};