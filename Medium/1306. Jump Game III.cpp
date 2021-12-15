class Solution
{
    int N;
public:
    bool canReach(vector<int>& arr, int start)
    {
        N = arr.size();
        vector<bool> visited(N, false);
        return dfs(start, arr, visited);
    }

    bool dfs(int currIdx, vector<int>& arr, vector<bool>& visited)
    {
        if(currIdx < 0 || currIdx >= N || visited[currIdx]) return false;
        if(arr[currIdx] == 0) return true;

        visited[currIdx] = true;
        
        int returnVal = dfs(currIdx + arr[currIdx], arr, visited) || 
                        dfs(currIdx - arr[currIdx], arr, visited);

        visited[currIdx] = false;
        return returnVal;
    }
};