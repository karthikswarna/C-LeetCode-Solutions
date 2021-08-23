class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> S;
        S.insert(n);

        while(n != 1)
        {
            int m = n;
            int next = 0;
            while(m > 0)
            {
                next += pow((m % 10), 2);
                m = m / 10;
            }
            
            cout << next << endl;
            if(S.find(next) != S.end()) return false;
            
            S.insert(next);
            n = next;
        }
        
        return true;
    }
};