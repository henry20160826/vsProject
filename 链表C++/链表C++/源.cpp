#include<iostream>
using namespace std;
struct node
{
	int num;
	struct node *next;
};
class LinkedList
{
public:
	LinkedList()
	{
		creatEmptyList();//公有函数可以调用私有函数
	}
	LinkedList(int num[], int len)
	{
		creatList(num, len);//公有函数可以调用私有函数
	}
	~LinkedList()
	{
		struct node *p;
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
	struct node* gethead()
	{
		return head;
	}
	struct node* findNode(struct node *tempHead, int n)
	{
		//返回查找到的位置的前一个节点
		//返回第一个查找结果，之后可能还有符合条件的结点
		//从p的下一个结点开始查
		while (NULL != tempHead->next)
		{
			if (tempHead->next->num == n)
			{
				return tempHead;
			}
			tempHead = tempHead->next;
		}
		return NULL;
	}
	struct node* update(struct node *tempHead,int oldData, int newData)//只查找tempHead后面的结点，只更新发现的第一个结点
	{
		tempHead = findNode(tempHead, oldData);
		if (NULL == tempHead)
		{
			return tempHead;
		}
		tempHead->next->num = newData;
		return tempHead;
	}
	bool updateAll(int oldData,int newData)//更新所有数据
	{
		struct node *tempHead = head;
		bool flag = false;
		tempHead = update(tempHead, oldData, newData);
		flag = (tempHead != NULL);
		while (tempHead!=NULL)
		{
			tempHead=update(tempHead, oldData, newData);
		}
		return flag;
	}
	bool deleteNode(struct node *tempHead, int n)//删除p结点之后（不包括p），结点值为n的结点（只删除第一个，后面可能还有）
	{
		struct node *prior, *p;
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
	void addNode(struct node *p)
	{
		struct node *temp;
		temp = head->next;
		head->next = p;
		p->next = temp;//按头插法添加新节点
	}

	void addNode(int n)
	{
		struct node *p;
		p = (struct node*)malloc(sizeof(struct node));
		p->num = n;
		addNode(p);//按头插法添加新节点
	}
	void addNodeToRear(struct node *p)//尾插法添加新结点
	{
		struct node *tempHead = head;
		while (NULL != tempHead->next);
		p->next = NULL;
		tempHead->next = p;
	}
	void addNodeToRear(int n)
	{
		struct node *p;
		p = (struct node*)malloc(sizeof(struct node));
		p->num = n;
		addNodeToRear(p);
	}
	void print()
	{
		struct node *tempHead = head;
		tempHead = tempHead->next;
		while (tempHead != NULL)
		{
			cout << tempHead->num << ",";
			tempHead = tempHead->next;
		}
		cout << "\b \n";
	}
	void deleteRedundancy()
	{
		struct node *p = head->next;
		while (p != NULL)
		{
			while (deleteNode(p, p->num));
			p = p->next;
		}
	}
	LinkedList* interSection(LinkedList *list2)//求交集
	{
		LinkedList *result = new LinkedList();
		struct node *tempHead1 = head;
		struct node *temphead2 = list2->gethead();
		tempHead1 = tempHead1->next;
		while (tempHead1 != NULL)
		{
			if (findNode(temphead2, tempHead1->num) != NULL)
			{
				result->addNode(tempHead1->num);
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
		struct node *tempHead1 = head;
		struct node *temphead2 = list2->gethead();
		tempHead1 = tempHead1->next;
		while (tempHead1 != NULL)
		{
			result->addNode(tempHead1->num);
			tempHead1 = tempHead1->next;
		}
		temphead2 = temphead2->next;
		while (temphead2 != NULL)
		{
			result->addNode(temphead2->num);
			temphead2 = temphead2->next;
		}
		//去除重复
		result->deleteRedundancy();
		return result;
	}
	void selectSort()//链表的选择排序
	{
		//从小到大
		struct node *pminp, *p;
		struct node *tempHead1 = head;

		//pminp指向最小值的前一个结点
		while (NULL != tempHead1->next)
		{
			pminp = tempHead1;
			p = pminp->next;
			//找到最小值的前一个节点，pminp指向这个结点
			while (NULL != p->next)
			{
				if (p->next->num < pminp->next->num)
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
	struct node *head;
	void creatEmptyList()
	{
		head = new struct node;
		head->next = NULL;
		//头结点不存数据，头结点储存的指针不需要变动，
		//只需修改头结点的next指针，除了创建链表的函数之外，其余位置都不需要传入头结点的引用
	}
	void creatList(struct node *&head)//指针的引用
	{
		//struct node *p;
		//int a;
		//head = (struct node*)malloc(sizeof(struct node));//malloc返回的指针有extern声明，所以分配的空间在函数之外依然存在，属于匿名的静态变量
		//p = head;
		//for (int i = 0; i < 4; i++)
		//{
		//	p->next = (struct node*)malloc(sizeof(struct node));
		//	p = p->next;
		//	cin >> p->num;
		//}
		//p->next = NULL;//这是尾插法比较简练的代码方式
		creatEmptyList();
		for (int i = 0; i < 4; i++)
		{
			//cin >> a;
			addNode(i);
		}
	}
	void creatList(int num[], int len)//头插法创建链表
	{
		//int len = sizeof(num)/sizeof(int);//数组的长度不能在子函数中计算
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNode(num[i]);
		}
	}
	void creatListRear(int num[], int len)//尾插法创建链表
	{
		//int len = sizeof(num)/sizeof(int);//数组的长度不能在子函数中计算
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNodeToRear(num[i]);
		}
	}
};
void main()
{
	int num[] = { 2,3,5,1,7,2,8 };
	int len;
	int num1[] = { 2,9,3,5,6 };
	LinkedList *l1, *l2, *lj, *lu;
	len = sizeof(num) / sizeof(int);
	l1 = new LinkedList(num, len);
	l1->print();
	l1->addNode(10);
	l1->print();
	l1->selectSort();
	l1->print();
	//deleteNode(head, 10);
	//print(head);
	len = sizeof(num1) / sizeof(int);
	l2 = new LinkedList(num1, len);
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