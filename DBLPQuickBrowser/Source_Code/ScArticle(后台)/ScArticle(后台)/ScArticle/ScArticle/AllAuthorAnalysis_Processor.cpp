#include "AllAuthorAnalysis_Writer.h"
#include <algorithm>

bool Compare_greater(const pair<string,int> & m1,
	const pair<string,int> & m2) {
	return m1.second > m2.second;
}

void AllAuthorWriter::Author_RBProcessor()
{
	string tempstr;
	int counter = 0;//测试用
	ifstream infile;
	std::map<string, int>::iterator it = aufrequence_RBtree.end();
	for (int file_i = 1; file_i <= 124; file_i++)
	{
		infile.open(save_url + "allauthor\\namefile" + itostr(file_i) + ".aua", ios::in | ios::binary);//文件读取,如果不是相对路径，请手动修改 
		//写入map,统计频率		
		while (!infile.eof()) {
			getline(infile, tempstr);
			it = aufrequence_RBtree.find(tempstr);
			if (it == aufrequence_RBtree.end())//没有找到
				aufrequence_RBtree.insert(make_pair(tempstr, 1));
			else//找到了，value++
				(it->second)++;
		}
		infile.close();
		cout << "namefile" << file_i << ".aua导入完毕" << endl;
	}
	//写入vector,排序
	vector<pair<string, int>> author_vec;
	map<string,int>::iterator mapiter;
	for (mapiter = aufrequence_RBtree.begin(); mapiter != aufrequence_RBtree.end(); mapiter++)
	{
		author_vec.push_back(make_pair(mapiter->first, mapiter->second));
	}
	vector<pair<string, int>>::iterator veciter;//输出
	std::sort(author_vec.begin(), author_vec.end(), Compare_greater);
	int veccounter = 0;
	ofstream outfile(save_url + "allauthor_result.txt", ios::app);

	for (veciter = author_vec.begin(); veciter != author_vec.end(); veciter++)
	{
		cout<< veciter->first << endl;
		outfile << veciter->first << endl;
		cout<< veciter->second << endl;
		outfile << veciter->second << endl;
		veccounter++;
		if (veccounter > 100)break;
	}
}
//
//int main()
//{
//	save_url = "G:\\dblp\\src\\";
//	AllAuthorWriter a;
//	a.Author_RBProcessor();
//}
