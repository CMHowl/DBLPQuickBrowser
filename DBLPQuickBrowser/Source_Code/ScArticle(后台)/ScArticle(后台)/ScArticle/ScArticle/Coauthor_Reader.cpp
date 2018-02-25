#include "Coauthor_Reader.h"
using namespace std;

bool check_TailElem(string tempstr)//β�ڵ��ж�
{
	if ((tempstr.find("</article>") != string::npos) || (tempstr.find("</inproceedings>") != string::npos) ||
		(tempstr.find("</proceedings>") != string::npos) || (tempstr.find("</book>") != string::npos) ||
		(tempstr.find("</incollection>") != string::npos) || (tempstr.find("</phdthesis>") != string::npos) ||
		(tempstr.find("</mastersthesis>") != string::npos) || (tempstr.find("</www>") != string::npos))
		return true;
	else return false;
};

void CoauthorReader::Probe_RBTree()
{
		set<string>::iterator MJiter = coauthor_tree.begin();//�����������ڱ������ź����
		while (MJiter != coauthor_tree.end())
		{
			cout << *MJiter << endl;
			++MJiter;
		}
}

void CoauthorReader::Show_inDBLP()
{
	if (div_finder != 0)
	{
		ifstream indblp(save_url+"dblp.xml", ios::in | ios::binary);
		indblp.seekg(div_finder, ios::beg);
		while (!check_TailElem(tempstr)) {//������
			getline(indblp, tempstr);
			if (tempstr.find("<author>") != string::npos) {
				size_t startPos = tempstr.find_first_of(">");
				size_t endPos = tempstr.find_last_of("<");
				coauthor_tree.insert(tempstr.substr(startPos + 1, endPos - (startPos + 1)));
			}
		}
	}
}

void CoauthorReader::main_Reader(string search_name)
{
	div_finder = 0;
	CoauthorReader* coareader = new CoauthorReader();
	string tmp_nickname = search_name.substr(0, 3);
	transformer_Filename(tmp_nickname);
	ifstream infile(save_url+"coauthor\\" + tmp_nickname + ".txt", ios::in);
	getline(infile, tempstr);
	while (!infile.eof()) {
		if (tempstr.find(search_name) != string::npos)
		{
			size_t startPos = tempstr.find_last_of("=") + 1;//urlpt="�У���ȡ=��λ�ú�+1������λ��
			size_t endPos = tempstr.find_last_of("\"");//���ġ�λ��
			div_finder = stolongl(tempstr.substr(startPos + 1, endPos - (startPos + 1)));

			size_t pub_startPos = tempstr.find("pname=") + 6;
			size_t pub_endPos = tempstr.find("\" urlpt");
			string pub_name = tempstr.substr(pub_startPos + 1, pub_endPos - (pub_startPos + 1));
			cout << pub_name << endl;
		}
		getline(infile, tempstr);
	}
	infile.close();
}

void CoauthorReader::author_Reader(string search_name)
{
	div_finder = 0;
	CoauthorReader* coareader = new CoauthorReader();
	string tmp_nickname = search_name.substr(0, 3);
	transformer_Filename(tmp_nickname);
	ifstream infile(save_url+"coauthor\\" + tmp_nickname + ".txt", ios::in);
	getline(infile, tempstr);
	while (!infile.eof()) {
		if (tempstr.find(search_name) != string::npos)
		{
			size_t startPos = tempstr.find_last_of("=") + 1;//urlpt="�У���ȡ=��λ�ú�+1������λ��
			size_t endPos = tempstr.find_last_of("\"");//���ġ�λ��
			div_finder = stolongl(tempstr.substr(startPos + 1, endPos - (startPos + 1)));
			Show_inDBLP();
		}
		getline(infile, tempstr);
	}
	infile.close();
	Probe_RBTree();//�������ߺ����
}

//int main()
//{
//	CoauthorReader a;
//	string f;
//	getline(cin, f);
//	a.author_Reader(f);
//}