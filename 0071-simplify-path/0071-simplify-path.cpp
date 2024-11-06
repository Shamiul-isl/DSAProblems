class Solution {
public:
    string simplifyPath(string path) {
        stack<string> seen;
        string temp;

        stringstream ss(path);

        while (getline(ss, temp, '/')) {
            if (temp == "..") {
                if (!seen.empty()) seen.pop();
            } else if (temp != "." && temp.size() > 0) {
                seen.push(temp);
            }

        }
        
        temp = "";
        while (!seen.empty()) {
            temp = "/" + seen.top() + temp;
            seen.pop();
        }
        
        if (temp.size() == 0) return "/";

        return temp;
        
    }
};