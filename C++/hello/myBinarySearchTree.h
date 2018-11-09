template<class T>
class TreeNode{
    friend class BSTree;
    private:
    TreeNode *lchild,*rchild;
    T data;
};
template<class T>
class BSTree{
    private:
    TreeNode* tree;
    TreeNode* Search(TreeNode* t,T x);
    public:
    BSTree(){
        tree=nullptr;
    }
    ~BSTree(){
        delete tree;
    }
    TreeNode* Search(T x);
    TreeNode* ISearch(T x);
    void Insert(T x);
    void Delete(T& x);
}