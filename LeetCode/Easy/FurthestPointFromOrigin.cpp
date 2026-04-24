class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        char dir;
        int lCnt = 0, rCnt = 0;
        for (char& c : moves) {
            if (c == 'L') lCnt++;
            else if (c == 'R') rCnt++;
        }
        dir = lCnt >= rCnt ? 'L' : 'R';
        int curr = 0;
        for (char& c : moves) {
            if (c == '_') {
                curr += dir == 'L' ? -1 : 1;
            }
            else {
                curr += c == 'L' ? -1 : 1;
            }
        }
        return abs(curr);
    }
};