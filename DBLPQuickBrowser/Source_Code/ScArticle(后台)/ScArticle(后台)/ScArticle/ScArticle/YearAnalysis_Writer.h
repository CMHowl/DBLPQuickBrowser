#pragma once
#include "allFuction.h"
using namespace std;
#define MAX_WORD 1000000/*估计单词种类最多数量*/
#define MAX_LEN 50/*限制单词最大长度*/
#define MAX_OUT_SCREEN 100/*屏幕输出单词数量最大值*/
#define ALPHA 26
void main_WriterTrieTree();

static string temp_year;
typedef struct word
{
	int count;
	char *word_value;
	int dictionary_code;/*字典树中字典序编号(最后遍历的时候输入)*/
}*WordNodeptr;

typedef struct branch_trie
{
	char current_char;
	int flag[ALPHA];/*对应该结点的26个链接点存在状态*/
	int flag_word_exist;
	struct branch_trie *links[ALPHA];
	WordNodeptr current_words;
}*Branchptr;

class TrieTree {
public:
	Branchptr myTrie;
	int dictionary_number_for_search;
	WordNodeptr word_list[MAX_WORD];

	int Insert(char *);
	void Travel_Trie();
	void Quick_Sort(int, int);
	int Partition(int, int);
	void DFS_Travel(Branchptr restrict);
	void Outcome_Print();
};

struct Yearer
{
	string yearer_num;
	string yearer_text;
};

class YearerWriter
{
public:
	Yearer* yearer = new Yearer();
	YearerWriter() {};
	~YearerWriter() {};
	void YearAna_Writer();
};