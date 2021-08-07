class Solution {
public:
    // Solution by calculating net force on each domino.
    // Force toward right direction is taken as positive. 
    // Force toward left is taken as negative. IF net force on a domino is 0, then it stays vertical.
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> forces(n, 0);
        
        int force = 0;

        // Calculating rightward forces.
        for(int i = 0; i < n; i++)
        {
            if(dominoes[i] == 'R') force = n;
            else if(dominoes[i] == 'L') force = 0;
            else force = std::max(force - 1, 0);
            
            forces[i] += force;
        }
        
        // Calculating leftward forces.
        for(int i = n - 1; i >= 0; i--)
        {
            if(dominoes[i] == 'L') force = n;
            else if(dominoes[i] == 'R') force = 0;
            else force = std::max(force - 1, 0);
            
            forces[i] -= force;
        }
        
        // Building the result. Net positive force - domino falls rightward.
        // Net negative force - domino falls leftward.
        string result(n, '.');
        for(int i = 0; i < n; i++)
        {
            if(forces[i] > 0) result[i] = 'R';
            else if(forces[i] < 0) result[i] = 'L';
        }
        
        return result;
    }
};