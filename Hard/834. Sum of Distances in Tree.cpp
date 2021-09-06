class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> tree;
        for(const auto &edge: edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> subtreeNodeCount(n, 0);
        vector<int> subtreeDistanceSum(n, 0);
        postorder(tree, 0, -1, subtreeNodeCount, subtreeDistanceSum);

        // The result for root is already calculated
        preorder(tree, 0, -1, subtreeNodeCount, subtreeDistanceSum);

        return subtreeDistanceSum;
    }
    
    void postorder(unordered_map<int, vector<int>>& tree, int src, int parent, vector<int>& count, vector<int>& stsum)
    {
        count[src] += 1;
        for(auto dst: tree[src])
        {
            if(parent != dst)
            {
                postorder(tree, dst, src, count, stsum);
            // Calculate number of nodes in subtree rooted at current node.
                count[src] += count[dst];
            // Calculate sum of distances from current node to all other nodes in subtree rooted at current node.
                stsum[src] += stsum[dst] + count[dst];
            }
        }
    }
    
    void preorder(unordered_map<int, vector<int>>& tree, int src, int parent, vector<int>& count, vector<int>& stsum)
    {
        for(auto dst: tree[src])
        {
            if(parent != dst)
            {
                // Calculating the result using count and stsum arrays.
                stsum[dst] = (stsum[src] - count[dst]) + (count.size() - count[dst]);
                preorder(tree, dst, src, count, stsum);
            }
        }
    }
    

// Floyd-Warshall Algorithm Time: O(V^3)
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
//     {
//         vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
//         vector<int> result(n, 0);
        
//         for(const auto &edge: edges)
//         {
//             distance[edge[0]][edge[1]] = 1;
//             distance[edge[1]][edge[0]] = 1;
//         }

//         for(int i = 0; i < n ; ++i)
//             distance[i][i] = 0;

//         for(int k = 0; k < n ; ++k)
//             for(int i = 0; i < n ; ++i)
//                 for(int j = 0; j < n ; ++j)
//                     if(distance[i][k] < INT_MAX && distance[k][j] < INT_MAX && distance[i][j] > distance[i][k] + distance[k][j])
//                         distance[i][j] = distance[i][k] + distance[k][j];
    
//         for(int i = 0; i < n ; ++i)
//             result[i] = accumulate(distance[i].begin(), distance[i].end(), 0);
        
//         return result;
//     }
};