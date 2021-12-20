class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        // IDEA: Find the diameter path of the n-ary tree, return the mid point/s of that path.
        // ASSERTION: There can be only two centroid nodes in the n-ary tree.
        // REASONING: 1.  The problem is finding out the nodes that are overall close to all other nodes, especially the leaf nodes.
        //            2. If we view the graph as an area of circle, and the leaf nodes as the peripheral of the circle, then what we are looking for are actually the "centroids" of the circle, i.e. nodes that is close to all the peripheral nodes (leaf nodes).
        //            3. There cannot be more than 2 centroids - Proof: Assume that there are 3 centroids. When all non-centroid nodes and related edges are removed from the graph, the three remaining nodes should form a cycle. Because all of them should be equally close to eachother inorder to be centroids. But there cannot be a cycle in a tree. So there can only be two (or one) centroid nodes.

        if(n == 1) return vector<int>{0};

        // Build the Adjacency List.
        unordered_map<int, vector<int>> adj_list;
        for(int i = 0; i < n; ++i)
            adj_list[i] = vector<int>{};

        for(auto edge: edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // Get the diameter of the tree.
        vector<int> diameter;
        getDiameter(0, -1, adj_list, diameter);

        // Return the two centroids of the tree.
        int mid = diameter.size() / 2;
        if(diameter.size() % 2 == 0)
            return vector<int>{ diameter[mid - 1], diameter[mid] };

        return vector<int>{diameter[mid]};
    }
    
    vector<int> getDiameter(int curr, int parent, unordered_map<int, vector<int>>& adj_list, vector<int>& diameter)
    {
        if(adj_list[curr].size() == 0) return vector<int>{curr};

        vector<int> firstLongPath;
        vector<int> secondLongPath;

        for(auto next: adj_list[curr])
        {
            if(next == parent) continue;

            vector<int> longestPathFromNext = getDiameter(next, curr, adj_list, diameter);
            int pathLen = longestPathFromNext.size();

            if(pathLen > firstLongPath.size())
            {
                secondLongPath = firstLongPath;
                firstLongPath = longestPathFromNext;
            }
            else if(pathLen > secondLongPath.size())
                secondLongPath = longestPathFromNext;
        }

        firstLongPath.push_back(curr);
        secondLongPath.push_back(curr);

        if(firstLongPath.size() + secondLongPath.size() - 1 > diameter.size())
        {
            diameter = firstLongPath;
            diameter.insert(diameter.end(), secondLongPath.rbegin(), secondLongPath.rend() - 1);
        }
        
        return (secondLongPath.size() > firstLongPath.size()) ? secondLongPath : firstLongPath;
    }
};