class Spreadsheet {
    unordered_map<string, int> sheet;
public:
    Spreadsheet(int rows) {
        return;
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    
    void resetCell(string cell) {
        sheet[cell] = 0;
    }
    
    int getValue(string formula) {
        string op1 = "", op2 = "";
        int n1, n2;
        int index = 1;
        while (formula[index] != '+') {
            op1 += formula[index];
            index++;
        }
        index++;
        while (index < formula.size()) {
            op2 += formula[index];
            index++;
        }

        if (!isdigit(op1[0]))
            n1 = sheet[op1];
        else
            n1 = stoi(op1);

        if (!isdigit(op2[0]))
            n2 = sheet[op2];
        else
            n2 = stoi(op2);

        return n1 + n2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */