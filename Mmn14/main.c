#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/*-----------------------------------------------------------------------------------------------------------------------*/



typedef struct
{
    unsigned int type_coding: 2;
    unsigned int dest_addressing: 2;
    unsigned int origin_addressing: 2;
    unsigned int opcode: 4;    
}InstructOrder;


typedef struct
{
    char * label_name;
    int dec_value;
    int type;

}Symbol;



void allocate_check(void * p)
{
    if(!p)
    {
        fprintf(stderr,"Error to allocate new memory\n");
        exit(0);
    }
    
}

/*-----------------------------------------------------------------------------------------------------------------------*/



/*Make new pointer of int value for new data instruction*/
int * newData(int value)
{
    
    
    
}






int CommandLineToLinkedList()
{
    char ** commands;           /*array of strings*/
    char c;              /*char variable to iterate on content std*/
    int chars_len,i;      /*chars_len: the char length of the current word, current_line: indicate in the current number line*/
    
    i=0;
    c='\0';
    chars_len=1;
    commands=(char **)calloc(chars_len, sizeof(char *));
   
    
    while((c=getchar()!=EOF)&&(c!='\n'))
    {
        if((c!=' ')&&(c!=','))
        {
            commands[i]=(char *)realloc((char *)(commands[i]), (chars_len+1)*sizeof(char));
            allocate_check((char *)commands[i]);
            commands[i][chars_len-1]=c;
            commands[i][chars_len]='\0';
            chars_len++;
        }
       else
       {
           i++;
           commands=(char **)realloc((char **)commands, (i+1)*sizeof(char *));
           chars_len=0;
       }
    }
    if (c=='\n')
        CheckingCommand(&commands);
    else
    {
        
        
    }

}

/*The main function when iterating on the string array */
int CheckingCommand(char ** commands)
{
    char * label_name;
    
    
    
    
}





int main(int argc, const char * argv[]) {
    extern Symbol ** symbol_table;
    extern void ** instructions_table;   // for data and instruction order
    int * x = NULL;
    
    
    instructions_table[0]=x;
    
    extern int ** data_table;

    
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
}



































