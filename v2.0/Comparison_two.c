#include "Instruction.c"

//! An old version of Comparison which handle just two.
/*int Comparison(char* comp){
    char OP[5],C1[20],C2[20];
    int index=-1;
    for(int i=0;i<strlen(comp);i++){
        if(comp[i]==' '){
            index=i;
            break;
        }
    }
    if(index==-1) return compa(comp);
    if(index==0){ printf("\nComparison Syntax Error!"); exit(5);}
    else{
        if(comp[index+3]!=' '){ printf("\nComparison Syntax Error!"); exit(5);}
        else{
            Copying(comp,C1,0,index);
            Copying(comp,OP,index+1,index+3);
            Copying(comp,C2,index+4,strlen(comp));
            if(Exist_In_Logic_Op(OP)){
                printf("\nLogical Operator : %s\n",OP);
                return 4+compa(C1)+compa(C2);
            }
            else{
                printf("\nComparison Syntax Error!"); exit(5);
            }
        }
    }
}*/

