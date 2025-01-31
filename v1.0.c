#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
    ! Dans cet exercice on sait la formule générale de la condition if(comparaison)instruction.
    ! Dans le cas de cet exercice on a que la comparaison == et l'instructions = (afectation comme une seule instruction).
    ! Alors pour savoir que la phrase entrée est validé on cherche pour la commande (if) les parenthèses et le char '='.
    ! Apres on devise la phrase selon : commande-comparaison-instruction.
    ! 
*/

struct Alphabet{
    char lettre[10];
};
struct Alphabet B[3]={
    //{"if"},
    {"x11"},
    {"y1"},
    {"z"},
    //{"("},
    //{")"},
    //{"="},
    //{";"},
};

int Copying(char* source,char* destination,int index,char stop_char){
        int c=0;
        do{
                destination[c]=source[index];
                index++;c++;
        }while(source[index]!=stop_char);
        destination[c]='\0';
        return index;
}

int Exist_In_Alphabet(char* element){
    int i;
    for(i=0;i<3;i++){
        if(strcmp(B[i].lettre,element)==0)
            return 1;
    }
            return 0;
}

int comp(char* comp){
    int i,j;
    char v1[100],v2[100];

    for(j=0;j<strlen(comp);j++){

    if(comp[j]=='=' && comp[j+1]=='='){
        i=Copying(comp,v1,0,'=');
        i=Copying(comp,v2,i+2,'\0');
        printf("\nComparaison : \n");
        printf("\n\tV1 = %s\n",v1);
        printf("\n\tV2 = %s\n",v2);

        return 2+Exist_In_Alphabet(v1)+Exist_In_Alphabet(v2);
    }
    }
    printf("\nThe syntax of Comparaison not valid\n");
    return 0;
}

int inst(char* inst){
    int i,j;
    char v1[5],v2[5];

    for(j=0;j<strlen(inst);j++){
        if(inst[j]=='='){
    i=Copying(inst,v1,0,'=');
    i=Copying(inst,v2,i+1,'\0');

    printf("\nInstruction : \n");
    printf("\n\tV1 = %s\n",v1);
    printf("\n\tV2 = %s\n",v2);

    return 1+Exist_In_Alphabet(v1)+Exist_In_Alphabet(v2);
    }
    }
    printf("\nInstruction Syntax Error\n");
    return 0;
}
int cmnd(char* cmnd){
    if(strcmp(cmnd,"if")==0)
        return 1;
    else
        return 0;
}

void main(){
    char sentence[50],comparaison[20],instruction[20],commande[20];

    printf("\nEnter your sentence :\n\n\t");
    gets(sentence);

    int i=0;
            i=Copying(sentence,commande,i,'(');
            i=Copying(sentence,comparaison,i+1,')');
            i=Copying(sentence,instruction,i+1,';');

    printf("\n\tLa Commande : %s\n",commande);
    printf("\n\tLa Comparaison : %s\n",comparaison);
    printf("\n\tL'instruction : %s\n",instruction);

    printf("\n\tThe Length is %d\n\n",3+cmnd(commande)+comp(comparaison)+inst(instruction));

    return ;
    }
