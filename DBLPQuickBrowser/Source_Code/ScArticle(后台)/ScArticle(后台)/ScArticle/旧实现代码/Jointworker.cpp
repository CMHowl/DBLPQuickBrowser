//include"jointworker.h";
//void FileProbe(string tempname)//���ú�������н��洢����Ϊ�������ݽṹ�������ظ�Ԫ�أ����ʺϺ����ظ����ߵ������
//{
//	set<string> MyJointworker;//����дADT����ʱ����set����������п��ٲ�������
//	string tempstr;
//	ifstream infle;
//	string searchUrl;
//	searchUrl=constUrl+tempname+".txt";//·��ƴ��
//	infile.open(searchUrl, ios::in);
//	getline(infile, tempstr);
//	while (infile.eof()!=true) {
//		if (tempstr.find("author") != string::npos)//�ܹ��ҵ�author
//		{
//			size_t startPos = tempstr.find_first_of(">");
//			size_t endPos = tempstr.find_last_of("<");
//			string tempauthor = tempstr.substr(startPos + 1, endPos - (startPos + 1));
//			if (tempauthor != tempname) {
//				MyJointworker.insert(tempauthor);//���������Ԫ�أ�����ĸ����
//			}
//		}
//		getline(infile, tempstr);
//	}
//	cout << "��" << tempname <<"�����к�����ϵ�������������£�"<< endl;
//	set<string>::iterator MJiter = MyJointworker.begin();//�����������ڱ������ź����
//	while (MJiter != MyJointworker.end())
//	{
//		cout << *MJiter << endl;
//		++MJiter;
//	}
//
//}
//
////int main()
////{
////	string search_authorname; 
////	//getline(cin,search_authorname);
////	FileProbe("Grzegorz Rozenberg");
////}
