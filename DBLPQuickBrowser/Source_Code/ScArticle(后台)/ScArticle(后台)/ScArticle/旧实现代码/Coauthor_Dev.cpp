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

const string constUrl = "G:\\ScArticle\\Src\\";//绝对路径前缀

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
	string tempstr;//暂存用字符串
	long long divcounter = 0;//记录偏移量，便于映射
	map<string,long> RBtree_Author;//红黑树记录作者名和偏移量
	ifstream infile;
	string MyUrl = constUrl;
	infile.open("dblp.xml", ios::in);//文件读取,如果不是相对路径，请手动修改 
	for (int i = 0; i < 3; i++) {
		getline(infile, tempstr);//预处理
		divcounter += tempstr.length();
	}



}