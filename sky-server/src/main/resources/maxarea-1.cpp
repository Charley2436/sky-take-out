#include <iostream>
#include <vector>
#include <algorithm> // 用于std::max

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiaSq = 0, maxArea = 0;
        // 遍历每个矩形的尺寸
        for (const auto& dim : dimensions) {
            int l = dim[0], w = dim[1];
            int diaSq = l * l + w * w; // 计算对角线的平方
            int area = l * w;          // 计算面积
            
            // 更新最大对角线和对应的面积
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                // 对角线相等时取面积更大的值
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    
    // 测试用例1：不同对角线长度
    vector<vector<int>> test1 = {{3,4}, {1,1}, {5,12}};
    cout << "测试用例1结果: " << solution.areaOfMaxDiagonal(test1) << " (预期60)" << endl;
    
    // 测试用例2：对角线相同但面积相同
    vector<vector<int>> test2 = {{2,3}, {1,4}, {3,2}};
    cout << "测试用例2结果: " << solution.areaOfMaxDiagonal(test2) << " (预期6)" << endl;
    
    // 测试用例3：对角线相同但面积不同
    vector<vector<int>> test3 = {{5,5}, {1,7}};
    cout << "测试用例3结果: " << solution.areaOfMaxDiagonal(test3) << " (预期25)" << endl;
    
    return 0;
}
    