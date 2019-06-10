class Solution {
public:
    void replaceSpace(char *str,int length) {
        int num_spaces=0;
        for(int i =0;str[i]!=0;++i)
            if(str[i] == ' ')
            {
                ++num_spaces;
            }
        int j;
        for(int i=length+num_spaces*2;i-num_spaces>=0;--i)
        {
            str[i] = str[i - num_spaces*2];
            if (str[i - num_spaces*2] == ' ')
            {
                str[i] = '0';
                str[i-1] = '2';
                str[i-2] = '%';
                --num_spaces;
                i -= 2;
            }
        }
    }
};
