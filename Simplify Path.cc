class Solution { 
public: 
    string simplifyPath(string path) { 
        vector<string> nodes; 
        int pos = 0, next; 
        string node; 
        while (pos < path.length()) { 
            // seek to next non '/' character 
            while (pos < path.length() && path[pos] == '/') ++pos; 
            // seek to next '/' 
            next = pos; 
            while (next < path.length() && path[next] != '/') ++next; 
            // node name 
            if (next > pos) { 
                node = path.substr(pos, next-pos); 
                if (node == "..") { 
                    if (!nodes.empty()) nodes.pop_back(); 
                } else if (node != ".") { 
                    nodes.push_back(node); 
                } 
            } 
            pos = next; 
        } 
         
        ostringstream buf; 
        for (auto& node_name : nodes) { 
            buf << '/' << node_name; 
        } 
        if (nodes.empty()) 
            buf << '/'; 
        return buf.str(); 
    } 
}; 