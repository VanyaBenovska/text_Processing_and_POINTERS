// Cpp_2017May21_03_Emails_POINTERs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include <functional>
using namespace std;


int SpecialWordsCounter(string line, string specialWord)
{
	int countOfWordsInLine = 0;


	stringstream ssCounter(line);
	string word;
	vector<string> wordsOfMessage;
	while (ssCounter >> word)
	{
		countOfWordsInLine++;
	}

	string * strArrWords = new string[countOfWordsInLine];
	stringstream ssToFillTheArray(line);
	int j = 0;
	word = "";
	while(ssToFillTheArray >> word)
	{
		strArrWords[j] = word;
		j++;
	}
	int count = 0;
	for (int i = 0; i < j; i++)
	{
		if (strArrWords[i] == specialWord)
		{
			count++;
		}
	}	
	delete[] strArrWords;
	return count;
}

int main()
{
	map<int, string, greater<int> > dataMessages;
	string specialWord;
	getline(cin, specialWord);
	//cout << "SEARCH WORD: " << specialWord << "----" << endl;
	int pageSize;
	string strPageSize;
	getline(cin, strPageSize);
	//cout << "SEARCH WORD: " << strPageSize << "----" <<endl;
	stringstream ss(strPageSize);
	ss >> pageSize;

	string line;
	getline(cin, line);
	while (line != ".")
	{
		int countOfSpecialWordInSenteance = SpecialWordsCounter(line, specialWord);
		dataMessages.insert({ countOfSpecialWordInSenteance, line });
		getline(cin, line);
	}
	int counterPages = 1;
	for (auto it = dataMessages.begin(); it != dataMessages.end(); it++)
	{
		if (counterPages > pageSize)
		{
			break;
		}
		if (it->first != 0)
		{
			cout << it->second << endl;
		}
		counterPages++;
	}

	return 0;
}
