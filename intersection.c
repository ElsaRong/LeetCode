class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1,set2;
        for (auto& num : nums1)
            set1.insert(num);
        for (auto& num : nums2)
            set2.insert(num);
        return getIntersection(set1, set2);
    }

    vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        if (set1.size() > set2.size())
            getIntersection(set2, set1);

        vector<int> intersecter; 
        for (auto& val : set2) {
            if (set1.count(val)) {
                intersecter.push_back(val);
            }
        }
        return intersecter;
    }
};
