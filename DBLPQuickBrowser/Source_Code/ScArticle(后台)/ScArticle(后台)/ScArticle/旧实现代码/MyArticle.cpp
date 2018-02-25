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


//--��֪Bug���޷���ȡ�������鼮ʱ�����--
//--����ɹ��ܣ���������������չʾ����������Ϣ--

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
	infile.open("dblp.xml", ios::in);//�ļ���ȡ
	getline(infile, temp);//�Ե��汾��Ϣ
	getline(infile, temp);//�Ե�ע��
	getline(infile, temp);//�Ե�<dblp>ǰ׺
	//while (temp.find("</dblp>") == string::npos) { //ֻҪû����</dblp>,�ͼ�������
		for (int scount = 0; scount < bigLoop; scount++)
		{
			ArticleNode *ArHead = new ArticleNode();
			ArticleNode *ArList = ArHead;
			ArSquareHead[scount] = ArHead;
			for (int i = 0; i < 1000; i++)//�����ã�ִ��5��
			{
				getline(infile, temp);//��ȡһ��
				//if (temp.find("<!"))continue;//��ȡ��ע�ͣ�����ѭ���Զ�����
				if (temp.find("<article") != string::npos)//����<article,��ʼ��ȡ��������Ϣ��д��
				{
					string testA = temp;
					getline(infile, temp);//��ȡһ��

					if (infile.eof() == true) { cout << "��ȡ���ļ�β��" << endl; break; }
					if (temp.compare(testA) == 0) { cout << "����ĩβ" << endl; break;}
					if (temp.find("</article>") != string::npos) cout << "�ս��" << endl;
					int inputcounter = 0;
					bool unknownmark = false;//δ֪Ԫ�ر��
					while (temp.find("</article>") == string::npos) {
						switch (inputcounter)
						{

						case 0://�ýڵ�Ϊ��
						{ArList->exist = true; }

						case 1://����Author��Ϣ
						{
							int zz = 0;
							while (temp.find("author") != string::npos) {//�ҵ�author
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Arthor[zz] = temp.substr(startPos + 1, endPos - (startPos + 1));
								//cout << "��ȡ" << zz << "������" << ArList->Arthor[zz] << endl;
								//zz++;
								getline(infile, temp);//��ȡһ��



								 
							}
						}

						case 2://����Title��Ϣ
						{
							size_t startPos = temp.find_first_of(">");
							size_t endPos = temp.find_last_of("<");
							ArList->Title = temp.substr(startPos + 1, endPos - (startPos + 1));
							getline(infile, temp);//��ȡһ��



							 
						}


						case 3://����Pages��Ϣ
						{
							if (temp.find("pages") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Pages = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 4://����Year��Ϣ
						{
							if (temp.find("year") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Year = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 5://����Volume��Ϣ
						{
							if (temp.find("volume") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Volume = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 6://����Journal��Ϣ
						{
							if (temp.find("journal") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Journal = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 7://����Number��Ϣ
						{
							if (temp.find("number") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Number = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 8://����Url��Ϣ
						{
							if (temp.find("url") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Url = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 9://����Ee��Ϣ
						{
							if (temp.find("ee") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Ee = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 10://����Cdrom��Ϣ
						{
							if (temp.find("cdrom") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Cdrom = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 11://����Note��Ϣ
						{
							if (temp.find("note") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Note = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
								unknownmark = false;
							}
						}

						case 12://����Cite��Ϣ
						{
							if (temp.find("cite") != string::npos) {
								size_t startPos = temp.find_first_of(">");
								size_t endPos = temp.find_last_of("<");
								ArList->Cite = temp.substr(startPos + 1, endPos - (startPos + 1));
								getline(infile, temp);//��ȡһ��



								 
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
							cout << "����δ֪Ԫ��:" << temp << endl;
							getline(infile, temp);//��ȡһ��


							// 
						}
						}
						//case 14://��������δ֪Ԫ��
						//{
						//	if ((temp.find("</article>") == string::npos) && (unknownmark == true)) {
						//		cout << "δ֪Ԫ�أ�" << temp << endl;
						//		getline(infile, temp);//��ȡһ��
						//		unknownmark = false;
						//	}
						//	else unknownmark = true;
						//}



						}
					}
					ArticleNode *TempAr = new ArticleNode();
					ArList->next = TempAr;
					ArList = ArList->next;//��������Ϣ��д��ϣ���ȡ��һ������
					TempAr = NULL;
				}
				//if (scount >= 36) cout << "Сѭ��ִ�д���:" << i << endl;
				// 
				//if ((scount >= 36) && (i == 53)) break;
			}
			ArHead = NULL;
			ArList = NULL;
			delete ArHead;
			delete ArList;
			cout << "��ѭ��ִ�д�����" << scount << endl;
			if (temp.find("</dblp>") != string::npos) break;
			if (infile.eof() == 1) break;
		}
	//}
	cout << "��ȡ��ϣ�" << endl;
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
					if (p->Arthor[i] == search_name)//�����������������
					{
						cout << "��λ" << search_name << "���߷�����������£�" << endl;
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

