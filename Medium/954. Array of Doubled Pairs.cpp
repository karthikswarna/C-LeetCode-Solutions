class Solution {
public:
    bool canReorderDoubled(vector<int>& arr)
    {
        unordered_map<int, int> M;
        for(auto &i: arr)
            ++M[i];

        // IDEA: If x is currently the array element with the least absolute value, it must pair with 2*x, as there does not exist any other x/2 to pair with it.
        // Absolute sorting is required here because: Consider [2, -4, -2, 4], 
        // Normal sorting will be: [-4, -2, 2, -4]. Absolute Sorting will be: [2, -2, -4, 4]. So only in case of absolute sorting the above property of matching only with doubles satisfies.
        sort(arr.begin(), arr.end(), [](int a, int b){return abs(a) < abs(b);});

        for(auto &i: arr)
        {
            if(M[i] == 0) continue;     // This element is already used by a previous element.
            
            if(M[2 * i] <= 0) return false;     // Double not present in the array.
            
            // Pair found.
            --M[i];
            --M[2 * i];
        }
        
        return true;
    }
};