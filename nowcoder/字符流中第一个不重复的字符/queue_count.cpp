class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         ++count[ch]; // ch - '0' would cause index error
        // if it is the first time ch appears in the stream
        if(count[ch] == 1)
            q.push(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        // pop the elements that appear at least twice
        while(!q.empty() && count[q.front()] != 1)
            q.pop();
        if (q.empty()) return '#';
        return q.front(); // the remaining first element in the queue appears exactly once
         
     
    }
    Solution(){
        memset(count, 0, sizeof(count[0]) * 256);
    }
private:
    queue<int> q;
    unsigned int count[256];
};
