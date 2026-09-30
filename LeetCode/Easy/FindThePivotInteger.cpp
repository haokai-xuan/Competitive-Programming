class Solution {
    bool isSquare(int num, int root) {
        return root * root == num;
    }
public:
    int pivotInteger(int n) {
        int root = static_cast<int>(sqrt((n * n + n) / 2));
        if (isSquare((n * n + n) / 2, root)) return root;
        return -1;
    }
};