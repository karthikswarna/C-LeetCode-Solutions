// https://leetcode.com/problems/iterator-for-combination/discuss/1576763/C%2B%2B-or-Permuting-Pointers!-or-Pictures-%2B-Detailed-Explanation-%2B-Commented-Code-or-NovemberChallenge
class CombinationIterator
{
    int N;
    string characters;
    int combinationLength;

    // i'th pointer represents whether tha i'th character of "characters" is included in the next permutation.
    vector<bool> pointers;
    bool hasNextPermutation = true;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        this->characters = characters;
        this->combinationLength = combinationLength;
        N = characters.size();

        pointers.resize(N, false);
        for(int i = 0; i < combinationLength; ++i)
            pointers[i] = true;
    }
    
    string next()
    {
        string answer = "";
        for(int i = 0; i < N; ++i)
            if(pointers[i]) 
                answer += characters[i];
    
        // Generate the next permutation (for the future calls and the hasNext() function.)
        if(pointers.back())     // If the last character is in the current permutation.
        {
            // Find the next rightmost set pointer that can move to right (has a zero next to it.)
            int rightPtr;
            int endSetCount = 1;
            for(rightPtr = N - 2; rightPtr >= 0; --rightPtr)
            {
                if(pointers[rightPtr])
                {
                    if(!pointers[rightPtr + 1])     
                    {
                        pointers[rightPtr] = false;
                        pointers[rightPtr + 1] = true;
                        break;
                    }
                    else
                        ++endSetCount;
                }   
            }

            // If all pointers are set at the end. (current "answer" is the largest combination.)
            if(endSetCount == combinationLength)
                hasNextPermutation = false;
            else
                for(int i = rightPtr + 2; i < N; ++i)
                {
                    if(i - rightPtr - 1 <= endSetCount)
                        pointers[i] = true;
                    else
                        pointers[i] = false;
                }
        }
        else
        {
            int rightPtr;
            for(rightPtr = N - 2; rightPtr >= 0; --rightPtr)
            {
                if(pointers[rightPtr])
                {        
                    pointers[rightPtr] = false;
                    pointers[rightPtr + 1] = true;
                    break;
                }
            }
        }


        return answer;
    }
    
    bool hasNext()
    {
        return hasNextPermutation;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */