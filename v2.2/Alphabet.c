#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Alphabet{
    char lettre[20];
};
struct Alphabet commands[4]={
    {"if"},
    {"for"},
    {"do"},
    {"while"}
};
char comparisons[4]={
    '=','<','>','!'
};
char Operations[4]={
    /*'='*/
    '+','-','*','/'
};
struct Alphabet Variables[4]={
    {"x11"},
    {"y1"},
    {"z"},
    {"5"}
};
struct Alphabet Logic_Op[2]={
    {"&&"},
    {"||"}
};

int Exist_In_Command(char* cmnd){
    int i;
    for(i=0;i<4;i++){
    if(strcmp(cmnd,commands[i].lettre)==0)
        return 1;
    }
        return 0;
}

int Exist_In_Comparison(char element){
    int i;
    for(i=0;i<4;i++){
        if(comparisons[i]==element)
            return 1;
    }
            return 0;
}

int Exist_In_Operation(char element){
    int i;
    for(i=0;i<4;i++){
        if(Operations[i]==element)
            return 1;
    }
            return 0;
}

int Exist_In_Variables(char* element){
    int i;
    for(i=0;i<4;i++){
        if(strcmp(Variables[i].lettre,element)==0)
            return 1;
    }
            return 0;
}


int Exist_In_Logic_Op(char* element){
    int i;
    for(i=0;i<2;i++){
        if(strcmp(Logic_Op[i].lettre,element)==0)
            return 1;
    }
            return 0;
}

void Copying(char* source,char* destination,int index,int stop){
        int i,c=0;
        for(i=index;i<stop;i++){
            destination[c]=source[index];
            index++;c++;
        }
        destination[c]='\0';
}
