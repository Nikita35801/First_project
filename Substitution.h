#pragma once
#include <string>
using namespace std;
class Substitution
{
private:
	string ShiftUppercase; // ������� ��������
	bool IsEmpty(string s); // ����� �������� �� ������ ��������� ������
	inline char ConversionSymbol(char& i); // ����� ������ ������ �������
	inline char DisConversionSymbol(char& i);
	void TranslationTable();
	void SetTable();
public:
	void Encription(string s);
    void DisEncription(string s);
	Substitution(string table) :ShiftUppercase(table) {}; // �����������, ����������� �� ���� ������ � �����
};

class Substitution_shift
{
private:
	int shift; // ���������� ��� �����
	bool IsEmpty(string s); // ����� �������� �� ������ ��������� ������
	inline char ConversionSymbol(char& i); // ����� ������ ������ �������
	inline char DisConversionSymbol(char& i); // ����� �������� ������ ������ �������
public:
    void Encription(string s);
    void DisEncription(string s);
	Substitution_shift(int n) :shift(n){}; // �����������, ����������� �� ���� �����
};

