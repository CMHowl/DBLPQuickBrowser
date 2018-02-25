#include"Publication_Reader.h"
#include"Publication_Writer.h"
#include"Coauthor_Reader.h"
#include"Coauthor_Writer.h"
#include"AllAuthorAnalysis_Writer.h"
#include"YearAnalysis_Writer.h"
#include <windows.h>
#include <direct.h>
using namespace std;

void Generate_Path(const char *strDirPath)
{
//char *strDirPath = "D:\\test\\test1\\test2\\";
if (strlen(strDirPath)>MAX_PATH)
{
	return;
}
int ipathLength = strlen(strDirPath);
int ileaveLength = 0;
int iCreatedLength = 0;
char szPathTemp[MAX_PATH] = { 0 };
for (int i = 0; (NULL != strchr(strDirPath + iCreatedLength, '\\')); i++)
{
	ileaveLength = strlen(strchr(strDirPath + iCreatedLength, '\\')) - 1;
	iCreatedLength = ipathLength - ileaveLength;
	strncpy(szPathTemp, strDirPath, iCreatedLength);
	_mkdir(szPathTemp);
}
if (iCreatedLength<ipathLength)
{
	_mkdir(strDirPath);
}

}
int main()
{
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "|Welcome to DBLP Generator for DBLPQuickBrowser!                           |" << endl;
	cout << "|DBLPQuickBrowser��ʹ��c++���ԣ�ͨ��Qt Creator�����Ŀ��ٷ���DBLP�ĵ����   |" << endl;
	cout << "|�����226-Studio��CMH��CJJ��CY&SJY������������DBLP���ݼ���������ѧ��������|" << endl;
	cout << "|�Ͻ�������ҵ��;��                                                        |" << endl;
	cout << "|������������������������Ŀ¼�ļ����밴��ʾ���в�����                    |" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Ĭ�ϵ�ַsrc\\����exe�ļ�ͬһ·���������ڳ����в���const���Σ�" << endl;
	cout << "�����������·��������Դ�����allFuction.h�ļ����޸�save_url��ֵ��" << endl;
	Generate_Path((save_url + "allauthor\\").c_str());
	Generate_Path((save_url + "coauthor\\").c_str());
	Generate_Path((save_url + "publication\\").c_str());
	Generate_Path((save_url + "year\\").c_str());
	Generate_Path((save_url + "year_analysis\\").c_str());
	cout << "·�������ļ��У�" << save_url <<"������ϣ�"<< endl;
	cout << "�뽫����dblp.xml�ļ�������ļ���Ŀ¼�£�ϵͳ���Զ���ȡ���ݣ�" << endl;
	cout << "�����������������ص������ڣ��������������ִ�����ɳ���" << endl;
	system("pause");

	cout << "PublicationĿ¼���ɳ��������������!" << endl;
	Sleep(3 * 1000);
	PublicationWriter a;
	a.main_Writer();
	
	cout << "CoauthorĿ¼���ɳ��������������!" << endl;
	Sleep(3 * 1000);
	CoauthorWriter b;
	b.coa_Writer();
	
	cout << "AllCoauthorĿ¼���ɳ��������������!" << endl;
	Sleep(3 * 1000);
	AllAuthorWriter c;
	c.Author_RBWriter();
	c.Author_RBProcessor();

	cout << "Year&AnalysisĿ¼���ɳ��������������!" << endl;
	Sleep(3 * 1000);
	YearerWriter d;
	d.YearAna_Writer();
	main_WriterTrieTree();

	cout << "Path·���ļ����ɳ�������" << endl;
	ofstream outpath(save_url + "path.txt", ios::app);

	cout << "����Ŀ¼���ɳɹ�!��л����ʹ��!" << endl;
}