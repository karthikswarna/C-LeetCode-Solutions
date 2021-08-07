class Solution {
public:
    bool stoneGame(vector<int>& piles)
    {
        return stoneGame(piles, 0, 0, 0, 1);
    }
    
    bool stoneGame(vector<int>& piles, int low, int high, int score, int turn)
    {
        if(low > high && score > 0) return true;
        if(low > high && score <= 0) return false;

        bool rightHalf, leftHalf;
        if(turn == 1)
        {
            rightHalf = stoneGame(piles, low + 1, high, score + piles[low], !turn);
            leftHalf = stoneGame(piles, low, high - 1, score + piles[high], !turn);
        }
        else
        {
            rightHalf = stoneGame(piles, low + 1, high, score - piles[low], !turn);
            leftHalf = stoneGame(piles, low, high - 1, score - piles[high], !turn);
        }
        
        return rightHalf || leftHalf;
    }
};