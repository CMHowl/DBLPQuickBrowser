#include "Coauthor_Writer.h"
using namespace std;

void CoauthorWriter::coa_Writer()
{
	CoauthorWriter* coawriter = new CoauthorWriter();
	string tempstr;
	int counter = 0;//测试用
	long long divcounter = 0;//记录偏移量，便于映射
	ifstream infile;
	infile.open(save_url+"dblp.xml", ios::in | ios::binary);//文件读取,如果不是相对路径，请手动修改 
	getline(infile, tempstr);
	while (tempstr.find("</dblp>") == string::npos) {

		if (check_PrimaryElem(tempstr))//文件article头，写入偏移量
		{
			bool judge = false;
			vector<string> author_name;
			coawriter->coauthor->coauthor_urlpt = divcounter;
			getline(infile, tempstr);
			while (tempstr.find("<author>") != string::npos)//找到author，写入coauthors
			{
				size_t startPos = tempstr.find_first_of(">");
				size_t endPos = tempstr.find_last_of("<");
				author_name.push_back(tempstr.substr(startPos + 1, endPos - (startPos + 1)));
				getline(infile, tempstr);
			}
			while (tempstr.find("<title>") != string::npos) //注：不能记录booktitle!
			{
				size_t startPos = tempstr.find_first_of(">");
				size_t endPos = tempstr.find_last_of("<");
				coawriter->coauthor->coauthor_name = tempstr.substr(startPos + 1, endPos - (startPos + 1));
				getline(infile, tempstr);
			}
			vector<string>::iterator iter;
			for (iter = author_name.begin(); iter != author_name.end(); iter++)
			{
				string tmp_nickname = (*iter).substr(0, 3);
				transformer_Filename(tmp_nickname);
				ofstream outfile(save_url+"coauthor\\" + tmp_nickname + ".txt", ios::app);
				outfile << "<coauthor host=\"" + (*iter) + "\" " +"pname=\"" + coawriter->coauthor->coauthor_name + "\" " +
				"urlpt=\"" + lltos(coawriter->coauthor->coauthor_urlpt) + "\">" << endl;
				counter++;//测试用
				if (counter % 1000 == 0)cout <<"Coauthor::counter:"<< counter << endl;
				outfile.close();
			}
		}
		divcounter = infile.tellg();
		getline(infile, tempstr);
	}
}

//int main()
//{
//	CoauthorWriter a;
//	a.coa_Writer();
//}