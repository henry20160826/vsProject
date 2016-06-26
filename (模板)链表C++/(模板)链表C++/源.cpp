#include<iostream>
using namespace std;
template<class T> class Node
{
public:
	T t;
	Node *next;
	Node()
	{
		next = NULL;
	}
	Node(T ot)
	{
		t = ot;
		next = NULL;
	}
};
template <class T>class LinkedList
{
public:

	LinkedList()
	{
		creatEmptyList();//公有函数可以调用私有函数
	}
	LinkedList(T list[], int len)
	{
		creatList(list, len);//公有函数可以调用私有函数
	}
	~LinkedList()
	{
		Node<T> *p;
		p = head->next;
		while (p != NULL)
		{
			delete(head);
			head = p;
			p = p->next;
		}
		delete(head);
		cout << "我被析构" << endl;
	}
	Node<T>* gethead()
	{
		return head;
	}
	Node<T> *getOffNext(Node<T> *tempHead)
	{
		Node<T> *p = tempHead->next;
		if (p != NULL)
		{
			tempHead->next = p->next;
			p->next = NULL;
		}
		return p;
	}
	void reverse()//链表逆序
	{
		Node<T> *tempHead = head->next;
		Node<T> *p;
		while (tempHead->next)
		{
			p = getOffNext(tempHead);
			addNode(p);
		}
	}
	Node<T>* findNode(Node<T> *tempHead, T n)
	{
		//返回查找到的位置的前一个节点
		//返回第一个查找结果，之后可能还有符合条件的结点
		//从p的下一个结点开始查
		while (NULL != tempHead->next)
		{
			if (tempHead->next->t == n)
			{
				return tempHead;
			}
			tempHead = tempHead->next;
		}
		return NULL;
	}
	Node<T>* update(Node<T> *tempHead, T oldData, T newData)//只查找tempHead后面的结点，只更新发现的第一个结点
	{
		tempHead = findNode(tempHead, oldData);
		if (NULL == tempHead)
		{
			return tempHead;
		}
		tempHead->next->t = newData;
		return tempHead;
	}
	bool updateAll(T oldData, T newData)//更新所有数据
	{
		Node<T> *tempHead = head;
		bool flag = false;
		tempHead = update(tempHead, oldData, newData);
		flag = (tempHead != NULL);
		while (tempHead != NULL)
		{
			tempHead = update(tempHead, oldData, newData);
		}
		return flag;
	}
	bool deleteNode(Node<T> *tempHead, T n)//删除p结点之后（不包括p），结点值为n的结点（只删除第一个，后面可能还有）
	{
		Node<T> *prior, *p;
		prior = findNode(tempHead, n);
		if (NULL == prior)
		{
			return false;
		}
		p = prior->next;
		prior->next = p->next;
		delete(p);
		return true;
	}
	void addNode(Node<T> *p)
	{
		p->next = head->next;
		head->next = p;//按头插法添加新节点
	}

	void addNode(T n)
	{
		Node<T> *p = new Node<T>(n);
		addNode(p);//按头插法添加新节点
	}
	void addNodeToRear(Node<T> *p)//尾插法添加新结点
	{
		Node<T> *tempHead = head;
		while (NULL != tempHead->next);
		p->next = NULL;
		tempHead->next = p;
	}
	void addNodeToRear(T n)
	{
		Node<T> *p = new node(n);
		addNodeToRear(p);
	}
	void print()
	{
		Node<T> *tempHead = head;
		tempHead = tempHead->next;
		while (tempHead != NULL)
		{
			cout << tempHead->t << ",";
			tempHead = tempHead->next;
		}
		cout << "\b \n";
	}
	void deleteRedundancy()
	{
		Node<T> *p = head->next;
		while (p != NULL)
		{
			while (deleteNode(p, p->t));
			p = p->next;
		}
	}
	LinkedList* interSection(LinkedList *list2)//求交集
	{
		LinkedList *result = new LinkedList();
		Node<T> *tempHead1 = head;
		Node<T> *temphead2 = list2->gethead();
		tempHead1 = tempHead1->next;
		while (tempHead1 != NULL)
		{
			if (findNode(temphead2, tempHead1->t) != NULL)
			{
				result->addNode(tempHead1->t);
			}
			tempHead1 = tempHead1->next;
		}
		//去除重复内容
		result->deleteRedundancy();
		return result;
	}
	LinkedList* unionSection(LinkedList *list2)//求并集，要去除重复的内容
	{
		LinkedList *result = new LinkedList();
		//可以使用new/delete代替malloc与free
		//将两个链表合成一个链表
		Node<T> *tempHead1 = head;
		Node<T> *temphead2 = list2->gethead();
		tempHead1 = tempHead1->next;
		while (tempHead1 != NULL)
		{
			result->addNode(tempHead1->t);
			tempHead1 = tempHead1->next;
		}
		temphead2 = temphead2->next;
		while (temphead2 != NULL)
		{
			result->addNode(temphead2->t);
			temphead2 = temphead2->next;
		}
		//去除重复
		result->deleteRedundancy();
		return result;
	}
	void selectSort()//链表的选择排序
	{
		//从小到大
		Node<T> *pminp, *p;
		Node<T> *tempHead1 = head;

		//pminp指向最小值的前一个结点
		while (NULL != tempHead1->next)
		{
			pminp = tempHead1;
			p = pminp->next;
			//找到最小值的前一个节点，pminp指向这个结点
			while (NULL != p->next)
			{
				if (p->next->t < pminp->next->t)
				{
					pminp = p;
				}
				p = p->next;
			}
			//摘下pminp
			p = pminp->next;
			pminp->next = p->next;
			//插入pminp
			p->next = tempHead1->next;
			tempHead1->next = p;
			tempHead1 = tempHead1->next;
		}
	}
private:
	Node<T> *head;
	void creatEmptyList()
	{
		head = new Node<T>();
		//头结点不存数据，头结点储存的指针不需要变动，
		//只需修改头结点的next指针，除了创建链表的函数之外，其余位置都不需要传入头结点的引用
	}
	void creatList(T list[], int len)//头插法创建链表
	{
		//int len = sizeof(num)/sizeof(int);//数组的长度不能在子函数中计算
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNode(list[i]);
		}
	}
	void creatListRear(T list[], int len)//尾插法创建链表
	{
		//int len = sizeof(num)/sizeof(int);//数组的长度不能在子函数中计算
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNodeToRear(list[i]);
		}
	}
};
void main()
{
	int num[] = { 2,3,5,1,7,2,8 };
	int len;
	int num1[] = { 2,9,3,5,6 };
	LinkedList<int> *l1, *l2, *lj, *lu;
	len = sizeof(num) / sizeof(int);
	l1 = new LinkedList<int>(num, len);
	l1->print();
	l1->addNode(10);
	l1->print();
	l1->selectSort();
	l1->print();
	l1->reverse();
	l1->print();
	len = sizeof(num1) / sizeof(int);
	l2 = new LinkedList<int>(num1, len);
	l2->print();
	l2->selectSort();
	l2->print();
	cout << "*********************\n";
	cout << "交集：" << endl;
	lj = l1->interSection(l2);
	lj->print();
	cout << "并集：" << endl;
	lu = l1->unionSection(l2);
	lu->print();
	delete(l1);
	delete(l2);
	delete(lj);
	delete(lu);
	while (1);
}