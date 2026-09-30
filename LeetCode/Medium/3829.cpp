class RideSharingSystem {
    deque<int> riders, drivers;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans = {-1, -1};
        if (!riders.empty() && !drivers.empty()) {
            ans[0] = drivers.front();
            ans[1] = riders.front();
            drivers.pop_front();
            riders.pop_front();
            return ans;
        }
        return ans;
    }
    
    void cancelRider(int riderId) {
            riders.erase(remove(riders.begin(), riders.end(), riderId), riders.end());
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */