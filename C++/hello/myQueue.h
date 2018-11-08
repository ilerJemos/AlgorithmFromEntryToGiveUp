template <class T>
class myQueue{
    private:
        int MaxSize;
        int front,rear;
        T * queue;
    public:
        myQueue(int MSize):MaxSize(MSize)
        {
            front = rear = 0;
            queue = new T[MaxSize];
        }
        ~myQueue(){
            delete queue;
        }
        inline bool FullQueue(){
            if((rear+1)%MaxSize==front)return true;
            else return false;
        }
        inline bool EmptyQueue(){
            if(front==rear)
            return true;
            else return false;
        }
        bool Add(T item);
        bool Delete(T& item);
};