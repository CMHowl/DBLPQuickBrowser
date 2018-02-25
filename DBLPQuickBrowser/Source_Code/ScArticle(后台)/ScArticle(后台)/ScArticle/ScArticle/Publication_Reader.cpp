#include"Publication_Reader.h"
using namespace std;

long long stolongl(string str) //stringתlong long
{
	long long result;
	istringstream is(str);
	is >> result;
	return result;
}

void PublicationReader::main_Reader(string search_name)
{
	PublicationReader* pubwriter = new PublicationReader();
	string tempstr;
	long long div_finder=0;
	string tmp_nickname=search_name.substr(0, 3);
	transformer_Filename(tmp_nickname);
	ifstream infile(save_url+"publication\\" + tmp_nickname + ".txt", ios::in);
	getline(infile, tempstr);
	while (!infile.eof()) {
		if (tempstr.find(search_name) != string::npos)
		{
			size_t startPos = tempstr.find_last_of("=")+1;//urlpt="�У���ȡ=��λ�ú�+1������λ��
			size_t endPos = tempstr.find_last_of("\"");//���ġ�λ��
			div_finder=stolongl(tempstr.substr(startPos + 1, endPos - (startPos + 1)));
			break;
		}
		getline(infile, tempstr);
	}
	infile.close();
	if (div_finder != 0)
	{
		ifstream indblp(save_url+"dblp.xml", ios::in| ios::binary);
		indblp.seekg(div_finder,ios::beg);
		for (int i = 0; i < 10; i++) {//������
			getline(indblp, tempstr);
			cout << tempstr << endl;
		}
	}
	


}

//int main()
//{
//	//string str = "G:\\dblp\\src\\coauthor\\test";
//	//_mkdir(str.c_str());
//	PublicationReader a;
//	string f;
//	getline(cin,f);
//	a.main_Reader(f);
//	
//}