class Solution {
public:
    // Using Graphs
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int numAcc = accounts.size();
                
        // Build the graph. We have an undirected edge between the first email and all other emails of an account.
        // Actually, the way nodes are connected are not that important, until all the nodes belonging to the component can be reached in some way.
        unordered_map<string, vector<string>> adj_list;
        for(int i = 0; i < numAcc; ++i)
        {
            for(int j = 2; j < accounts[i].size(); ++j)
            {
                adj_list[accounts[i][1]].push_back(accounts[i][j]);
                adj_list[accounts[i][j]].push_back(accounts[i][1]);
            }
        }
        
        // After building the graph, the different components represent merged accounts. 
        // We just need to collect the emails in each component (using DFS), and return the result. 
        vector<vector<string>> result;
        unordered_set<string> visited;
        for(int i = 0; i < numAcc; ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                // If the email is already visited, its part of a different component/account.
                if(visited.find(accounts[i][j]) == visited.end())
                {
                    vector<string> component;
                    component.push_back(accounts[i][0]);
                    dfs(accounts[i][j], visited, component, adj_list);
                    
                    sort(component.begin() + 1, component.end());   // First one is the name of the user.
                    result.push_back(component);
                }
            }
        }
        
        return result;
    }
    
    void dfs(string& s, unordered_set<string>& visited, vector<string>& component, unordered_map<string, vector<string>>& adj_list)
    {
        visited.insert(s);
        component.push_back(s);
        
        for(auto neighbour : adj_list[s])
            if(visited.find(neighbour) == visited.end())
                dfs(neighbour, visited, component, adj_list);
    }
    
    // Using Union-Find
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
//     {
//         int numAcc = accounts.size();
        
//         unordered_map<string, string> user;
//         unordered_map<string, string> parent;
//         unordered_map<string, set<string>> disjoint_sets;   // We use a set to have sorted order.

//         // Initialize the user, parent maps.
//         for(int i = 0; i < numAcc; ++i)
//         {
//             for(int j = 1; j < accounts[i].size(); ++j)
//             {
//                 user[accounts[i][j]] = accounts[i][0];
//                 parent[accounts[i][j]] = accounts[i][j];
//             }
//         }
        
//         // Perform union operation on sets that atleast have one common email.
//         // The first email is the parent of the group.
//         for(int i = 0; i < numAcc; ++i)
//         {
//             string p = find(accounts[i][1], parent);

//             for(int j = 2; j < accounts[i].size(); ++j)
//                 parent[find(accounts[i][j], parent)] = p;
//         }
        
//         // For each set, create a list of emails that are part of it.
//         for(int i = 0; i < numAcc; ++i)
//             for(int j = 1; j < accounts[i].size(); ++j)
//                 disjoint_sets[find(accounts[i][j], parent)].insert(accounts[i][j]);

//         vector<vector<string>> result;
//         for(auto p: disjoint_sets)
//         {
//             vector<string> account;
//             account.push_back(user[p.first]);
//             account.insert(account.end(), p.second.begin(), p.second.end());

//             result.push_back(account);    
//         }

//         return result;
//     }
    
//     string find(string x, unordered_map<string, string>& parent)
//     {
//         if(parent[x] == x)
//             return x;
//         else
//         {
//             string p = find(parent[x], parent);
//             parent[x] = p;          // Path Compression.
//             return p;
//         }
//     }
};