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
		creatEmptyList();//���к������Ե���˽�к���
	}
	LinkedList(T list[], int len)
	{
		creatList(list, len);//���к������Ե���˽�к���
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
		cout << "�ұ�����" << endl;
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
	void reverse()//��������
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
		//���ز��ҵ���λ�õ�ǰһ���ڵ�
		//���ص�һ�����ҽ����֮����ܻ��з��������Ľ��
		//��p����һ����㿪ʼ��
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
	Node<T>* update(Node<T> *tempHead, T oldData, T newData)//ֻ����tempHead����Ľ�㣬ֻ���·��ֵĵ�һ�����
	{
		tempHead = findNode(tempHead, oldData);
		if (NULL == tempHead)
		{
			return tempHead;
		}
		tempHead->next->t = newData;
		return tempHead;
	}
	bool updateAll(T oldData, T newData)//������������
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
	bool deleteNode(Node<T> *tempHead, T n)//ɾ��p���֮�󣨲�����p�������ֵΪn�Ľ�㣨ֻɾ����һ����������ܻ��У�
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
		head->next = p;//��ͷ�巨����½ڵ�
	}

	void addNode(T n)
	{
		Node<T> *p = new Node<T>(n);
		addNode(p);//��ͷ�巨����½ڵ�
	}
	void addNodeToRear(Node<T> *p)//β�巨����½��
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
	LinkedList* interSection(LinkedList *list2)//�󽻼�
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
		//ȥ���ظ�����
		result->deleteRedundancy();
		return result;
	}
	LinkedList* unionSection(LinkedList *list2)//�󲢼���Ҫȥ���ظ�������
	{
		LinkedList *result = new LinkedList();
		//����ʹ��new/delete����malloc��free
		//����������ϳ�һ������
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
		//ȥ���ظ�
		result->deleteRedundancy();
		return result;
	}
	void selectSort()//�����ѡ������
	{
		//��С����
		Node<T> *pminp, *p;
		Node<T> *tempHead1 = head;

		//pminpָ����Сֵ��ǰһ�����
		while (NULL != tempHead1->next)
		{
			pminp = tempHead1;
			p = pminp->next;
			//�ҵ���Сֵ��ǰһ���ڵ㣬pminpָ��������
			while (NULL != p->next)
			{
				if (p->next->t < pminp->next->t)
				{
					pminp = p;
				}
				p = p->next;
			}
			//ժ��pminp
			p = pminp->next;
			pminp->next = p->next;
			//����pminp
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
		//ͷ��㲻�����ݣ�ͷ��㴢���ָ�벻��Ҫ�䶯��
		//ֻ���޸�ͷ����nextָ�룬���˴�������ĺ���֮�⣬����λ�ö�����Ҫ����ͷ��������
	}
	void creatList(T list[], int len)//ͷ�巨��������
	{
		//int len = sizeof(num)/sizeof(int);//����ĳ��Ȳ������Ӻ����м���
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNode(list[i]);
		}
	}
	void creatListRear(T list[], int len)//β�巨��������
	{
		//int len = sizeof(num)/sizeof(int);//����ĳ��Ȳ������Ӻ����м���
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
	cout << "������" << endl;
	lj = l1->interSection(l2);
	lj->print();
	cout << "������" << endl;
	lu = l1->unionSection(l2);
	lu->print();
	delete(l1);
	delete(l2);
	delete(lj);
	delete(lu);
	while (1);
}