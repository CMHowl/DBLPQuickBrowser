#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>
//#include "stdafx.h"
using namespace std;
static const int bigLoop = 2000;


//--已知Bug：无法读取多作者书籍时会出错--
//--已完成功能：输入作者名，能展示作者论文信息--

class ArticleNode
{
public:
	string *Arthor;
	string Title="";
	string Pages="";
	string Year="";
	string Volume="";
	string Journal="";
	string Number="";
	string Url="";
	string Ee="";
	string Cdrom ="";
	string Note = "";
	string Cite = "";
	bool exist = false;
	ArticleNode* pre = NULL;
	ArticleNode* next = NULL;
};

ArticleNode** ArticleInit()
{
	ofstream outfile;
	outfile.open("ErrorCode.txt", ios::out);

	static ArticleNode *ArSquareHead[bigLoop];
	string temp;
	ifstream infile;
	infile.open("dblp.xml", ios::in);//文件读取
	getline(infile, temp);//吃掉版本信息
	getline(infile, temp);//吃掉注释
	getline(infile, temp);//吃掉<dblp>前缀
	//while (temp.find("</dblp>") == string::npos) { //只要没读到</dblp>,就继续操作
		for (int scount = 0; scount < bigLoop; scount++)
		{
			ArticleNode *ArHead = new ArticleNode();
			ArticleNode *ArList = ArHead;
			ArSquareHead[scount] = ArHead;
			for (int i = 0; i < 1000; i++)//测试用，执行5次
			{
				getline(infile, temp);//读取一行
				//if (temp.find("<!"))continue;//读取到注释，本次循环自动忽略
				if (temp.find("<article") != string::npos)//读到<article,开始读取该文章信息并写入
				{
					string testA = temp;
					getline(infile, temp);//读取一行

					if (infile.eof() == true) { cout << "读取到文件尾！" << endl; break; }
					if (temp.compare(testA) == 0) { cout << "文章末尾" << endl; break;}
					if (temp.find("</article>") != string::npos) cout << "空结点" << endl;
					int inputcounter = 0;
					bool unknownmark = false;//未知元素标记
					while (temp.find("</article>") == string::npos) {
						switch (inputcounter)
						{

						case 0://该节点为真
						{ArList->exist = true; }

						case 1://输入Author信息
						{
							int zz = 0;
							while (temp.find("author") != string::npos) {//找到author
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Arthor[zz] = temp.substr(startPos + 1, endPos - (startPos + 1));
								//cout << "读取" << zz << "号作者" << ArList->Arthor[zz] << endl;
								//zz++;
								getline(infile, temp);//读取一行



								 
							}
						}

						case 2://输入Title信息
						{
							size_t startPos = temp.find_first_of(">");
							size_t endPos = temp.find_last_of("<");
							ArList->Title = temp.substr(startPos + 1, endPos - (startPos + 1));
							getline(infile, temp);//读取一行



							 
						}


						case 3://输入Pages信息
						{
							if (temp.find("pages") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Pages = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 4://输入Year信息
						{
							if (temp.find("year") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Year = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 5://输入Volume信息
						{
							if (temp.find("volume") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Volume = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 6://输入Journal信息
						{
							if (temp.find("journal") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Journal = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 7://输入Number信息
						{
							if (temp.find("number") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Number = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 8://输入Url信息
						{
							if (temp.find("url") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Url = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 9://输入Ee信息
						{
							if (temp.find("ee") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Ee = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 10://输入Cdrom信息
						{
							if (temp.find("cdrom") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Cdrom = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 11://输入Note信息
						{
							if (temp.find("note") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Note = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}

						case 12://输入Cite信息
						{
							if (temp.find("cite") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Cite = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//读取一行



								 
								unknownmark = false;
							}
						}


						case 13:
						{if ((temp.find("</article>") != string::npos) ||
							(temp.find("author") != string::npos) ||
							(temp.find("title") != string::npos)||
							(temp.find("pages") != string::npos) ||
							(temp.find("year") != string::npos) ||
							(temp.find("volume") != string::npos) ||
							(temp.find("journal") != string::npos) ||
							(temp.find("number") != string::npos) ||
							(temp.find("url") != string::npos) ||
							(temp.find("ee") != string::npos) ||
							(temp.find("note") != string::npos) ||
							(temp.find("cite") != string::npos) ||
							(temp.find("cdrom") != string::npos));
						else {
							cout << "发现未知元素:" << temp << endl;
							getline(infile, temp);//读取一行


							// 
						}
						}
						//case 14://纠错，查找未知元素
						//{
						//	if ((temp.find("</article>") == string::npos) && (unknownmark == true)) {
						//		cout << "未知元素：" << temp << endl;
						//		getline(infile, temp);//读取一行
						//		unknownmark = false;
						//	}
						//	else unknownmark = true;
						//}



						}
					}
					ArticleNode *TempAr = new ArticleNode();
					ArList->next = TempAr;
					ArList = ArList->next;//该文章信息读写完毕，读取下一条文章
					TempAr = NULL;
				}
				//if (scount >= 36) cout << "小循环执行次数:" << i << endl;
				// 
				//if ((scount >= 36) && (i == 53)) break;
			}
			ArHead = NULL;
			ArList = NULL;
			delete ArHead;
			delete ArList;
			cout << "大循环执行次数：" << scount << endl;
			if (temp.find("</dblp>") != string::npos) break;
			if (infile.eof() == 1) break;
		}
	//}
	cout << "读取完毕！" << endl;
	return ArSquareHead;
}

void BasicNameSearch(ArticleNode **head)
{
	if (head == NULL) cout << "No Such File!" << endl;
	string search_name;
	while (getline(cin, search_name))
	{
		for (int scount2 = 0; scount2 < bigLoop; scount2++)
		{
			ArticleNode* p = head[scount2];
			while (p->exist == true)
			{
				for (int i = 0; i < 5; i++)
				{
					if (p->Arthor[i] == search_name)//多作者情况加入在内
					{
						cout << "这位" << search_name << "作者发表过以下文章：" << endl;
						for (int j = 0; j < 5; j++)
						{
							cout << "Author" << j << ": " << p->Arthor[j] << endl;
							if (p->Arthor[j + 1] == "")break;
						}
						cout << "Title: " << p->Title << endl;
						cout << "Pages: " << p->Pages << endl;
						cout << "Year: " << p->Year << endl;
						cout << "Volume: " << p->Volume << endl;
						cout << "Journal: " << p->Journal << endl;
						cout << "Number: " << p->Number << endl;
						cout << "Url: " << p->Url << endl;
						cout << "Ee: " << p->Ee << endl;
						cout << endl;
					}
				}
				p = p->next;
			}
			p = NULL;
			delete p;
		}
	}
}

