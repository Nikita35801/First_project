#include "Substitution.h"
#include "SubstitutionException.h"
#include <iostream>
bool Substitution::IsEmpty(string s)
{

	if (s == "")
		throw SubstitutionException(SubstitutionException::Uncr_Line); // �� ���� ������� ������ ��� ��������
	else return true;
}
void Substitution::Encription(string s)
{
	IsEmpty(s);
	SetTable();
	for (int i = 0; s[i] != '\0'; i++)
	{
		ConversionSymbol(s[i]);
	}
	TranslationTable();
	cout <<endl<<"Rezult: "<<s;
}
void Substitution::DisEncription(string s)
{
	IsEmpty(s);
	SetTable();
	for (int i = 0; s[i] != '\0'; i++)
	{
		DisConversionSymbol(s[i]);
	}
	TranslationTable();
	cout <<endl<<"Rezult: "<<s;
}

char Substitution::ConversionSymbol(char& i)
{
	int SizeAlphabet = 25;
	if ((i >= 'A') && (i <= 'Z'))
	{
		if (i - 'A'<=SizeAlphabet)
			i=ShiftUppercase[i - 'A'];
	}
	else if ((i >= 'a') && (i <= 'z'))
	{
		if (i - 'a'<=SizeAlphabet)
			i=ShiftUppercase[i - 'a'];
	}
	return i;
}
char Substitution::DisConversionSymbol(char& i)
{
	for (int j=0; j<=25; j++)
	{
		if (ShiftUppercase[j]==i)
		{
			i='a'+j;
			goto metka1;
		}

	}
metka1:;
	return i;
}

void Substitution::TranslationTable()
{
	cout << "Translation table:"<<endl;
	for (char i='a'; i<='z';i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i=0; i<=25; i++)
		cout<< ShiftUppercase[i]<<" ";
}

void Substitution::SetTable()
{
	int i;
	for (i=0; ShiftUppercase[i]!='\0'; i++);
	if (i!=26)
		throw SubstitutionException(SubstitutionException::Uncr_Table);
}

bool Substitution_shift::IsEmpty(string s)
{
	if (s!="")
	{
		if (shift != 0)
		{
			return true;
		}
		else throw SubstitutionException(SubstitutionException::Uncr_Shift); // �� ��� ������ �����
	}
	else throw SubstitutionException(SubstitutionException::Uncr_Line);
}


void Substitution_shift::Encription(string s)
{
	IsEmpty(s);
	shift = shift % 26;
	for (int i = 0; s[i] != '\0'; i++)
	{
		ConversionSymbol(s[i]);
	}
	cout<<"Rezult: "<<s;
}
void Substitution_shift::DisEncription(string s)
{
	IsEmpty(s);
	shift = shift % 26;
	for (int i = 0; s[i] != '\0'; i++)
	{
		DisConversionSymbol(s[i]);
	}
	cout <<"Rezult: "<<s;
}

char Substitution_shift::ConversionSymbol(char& i)
{
	int SizeAlphabet = 26;
	if ((i >= 'A') && (i <= 'Z'))
	{
		if (i + shift > 'Z')
			i = i + shift - SizeAlphabet;
		else i = i + shift;
	}
	else if ((i >= 'a') && (i <= 'z'))
	{
		if (i + shift > 'z')
			i = i + shift - SizeAlphabet;
		else i = i + shift;
	}
	return i;
}
char Substitution_shift::DisConversionSymbol(char& i)
{
	int SizeAlphabet = 26;
	if ((i >= 'A') && (i <= 'Z'))
	{
		if (i - shift < 'A')
			i = i - shift + SizeAlphabet;
		else i = i - shift;
	}
	else if ((i >= 'a') && (i <= 'z'))
	{
		if (i - shift < 'a')
			i = i - shift + SizeAlphabet;
		else i = i - shift;
	}
return i;
}

