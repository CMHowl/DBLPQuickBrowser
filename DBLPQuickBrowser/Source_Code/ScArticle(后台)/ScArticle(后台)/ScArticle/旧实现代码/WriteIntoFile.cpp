#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

const string constUrl = "G:\\ScArticle\\ScArticle\\AuthorFile3\\";//绝对路径前缀

struct AuthorNode
{
	string author = "";
	AuthorNode* next = NULL;
};

AuthorNode*& Author_Calculate(AuthorNode *&authorname, string tempstr)//计算多作者情况，串成链表
{
	size_t startPos = tempstr.find_first_of(">");
	size_t endPos = tempstr.find_last_of("<");
	authorname->author = tempstr.substr(startPos + 1, endPos - (startPos + 1));
	//指针移动
	AuthorNode *authortemp = new AuthorNode();
	authorname->next = authortemp;
	authortemp = NULL;
	delete authortemp;
	authorname = authorname->next;
	authorname->next = NULL;
	return authorname;
}

ofstream& Write_intoTempFile(AuthorNode *&authorhead, ofstream& outfile,//存储临时文件函数
	stringstream &otherinfo, string articleinfo, string tempstr, bool judge)
{
	if (judge != true)outfile << articleinfo << endl;//写入article

	AuthorNode *authortemp2 = authorhead;
	while ((authortemp2->next != NULL) && (!judge == true))
	{
		outfile << "<author>" << authortemp2->author << "</author>" << endl;//写入author
		authortemp2 = authortemp2->next;
	}
	if (judge != true)getline(otherinfo, tempstr);
	while (tempstr.find("</article>") == string::npos)
	{
		if (judge == true)break;
		outfile << tempstr << endl;
		getline(otherinfo, tempstr);
	}
	if (judge != true)outfile << tempstr << endl;//写入</article>
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
	//---------需要用到的临时变量---------


	//---------预读取dblp---------
	infile.open("dblp.xml", ios::in);//文件读取,如果不是相对路径，请手动修改 
	getline(infile, tempstr);//吃掉版本信息
	getline(infile, tempstr);//吃掉注释
	getline(infile, tempstr);//吃掉<dblp>前缀
	//---------预读取完毕，开始article读取---------


	int counterzz = 0;//循环次数，仅供测试观察用
	//while (tempstr.find("</dblp>") == string::npos) { //只要没读到</dblp>,就继续操作
	for (int j = 0; j < 2000000; j++) {//测试样例数，可修改


		//---------结点变量定义---------
		bool copymark = false;//复制标记，针对多作者情况
		getline(infile, articleinfo);//读取article行，存入articleinfo
		AuthorNode *authorname = new AuthorNode();
		AuthorNode *authorhead = authorname;
		//---------定义结束---------


		//---------一轮读取开始---------
		if (articleinfo.find("<article") != string::npos)//读到<article,开始读取该文章信息并写入
		{
			getline(infile, tempstr);//读取一行,此处应为author属性
			bool judge = false;
			while (tempstr.find("author") != string::npos)
			{
				if (judge == true)copymark = true;//多作者，令复制标记为真
				Author_Calculate(authorname, tempstr);//调用函数
				getline(infile, tempstr);//读取一行,此处可能为author属性
				judge = true;
			}//下一行不是author,即可跳出循环

			while (tempstr.find("</article>") == string::npos)//将其他信息（如title、pages等）写入otherinfo中
			{
				otherinfo << tempstr << endl;
				getline(infile, tempstr);
			}//*

			otherinfo << tempstr << endl;//写入</article>

			judge = false;//重新设置为假，作为后面的第二作者标记
			for (AuthorNode *authorzz = authorhead; authorzz->author != "";)
			{
				ofstream outfile;

				filenamestr = authorzz->author;
				filenamestr.append(".txt");
				MyUrl.append(filenamestr);//绝对路径拼接完成

				outfile.open("TempFile.txt", ios::out | ios::app);//临时文件创建，便于复制
				Write_intoTempFile(authorhead, outfile, otherinfo, articleinfo, tempstr, judge);//写进临时文件中
				outfile.close();//输出流关闭，下一次TempFile将作为输入流打开

				ifstream finalin("TempFile.txt", ios::in);
				ofstream finalout(MyUrl, ios::out | ios::app);
				finalout << finalin.rdbuf();//文档复制
				finalout << endl;//空行，为了美观...
				finalin.close();
				finalout.close();

				MyUrl = constUrl;//恢复绝对路径前缀
				authorzz = authorzz->next;
				judge = true;//第一作者读取完毕，激活标记
			}
			ofstream fileout("TempFile.txt", ios::trunc);//清空Tempfile
			fileout.close();
		}
		//---------一轮读取结束---------


		counterzz++;//测试样例数++
		if (counterzz % 1000 == 0)cout << "循环次数：" << counterzz << endl;
	}
}


//
//int main()
//{
//	WriteToMyFile();
//	cout << "写入完毕" << endl;
//}
//
