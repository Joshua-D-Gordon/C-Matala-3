#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30
#define NUMSIMILAR 1

int getLine(char s[LINE]);
int getword(char w[WORD]);
int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

int main(){

    char Search[LINE], Function[LINE], funcToUse = ' ';
    char *str = Search;

    int start;
    start = getword(Search);
    if(start==0){
        printf("no search term exiting program\n");
        exit(0);
    }
    start = getword(Function);
    if(start==0){
        printf("no function exiting program\n");
        exit(0);
    }
    
    funcToUse = Function[0];
    
    switch (funcToUse)
    {
    case 'a':
        print_lines(str);
        break;

    case 'b':
        print_similar_words(str);
        break;
    
    default:
    printf("no such function\n");
        break;
    }

    return 0;
}

int getLine(char s[LINE]){

    char ch;
    int i = 0;
    while(scanf("%c",&ch)!=EOF && ch!='\n'){
        s[i] = ch;
        i++;
    }
    
    if(i == 0 && ch =='\n'){
        s[i] = ch;
        i++;
    }

    s[i] = '\0';

    return i;
}

int getword(char w[WORD]){
    char ch = '\0';
    int i = 0;
    while(ch!='\n' && ch!='\t' && ch!=' ' && scanf("%c",&ch)!=EOF){
        w[i] = ch;
        i++;
    }
    if(i>0){
        w[i-1] = '\0';
    }
    if(i>1){
        i--;
    }
    
    return i; 
}

int substring( char * str1, char * str2){

    if(strstr(str1, str2)!=NULL){//substring exists
        return 1;
    }

    return 0; // return 0 as no substring exists
}

int similar(char *s, char *t, int n){
    int ans; // binary answer to be returned (1,0)
    ans = strcmp(s,t);

    if(n<0){
        return 0;
    }

    if(ans == 0){
        return 1;
    }

    if(*(s) == *(t)){
        return similar((s+1),(t+1),n);
    }else{
        return similar((s+1),(t),n-1);
    }


    return 0;
}

void print_lines(char * str){
    
    int end, ans;

    char currentline[LINE]; // for saving current line
    char *ptr = currentline; // pointer to current line

    end = getLine(currentline); //initilizing current line from standrad input and saving length to end
    
    while(end!=0){ //if end !=0 meaning not EOF
    
        ans = substring(ptr,str); // answer of is our search term a substring of the line
    
        if(ans==1){
            printf("%s\n",currentline); // if substring print the line
        }
        end = getLine(currentline); //initilizing current line from standrad input and saving length to end
        
    }

}

void print_similar_words(char * str){
    
    int end, ans, num = 1;

    char currentword[WORD]; // for saving current line
    char *ptr = currentword; // pointer to current line

    end = getword(currentword); //initilizing current line from standrad input and saving length to end
    
    while(end!=0){ //if end !=0 meaning not EOF
        
        ans = similar(ptr,str,num);
       
        if(ans==1){
            printf("%s\n",currentword);
        }
        end = getword(currentword);
        
    }

}


