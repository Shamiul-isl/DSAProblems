class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> result;
        
        set<vector<int>> seen;

        for (vector<int> v: items1) {
            seen.insert(v);
        }

        for (vector<int> v: items2) {
            if (seen.count(v) > 0) {
                seen.erase(v);
                v[1] += v[1];      
            }
            seen.insert(v);
        }

        auto i = seen.begin();
        while (i != seen.end()) {
            vector<int> cur = *i;
            while (true) {
                std::advance(i, 1);
                if (i == seen.end())
                    break;
                if ((*i)[0] != cur[0]) {
                    break;
                }
                cur[1] += (*i)[1];
                
            }
            result.push_back(cur);
        }

        

        return result;
    }
};