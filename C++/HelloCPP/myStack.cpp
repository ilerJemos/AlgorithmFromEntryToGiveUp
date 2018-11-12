
template <class T>
class myStack
{
  private:
    int top, MaxSize;
    T *stack;

  public:
    myStack(int MSize) : MaxSize(MSize)
    {
        stack = new T[MaxSize];
        top = -1;
    }
    ~myStack()
    {
        delete stack;
    }
    inline bool Add(const T item)
    {
        if (StackFull())
        {
            //cout << "stack is full";
            return false;
        }
        else
        {
            stack[++top] = item;
            return true;
        }
    }
    inline bool Delete(T& item)
    {
        if(StackEmpty())
        return false;
        else{
            item = stack[top--];
            return true;
        }
    }
    inline bool StackFull()
    {
        if (top >= (MaxSize - 1))
            return true;
        else
            return false;
    }
    inline bool StackEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

// #include <iostream>
// #include <vector>
// int main()
// {
//     //myStack<int>* m = new myStack<int>(10);
//     myStack<int> m(10);
//     m.Add(4);
//     m.Add(100);
//     int b;
//     m.Delete(b);
//     std::cout<<b;
//     m.Delete(b);
//     std::cout<<b;
//     return 0;
// }
