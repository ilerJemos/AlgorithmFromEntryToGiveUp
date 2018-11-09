template<class T>
class myDictionary{
    private:
    public:
    myDictionary(int MSize);
    ~myDictionary();
    void Insert(T item);
    void Delete(T &item);
    void Search(T item);
}