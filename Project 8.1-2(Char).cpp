// Lab_8_1-1.cpp
// < Кузів Назар >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 6

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

/*Дано літерний рядок, який містить послідовність символів s0, …, sn, … .
 Замінити кожну пару сусідніх букв “SQ” або ”QS” трійкою зірочок “***”.
 */

char* ChangeSQ(char* s)
{
	char* t = new char[strlen(s)*3/2+1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	
	while (p = strchr(s + pos1, 'S'))
	{
		if (s[p - s + 1] == 'Q')
		{
			pos2 = p - s + 2;
			strncat(t, s + pos1, pos2 - pos1 - 2);
			strcat(t, "***");
			pos1 = pos2;

		}
		if (s[p - s + 1] != 'Q')
		{ 
			pos2 = p - s + 1;
			strncat(t, s + pos1, pos2 - pos1);
			pos1 = pos2;
		}
			

	}
	
	strcat(t, s + pos1);
	strcpy(s, t);

	return t;
}
char* ChangeQS(char* s)
{
	char* t = new char[strlen(s)*3/2+1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;

	while (p = strchr(s + pos1, 'Q'))
	{
		if (s[p - s + 1] == 'S')
		{
			pos2 = p - s + 2;
			strncat(t, s + pos1, pos2 - pos1 - 2);
			strcat(t, "***");
			pos1 = pos2;

		}
		if (s[p - s + 1] != 'S')
		{
			pos2 = p - s + 1;
			strncat(t, s + pos1, pos2 - pos1);
			pos1 = pos2;
		}
	}

	strcat(t, s + pos1);
	strcpy(s, t);

	return t;
}
int main()
{
	char Str[51]; //Оголошення літерного рядка
	char ModStr[77];

	cout << "Enter string:" << endl;
	cin.getline(Str, 50);

	ChangeSQ(Str);
	strcpy(ModStr, Str);
	ChangeQS(ModStr);

	cout << "Modified string:" << ModStr << endl;
	

	return 0;
}
