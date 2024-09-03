class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char ltr : letters){
            if (ltr > target){
                return ltr;
            }
        }
        return letters[0];
    }
};
