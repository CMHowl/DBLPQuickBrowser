#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include <cstdio>
using namespace std;

// 边
struct Edge {
	int vName;
	int weight;
	struct Edge* next;
};

// 顶点(链表头)
struct Vertex {
	int vName;
	struct Edge* next;
};

// 有向图
class GraphList
{
public:
	~GraphList();

	void createGraph();
	void printGraph();

	// 1. 输入定点数
	void inputVertexCount();
	// 2. 生成定点数组
	void makeVertexArray();
	// 3. 输入边数
	void inputEdgeCount();
	// 4. 输入边的起始点
	void inputEdgeInfo();
	// 5. 添加边节点至对应的链表中
	void addEdgeToList(int vFrom, int weight, int vTo);
private:
	int m_vCount;
	int m_eCount;
	Vertex* m_vVertex;
};

GraphList::~GraphList() {
	for (int i = 0; i < m_vCount; ++i) {
		Edge* tmp = m_vVertex[i].next;
		Edge* edge = NULL;
		while (tmp) {
			edge = tmp;
			tmp = tmp->next;
			delete edge;
			edge = NULL;
		}
	}
	delete[] m_vVertex;
}

void GraphList::inputVertexCount()
{
	cout << "please input count of vertex:";
	cin >> m_vCount;
}

void GraphList::makeVertexArray()
{
	m_vVertex = new Vertex[m_vCount];
	// 初始化
	for (int i = 0; i < m_vCount; ++i) {
		m_vVertex[i].vName = i;
		m_vVertex[i].next = NULL;
	}
}

void GraphList::inputEdgeCount()
{
	cout << "please input count of edge:";
	cin >> m_eCount;
}

void GraphList::inputEdgeInfo()//事实上无需知道边数
{
	cout << "please input edge information:" << endl;
	for (int i = 0; i < m_eCount; ++i) {
		cout << "the edge " << i << ":" << endl;

		// 起点
		int from = 0;
		cout << "From: ";
		cin >> from;

		// 权值
		int weight = 0;
		cout << "Weight:";
		cin >> weight;

		// 终点
		int to = 0;
		cout << "To: ";
		cin >> to;
		cout << endl;

		addEdgeToList(from, weight, to);
	}
}

void GraphList::addEdgeToList(int vFrom, int weight, int vTo)
{
	Edge* edge = new Edge();
	edge->vName = vTo;
	edge->weight = weight;
	edge->next = NULL;
	if (m_vVertex[vFrom].next) {
		Edge* tmp = m_vVertex[vFrom].next;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = edge;
	}
	else {
		m_vVertex[vFrom].next = edge;
	}
}

void GraphList::printGraph()
{
	for (int i = 0; i < m_vCount; ++i) {
		Edge* tmp = m_vVertex[i].next;
		cout << "list:" << m_vVertex[i].vName << "->";
		while (tmp) {
			cout << "(" << tmp->weight << ")";
			cout << tmp->vName << "->";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}
}

// **************************************************************************
// 流程控制
// **************************************************************************
void GraphList::createGraph()
{
	inputVertexCount();
	makeVertexArray();
	inputEdgeCount();
	inputEdgeInfo();
}