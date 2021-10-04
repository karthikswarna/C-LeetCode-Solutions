class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        // Construct Adjacency List.
        vector<vector<int>> adjList(numCourses);
        for(auto edge: prerequisites)
            adjList[edge[1]].push_back(edge[0]);
        

        // If the graph is cyclic, topological sort is not possible.
        vector<int> topSort;
        vector<int> visited(numCourses, false);
        vector<int> onRecStack(numCourses, false);  // Used to find the cycle.

        for(int i = 0; i < numCourses; ++i)
            if(!visited[i])
                if(isCyclic(i, adjList, topSort, visited, onRecStack)) return vector<int>{};
        
        
        reverse(topSort.begin(), topSort.end());
        return topSort;
    }
    
    bool isCyclic(int src, vector<vector<int>>& adjList, vector<int>& topSort, vector<int>& visited, vector<int>& onRecStack)
    {
        visited[src] = true;
        onRecStack[src] = true;
        
        for(auto dest: adjList[src])
        {
            if(!visited[dest])
            {
                if(isCyclic(dest, adjList, topSort, visited, onRecStack)) return true;
            }
            else if(onRecStack[dest]) return true;
            
        }

        topSort.push_back(src);
        onRecStack[src] = false;
        return false;
    }
};