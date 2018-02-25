#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

const string constUrl = "G:\\ScArticle\\ScArticle\\AuthorFile3\\";//����·��ǰ׺

struct AuthorNode
{
	string author = "";
	AuthorNode* next = NULL;
};

AuthorNode*& Author_Calculate(AuthorNode *&authorname, string tempstr)//����������������������
{
	size_t startPos = tempstr.find_first_of(">");
	size_t endPos = tempstr.find_last_of("<");
	authorname->author = tempstr.substr(startPos + 1, endPos - (startPos + 1));
	//ָ���ƶ�
	AuthorNode *authortemp = new AuthorNode();
	authorname->next = authortemp;
	authortemp = NULL;
	delete authortemp;
	authorname = authorname->next;
	authorname->next = NULL;
	return authorname;
}

ofstream& Write_intoTempFile(AuthorNode *&authorhead, ofstream& outfile,//�洢��ʱ�ļ�����
	stringstream &otherinfo, string articleinfo, string tempstr, bool judge)
{
	if (judge != true)outfile << articleinfo << endl;//д��article

	AuthorNode *authortemp2 = authorhead;
	while ((authortemp2->next != NULL) && (!judge == true))
	{
		outfile << "<author>" << authortemp2->author << "</author>" << endl;//д��author
		authortemp2 = authortemp2->next;
	}
	if (judge != true)getline(otherinfo, tempstr);
	while (tempstr.find("</article>") == string::npos)
	{
		if (judge == true)break;
		outfile << tempstr << endl;
		getline(otherinfo, tempstr);
	}
	if (judge != true)outfile << tempstr << endl;//д��</article>
	return outfile;
}



void WriteToMyFile()
{
	string tempstr;
	string filenamestr;
	string articleinfo;
	stringstream otherinfo;
	ifstream infile;
	string MyUrl = constUrl;
	//---------��Ҫ�õ�����ʱ����---------


	//---------Ԥ��ȡdblp---------
	infile.open("dblp.xml", ios::in);//�ļ���ȡ,����������·�������ֶ��޸� 
	getline(infile, tempstr);//�Ե��汾��Ϣ
	getline(infile, tempstr);//�Ե�ע��
	getline(infile, tempstr);//�Ե�<dblp>ǰ׺
	//---------Ԥ��ȡ��ϣ���ʼarticle��ȡ---------


	int counterzz = 0;//ѭ���������������Թ۲���
	//while (tempstr.find("</dblp>") == string::npos) { //ֻҪû����</dblp>,�ͼ�������
	for (int j = 0; j < 2000000; j++) {//���������������޸�


		//---------����������---------
		bool copymark = false;//���Ʊ�ǣ���Զ��������
		getline(infile, articleinfo);//��ȡarticle�У�����articleinfo
		AuthorNode *authorname = new AuthorNode();
		AuthorNode *authorhead = authorname;
		//---------�������---------


		//---------һ�ֶ�ȡ��ʼ---------
		if (articleinfo.find("<article") != string::npos)//����<article,��ʼ��ȡ��������Ϣ��д��
		{
			getline(infile, tempstr);//��ȡһ��,�˴�ӦΪauthor����
			bool judge = false;
			while (tempstr.find("author") != string::npos)
			{
				if (judge == true)copymark = true;//�����ߣ���Ʊ��Ϊ��
				Author_Calculate(authorname, tempstr);//���ú���
				getline(infile, tempstr);//��ȡһ��,�˴�����Ϊauthor����
				judge = true;
			}//��һ�в���author,��������ѭ��

			while (tempstr.find("</article>") == string::npos)//��������Ϣ����title��pages�ȣ�д��otherinfo��
			{
				otherinfo << tempstr << endl;
				getline(infile, tempstr);
			}//*

			otherinfo << tempstr << endl;//д��</article>

			judge = false;//��������Ϊ�٣���Ϊ����ĵڶ����߱��
			for (AuthorNode *authorzz = authorhead; authorzz->author != "";)
			{
				ofstream outfile;

				filenamestr = authorzz->author;
				filenamestr.append(".txt");
				MyUrl.append(filenamestr);//����·��ƴ�����

				outfile.open("TempFile.txt", ios::out | ios::app);//��ʱ�ļ����������ڸ���
				Write_intoTempFile(authorhead, outfile, otherinfo, articleinfo, tempstr, judge);//д����ʱ�ļ���
				outfile.close();//������رգ���һ��TempFile����Ϊ��������

				ifstream finalin("TempFile.txt", ios::in);
				ofstream finalout(MyUrl, ios::out | ios::app);
				finalout << finalin.rdbuf();//�ĵ�����
				finalout << endl;//���У�Ϊ������...
				finalin.close();
				finalout.close();

				MyUrl = constUrl;//�ָ�����·��ǰ׺
				authorzz = authorzz->next;
				judge = true;//��һ���߶�ȡ��ϣ�������
			}
			ofstream fileout("TempFile.txt", ios::trunc);//���Tempfile
			fileout.close();
		}
		//---------һ�ֶ�ȡ����---------


		counterzz++;//����������++
		if (counterzz % 1000 == 0)cout << "ѭ��������" << counterzz << endl;
	}
}


//
//int main()
//{
//	WriteToMyFile();
//	cout << "д�����" << endl;
//}
//
