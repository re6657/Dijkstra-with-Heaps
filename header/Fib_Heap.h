#ifndef _FIBONACCI_TREE_HPP_
#define _FIBONACCI_TREE_HPP_

#include "default.h"

using namespace std;

class FibNode {
    public:
        int key;                // 关键字(键值)
        int vertex;             // 节点信息
        int degree;            // 度数
        FibNode *left;    // 左兄弟
        FibNode *right;    // 右兄弟
        FibNode *child;    // 第一个孩子节点
        FibNode *parent;    // 父节点
        bool marked;        // 是否被删除第一个孩子

        FibNode(int value, int vertex):key(value), vertex(vertex), degree(0), marked(false),
            left(NULL),right(NULL),child(NULL),parent(NULL) 
        {
            left = this;
            right = this;
        }
};

class FibHeap{
    private:
        int keyNum;         // 堆中节点的总数
        int maxDegree;      // 最大度
        FibNode *min;    // 最小节点(某个最小堆的根节点)
        FibNode **cons;    // 最大度的内存区域

    public:
        FibHeap();
        ~FibHeap();

        // 判断是否为空
        bool isEmpty();
        // 新建key对应的节点，并将其插入到斐波那契堆中
        void insert(int key, int vertex);
        // 移除斐波那契堆中的最小key节点
        void removeMin();
        // 将other合并到当前堆中
        void combine(FibHeap *other);
        // 获取斐波那契堆中最小键值，并保存到pkey中；成功返回true，否则返回false。
        bool minimum(int *pkey);
        // 将斐波那契堆中节点vertex的值更新为newkey
        void update(int vertex, int newkey);
        // 删除键值为key的节点
        void remove(int key);
        // 斐波那契堆中是否包含节点vertex
        bool contains(int vertex);
        // 销毁
        void destroy();

    private:
        // 将node从双链表移除
        void removeNode(FibNode *node);
        // 将node堆结点加入root结点之前(循环链表中)
        void addNode(FibNode *node, FibNode *root);
        // 将双向链表b链接到双向链表a的后面
        void catList(FibNode *a, FibNode *b);
        // 将节点node插入到斐波那契堆中
        void insert(FibNode *node);
        // 将堆的最小结点从根链表中移除，
        FibNode* extractMin();
        // 将node链接到root根结点
        void link(FibNode* node, FibNode* root);
        // 创建consolidate所需空间
        void makeCons();
        // 合并斐波那契堆的根链表中左右相同度数的树
        void consolidate();
        // 修改度数
        void renewDegree(FibNode *parent, int degree);
        // 将node从父节点parent的子链接中剥离出来，并使node成为堆的根链表中的一员。
        void cut(FibNode *node, FibNode *parent);
        // 对节点node进行级联剪切
        void cascadingCut(FibNode *node) ;
        // 将斐波那契堆中节点node的值减少为key
        void decrease(FibNode *node, int key);
        // 将斐波那契堆中节点node的值增加为key
        void increase(FibNode *node, int key);
        // 更新斐波那契堆的节点node的键值为key
        void update(FibNode *node, int key);
        // 在最小堆root中查找节点vertex
        FibNode* search(FibNode *root, int vertex);
        // 在斐波那契堆中查找节点vertex
        FibNode* search(int vertex);
        // 删除结点node
        void remove(FibNode *node);
        // 销毁斐波那契堆
        void destroyNode(FibNode *node);
};

#endif