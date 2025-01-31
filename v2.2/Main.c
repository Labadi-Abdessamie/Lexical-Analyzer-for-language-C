#include "Comparison.c"

void Verification(char* sentence,int* indexs){
    int i,o=0,c=0;

    for(i=0;i<strlen(sentence);i++){
        if(sentence[i]=='('){
            indexs[0]=i;
            break;
        }
    }
    for(i=indexs[0];i<strlen(sentence);i++){
        if(sentence[i]==')'){
          indexs[1]=i;
        }
    }

    if(indexs[0]>indexs[1]) exit(1);
    if(sentence[indexs[1]+1]=='{'){
        if(sentence[strlen(sentence)-1]!='}') exit(10);
    }
}

void main(){
    char sentence[100]="if((x11==5)||(y1==5)&&z!=5){z=y1;y1=x11;x11=z;z=x11+y1;}",comparison[50],instruction[50],command[20];
    char Declaration[50];
    int indexs[2];

    //printf("\nEnter your sentence :\n\n\t");
    //gets(sentence);
    Verification(sentence,indexs);

            Copying(sentence,command,0,indexs[0]);
            Copying(sentence,comparison,indexs[0]+1,indexs[1]);
            Copying(sentence,instruction,indexs[1]+1,strlen(sentence));

    printf("\n\tThe command : %s\n",command);
    printf("\n\tThe comparison : %s\n",comparison);
    printf("\n\tThe instruction : %s\n",instruction);
    printf("\n\n\tThe Length is %d\n\n",2+Exist_In_Command(command)+Comparison(comparison)+inst(instruction));

    return;
    }
