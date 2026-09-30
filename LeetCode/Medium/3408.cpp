class TaskManager {
    struct Triple {
        int first, second, third;
    };
    struct Comp {
        bool operator()(const Triple& a, const Triple& b) const {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        }
    };
    unordered_map<int, int> taskToPrior;
    unordered_map<int, int> taskToUser;
    set<Triple, Comp> global;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& v : tasks) {
            taskToPrior[v[1]] = v[2];
            taskToUser[v[1]] = v[0];
            global.insert(Triple{v[2], v[1], v[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToPrior[taskId] = priority;
        taskToUser[taskId] = userId;
        global.insert(Triple{priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        int user = taskToUser[taskId];
        int oldPriority = taskToPrior[taskId];
        global.erase(Triple{oldPriority, taskId, user});
        global.insert(Triple{newPriority, taskId, user});
        taskToPrior[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int user = taskToUser[taskId];
        int prior = taskToPrior[taskId];
        global.erase(Triple{prior, taskId, user});
    }
    
    int execTop() {
        if (!global.empty()) {
            auto it = global.begin();
            int task = it->second;
            rmv(task);
            return taskToUser[task];
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */