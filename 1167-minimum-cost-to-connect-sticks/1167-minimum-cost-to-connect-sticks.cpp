class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        vector<int> res(sticks.begin(), sticks.end());
        make_heap(res.begin(), res.end(), greater());

        int sum = 0;
        
        while (res.size() > 1) {
          pop_heap(res.begin(), res.end(), greater());
          int temp = res.back();
          res.pop_back();
          pop_heap(res.begin(), res.end(), greater());
          temp += res.back();
          res.pop_back();
          sum += temp;

          res.push_back(temp);
          push_heap(res.begin(), res.end(), greater());

        }

        return sum;
    }
};