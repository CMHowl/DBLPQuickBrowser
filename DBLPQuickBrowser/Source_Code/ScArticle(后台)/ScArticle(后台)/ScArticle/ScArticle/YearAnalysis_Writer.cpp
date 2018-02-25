#include "YearAnalysis_Writer.h"
using namespace std;

void YearerWriter::YearAna_Writer()
{
	string tempstr;
	int counter = 0;//������
	ifstream infile;
	infile.open(save_url + "dblp.xml", ios::in | ios::binary);//�ļ���ȡ,����������·�������ֶ��޸� 
	getline(infile, tempstr);
	while (tempstr.find("</dblp>") == string::npos) {
			if (tempstr.find("<title>") != string::npos)
			{
				size_t startPos = tempstr.find_first_of(">");
				size_t endPos = tempstr.find_last_of("<");
				yearer->yearer_text= tempstr.substr(startPos + 1, endPos - (startPos + 1));
			}
			if (tempstr.find("<year>") != string::npos)
			{
				size_t startPos = tempstr.find_first_of(">");
				size_t endPos = tempstr.find_last_of("<");
				yearer->yearer_num = tempstr.substr(startPos + 1, endPos - (startPos + 1));
				ofstream outfile(save_url + "year\\" + yearer->yearer_num + ".txt", ios::app);
				outfile << yearer->yearer_text << endl;
				counter++;//������
				if (counter % 1000 == 0)cout << "YearAna_Writer::counter:" << counter << endl;
				outfile.close();
			}
			getline(infile, tempstr);
		}
	cout << "Finished!" << endl;
}

//int main()
//{
//	save_url = "G:\\dblp\\src\\";
//	YearerWriter z;
//	z.YearAna_Writer();
//}