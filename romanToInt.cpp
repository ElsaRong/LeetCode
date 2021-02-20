class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> romanTable;            //注意：map和unordered_map比较差异
        romanTable.insert(make_pair('I', 1));
        romanTable.insert(make_pair('V', 5));
        romanTable.insert(make_pair('X', 10));
        romanTable.insert(make_pair('L', 50));
        romanTable.insert(make_pair('C', 100));
        romanTable.insert(make_pair('D', 500));
        romanTable.insert(make_pair('M', 1000));

        int i = 0, sum = 0;
        int diff = 0;
        int sLen = s.size();
        for(i = sLen - 1; i > 0; i--)
        {
            if(isSpecial(s[i-1], s[i]))
            {
                diff = romanTable.find(s[i])->second - romanTable.find(s[i-1])->second;
                sum += diff;
                i--;     //注意：前移2步，这里减1，因为条件语句中已经减过1
            }
            else
            {
                sum += romanTable.find(s[i])->second;
            }
        }
        if (0 == i)
            sum += romanTable.find(s[0])->second;
        return sum;
    }

    bool isSpecial(char pre, char curr) 
    {
        if(curr == 'V' || curr == 'X')
        {
            if(pre == 'I')
                return true;
        }

        if(curr == 'L' || curr == 'C')
        {
            if(pre == 'X')
                return true;
        }

        if(curr == 'D' || curr == 'M')
        {
            if(pre == 'C')
                return true;
        }
        return false;
    }
};
