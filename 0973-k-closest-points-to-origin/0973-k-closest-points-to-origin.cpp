class Solution {
public:
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) const {
          return ((a.front() * a.front()) + (a.back() * a.back())) < ((b.front() * b.front()) + (b.back() * b.back()));
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result(points.begin(), points.begin() + k);

        make_heap(result.begin(), result.end(), cmp());

        for (int i = k; i < points.size(); i++) {
          if (cmp()(points[i], result.front())) {
            pop_heap(result.begin(), result.end(), cmp());
            result.pop_back();
            result.push_back(points[i]);
            push_heap(result.begin(), result.end(), cmp());
          }
        }

        return result;
    }
};