#ifndef __BIQ_H
#define __BIQ_H

#include "default.h"

using namespace std;

class BiNode{
public:
    int key;       // 关键字(键值)
    int vertex;    // 节点信息
    BiNode *child; // 子节点
    BiNode *sibling; // 兄弟节点

    BiNode():key(-1), vertex(-1), child(nullptr), sibling(nullptr) {};
    BiNode(int value, int vertex):key(value), vertex(vertex), child(nullptr), sibling(nullptr) {}

};

class Binomial_Queue{
private:
    unordered_map<int, BiNode> heads;
    int currentSize;
public:
    Binomial_Queue():currentSize(0),heads({}){}
    Binomial_Queue(BiNode* node):currentSize(1),heads({})
    {
        heads[0] = *node;
    }
    ~Binomial_Queue(){}

    // 判断是否为空
    bool isEmpty();
    // 新建key对应的节点，并将其插入到二项队列中
    void insert(int key, int vertex);
    // 移除二项队列中的最小key节点
    void removeMin();
    // 将other合并到当前堆中
    void combine(Binomial_Queue *other);
    // 获取二项队列中最小键值，并保存到pkey中；成功返回true，否则返回false。
    bool minimum(int *pkey);

private:
    BiNode combineTrees(BiNode t1, BiNode t2);
    BiNode* search(int vertex);
    BiNode* search(BiNode* node, int vertex);
};


#endif