#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<set>
using namespace std;
void transformer_Filename(string &tmp_nickname);
bool check_PrimaryElem(string tempstr);
string lltos(long long l);
long long stolongl(string str); //stringתlong long
bool check_TailElem(string tempstr);
string itostr(int temp);
//--------------------------------
const string save_url = "src\\";
//--------------------------------