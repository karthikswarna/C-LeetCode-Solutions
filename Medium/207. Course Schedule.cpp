class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {        
        // Build Adjacency List.
        vector<vector<int>> adjList(numCourses);
        for(auto edge: prerequisites)
            adjList[edge[1]].push_back(edge[0]);


        // DFS. Uncomment line 12, 23 to find the topological Sort. 
        // vector<int> topSort;
        vector<bool> visited(numCourses, false);
        vector<bool> onRecStack(numCourses, false);
        for(int i = 0; i < numCourses; ++i)
        {
            if(!visited[i])
            {
                // If the component is cyclic, topSort cannot be formed.
                if(isCyclic(i, adjList, visited, onRecStack)) 
                    return false;

                // dfs(i, adjList, topSort, visited);
            }
        }                        

        return true;
    }

    void dfs(int src, vector<vector<int>>& adjList, vector<int>& topSort, vector<bool>& visited)
    {
        visited[src] = true;

        for(auto dest: adjList[src])
            if(!visited[dest])
                dfs(dest, adjList, topSort, visited);

        topSort.push_back(src);
    }
    
    bool isCyclic(int src, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& onRecStack)
    {
        visited[src] = true;
        onRecStack[src] = true;

        for(auto dest: adjList[src])
        {
            if(!visited[dest])
            {
                if(isCyclic(dest, adjList, visited, onRecStack)) return true;
            }

            else if(onRecStack[dest] == true) return true;
        }

        onRecStack[src] = false;
        return false;
    }
};