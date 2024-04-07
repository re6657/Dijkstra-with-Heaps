#include "Binomial_Queue.h"

bool Binomial_Queue::isEmpty() 
{
    for(auto it : heads)
    {
        if(it.second.key != -1)
            return false;
    }
    return true;
}

BiNode Binomial_Queue::combineTrees(BiNode t1, BiNode t2)
{
    if(t1.key > t2.key)
        return combineTrees(t2, t1);
    if(t1.key == t2.key)
    {
        t1.vertex = t2.vertex;
        return t1;
    }
    t2.sibling = t1.child;
    t1.child = &t2;
    return t1;
}

void Binomial_Queue::combine(Binomial_Queue *other)
{
    if(other->currentSize == 0)
        return;
    currentSize += other->currentSize;
    BiNode carry;
    for(int i = 0, j = 1; j <= currentSize; i++, j *= 2)
    {
        BiNode empty;
        BiNode t1 = heads[i];
        BiNode t2 = i < other->currentSize ? other->heads[i] : empty;
        int whichCase = (t1.key == -1 ? 0 : 1);
        whichCase += (t2.key == -1 ? 0 : 2);
        whichCase += (carry.key == -1 ? 0 : 4);
        switch(whichCase)
        {
            case 0:
            case 1: break;
            case 2:
                heads[i] = t2;
                other->heads[i] = empty;
            break;
            case 4:
                heads[i] = carry;
                carry = empty;
            break;
            case 3:
                carry = combineTrees(t1, t2);
                heads[i] = other->heads[i] = empty;
            break;
            case 5:
                carry = combineTrees(t1, carry);
                heads[i] = empty;
            break;
            case 6:
                carry = combineTrees(t2, carry);
                other->heads[i] = empty;
            break;
            case 7:
                heads[i]= carry;
                carry = combineTrees(t1, t2);
                other->heads[i] = empty;
            break;
        }
    other->currentSize = 0;
    other->heads.clear();
    }
}

void Binomial_Queue::insert(int key, int vertex)
{
    BiNode* newnode = new BiNode(key, vertex);
    Binomial_Queue* queue = new Binomial_Queue(newnode);
    if(currentSize == 0)
    {
        heads[0] = *newnode;
        currentSize++;
        return;
    }
    combine(queue);
}

BiNode* Binomial_Queue::search(int vertex)
{
    for(auto it : heads)
    {
        BiNode* result = search(&it.second, vertex);
        if(result != nullptr)
            return result;
    }
    return nullptr;
}

BiNode* Binomial_Queue::search(BiNode* node, int vertex)
{
    if(node->vertex == vertex)
        return node;
    BiNode* result = nullptr;
    BiNode* child = node->child;
    while(child != nullptr && result == nullptr)
    {
        result = search(child, vertex);
        child = child->sibling;
    }
    return result;
}

void Binomial_Queue::removeMin()
{
    BiNode empty;
    int minElem = MAX;
    int minIndex = -1;
    for(int i = 0; i < heads.size(); i++)
    {
        if(heads[i].key != -1 && minElem > heads[i].key)
        {
            minElem = heads[i].key;
            minIndex = i;
        }
    }
    if(minIndex == -1)
    {
        throw "No element in queue, cannot remove minimum";
        return;
    }
    int childDegree = minIndex - 1;
    Binomial_Queue remains;
    BiNode *child = heads[minIndex].child;
    while(child != nullptr && childDegree >= 0)
    {
        BiNode *next = child->sibling;
        child->sibling = nullptr; 
        remains.heads[childDegree--] = *child; 
        child = next;
    }
    currentSize -= (1 << minIndex);
    combine(&remains);
}

bool Binomial_Queue::minimum(int *pkey)
{
    int minElem = MAX;
    int minIndex = -1;
    for(int i = 0; i < heads.size(); i++)
    {
        if(heads[i].key != -1 && minElem > heads[i].key)
        {
            minElem = heads[i].key;
            minIndex = i;
        }
    }
    if(minIndex == -1)
    {
        throw "No element in queue, cannot find minimum";
        return false;
    }
    *pkey = heads[minIndex].vertex;
    return true;
}