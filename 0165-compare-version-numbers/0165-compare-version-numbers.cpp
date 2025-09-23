class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        stringstream ss1(version1), ss2(version2);
        string token;
        
        while (getline(ss1, token, '.')) v1.push_back(stoi(token));
        while (getline(ss2, token, '.')) v2.push_back(stoi(token));
        
        int length = max(v1.size(), v2.size());
        v1.resize(length, 0);
        v2.resize(length, 0);
        
        for (int i = 0; i < length; i++) {
            if (v1[i] < v2[i]) return -1;
            else if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
