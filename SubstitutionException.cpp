#include "SubstitutionException.h"
const char* SubstitutionException::what()
{
	if (t==Uncr_Line)
		return "Uncorrect line \n";
	else if (t==Uncr_Table)
		return "Uncorrect table \n";
	else if (t==Uncr_Encr)
		return "Uncorrect Encriprion \n";
	else if (t==Uncr_Shift)
		return "Uncorrect shift \n";
    else if (t==Uncr_Shifr)
		return "Uncorrect shifr \n";
	else
		return "Unknown error in equation";

}
