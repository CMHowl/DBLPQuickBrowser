#pragma once
#include "allFuction.h"
using namespace std;
struct Coauthor
{
	string coauthor_name;
	long long coauthor_urlpt;
};

class CoauthorWriter
{
public:
	Coauthor* coauthor = new Coauthor();
	CoauthorWriter() {};
	~CoauthorWriter() {};
	void coa_Writer();
};