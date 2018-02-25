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
	Red_Black_Tree_Node<Key,Value>* get_root() const;//获取根节点
	bool find_node(Key&key);//
	Red_Black_Tree_Node<Key,Value>* search_tree_node(const Key& k)const;//查找关键字为k的节点
	void left_rotate(Red_Black_Tree_Node<Key,Value> *pnode);//左旋转操作
	void right_rotate(Red_Black_Tree_Node<Key,Value> *pnode);//右旋转操作
	void rb_insert_fixup(Red_Black_Tree_Node<Key,Value>*pnode);//修正插入操作引起的违反红黑树性质的行为
	void rb_delete_fixup(Red_Black_Tree_Node<Key,Value> *pnode);//修正删除操作引起的违反红黑树性质的行为
	
	void rb_insert(Red_Black_Tree_Node<Key,Value>* z);//插入节点
	void rb_delete(Red_Black_Tree_Node<Key,Value>* z);//删除节点


	void inorder_tree_walk()const;//遍历红黑树并压入vector中
	void make_empty(Red_Black_Tree_Node<Key,Value>* root);
	//~Red_Black_Tree();


public:
	static	Red_Black_Tree_Node<Key,Value> *NIL;
private:
	Red_Black_Tree_Node<Key,Value>* root;
};

//初始化nil
template <class Key,class Value>
Red_Black_Tree_Node<Key,Value>* Red_Black_Tree<Key,Value>::NIL = new Red_Black_Tree_Node<Key,Value>("null");

//初始化root节点   利用默认构造函数
template <class Key,class Value>
Red_Black_Tree<Key,Value>::Red_Black_Tree()
{
	root = NIL;
};

//---------------------------------------------------------------------------------------
template <class Key,class Value>
Red_Black_Tree_Node<Key,Value>* Red_Black_Tree<Key,Value>::get_root() const//获取根节点
{
	return root;
}
//查找是否存在key的节点
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
//查找树中关键字key的节点

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
//左旋转
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
//右旋转
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
//插入的子过程：修正插入过后可能违反红黑树的节点
template <class Key,class Value>
void  Red_Black_Tree<Key,Value>::rb_insert_fixup(Red_Black_Tree_Node<Key,Value>* z)
{
	Red_Black_Tree_Node<Key,Value> *y;
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)//z.p是z祖父的左孩子
		{
			y = z->p->p->right;

			if (y->color == RED)//case1 z的叔节点为红色
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else   //case 2 or case 3：叔节点是黑色
			{
				if (z == z->p->right)//z是右孩子
				{
					z = z->p;
					left_rotate(z);
				}
				//case3  z为左孩子
				z->p->color = BLACK;
				z->p->p->color = RED;
				right_rotate(z->p->p);
			}

		}

		else if (z->p == z->p->p->right)//z.p是z祖父的右孩子，和上边情况相同也有三种情形
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
//修正删除rb_tree某个节点带来的可能违反红黑树性质的行为
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::rb_delete_fixup(Red_Black_Tree_Node<Key,Value> *x)
{
	Red_Black_Tree_Node<Key,Value> *w;
	//如果这个额外的黑色在一个根结点或一个红结点上，结点会吸收额外的黑色，成为一个黑色的结点
	while (x != root&&x->color == BLACK)
	{
		//若x是其父的左结点（右结点的情况相对应）  
		if (x == x->p->left)
		{
			//令w为x的兄弟，根据w的不同，分为三种情况来处理  
			//执行删除操作前x肯定是没有兄弟的，执行删除操作后x肯定是有兄弟的
			w = x->p->right;

			if (w->color == RED)// case 1  w为红色
			{
				w->color = BLACK;
				x->p->color = RED;
				left_rotate(x->p);
				w = x->p->right;//由这种情形可以进入2 3 4任何一种情形
			}

			if (w->left->color == BLACK && w->right->color == BLACK)//case 2：w为黑色，w的两个孩子也都是黑色  
			{
				w->color = RED;
				x = x->p;
			}
			else //case 3 w是黑色的,w->left是红色的,w->right是黑色的
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(w);
					w = x->p->right;
				}

				//case 4：w是黑色的,w->left可以是红色也是可以是黑色,w->right 是红色
				//修改 w 和 x.p的颜色  
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				left_rotate(x->p);
				x = root;
			}
		}
		else if (x == x->p->right)//x为其父节点的右孩子
		{ 
			w = x->p->left;  
			if (w->color == RED)//case1,w.color为红色
			{
				w->color = BLACK;
				x->p->color = RED; 
				right_rotate(x->p);  
				w = x->p->left;//令w为x的兄弟，转为2.3.4三种情况之一  
			}
			  
			if (w->right->color == BLACK && w->left->color == BLACK)//case2：w为黑色，w的两个孩子也都是黑色
			{ 
				w->color = RED;
				x = x->p;
			}
			else //case3：w是黑色的,w->left黑色,w->right是红色（与上面的相反：w->left是红色的,w->right是黑色的）
			{
				if (w->left->color == BLACK)
				{  
					w->right->color = BLACK;
					w->color = RED; 
					left_rotate(w);
					  
					w = x->p->left;////令w为x的新兄弟，进入case4
				}
				//case4：w是黑色的, w->left是红色 , w->right是可以是红色也可以是黑色.
				//修改w和p[x]的颜色  
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK; 
				right_rotate(x->p);
				//此时调整已经结束，将x置为根结点是为了结束循环  
				x = root;
			}
		}
	}

	x->color = BLACK;//while循环结束的时候x的的颜色为红色，用来吸收黑色.
}


//---------------------------------------------------------------------------------------------
//插入操作：rb_insert
template <class Key,class Value>
void Red_Black_Tree<Key,Value>::rb_insert(Red_Black_Tree_Node<Key,Value>* z)
{
	Red_Black_Tree_Node<Key,Value>* y = NIL;
	Red_Black_Tree_Node<Key,Value>* x = root;
	while (x != NIL)//找到插入的位置
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
//节点删除操作：rb_delete
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
	//如果被删除的结点是黑色的，则需要调整  
	if (y->color == BLACK)
		rb_delete_fixup(x);
}

//-----------------------------------------------------------------------------------------
//遍历红黑树
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

//测试用：
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
