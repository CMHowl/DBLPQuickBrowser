#include"Publication_Writer.h"
using namespace std;

//转换说明：
//_a，用于替换系统预设文件名，如CON.txt
//_b~m，用于替换系统规定非法的标点符号
void transformer_Filename(string &tmp_nickname)
{
	if ((_stricmp(tmp_nickname.c_str(), "CON") == 0) || (_stricmp(tmp_nickname.c_str(), "PRN") == 0) ||
		(_stricmp(tmp_nickname.c_str(), "AUX") == 0) || (_stricmp(tmp_nickname.c_str(), "NUL") == 0))
		tmp_nickname += "_a";//特殊命名处理
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

bool check_PrimaryElem(string tempstr)//父节点判定
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
	int counter = 0;//测试用
	long long divcounter = 0;//记录偏移量，便于映射
	ifstream infile;
	infile.open(save_url + "dblp.xml", ios::in | ios::binary);//文件读取,如果不是相对路径，请手动修改 
	getline(infile, tempstr);
	while(tempstr.find("</dblp>")==string::npos){
		if (check_PrimaryElem(tempstr))//文件article头，写入偏移量
		{
			pubwriter->publication->publications_urlpt = divcounter;
			while (tempstr.find("<title>") == string::npos)
			{
				divcounter = infile.tellg();
				getline(infile, tempstr);	
			}
			if (tempstr.find("<title>") != string::npos)//找到title，写入publications
			{
			size_t startPos = tempstr.find_first_of(">");
			size_t endPos = tempstr.find_last_of("<");
			pubwriter->publication->publications_name =tempstr.substr(startPos + 1, endPos - (startPos + 1));
			string tmp_nickname = pubwriter->publication->publications_name.substr(0, 3);
			transformer_Filename(tmp_nickname);
			ofstream outfile(save_url+"publication\\" + tmp_nickname + ".txt", ios::app);
			outfile << "<publication pname=\"" + pubwriter->publication->publications_name + "\" " +
			"urlpt=\"" + lltos(pubwriter->publication->publications_urlpt) + "\">"<<endl;
			counter++;//测试用
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