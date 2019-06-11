class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int n = array.size();
        for(int i =0,j=n-1;i < j;)
        {
            if(array[i] + array[j] == sum)
                return vector<int>{array[i], array[j]};
            else if (array[i] + array[j]>sum) 
                --j; // if i move to the right, the sum would be larger
            else // if j move the left, the sum would be smaller
                ++i;
            
        }
        return vector<int> {};
    }
};
