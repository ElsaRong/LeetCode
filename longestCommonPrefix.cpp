class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string prefix = strs[0];
        int count = strs.size();

        for(int i = 1; i < count; i++) 
        {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if(!prefix.size())
                return "";
        }
        return prefix;
    }

    string longestCommonPrefix(string& str1, string& str2)
    {
        int minLen = min(str1.size(), str2.size());
        int index = 0;
        while(index < minLen && str1[index] == str2[index]) //逻辑：当跳出while时，index指向的val已经不等
            index++;
        return str1.substr(0, index);
    }
};
