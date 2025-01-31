#include "Instruction.c"

int Comparison(char* comp){
    int indexs[20]={-1};
    int i=0,c=0;
    char OP[20];
    int Result=0;
    while(comp[i]!='\0'){
        if(comp[i]==' ' && comp[i+3]==' '){
            Copying(comp,OP,i+1,i+3);
            if(!Exist_In_Logic_Op(OP)){
                printf("\nComparison Syntax Error!"); exit(5);
            }
            else{
                printf("\nLogical Operator N%d: %s\n",c+1,OP);
                Result+=4;
                indexs[c]=i;
                c++;
                i+=4;
                continue;
            }
        }
        i++;
    }

    if(indexs[0]==-1) return compa(comp);
    int j=0;
    char Temp[50];
    for(i=0;i<c;i++){
        Copying(comp,Temp,j,indexs[i]);
        j=indexs[i]+4;
        Result+=compa(Temp);
    }
    Copying(comp,Temp,j,strlen(comp));
    Result+=compa(Temp);
    return Result;
}

int brackets_verification(char* with_brackets,char* without_brackets){
    int i;

    for(i=0;i<strlen(with_brackets);i++){
        if(with_brackets[0]=='('){
            if(with_brackets[strlen(with_brackets)-1]==')'){
            Copying(with_brackets,without_brackets,1,strlen(with_brackets)-1);
            return 2;
            }
            else{
                printf("\nComparison Syntax Error!"); exit(5);
            }
        }
    }
    return 0;
}


int compa(char* comp){
    int i,j,index=0;
    char v1[20],v2[20];

    int intern_brckts = brackets_verification(comp,comp);

    for(i=0;i<strlen(comp);i++){
        if(Exist_In_Comparison(comp[i])){
            index=i;break;
        }
    }
    if(index==0) exit(2);
    if(comp[index+1]=='='){
        for(i=index+2;i<strlen(comp);i++){
            if(Exist_In_Comparison(comp[i])){
                printf("\nComparison Syntax Error!"); exit(5);
            }
        }
        Copying(comp,v1,0,index);
        Copying(comp,v2,index+2,strlen(comp));
        printf("\nComparison : \n");
        printf("\n\tOperator : %c=\n",comp[index]);
        printf("\n\tV1 = %s\n",v1);
        printf("\n\tV2 = %s\n",v2);

        return 2+intern_brckts+Exist_In_Variables(v1)+Exist_In_Variables(v2);
    }
    else if(comp[index]!='=' && comp[index]!='!'){

        Copying(comp,v1,0,index);
        Copying(comp,v2,index+1,strlen(comp));
        printf("\nComparison : \n");
        printf("\n\tOperator : %c\n",comp[index]);
        printf("\n\tV1 = %s\n",v1);
        printf("\n\tV2 = %s\n",v2);

        return 1+intern_brckts+Exist_In_Variables(v1)+Exist_In_Variables(v2);
    }
        printf("\n  Comparison Syntax Error");
        exit(2);
}
