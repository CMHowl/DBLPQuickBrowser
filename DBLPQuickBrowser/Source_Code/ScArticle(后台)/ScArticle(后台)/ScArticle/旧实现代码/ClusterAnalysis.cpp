#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include <cstdio>
using namespace std;

// ��
struct Edge {
	int vName;
	int weight;
	struct Edge* next;
};

// ����(����ͷ)
struct Vertex {
	int vName;
	struct Edge* next;
};

// ����ͼ
class GraphList
{
public:
	~GraphList();

	void createGraph();
	void printGraph();

	// 1. ���붨����
	void inputVertexCount();
	// 2. ���ɶ�������
	void makeVertexArray();
	// 3. �������
	void inputEdgeCount();
	// 4. ����ߵ���ʼ��
	void inputEdgeInfo();
	// 5. ��ӱ߽ڵ�����Ӧ��������
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
	// ��ʼ��
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

void GraphList::inputEdgeInfo()//��ʵ������֪������
{
	cout << "please input edge information:" << endl;
	for (int i = 0; i < m_eCount; ++i) {
		cout << "the edge " << i << ":" << endl;

		// ���
		int from = 0;
		cout << "From: ";
		cin >> from;

		// Ȩֵ
		int weight = 0;
		cout << "Weight:";
		cin >> weight;

		// �յ�
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
// ���̿���
// **************************************************************************
void GraphList::createGraph()
{
	inputVertexCount();
	makeVertexArray();
	inputEdgeCount();
	inputEdgeInfo();
}