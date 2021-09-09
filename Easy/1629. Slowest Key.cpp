class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed)
    {
        int maxDur = releaseTimes[0];
        char ans = keysPressed[0];
        for(int i = 1; i < releaseTimes.size(); ++i)
        {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if(duration > maxDur || (duration == maxDur && keysPressed[i] > ans))
            {
                maxDur = duration;
                ans = keysPressed[i];
            }
        }
        
        return ans;
    }
};