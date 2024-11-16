class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        set<int> seen;
        for (int i=0; i < isConnected.size(); i++) {
            if (seen.count(i) > 0) continue;
            seen.insert(i);
            stack<vector<int>> dfs;
            int curIndex = i;
            dfs.push(isConnected[i]);

            while (!dfs.empty()) {
                bool added = false;
                for (int j = 0; j < dfs.top().size(); j++) {
                    if (j == curIndex) {
                        (dfs.top())[j] = 0;
                    } else if ((dfs.top())[j] == 1){
                        (dfs.top())[j] = 0;
                        isConnected[j][curIndex] = 0;
                        if (seen.count(j) > 0) continue;
                        dfs.push(isConnected[j]);
                        curIndex = j;
                        seen.insert(curIndex);
                        added = true;
                        break;
                    }
                }

                if (!added) dfs.pop();
            }

            provinces++;
        }

        return provinces;
    }
};