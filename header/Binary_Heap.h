#ifndef __BIH_H
#define __BIH_H
#include "default.h"
using namespace std;  
class Binary 
{  
	private:  
	vector<pair<int, int> > node;  
	int size = 0;  
	
	void swap(int i, int j)//交换
	{  
		pair<int, int> tmp = node[i];  
		node[i] = node[j];  
		node[j] = tmp;  
	}  
	
	void up(int i)//上滤
	{
		while(i>0)
		{
			int dad=(i-1)/2;
			if(node[dad].first>node[i].first)
			{
				swap(dad,i);
				i=dad;
			}
			else
				break;
		}
	}
	
	void down(int i)//下滤
	{
		int left;
		int right;
		while(2*i+2<=size)	
		{
			left=2*i+1;
			right=2*i+2;
			if(node[left].first>node[right].first)
				left=right;
			if(node[left].first<node[i].first)
			{	
				swap(left,i);
				i=left;
			}
			else
				break;
		}	
	}		
	public:  
	void insert(const pair<int, int>& p)
	{  
		node.push_back(p);   
		size++;   
		if(size>0)
		up(size-1);   
	}  
	
	void update(const pair<int, int>& p)
	{  
		node.push_back(p);   
		size++;   
		if(size>0)
			up(size-1);   
		
	} 
	
	pair<int, int> removeMin()
	{  
		pair<int, int> tmp=node[0];  
		node[0]=node.back();  
		node.pop_back();  
		size--;  
		down(0);  
		return tmp;  
	}  
	
	//pair<int, int> minimum()
	int minimum()
	{  
		return node[0].second;  
	}  
	
	int Size() 
	{  
		return size;  
	}  
	
	bool isEmpty()  
	{  
		return size == 0;  
	}  
};  

#endif


