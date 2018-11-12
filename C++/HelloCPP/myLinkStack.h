template<class T>
class myLinkStack
{
    private:
        struct node{
            T data;
            struct node *link;
        };
        struct node *top;
    public:
        myLinkStack(){
            top = nullptr;
        }
        ~myLinkStack(){
            struct node *temp;
            while(top){
                temp= top;
                top= top->link;
                delete temp;
            }
        }
        bool Add(const T item);
        bool Delete(T& itemp);
        inline bool StackEmpty(){
            if(top) return false;
            else return true;
        }
};