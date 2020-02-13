#include "lc.hpp"

class CQueue {
private:
    stack<int> StackOrder;
    stack<int> QueueOrder;
    bool InStack;

public:
    void SwitchStack() {
        if (InStack) {
            while (!StackOrder.empty()) {
                QueueOrder.push(StackOrder.top());
                StackOrder.pop();
            }
            InStack = false;
            return;
        } else {
            while (!QueueOrder.empty()) {
                StackOrder.push(QueueOrder.top());
                QueueOrder.pop();
            }
            InStack = true;
            return;
        }
    }

    CQueue() {
        InStack = true;
    }

    void appendTail(int value) {
        if (!InStack)
            SwitchStack();
        StackOrder.push(value);
        return;
    }

    int deleteHead() {
        if (InStack)
            SwitchStack();
        if (QueueOrder.empty())
            return -1;
        int ret = QueueOrder.top();
        QueueOrder.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */