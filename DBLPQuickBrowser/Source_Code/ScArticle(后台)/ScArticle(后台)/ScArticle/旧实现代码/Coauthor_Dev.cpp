#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<set>
#include<map>

using namespace std;

const string constUrl = "G:\\ScArticle\\Src\\";//����·��ǰ׺

struct MainAuthors
{
	string mainauthors_name;
	string mainauthors_length;
	string author_name;
	string author_title;
	string author_urlpt;
};

class MainAuthorWriter
{
public:
	MainAuthors mainauthor;
	MainAuthorWriter();
	~MainAuthorWriter();
	void Deviation();
	void CoInfo_Writer();
private:

};

MainAuthorWriter::MainAuthorWriter()
{
}

MainAuthorWriter::~MainAuthorWriter()
{
}

void MainAuthorWriter::Deviation()
{
}

void MainAuthorWriter::CoInfo_Writer()
{
	string tempstr;//�ݴ����ַ���
	long long divcounter = 0;//��¼ƫ����������ӳ��
	map<string,long> RBtree_Author;//�������¼��������ƫ����
	ifstream infile;
	string MyUrl = constUrl;
	infile.open("dblp.xml", ios::in);//�ļ���ȡ,����������·�������ֶ��޸� 
	for (int i = 0; i < 3; i++) {
		getline(infile, tempstr);//Ԥ����
		divcounter += tempstr.length();
	}



}