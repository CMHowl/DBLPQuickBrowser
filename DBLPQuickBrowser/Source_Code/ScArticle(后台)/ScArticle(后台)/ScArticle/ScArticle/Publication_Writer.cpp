#include"Publication_Writer.h"
using namespace std;

//ת��˵����
//_a�������滻ϵͳԤ���ļ�������CON.txt
//_b~m�������滻ϵͳ�涨�Ƿ��ı�����
void transformer_Filename(string &tmp_nickname)
{
	if ((_stricmp(tmp_nickname.c_str(), "CON") == 0) || (_stricmp(tmp_nickname.c_str(), "PRN") == 0) ||
		(_stricmp(tmp_nickname.c_str(), "AUX") == 0) || (_stricmp(tmp_nickname.c_str(), "NUL") == 0))
		tmp_nickname += "_a";//������������
	if (tmp_nickname.find(".") != string::npos)tmp_nickname.replace(tmp_nickname.find("."), 1, "_b");
	if (tmp_nickname.find("/") != string::npos)tmp_nickname.replace(tmp_nickname.find("/"), 1, "_c");
	if (tmp_nickname.find("\\") != string::npos)tmp_nickname.replace(tmp_nickname.find("\\"), 1, "_d");
	if (tmp_nickname.find("<") != string::npos)tmp_nickname.replace(tmp_nickname.find("<"), 1, "_e");
	if (tmp_nickname.find(">") != string::npos)tmp_nickname.replace(tmp_nickname.find(">"), 1, "_f");
	if (tmp_nickname.find("\"") != string::npos)tmp_nickname.replace(tmp_nickname.find("\""), 1, "_g");
	if (tmp_nickname.find(":") != string::npos)tmp_nickname.replace(tmp_nickname.find(":"), 1, "_h");
	if (tmp_nickname.find("|") != string::npos)tmp_nickname.replace(tmp_nickname.find("|"), 1, "_i");
	if (tmp_nickname.find("*") != string::npos)tmp_nickname.replace(tmp_nickname.find("*"), 1, "_j");
	if (tmp_nickname.find("?") != string::npos)tmp_nickname.replace(tmp_nickname.find("?"), 1, "_k");
	if (tmp_nickname.find(" ") != string::npos)tmp_nickname.replace(tmp_nickname.find(" "), 1, "_l");
	if (tmp_nickname.find("$") != string::npos)tmp_nickname.replace(tmp_nickname.find("$"), 1, "_m");
}

bool check_PrimaryElem(string tempstr)//���ڵ��ж�
{
	if ((tempstr.find("<article") != string::npos) || (tempstr.find("<inproceedings") != string::npos) ||
		(tempstr.find("<proceedings") != string::npos) || (tempstr.find("<book") != string::npos) ||
		(tempstr.find("<incollection") != string::npos) || (tempstr.find("<phdthesis") != string::npos) ||
		(tempstr.find("<mastersthesis") != string::npos) || (tempstr.find("<www") != string::npos))
		return true;
	else return false;
};

string lltos(long long l)
{
	ostringstream os;
	os << l;
	string result;
	istringstream is(os.str());
	is >> result;
	return result;
}

void PublicationWriter::main_Writer()
{
	PublicationWriter* pubwriter = new PublicationWriter();
	string tempstr;
	int counter = 0;//������
	long long divcounter = 0;//��¼ƫ����������ӳ��
	ifstream infile;
	infile.open(save_url + "dblp.xml", ios::in | ios::binary);//�ļ���ȡ,����������·�������ֶ��޸� 
	getline(infile, tempstr);
	while(tempstr.find("</dblp>")==string::npos){
		if (check_PrimaryElem(tempstr))//�ļ�articleͷ��д��ƫ����
		{
			pubwriter->publication->publications_urlpt = divcounter;
			while (tempstr.find("<title>") == string::npos)
			{
				divcounter = infile.tellg();
				getline(infile, tempstr);	
			}
			if (tempstr.find("<title>") != string::npos)//�ҵ�title��д��publications
			{
			size_t startPos = tempstr.find_first_of(">");
			size_t endPos = tempstr.find_last_of("<");
			pubwriter->publication->publications_name =tempstr.substr(startPos + 1, endPos - (startPos + 1));
			string tmp_nickname = pubwriter->publication->publications_name.substr(0, 3);
			transformer_Filename(tmp_nickname);
			ofstream outfile(save_url+"publication\\" + tmp_nickname + ".txt", ios::app);
			outfile << "<publication pname=\"" + pubwriter->publication->publications_name + "\" " +
			"urlpt=\"" + lltos(pubwriter->publication->publications_urlpt) + "\">"<<endl;
			counter++;//������
			if(counter%1000==0)cout <<"Publication_Writer::counter:"<< counter << endl;
			outfile.close();
			}
		}
		divcounter = infile.tellg();
		getline(infile, tempstr);

	}
	

}

//int main()
//{
//	PublicationWriter a;
//	a.main_Writer();
//}