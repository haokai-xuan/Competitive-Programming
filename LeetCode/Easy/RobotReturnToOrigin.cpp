class Solution {
public:
    bool judgeCircle(string moves) {
        int vertDisp = 0;
        int horDisp = 0;
        for (char& c : moves) {
            switch(c) {
                case 'U':
                    vertDisp++;
                    break;
                case 'D':
                    vertDisp--;
                    break;
                case 'L':
                    horDisp--;
                    break;
                case 'R':
                    horDisp++;
                    break;
            }
        }

        return horDisp == 0 && vertDisp == 0;
    }
};