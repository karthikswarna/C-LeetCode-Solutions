class Solution {
public:
    int trap(vector<int>& height)
    {
        if(height.size() <= 1) return 0;

        int result = 0;
        
        auto begin = height.begin();
        auto end = height.end();
        auto max = max_element(begin, end);
        end = max;

        // Towards left
        while(end > height.begin())
        {
            auto temp = max_element(begin, end); // Second highest towards left;

            result += (end - temp - 1) * (*temp); // only *temp
            for(auto itr = temp + 1; itr != end; itr++)
                result -= *itr;
            
            end = temp;
        }

        begin = max;
        end = height.end();
        
        // Towards right
        while(begin < height.end() - 1)
        {
            auto temp = max_element(begin + 1, end); // Second highest towards right;

            result += (temp - begin - 1) * (*temp);
            for(auto itr = begin + 1; itr != temp; itr++)
                result -= *itr;
            
            begin = temp;
        }

        return result;
    }
};