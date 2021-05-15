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
    //这是查找的私有接口，供公有实现调用
    bool exists(object & x,node* t);
    //查找最小值，内部接口
    node* find_min_private(node* t);
    //查找最大值，内部接口
    node* find_max_private(node* t);
    //向树中插入一个元素，内部接口
    void get_in_private(object & x,node* t);
public:
    //构造函数
    binary_search_tree();
    //析构函数，调用了私有的remove(node* a)函数
    ~binary_search_tree();
    //查找树中是否存在大小等于x的节点
    bool exists(object & x);
    //查找最小值，公有接口
    node* find_min();
    //查找最大值，公有接口
    node* find_max();
    //向树中插入一个元素
    void get_in(object & x);
    //从树中删除一个节点
    void remove(object & x);
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

template<typename object>
bool binary_search_tree<object>::exists(object & x,node* t)
{
    if (t == nullptr)
        return false;
    else if (t->the_data > x)
        return exists(object & x,t->left);
    else if (t->the_data < x)
        return exists(object & x,t->right)
    else
        return true;
}

template<typename object>
bool binary_search_tree<object>::exists(object & x)
{
    return exists(object & x,root);
}

template<typename object>
binary_search_tree<object>::node* binary_search_tree<object>::find_min_private(node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return find_min_private(t->left);
}

template<typename object>
binary_search_tree<object>::node* binary_search_tree<object>::find_max_private(node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return find_max_private(t->right);
}

template<typename object>
binary_search_tree<object>::node* binary_search_tree<object>::find_min()
{
    return find_min_private(root);
}

template<typename object>
binary_search_tree<object>::node* binary_search_tree<object>::find_max()
{
    return find_max_private(root);
}

template<typename object>
void binary_search_tree<object>::get_in_private(object & x,node* t)
{
    if (t == nullptr)
        t = new node(x,nullptr,nullptr);
    else if (t->object > x)
        get_in_private(x,t->left);
    else if (t->object < x)
        get_in_private(x,t->right);
    else
        ;
}

template<typename object>
void binary_search_tree<object>::get_in(object & x)
{
    get_in_private(x,root);
} 