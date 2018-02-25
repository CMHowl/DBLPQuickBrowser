#pragma once
#include "allFuction.h"
using namespace std;
class CoauthorReader
{
public:
	set<string> coauthor_tree;
	string tempstr;
	long long div_finder;
	CoauthorReader() {};
	~CoauthorReader() {};
	void Probe_RBTree();
	void Show_inDBLP();
	void main_Reader(string search_name);
	void author_Reader(string search_name);
};