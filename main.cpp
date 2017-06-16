#include "SubstitutionException.h"
#include "Substitution.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	int OnceMore; // ���������� ��� ����������� ����� ����� ������
	string line; // ����������, �������� ��������� ������
	string table; // ����������, �������� ������� ������
	int Encription,cipher, shift;
	cout<<"Choose: cipher shift-0  or  cipher simple substitution-1"<<endl;
	cin>>cipher;
	cout<<"Choose action: encryption - 0 decryption - 1: "<<endl;
	cin>>Encription;
	if (cipher==0)
	{
		cout << "Write you shift" << endl;
		cin >> shift;
	}
	else if (cipher==1)
	{
		cout << "Write your 26 digit translation table"<<endl;
		cin >> table;
	}
	else goto metka1;
	do
	{
		try
		{
			if (cipher==0)
			{
				Substitution_shift OurLine(shift);
				cout << "Write your string" << endl;
				cin >> line;
				if (Encription==0)
					OurLine.Encription(line);
				else if (Encription==1)
					OurLine.DisEncription(line);
				else throw SubstitutionException(SubstitutionException::Uncr_Encr);
			}
			else if (cipher==1)
			{

				Substitution OurLine(table);
				cout << "Write your string" << endl;
				cin >> line;
				if (Encription==0)
					OurLine.Encription(line);
				else if (Encription==1)
					OurLine.DisEncription(line);
				else throw SubstitutionException(SubstitutionException::Uncr_Encr);
			}
		}
		catch(SubstitutionException& e)
		{
			cerr<<"Warning \n"<<e.what();
		}
		cout <<endl<<"If your want write other operands enter 1, else 0: ";
		cin >> OnceMore;
	} while (OnceMore == 1);
metka1:;
	return 0;
}

