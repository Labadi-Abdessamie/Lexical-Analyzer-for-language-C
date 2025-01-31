#include "Alphabet.c"


int inst(char* inst){
    if(inst[0]=='{' && inst[strlen(inst)-1]=='}'){
        return block_instruction(inst);
    }
    return instruction(inst,0);
}

int block_instruction(char* inst){
    char instruct[20];
    int indexs[20];
    int c=0,Numbers=0,i=1 ;
    while(inst[i]!='}'){
        if(inst[i]==';'){
            indexs[c]=i;
            c++;
        }
        i++;
    }
    int j=1;
    if(inst[strlen(inst)-2]==';') c-=1;
    for(i=0;i<c;i++){
        Copying(inst,instruct,j,indexs[i]+1);
        j=indexs[i]+1;
        Numbers+=instruction(instruct,1);
        }
    if(inst[strlen(inst)-2]==';'){
    Copying(inst,instruct,j,strlen(inst)-1);
    Numbers+=instruction(instruct,1);
    return 2+Numbers;
    }
    Copying(inst,instruct,j,strlen(inst));
    Numbers+=instruction(instruct,1);
    return 1+Numbers;
}

int instruction(char* inst,int Is_it_bloc){
    int i,index;
    char v1[20],v2[20];

    for(i=0;i<strlen(inst);i++){
        if(inst[i]=='='){
            index=i;break;
        }
    }
    if(index==0) exit(11);
    Copying(inst,v1,0,index);
    Copying(inst,v2,index+1,strlen(inst)-1);
    if(inst[strlen(inst)-1]==';' || (inst[strlen(inst)-1]=='}' && Is_it_bloc==1)){

    printf("\nInstruction : \n");
    printf("\n\tAffectation ? : %c\n",inst[index]);
    printf("\n\tV1 = %s\n",v1);
    printf("\n\tV2 = %s\n",v2);

    for(i=0;i<strlen(v2);i++){
        if(Exist_In_Operation(v2[i])){
            return 2+Exist_In_Variables(v1)+Oper(v2,i);
        }
    }
    return 2+Exist_In_Variables(v1)+Exist_In_Variables(v2);
    }
    printf("\nInstruction Syntax Error");
    exit(12);
}

int Oper(char* operation,int index){
    int i,j;
    char v1[20],v2[20];
    if(index==0) exit(13);

    Copying(operation,v1,0,index);
    Copying(operation,v2,index+1,strlen(operation));

    printf("\n\t\tOperation : %c\n",operation[index]);
    printf("\n\t\tV1 = %s\n",v1);
    printf("\n\t\tV2 = %s\n",v2);


    for(i=0;i<strlen(v2);i++){
        if(Exist_In_Operation(v2[i])){
            return 1+Exist_In_Variables(v1)+Oper(v2,i);
        }
    }

    return 1+Exist_In_Variables(v1)+Exist_In_Variables(v2);
}
