#pragma once
#include "allFuction.h"
#include <map>
using namespace std;
struct Author_Node
{
	string author_name;
	string author_frequence;
};

class AllAuthorWriter
{
public:
	map<string,int> aufrequence_RBtree;
	Author_Node* aunode = new Author_Node();
	AllAuthorWriter() {};
	~AllAuthorWriter() {};
	void Author_RBWriter();
	void Author_RBProcessor();
	//void Author_RBProcessor();
};