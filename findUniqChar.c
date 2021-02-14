/* C++无序哈希表unordered_map:
 * 1、内部使用哈希表实现，属于C++11标准库
 * 2、哈希表实现的特点是，插入、查找、删除操作平均时间复杂度O(1)，但最坏情况是O(N)
 * 3、最坏情况的原因：（1）哈希函数太烂导致大量key的哈希值冲突；（2）insert太多触发rehash；（3）初始化哈希表耗时
 * 4、常用操作：insert(3)\insert(make_pair("Elsa",99))\map[char]=true\erase(ch)\find("Elsa")
 * 5、注意事项：不允许插入重复元素，insert已存在元素不会成功
 * 5、比较unordered_set：set在哈希表中直接插入value，不像map一样使用key-value
 */
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> myMap; 
        for (auto& ch : s) {
            if (myMap.find(ch) == myMap.end()) { 
                myMap[ch] = true;; //第一次出现
            } else {
                myMap[ch] = false; //不是第一次出现
            }
        }
        //遍历完成后，返回为true的key
        for (auto& ch : s) {
            if (myMap[ch] == true) return ch;
        }
        return ' ';
    }
};
