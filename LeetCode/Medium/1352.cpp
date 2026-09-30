class ProductOfNumbers {
public:
    ProductOfNumbers() {
        v = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            v = {1};
        }
        else {
            v.push_back(v.back() * num);
        }
    }
    
    int getProduct(int k) {
        int len = v.size();
        if (k >= len) {
            return 0;
        }
        
        return v[len - 1] / v[len - 1 - k];
    }
private:
    vector<int> v;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */