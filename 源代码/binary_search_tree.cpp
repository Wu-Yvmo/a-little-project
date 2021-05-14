template<typename object>
class binary_search_tree
{
private:
    //二叉树的节点由一个结构体实现
    //包括节点本身，指向左树的指针，指向右树的指针
    //我顺便写了两个构造函数，应该后面会有用
    struct node
    {
        object the_data;
        node* left;
        node* right;
        node()
        {
            left=nullptr;
            right=nullptr;
        }
        node(object a,node* b,node* c)
        {
            the_data=a;
            left=b;
            right=c;
        }
    };

    //该指针指向树根
    node* root;
    //binary_search_tree类私有，该方法删除参数指针指向的树
    void remove(node*);
public:
    //构造函数
    binary_search_tree();
    //析构函数，调用了私有的remove(node* a)函数
    ~binary_search_tree();
};

template<typename object>
void binary_search_tree<object>::remove(node* a)
{
    if (a != nullptr)
    {
        remove(a->left);
        remove(a->right);
        delete a;
    }
    else
        ;
}

template<typename object>
binary_search_tree<object>::binary_search_tree()
{
    root=new node();
}

template<typename object>
binary_search_tree<object>::~binary_search_tree()
{
    remove(root);
}
