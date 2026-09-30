class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        bool iscoord1black, iscoord2black;
        if ((coordinate1[0] - 'a') % 2 == (coordinate1[1] - '1') % 2) {
            iscoord1black = true;
        } else {
            iscoord1black = false;
        }

        if ((coordinate2[0] - 'a') % 2 == (coordinate2[1] - '1') % 2) {
            iscoord2black = true;
        } else {
            iscoord2black = false;
        }
        return iscoord1black == iscoord2black ? true : false;
    }
};
