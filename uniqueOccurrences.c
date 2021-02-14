class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurRecord;
        //生成数值-出现次数的记录表
        for (auto& val : arr) {
            occurRecord[val]++;
        }
        unordered_set<int> uniqSet;
        unordered_map<int, int>::iterator iter;
        //遍历数组，获取数值出现的次数，判断在set中是否能找到，找不到继续遍历
        for (iter = occurRecord.begin(); iter != occurRecord.end(); iter++) {
            if (uniqSet.find(iter->second) == uniqSet.end()) 
                uniqSet.insert(iter->second);
            else
                return false;
        }
        return true;
    }
};
