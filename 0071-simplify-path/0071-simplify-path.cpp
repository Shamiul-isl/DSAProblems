class Solution {
public:
    string simplifyPath(string path) {
        stack<string> seen;
        string temp = "";
        for (int i = 0; i < path.size(); i++) {          
//             if (path[i] == '.') {
//                 string t =  "";
//                 t += path[i];
//                 int j = i + 1;
//                 while (j < path.size()) {
//                     if (path[j] == '.') { 
//                         t += path[j];
//                         j++;
//                     } else
//                         break;
//                 }
                
                
//                 if (t.size() == 2 && seen.size() > 1) {
//                     if (seen.top() == "/") {
//                         seen.pop();
//                     }
//                     seen.pop();
//                 } else if (t.size() > 2) {
//                     seen.push(t);
//                 }
//                 i += t.size() - 1;
//             } else 
            
            if (path[i] == '/') {

                if (temp.size() == 2 && temp == "..") {
                    if (seen.size() > 1) {
                        if (seen.top() == "/") {
                            seen.pop();
                        }
                        seen.pop();
                    }
                } else if (!(temp.size() == 1 && temp[0] == '.') && temp != "") {
                    seen.push(temp);
                }
                temp = "";
                if (seen.size() == 0 || (seen.size() > 0 && seen.top() != "/")) {
                    seen.push("/");
                }  
            } else {
                temp += path[i];
            }
        }
        
        if (temp.size() == 2 && temp == "..") {
            if (seen.size() > 1) {
                if (seen.top() == "/") {
                    seen.pop();
                }
                seen.pop();
            }
            temp = "";
        }
        
        if (temp.size() == 1 && temp[0] == '.') temp = "";
        
        if (temp.size() > 0) seen.push(temp);

        string res = "";
        if (seen.top() == "/" && seen.size() > 1)
            seen.pop();
        while (seen.size() > 0) {
            res = seen.top() + res;
            seen.pop();
        }
        return res;
    }
};