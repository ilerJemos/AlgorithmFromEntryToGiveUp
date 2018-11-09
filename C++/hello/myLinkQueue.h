template <class T>
class myLinkQueue
{
  private:
    struct node
    {
        T data;
        node *link;
    };
     struct node *front, *rear;

  public:
    myLinkQueue()
    {
        front = new struct node;
        rear = front;
    }
    ~myLinkQueue()
    {
        struct node *temp;
        while (front != rear)
        {
            temp = front;
            front = temp->link;
            delete temp;
        }
        delete front;
    }
    inline bool EmptyQueue()
    {
        // if (front == rear||((!front)&&(!rear)))
        //     return true;
        // else
            return false;
    }
    bool Add(const T item);
    bool Delete(T &item);
};