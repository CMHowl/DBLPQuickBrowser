//include"jointworker.h";
//void FileProbe(string tempname)//采用红黑树进行结点存储（因为这种数据结构不允许重复元素，很适合忽略重复作者的情况）
//{
//	set<string> MyJointworker;//懒得写ADT，暂时采用set容器，如果有空再补充上来
//	string tempstr;
//	ifstream infle;
//	string searchUrl;
//	searchUrl=constUrl+tempname+".txt";//路径拼接
//	infile.open(searchUrl, ios::in);
//	getline(infile, tempstr);
//	while (infile.eof()!=true) {
//		if (tempstr.find("author") != string::npos)//能够找到author
//		{
//			size_t startPos = tempstr.find_first_of(">");
//			size_t endPos = tempstr.find_last_of("<");
//			string tempauthor = tempstr.substr(startPos + 1, endPos - (startPos + 1));
//			if (tempauthor != tempname) {
//				MyJointworker.insert(tempauthor);//红黑树插入元素（首字母排序）
//			}
//		}
//		getline(infile, tempstr);
//	}
//	cout << "与" << tempname <<"作者有合作关系的所有作者如下："<< endl;
//	set<string>::iterator MJiter = MyJointworker.begin();//迭代器，用于遍历整颗红黑树
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
