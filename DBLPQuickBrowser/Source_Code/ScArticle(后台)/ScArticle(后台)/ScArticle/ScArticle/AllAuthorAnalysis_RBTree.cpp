#include<iostream>
#include<stack>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
static int num=0;
static const int RED = 0;
static const int BLACK = 1;
struct node{
	string key;
	int value;
	bool operator <(const node& a) const
	{
		if(value<a.value)
			return true;
		else 
			return false;
	}
};
vector<node> help;
template <class Key,class Value>
class Red_Black_Tree_Node
{
public:
	Red_Black_Tree_Node(Key k) :key(k),value(1), color(BLACK), p(NULL), left(NULL), right(NULL) {}
	Key key;
	Value value;
	int color;
	Red_Black_Tree_Node<Key,Value>* p;
	Red_Black_Tree_Node<Key,Value>* left;
	Red_Black_Tree_Node<Key,Value>* right;
};
template <class Key,class Value>
class Red_Black_Tree
{
public:
	Red_Black_Tree();
	Red_Black_Tree_Node<Key,Value>* get_root() const;//��ȡ���ڵ�
	bool find_node(Key&key);//
	Red_Black_Tree_Node<Key,Value>* search_tree_node(const Key& k)const;//���ҹؼ���Ϊk�Ľڵ�
	void left_rotate(Red_Black_Tree_Node<Key,Value> *pnode);//����ת����
	void right_rotate(Red_Black_Tree_Node<Key,Value> *pnode);//����ת����
	void rb_insert_fixup(Red_Black_Tree_Node<Key,Value>*pnode);//����������������Υ����������ʵ���Ϊ
	void rb_delete_fixup(Red_Black_Tree_Node<Key,Value> *pnode);//����ɾ�����������Υ����������ʵ���Ϊ
	
	void rb_insert(Red_Black_Tree_Node<Key,Value>* z);//����ڵ�
	void rb_delete(Red_Black_Tree_Node<Key,Value>* z);//ɾ���ڵ�


	void inorder_tree_walk()const;//�����������ѹ��vector��
	void make_empty(Red_Black_Tree_Node<Key,Value>* root);
	//~Red_Black_Tree();


public:
	static	Red_Black_Tree_Node<Key,Value> *NIL;
private:
	Red_Black_Tree_Node<Key,Value>* root;
};

//��ʼ��nil
template <class Key,class Value>
Red_Black_Tree_Node<Key,Value>* Red_Black_Tree<Key,Value>::NIL = new Red_Black_Tree_Node<Key,Value>("null");

//��ʼ��root�ڵ�   ����Ĭ�Ϲ��캯��
template <class Key,class Value>
Red_Black_Tree<Key,Value>::Red_Black_Tree()
{
	root = NIL;
};

//---------------------------------------------------------------------------------------
template <class Key,class Value>
Red_Black_Tree_Node<Key,Value>* Red_Black_Tree<Key,Value>::get_root() const//��ȡ���ڵ�
{
	return root;
}
//�����Ƿ����key�Ľڵ�
//---------------------------------------------------------------------------------------
template <class Key,class Value>
bool Red_Black_Tree<Key,Value>::find_node(Key&key)
{
	Red_Black_Tree_Node<Key,Value>* p = root;
		while (p != NIL)
	{
		if (p->key == key)
			return true;
		else if (p -> key > key)
			p = p->left;
		else
			p = p->right;
	}
 return false;
}
//------------------------------------------------------------------------------------------
//�������йؼ���key�Ľڵ�

template <class Key,class Value>
Red_Black_Tree_Node<Key,Value>* Red_Black_Tree<Key,Value>::search_tree_node(const Key& key) const
{
	Red_Black_Tree_Node<Key,Value>* p = root;
	while (p != NIL)
	{
		if (p->key == key)
			return p;
		else if (p -> key > key)
			p = p->left;
		else
			p = p->right;
	}
 return false;
}
//----------------------------------------------------------------------------------------------------
//����ת
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::left_rotate(Red_Black_Tree_Node<Key,Value> *x)
{
	Red_Black_Tree_Node<Key,Value> *y = x->right;
	x->right = y->left; 
	if (y->left != NIL)
		y->left->p = x;

	y->p = x->p;
	if (x->p == NIL)
		root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;

	y->left = x;
	x->p = y;
}
//����ת
//------------------------------------------------------------------------------------------------------
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::right_rotate(Red_Black_Tree_Node<Key,Value> *x)
{
	Red_Black_Tree_Node<Key,Value> *y = x->left;
	x->left = y->right;
	if (y->right != NIL)
		y->right->p = x;

	y->p = x->p;
	if (x->p == NIL)
		root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;

	y->right = x;
	x->p = y;
}

//--------------------------------------------------------------------------------
//������ӹ��̣���������������Υ��������Ľڵ�
template <class Key,class Value>
void  Red_Black_Tree<Key,Value>::rb_insert_fixup(Red_Black_Tree_Node<Key,Value>* z)
{
	Red_Black_Tree_Node<Key,Value> *y;
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)//z.p��z�游������
		{
			y = z->p->p->right;

			if (y->color == RED)//case1 z����ڵ�Ϊ��ɫ
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else   //case 2 or case 3����ڵ��Ǻ�ɫ
			{
				if (z == z->p->right)//z���Һ���
				{
					z = z->p;
					left_rotate(z);
				}
				//case3  zΪ����
				z->p->color = BLACK;
				z->p->p->color = RED;
				right_rotate(z->p->p);
			}

		}

		else if (z->p == z->p->p->right)//z.p��z�游���Һ��ӣ����ϱ������ͬҲ����������
		{
			y = z->p->p->left;
			if (y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else
			{
				if (z == z->p->left)
				{
					z = z->p;
					right_rotate(z);
				}

				z->p->color = BLACK;
				z->p->p->color = RED;
				left_rotate(z->p->p);
			}
		}
	}
	root->color = BLACK;
}


//-------------------------------------------------------------------------------------------
//����ɾ��rb_treeĳ���ڵ�����Ŀ���Υ����������ʵ���Ϊ
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::rb_delete_fixup(Red_Black_Tree_Node<Key,Value> *x)
{
	Red_Black_Tree_Node<Key,Value> *w;
	//����������ĺ�ɫ��һ��������һ�������ϣ��������ն���ĺ�ɫ����Ϊһ����ɫ�Ľ��
	while (x != root&&x->color == BLACK)
	{
		//��x���丸�����㣨�ҽ���������Ӧ��  
		if (x == x->p->left)
		{
			//��wΪx���ֵܣ�����w�Ĳ�ͬ����Ϊ�������������  
			//ִ��ɾ������ǰx�϶���û���ֵܵģ�ִ��ɾ��������x�϶������ֵܵ�
			w = x->p->right;

			if (w->color == RED)// case 1  wΪ��ɫ
			{
				w->color = BLACK;
				x->p->color = RED;
				left_rotate(x->p);
				w = x->p->right;//���������ο��Խ���2 3 4�κ�һ������
			}

			if (w->left->color == BLACK && w->right->color == BLACK)//case 2��wΪ��ɫ��w����������Ҳ���Ǻ�ɫ  
			{
				w->color = RED;
				x = x->p;
			}
			else //case 3 w�Ǻ�ɫ��,w->left�Ǻ�ɫ��,w->right�Ǻ�ɫ��
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(w);
					w = x->p->right;
				}

				//case 4��w�Ǻ�ɫ��,w->left�����Ǻ�ɫҲ�ǿ����Ǻ�ɫ,w->right �Ǻ�ɫ
				//�޸� w �� x.p����ɫ  
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				left_rotate(x->p);
				x = root;
			}
		}
		else if (x == x->p->right)//xΪ�丸�ڵ���Һ���
		{ 
			w = x->p->left;  
			if (w->color == RED)//case1,w.colorΪ��ɫ
			{
				w->color = BLACK;
				x->p->color = RED; 
				right_rotate(x->p);  
				w = x->p->left;//��wΪx���ֵܣ�תΪ2.3.4�������֮һ  
			}
			  
			if (w->right->color == BLACK && w->left->color == BLACK)//case2��wΪ��ɫ��w����������Ҳ���Ǻ�ɫ
			{ 
				w->color = RED;
				x = x->p;
			}
			else //case3��w�Ǻ�ɫ��,w->left��ɫ,w->right�Ǻ�ɫ����������෴��w->left�Ǻ�ɫ��,w->right�Ǻ�ɫ�ģ�
			{
				if (w->left->color == BLACK)
				{  
					w->right->color = BLACK;
					w->color = RED; 
					left_rotate(w);
					  
					w = x->p->left;////��wΪx�����ֵܣ�����case4
				}
				//case4��w�Ǻ�ɫ��, w->left�Ǻ�ɫ , w->right�ǿ����Ǻ�ɫҲ�����Ǻ�ɫ.
				//�޸�w��p[x]����ɫ  
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK; 
				right_rotate(x->p);
				//��ʱ�����Ѿ���������x��Ϊ�������Ϊ�˽���ѭ��  
				x = root;
			}
		}
	}

	x->color = BLACK;//whileѭ��������ʱ��x�ĵ���ɫΪ��ɫ���������պ�ɫ.
}


//---------------------------------------------------------------------------------------------
//���������rb_insert
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::rb_insert(Red_Black_Tree_Node<Key,Value>* z)
{
	Red_Black_Tree_Node<Key,Value>* y = NIL;
	Red_Black_Tree_Node<Key,Value>* x = root;
	while (x != NIL)//�ҵ������λ��
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->p = y;
	if (y == NIL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	z->left = NIL;
	z->right = NIL;
	z->color = RED;

	rb_insert_fixup(z);
}


//-------------------------------------------------------------------------------
//�ڵ�ɾ��������rb_delete
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::rb_delete(Red_Black_Tree_Node<Key,Value>* z)
{
	Red_Black_Tree_Node<Key,Value>* y;
	Red_Black_Tree_Node<Key,Value>* x;
	if (z->left == NIL || z->right == NIL)
		y = z;
	else y = tree_successor(z);

	if (y->left != NIL)
		x = y->left;
	else x = y->right;

	x->p = y->p;
	if (y->p == NIL)
		root = x;
	else if (y == y->p->left)
		y->p->left = x;
	else
		y->p->right = x;

	if (y != z)
		z->key = y->key;
	//�����ɾ���Ľ���Ǻ�ɫ�ģ�����Ҫ����  
	if (y->color == BLACK)
		rb_delete_fixup(x);
}

//-----------------------------------------------------------------------------------------
//���������
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::inorder_tree_walk() const
{
	if (NULL != root)
	{
		stack<Red_Black_Tree_Node<Key,Value>* >s;
		node a;
		Red_Black_Tree_Node<Key,Value> *p;
		p = root;
		while (NIL != p || !s.empty())
		{
			if (NIL != p)
			{
				s.push(p);
				p = p->left;
			}
			else
			{
				p = s.top();
				s.pop();
				a.value=p->value;
				a.key=p->key;
				help.push_back(a);
				num++;
			/*	cout << p->key << ":";
				cout << p->value<<endl;*/
				p = p->right;
			}
		}
	}
}

//�����ã�
int main()
{
	Red_Black_Tree<string ,int> tree ;
	ifstream file;
	file.open("d:\\dblp\\content.txt",ios::in);
    string s;
	for(int i=0;i<10000000;i++)
	{
	getline(file,s);
	cout<<i<<endl;
	if(tree.find_node(s)!=0){
		Red_Black_Tree_Node<string,int>*x=tree.search_tree_node(s);
		x->value+=1;

	}
	else {
	     Red_Black_Tree_Node<string,int>*x=new Red_Black_Tree_Node<string,int>(s);
		tree.rb_insert(x);
	}

	}
	tree.inorder_tree_walk();
	sort(help.begin(),help.end());
	ofstream outfile;
	outfile.open("d:\\result",ios::out);
	for(int i=num-1;i>=num-100;i--)
		outfile<<help[i].key<<"\n"<<help[i].value<<endl;

    system("pause");
}
