/*
0690. Employee Importance

给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

思路：先建立员工编号到数组位置的映射，再做DFS。

*/

class Solution {
public:
    int res = 0;
    unordered_map<int, int> idPos;

    void traverse(vector<Employee*> employees, int id) {
        if (employees[idPos[id]]->subordinates.size() == 0) {
            res += employees[idPos[id]]->importance;
            return;
        }
        else {
            res += employees[idPos[id]]->importance;
            for (auto sub : employees[idPos[id]]->subordinates) {
                traverse(employees, sub);
            }
        }         
    }

    int getImportance(vector<Employee*> employees, int id) {
        // 建立id与数组位置的映射
        for (int i = 0; i < employees.size(); i++) {
            idPos[employees[i]->id] = i;
        }

        // DFS
        traverse(employees, id);
        return res;
    }
};