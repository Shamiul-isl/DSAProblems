class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::vector<int> result;
        map<int, vector<int>> edgeMap;
        unordered_set<int> visited;

        for (int i = 0; i < edges.size(); i++) {
            if (edgeMap.count(edges[i][0]) > 0) {
                edgeMap[edges[i][0]].push_back(edges[i][1]);
            } else {
                vector<int> temp = {edges[i][1]};
                edgeMap[edges[i][0]] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited.count(i) < 1) {
                dfs(i, edgeMap, visited);
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited.count(i) < 1) {
                result.push_back(i);
            }
        }
        return result;
    }
    
    void dfs(int cur, map<int, vector<int>>& edgeMap, unordered_set<int>& visited) {
        for (int i : edgeMap[cur]) {
            if (visited.count(i) < 1) {
                visited.insert(i);
                dfs(i, edgeMap, visited);
            }
        }
    }
};