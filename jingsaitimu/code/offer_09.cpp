#include "headl.h" 
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {
    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        int it;
        if (s1.empty() and s2.empty())
        {
            return -1;
        }
        else
        {
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    int it = s1.top();
                    s1.pop();
                    s2.push(it);
                }
                it = s2.top();
                s2.pop();
            }
            else
            {
                it = s2.top();
                s2.pop();
            }
        }

        return it;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);

}
