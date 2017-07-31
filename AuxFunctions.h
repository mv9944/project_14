

#ifndef AuxFunctions_h
#define AuxFunctions_h

#include <stdio.h>

/*Bool Function that checks if the label is valid by return boolean value, if will be an error the function will insert the match error into ErrorsAssembler table */
int isValidLabel(char * label);

/*Bool Function that check if the first string from the command line is a lavel or not*/
int isLabel(char * order);

/*int Function that checks if the given order string is an vald instruction/data defining order: if is .data then ->16, if is .string then ->17, if is .mat then ->18 ,if is .entry then -> 19, if is .extern then -> 20 ,if is mov ->func.mov,otherwise the function will return -1;
 if EntryExter=0 then the function will checks without checking entry and extern otherwise the function will checks all the options above including .entry and .extern*/
int isInstruction(char * order, int EntryExtern);

/*Function that insert the symbol into the symbols tabel by the type: 16 or 17 or 18 is data; 20 is extern otherwise is instruction type. and update SC counter too*/
void insertSymbolToTable(char *label,int type);

/* Function that insert the given data into the instructions_table, the function will update the IC counter by matching to the length of the given data */
void insertToIT(char **data,int data_type);




#endif /* AuxFunctions_h */
