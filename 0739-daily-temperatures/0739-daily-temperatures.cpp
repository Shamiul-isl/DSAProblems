class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // TODO: Write your code here
        vector<pair<int, int>> ms;
        vector<int> res(temperatures.size(), 0);


        for (int i = 0; i < temperatures.size(); i++) {
            while (!ms.empty() && temperatures[i] > ms.back().first) {
                res[ms.back().second] = i - ms.back().second;
                ms.pop_back();
            }

            ms.push_back(make_pair(temperatures[i], i));
        }

        return res;
    }
};