class Solution
{
public:
    void push(int node) {
        while (!stack2.empty()) // place all the data to stack1
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node); // stack1 is used to push
     }
 
    int pop() {
        while(!stack1.empty()) // place all the data to stack2
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int top = stack2.top();
        stack2.pop();
        return top; // stack2 is used to pop
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};

