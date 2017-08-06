
#include "AuxFunctions.h"
#include "Assembler.h"


#include <stdio.h>



/*Bool Function that checks if the label is valid by return boolean value, if will be an error the function will insert the match error into ErrorsAssembler table */
int isValidLabel(char * label)
{
    int i = strlen(label);
    if(i>30) return 0;
    int k;
    if ((int)label[0]>= 48 && (int)label[0]<=57)
        return 0;
    for ( k = 0; k < i-2; k++) {
        if (!isGoodLetter(label[k]))
        {
            return 0;
        }
    }

    k++;
    if (label[k]!=':')
    {
        return 0;
    }

    return 1;
}


/*Bool Function that check if the first string from the command line is a lavel or not*/
int isLabel(char * order)
{
    
}

/*int Function that checks if the given order string is an vald instruction/data defining order: if is .data then ->16, if is .string then ->17, if is .mat then ->18 ,if is .entry then -> 19, if is .extern then -> 20 ,if is mov ->func.mov,otherwise the function will return -1*/
int isInstruction(char * order)
{
    
}

/*Function that insert the symbol into the symbols tabel by the type: 16 or 17 or 18 is data;19 is .entry and 20 is .extern otherwise is instruction type. and update SC counter too*/
void insertSymbolToTable(char **data,int type)
{
        if (strcmp(order,"mov")==0){
        return 0;
    }
    if (strcmp(order,"cmp")==0){
        return 1;
    }
    if (strcmp(order,"add")==0){
        return 2;
    }
    if (strcmp(order,"sub")==0){
        return 3;
    }
    if (strcmp(order,"not")==0){
        return 4;
    }
    if (strcmp(order,"clr")==0){
        return 5;
    }
    if (strcmp(order,"lea")==0){
        return 6;
    }
    if (strcmp(order,"inc")==0){
        return 7;
    }
    if (strcmp(order,"dec")==0){
        return 8;
    }
    if (strcmp(order,"jmp")==0){
        return 9;
    }
    if (strcmp(order,"bne")==0){
        return 10;
    }
    if (strcmp(order,"red")==0){
        return 11;
    }
    if (strcmp(order,"prn")==0){
        return 12;
    }
    if (strcmp(order,"jsr")==0){
        return 13;
    }
    if (strcmp(order,"rts")==0){
        return 14;
    }
    if (strcmp(order,"stop")==0){
        return 15;
    }
    if (strcmp(order,".data")==0){
        return 16;
    }
    if (strcmp(order,".string")==0){
        return 17;
    }
    if (strcmp(order,".mat")==0){
        return 18;
    }

    return -1;
    
}


/* Function that insert the given data into the instructions_table, the function will update too the IC counter by matching to the length of the given data */
void insertToIT(char **data,int Instruc_type)
{
    
    
    
    
}

/*Function that insert data by the given Instruc_type argument into the data table*/
void insertToDT(char **data,int Instruc_type)
{
    
    
}

/*Update the given instruction command for the second checking*/
void updateInstruction(char **data,int Instruc_type)
{
    
    
    
    
    
}


int isGoodLetter (char toTest){

    int tester = (int)toTest;
    if( (tester>= 65 && tester<=90) || (tester>= 97 && tester<=122) || (tester>= 48 && tester<=57) )
    {return 1;}
    return 0;
}












