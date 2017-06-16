#pragma once
#include <exception>
class SubstitutionException: public std::exception
{
public:
	enum ErrorType {Uncr_Line,Uncr_Table,Uncr_Encr,Uncr_Shift,Uncr_Shifr};
private:
	ErrorType t;
public:
	SubstitutionException(ErrorType T):t(T) {};
	const char* what();
};
// This is testing conflict Merge
