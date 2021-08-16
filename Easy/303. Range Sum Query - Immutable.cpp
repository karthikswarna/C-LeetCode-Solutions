class NumArray {
    vector<int> A;
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums): A(nums)
    {
        if(A.size() == 0) return;

        prefixSum.resize(A.size());
        prefixSum[0] = A[0];
        for(int i = 1; i < A.size(); ++i)
            prefixSum[i] = prefixSum[i - 1] + A[i];
    }
    
    int sumRange(int left, int right)
    {
        return prefixSum[right] - prefixSum[left] + A[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */