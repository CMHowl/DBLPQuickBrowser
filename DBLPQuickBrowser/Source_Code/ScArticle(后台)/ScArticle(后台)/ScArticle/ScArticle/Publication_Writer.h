#pragma once
#include"allFuction.h"
using namespace std;
struct Publications
{
	string publications_name;
	long long publications_urlpt;
};

class PublicationWriter
{
public:
	Publications* publication = new Publications();
	PublicationWriter() {};
	~PublicationWriter() {};
	void main_Writer();
};