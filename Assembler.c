#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Assembler.h"
#include "AuxFunctions.h"


extern Symbol ** symbol_table;               /*The symbols table*/
extern void ** instructions_table;   /* for data and instruction order*/
//void ** data_table;           /**/
extern unsigned IC;                 /*Instruction table counter*/
//unsigned DC=0;                 /*Data table counter*/
extern unsigned SC;                 /*Symbol counter*/
extern char ** ErrorsAssembler;     /*Error in the compiling*/
extern unsigned EC;                 /*Error counter*/
extern unsigned LC;                 /*Line counter*/
unsigned word_counter;
FILE * fd;


/*fucntion that checks if the new memory allocate was successed, if not the function will print to stderr a new error message and then will exit the program*/
void allocate_check(void * p)
{
    if(!p)
    {
        fprintf(stderr,"Error to allocate new memory\n");
        exit(0);
    }
    
}




/*fucntion that insert new assembler error into ErrorsAssembler table */
void insertNewError(char * error)
{
    if (!EC)
    {
        ErrorsAssembler=(char **)calloc(1, sizeof(char *));
        allocate_check((char **)ErrorsAssembler);            /*-------------Need to check if (char **)commands is valid------------*/

    }
    ErrorsAssembler[EC]=error;
    EC++;
    ErrorsAssembler=(char **)realloc((char **)ErrorsAssembler, (EC+1)*sizeof(char *));
    allocate_check((char *)ErrorsAssembler[EC]);

}

/*function that free the linked list of strings*/
void freeLinkedList(char ** list)
{
   while(list)
   {
     free((char *)*list); 
     list++;
   }
}






/*get the whole command and transfer it to linked list, if returned ans>0 then there is an error in the input otherwise the input is valid*/
void CommandLineToLinkedList(int NumIteration)
{
    char ** command;           /*dynamic matrix of strings*/
    char c;              /*char variable to iterate on content std*/
    int chars_len,word_counter;      /*chars_len: the char length of the current word, word_counter: indicate in the current number of word*/
    
    LC++;
    word_counter=0;
    c='\0';
    chars_len=1;
    command=(char **)malloc(sizeof(char *));
    allocate_check((char **)command);            /*-------------Need to check if (char **)commands is valid------------*/
    commands[0]=(char *)calloc(1,sizeof(char));
    allocate_check((char *)command[0]);
    
    while(((c=fgetc(fp))!=EOF)&&(c!='\n'))
    {
        if((c!=' ')&&(c!=','))
        {
            command[word_counter]=(char *)realloc((char *)(command[word_counter]), (chars_len+1)*sizeof(char));
            allocate_check((char *)command[word_counter]);
            command[word_counter][chars_len-1]=c;
            command[word_counter][chars_len]='\0';
            chars_len++;
        }
       else
       {
           if(chars_len>1)
           {
               word_counter++;
               command=(char **)realloc((char **)command, (word_counter+1)*sizeof(char *));
               allocate_check((char **)command);
               command[word_counter]=(char *)calloc(1,sizeof(char));
               allocate_check((char *)command[word_counter]);
               chars_len=1;
           }
          
       }
    }
    if(c=='\n')
    {
        if(NumIteration)
            FirstCheckingCommand(&command);
        else
            CompleteCheckingCommand(&command);
        freeLinkedList(&command);
        CommandLineToLinkedList(NumIteration);
    }
    else   /*if c is EOF*/
    {
        if(NumIteration)
            FirstCheckingCommand(&command);
        else
            CompleteCheckingCommand(&command);
        freeLinkedList(&command);
    }
}






/*checking and processing the current command line*/
void FirstCheckingCommand(char ** command)
{
    int flag_symbol_type;

    if (isLabel(command[0]))
    {
        /*In the case that the first string on the current command line is a label(symbol) */
        if((isValidLabel(command[0]))&&((flag_symbol_type=isInstruction(command[1],0)>=0)))
        {
            /*In the case that the current label is a valid label*/
            insertSymbolToTable(command[0],flag_symbol_type);
            insertToIT(&command[2],flag_symbol_type);   /*the command[2] is first operand*/
        }
    }
    else /*if the commands[0] isn't label*/
    {
        if ((flag_symbol_type=isInstruction(command[0],1)>=0))
        {
            if (flag_symbol_type>=19)
            {
                insertSymbolToTable(command[1],flag_symbol_type);
            }
            else
            {
                insertToIT(&command[1],flag_symbol_type);  /*the command[1] is first operand*/
            }
        }    
    }
}

/*The Secound check of the given command line*/
void SecondCheckingCommand(char ** command)
{
    
}






int main(int argc,char * argv) {
    /*Function the check the validity of the inputed arguments*/
    /*********************************************************/
    IC=0;
    SC=0;
    EC=0;
    LC=0;
    
    fp = fopen ("argv[0]", "r");
    
    if(!fp)
    {
        fprintf(stderr,"File address isn't valid\n");
        exit(0);
    }
    
    CommandLineToLinkedList(1);
    
    /*sets the file position to the beginning of the assembly file*/
    rewind(fp);

    if (EC>0)
    {
        /*Print all the compile error from ErrorsAssembler*/
    }
    
    /*Second pass of the program*/
    IC=0;
    LC=0;
    CommandLineToLinkedList(2);

    
    
    return 0;
    
    
    
}



































