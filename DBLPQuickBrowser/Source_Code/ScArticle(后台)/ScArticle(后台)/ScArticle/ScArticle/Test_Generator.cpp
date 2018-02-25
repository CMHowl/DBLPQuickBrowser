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
	cout << "|DBLPQuickBrowser是使用c++语言，通过Qt Creator开发的快速访问DBLP文档软件   |" << endl;
	cout << "|软件由226-Studio（CMH、CJJ、CY&SJY）开发，基于DBLP数据集，仅用于学术交流，|" << endl;
	cout << "|严禁用于商业用途！                                                        |" << endl;
	cout << "|本程序用于生成软件所必需的目录文件，请按提示进行操作！                    |" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "默认地址src\\（与exe文件同一路径），由于程序中采用const修饰，" << endl;
	cout << "所以如需更改路径，请在源代码的allFuction.h文件中修改save_url的值。" << endl;
	Generate_Path((save_url + "allauthor\\").c_str());
	Generate_Path((save_url + "coauthor\\").c_str());
	Generate_Path((save_url + "publication\\").c_str());
	Generate_Path((save_url + "year\\").c_str());
	Generate_Path((save_url + "year_analysis\\").c_str());
	cout << "路径及其文件夹：" << save_url <<"生成完毕！"<< endl;
	cout << "请将您的dblp.xml文件放入该文件夹目录下，系统将自动读取内容；" << endl;
	cout << "请您完成上述操作后回到本窗口，按任意键，继续执行生成程序；" << endl;
	system("pause");

	cout << "Publication目录生成程序将在三秒后启动!" << endl;
	Sleep(3 * 1000);
	PublicationWriter a;
	a.main_Writer();
	
	cout << "Coauthor目录生成程序将在三秒后启动!" << endl;
	Sleep(3 * 1000);
	CoauthorWriter b;
	b.coa_Writer();
	
	cout << "AllCoauthor目录生成程序将在三秒后启动!" << endl;
	Sleep(3 * 1000);
	AllAuthorWriter c;
	c.Author_RBWriter();
	c.Author_RBProcessor();

	cout << "Year&Analysis目录生成程序将在三秒后启动!" << endl;
	Sleep(3 * 1000);
	YearerWriter d;
	d.YearAna_Writer();
	main_WriterTrieTree();

	cout << "Path路径文件生成程序启动" << endl;
	ofstream outpath(save_url + "path.txt", ios::app);

	cout << "所有目录生成成功!感谢您的使用!" << endl;
}