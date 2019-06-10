class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i=array.size()-1, j=0;
        while(i>=0 && j < array[i].size())
        {
            if(target < array[i][j])
                --i;
            else if (target > array[i][j])
                ++j;
            else return true;
        }
        return false;
    }
};

