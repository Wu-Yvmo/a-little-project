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
public:
    //测试
    binary_search_tree();
    ~binary_search_tree();
};

template<typename object>
binary_search_tree<object>::binary_search_tree()
{
    
}