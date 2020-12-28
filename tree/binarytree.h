#include<queue>

template <typename T>
class BinaryTreeNode
{
public:
    BinaryTreeNode(const T &element)
    :element_(element){}
    BinaryTreeNode(const T& element,BinaryTreeNode* leftChild,BinaryTreeNode* rightChild)
    :element_(element),left_child_(leftChild),right_child_(rightChild){}
public:
    T element_;
    BinaryTreeNode* left_child_{nullptr};
    BinaryTreeNode* right_child_{nullptr};
};

//使用链表构造二叉树
template<typename T>
class BinaryTree
{
public:
    BinaryTree(BinaryTreeNode<T>* root = nullptr,int size = 0)
    :root_(root),size_(size)
    {

    }
    int height()
    {
        return height(root_);
    }

    int size(){return size_;}

    void preOrder(void(*dealdada)(const T&))
    {
        transElement = dealdada;
        preOrder(root_);

    }
    void inOrder(void(*dealdada)(const T&))
    {
        transElement = dealdada;
        inOrder(root_);

    }
    void postOrder(void(*dealdada)(const T&))
    {
        transElement = dealdada;
        postOrder(root_);

    }
    void levelOrder(void(*dealdada)(const T&))
    {
        transElement = dealdada;
        levelOrder(root_);
    }
private:
    static int height(BinaryTreeNode<T>* node = this->root_)
    {
        if(node == nullptr)
            return 0;
        int lHeight = height(node->left_child_);
        int rHeight = height(node->right_child_);

        if(lHeight>rHeight)
            return ++lHeight;
        else
            return ++rHeight; 
    }
    static void(*transElement)(const T&){[](const T&)->void{}};

    static void preOrder(BinaryTreeNode<T>* node)
    {
        if(node == nullptr)
            return;
        transElement(node->element_);
        preOrder(node->left_child_);
        preOrder(node->right_child_);
    }

    static void inOrder(BinaryTreeNode<T>* node)
    {
        if(node == nullptr)
            return;
        inOrder(node->left_child_);
        transElement(node->element_);
        inOrder(node->right_child_);

    }

    static void postOrder(BinaryTreeNode<T>* node)
    {
        if(node == nullptr)
            return;
        postOrder(node->left_child_);
        postOrder(node->right_child_);
        transElement(node->element_);

    }

    static void levelOrder(BinaryTreeNode<T>* node)
    {
        if(node == nullptr )
            return;
        std::queue<BinaryTreeNode<T>*> checkQueQue;
        while (node!=nullptr)
        {
            transElement(node);
            if(node->left_child_!=nullptr) checkQueQue.push(node->left_child_);
            if(node->right_child_!=nullptr) checkQueQue.push(node->right_child_);
           
            if(checkQueQue.empty())
                return;
            else
            {
                node = checkQueQue.front();
            }
            checkQueQue.pop();
        }

    }


private:
    BinaryTreeNode<T> *root_;
    int size_;
};