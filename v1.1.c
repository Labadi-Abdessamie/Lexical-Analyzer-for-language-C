#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
    ! Dans cet exercice on sait la formule générale de la condition if(comparison)instruction.
    ! Dans le cas de cet exercice on a que la comparison == et l'instructions = (afectation comme une seule instruction).
    ! Alors pour savoir que la phrase entrée est validé on cherche pour la command (if) les parenthèses et le char '='.
    ! Apres on devise la phrase selon : command-comparison-instruction.
    !
*/

struct Alphabet{
    char lettre[20];
};
char Operations[4]={
    /*'='*/
    '+','-','*','/'
};
char comparisons[3]={
    '=','<','>'
};
struct Alphabet commands[4]={
    {"if"},
    {"for"},
    {"do"},
    {"while"}
};
struct Alphabet Variables[3]={
    {"x11"},
    {"y1"},
    {"z"}
};

void Verification(char* sentence,int* indexs){
    int i,o=0,c=0;
    for(i=0;i<strlen(sentence);i++){
        if(sentence[i]=='('){
            indexs[0]=i;o++;
        }
        if(sentence[i]==')'){
            indexs[1]=i;c++;
        }
    }
    if(c!=o) exit(EXIT_FAILURE);
        else{
            if(indexs[0]>indexs[1]) exit(EXIT_FAILURE);
            else printf("\n\n\t Sentence Accepted !\n\n");
        }
}

void Copying(char* source,char* destination,int index,int stop){
        int i,c=0;
        for(i=index;i<stop;i++){
            destination[c]=source[index];
            index++;c++;
        }
        destination[c]='\0';
}

int Exist_In_Variables(char* element){
    int i;
    for(i=0;i<3;i++){
        if(strcmp(Variables[i].lettre,element)==0)
            return 1;
    }
            return 0;
}

int Exist_In_comparison(char element){
    int i;
    for(i=0;i<3;i++){
        if(comparisons[i]==element)
            return 1;
    }
            return 0;
}

int Exist_In_Operation(char element){
    int i;
    for(i=0;i<3;i++){
        if(Operations[i]==element)
            return 1;
    }
            return 0;
}

int cmnd(char* cmnd){
    int i;
    for(i=0;i<4;i++){
    if(strcmp(cmnd,commands[i].lettre)==0)
        return 1;
    }
        return 0;
}

int comp(char* comp){
    int i,j,index=0;
    char v1[20],v2[20];

    for(i=0;i<strlen(comp);i++){
        if(Exist_In_comparison(comp[i])){
            index=i;break;
        }
    }
    if(index==0) exit(EXIT_FAILURE);
    if(comp[index+1]=='='){
        Copying(comp,v1,0,index);
        Copying(comp,v2,index+2,strlen(comp));
        printf("\ncomparison : \n");
        printf("\n\tOperator : %c=\n",comp[index]);
        printf("\n\tV1 = %s\n",v1);
        printf("\n\tV2 = %s\n",v2);

        return 2+Exist_In_Variables(v1)+Exist_In_Variables(v2);
    }
    else if(comp[index]!='='){

        Copying(comp,v1,0,index);
        Copying(comp,v2,index+1,strlen(comp));
        printf("\ncomparison : \n");
        printf("\n\tOperator : %c\n",comp[index]);
        printf("\n\tV1 = %s\n",v1);
        printf("\n\tV2 = %s\n",v2);

        return 1+Exist_In_Variables(v1)+Exist_In_Variables(v2);
    }
    return 0;
}

int inst(char* inst){
    int i,index;
    char v1[20],v2[20];

    for(i=0;i<strlen(inst);i++){
        if(inst[i]=='='){
            index=i;break;
        }
    }
    if(index==0) exit(EXIT_FAILURE);
    Copying(inst,v1,0,index);
    Copying(inst,v2,index+1,strlen(inst)-1);

    printf("\nInstruction : \n");
    printf("\n\tAffectation ? : %c\n",inst[index]);
    printf("\n\tV1 = %s\n",v1);
    printf("\n\tV2 = %s\n",v2);

    for(i=0;i<strlen(v2);i++){
        if(Exist_In_Operation(v2[i])){
            return 1+Exist_In_Variables(v1)+Oper(v2,i);
        }
    }
    return 1+Exist_In_Variables(v1)+Exist_In_Variables(v2);
}

int Oper(char* operation,int index){
    int i,j;
    char v1[20],v2[20];
    if(index==0) exit(EXIT_FAILURE);

    Copying(operation,v1,0,index);
    Copying(operation,v2,index+1,strlen(inst));
    printf("\n\t\tOperation : %c\n",operation[index]);
    printf("\n\t\tV1 = %s\n",v1);
    printf("\n\t\tV2 = %s\n",v2);

    return 1+Exist_In_Variables(v1)+Exist_In_Variables(v2);
}

void main(){
    char sentence[50],comparison[20],instruction[20],command[20];
    int indexs[2];
    int i;
    for(i=0;i<5;i++){
    printf("\nEnter your sentence :\n\n\t");
    gets(sentence);
    Verification(sentence,indexs);

            Copying(sentence,command,0,indexs[0]);
            Copying(sentence,comparison,indexs[0]+1,indexs[1]);
            Copying(sentence,instruction,indexs[1]+1,strlen(sentence));

    printf("\n\tLa command : %s\n",command);
    printf("\n\tLa comparison : %s\n",comparison);
    printf("\n\tL'instruction : %s\n",instruction);
    printf("\n\n\tThe Length is %d\n\n",3+cmnd(command)+comp(comparison)+inst(instruction));
    }

    return ;
    }
