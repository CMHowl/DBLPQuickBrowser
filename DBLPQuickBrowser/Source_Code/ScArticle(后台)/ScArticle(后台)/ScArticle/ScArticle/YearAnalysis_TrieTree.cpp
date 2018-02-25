#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include "YearAnalysis_Writer.h"
using namespace std;
bool check_Unimportant(string & tmp) {//过滤所有无用词
	string strunim[] = { "a", "b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s",
		"t","u","v","w","x","y","z","an", "are", "all", "any", "been", "both", "each", "either", "one", "two", "three",
		"four", "five", "six", "seven", "eigth", "nine", "ten", "none", "little", "few", "many", "much",
		"other", "another", "some", "no", "every", "nobody", "anybody", "somebody", "everybody", "when", "on",
		"at", "as", "first", "secend", "third", "fouth", "fifth", "sixth", "ninth", "above", "over", "below",
		"under", "beside", "behind", "of", "the", "after", "from", "since", "for", "which", "by", "next",
		"where", "how", "who", "there", "where", "is", "was", "were", "do", "did", "this", "that", "in",
		"last", "tomorrow", "yesterday", "before", "because", "against", "except", "beyond", "along", "among",
		"but", "so", "towards", "to", "it", "me", "i", "he", "she", "his", "they", "them", "her", "its", "and",
		"has", "have", "my", "would", "then", "too", "or", "our", "off", "we", "be", "into", "weel", "can",
		"having", "being", "even", "us", "these", "those", "if", "ours", "with", "using", "the", "based","-"};
	for (int i = 0; i < 149; i++) {
		if (tmp == strunim[i]) return true;
	}
	return false;
}

int TrieTree::Insert(char *word_temp)
{
	char *search_help = word_temp;
	Branchptr p = myTrie;
	while (*(word_temp) != '\0')
	{
		if (p->flag[*word_temp - 'a'])
		{
			p = p->links[*word_temp - 'a'];
			word_temp++;
		}
		else
		{
			p->flag[*word_temp - 'a'] = 1;
			p->links[*word_temp - 'a'] = (Branchptr)malloc(sizeof(struct branch_trie));
			p = p->links[*word_temp - 'a'];
			memset(p->flag, 0, sizeof(p->flag));
			p->current_char = *word_temp;
			p->flag_word_exist = 0;
			word_temp++;
			while (*word_temp != '\0')
			{
				p->flag[*word_temp - 'a'] = 1;
				p->links[*word_temp - 'a'] = (Branchptr)malloc(sizeof(struct branch_trie));
				p = p->links[*word_temp - 'a'];
				memset(p->flag, 0, sizeof(p->flag));
				p->current_char = *word_temp;
				p->flag_word_exist = 0;
				word_temp++;
			}
			p->current_words = (WordNodeptr)malloc(sizeof(struct word));
			p->current_words->word_value = search_help;
			p->flag_word_exist = 1;
			p->current_words->count = 1;
			return 1;
		}
	}
	if (p->flag_word_exist)
	{
		p->current_words->count++;
		return 0;
	}
	else
	{
		p->flag_word_exist = 1;
		p->current_words = (WordNodeptr)malloc(sizeof(struct word));
		p->current_words->word_value = search_help;
		p->current_words->count = 1;
		return 1;
	}
	return 0;
}
void TrieTree::Travel_Trie()
{
	int i;
	for (i = 0; i<ALPHA; i++)
		if (myTrie->flag[i])
			DFS_Travel(myTrie->links[i]);
}
void TrieTree::DFS_Travel(Branchptr head)
{
	int i;
	if (head->flag_word_exist)
	{
		head->current_words->dictionary_code = dictionary_number_for_search;
		word_list[dictionary_number_for_search++] = head->current_words;
	}
	for (i = 0; i<ALPHA; i++)
		if (head->flag[i])
			DFS_Travel(head->links[i]);
}
void TrieTree::Quick_Sort(int low, int high)
{
	int pivot;
	while (low<high)
	{
		pivot = Partition(low, high);
		Quick_Sort(low, pivot - 1);
		low = pivot + 1;
	}
}
int TrieTree::Partition(int low, int high)
{
	WordNodeptr pivotkey, temp;
	int mid = (low + high) / 2;
	if (word_list[low]->count>word_list[high]->count || ((word_list[low]->count == word_list\
		[high]->count) && (word_list[low]->dictionary_code<word_list[high]->dictionary_code)))
	{
		temp = word_list[low];
		word_list[low] = word_list[high];
		word_list[high] = temp;
	}
	if (word_list[mid]->count>word_list[high]->count || ((word_list[mid]->count == word_list\
		[high]->count) && (word_list[mid]->dictionary_code<word_list[high]->dictionary_code)))
	{
		temp = word_list[mid];
		word_list[mid] = word_list[high];
		word_list[high] = temp;
	}
	if (word_list[mid]->count>word_list[low]->count || ((word_list[mid]->count == word_list\
		[low]->count) && (word_list[mid]->dictionary_code<word_list[low]->dictionary_code)))
	{
		temp = word_list[mid];
		word_list[mid] = word_list[low];
		word_list[low] = temp;
	}
	pivotkey = word_list[low];
	word_list[0] = pivotkey;
	while (low<high)
	{
		while (low<high && (word_list[high]->count>pivotkey->count || ((word_list[high]->count\
			== pivotkey->count) && (word_list[high]->dictionary_code<pivotkey->dictionary_code))))
			high--;
		word_list[low] = word_list[high];
		while (low<high && (word_list[low]->count<pivotkey->count || ((word_list[low]->count\
			== pivotkey->count) && (word_list[low]->dictionary_code>pivotkey->dictionary_code))))
			low++;
		word_list[high] = word_list[low];
	}
	word_list[low] = word_list[0];
	return low;
}
void TrieTree::Outcome_Print()
{
	string out_year = save_url+"year_analysis\\" + temp_year + ".yea";
	FILE *out = fopen(out_year.c_str(), "w");
	int i, count = 0;
	int hunlimit = 0;
	cout << "Outcome_Print: " << temp_year << endl;
	//for (i = dictionary_number_for_search - 1; i >= 1; i--)
	for (i = dictionary_number_for_search - 1; hunlimit<=15; i--)
	{
		string s(word_list[i]->word_value);
		if (!check_Unimportant(s)) {
			fprintf(out, "%s %d\n", word_list[i]->word_value, word_list[i]->count);
			cout <<word_list[i]->word_value << " " << word_list[i]->count << endl;//最小文档1944.txt共16条记录
			hunlimit++;
		}
			//printf("%s %d\n", word_list[i]->word_value, word_list[i]->count);
		free(word_list[i]);
	}
	fclose(out);
}

void main_WriterTrieTree()
{
	for (int z = 1936; z <= 2017; z++)
	{
		stringstream transfromer;
		transfromer << z;
		transfromer >> temp_year;
		TrieTree *tritree = new TrieTree();
		tritree->dictionary_number_for_search = 1;
		tritree->myTrie = (Branchptr)malloc(sizeof(struct branch_trie));
		memset(tritree->myTrie->flag, 0, sizeof(tritree->myTrie->flag));
		string raw_year = save_url+"year\\" + temp_year + ".txt";
		FILE *in = fopen(raw_year.c_str(), "r");
		char *word_temp = (char *)malloc(MAX_LEN);
		int index, ch = 0;
		while (!feof(in))
		{
			index = 0;
			while (ch != EOF && !isalpha(ch))
				ch = fgetc(in);
			if (ch == EOF)
				break;
			word_temp[index++] = tolower(ch);//转换大写字母
			while (isalpha((ch = fgetc(in))))
				word_temp[index++] = tolower(ch);
			word_temp[index] = '\0';//结尾\0
			if (tritree->Insert(word_temp))
				word_temp = (char *)malloc(MAX_LEN);
		}
		fclose(in);
		tritree->Travel_Trie();
		tritree->Quick_Sort(1, tritree->dictionary_number_for_search - 1);
		tritree->Outcome_Print();
		free(tritree->myTrie);
	}
}
//
//int main()
//{
//	main_WriterTrieTree();
//}