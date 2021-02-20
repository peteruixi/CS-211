#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    //int flag;
    if(argc < 2){
        printf("...");
        return EXIT_SUCCESS;
    }
    printf("(");
    // if(argc > 2){
    //     printf("(");
    //     flag =1;
        
    // }
    for(int i = 1; i<argc; i++){
        char* buff = argv[i];
        for(int j = 0; j<strlen(buff); j++){
            if(buff[j] == '!'){
                //output[idx] = ".";
                printf(".");
                //idx ++;
            }
            else if(isupper(buff[j]) ==1 ){
                char temp = tolower(buff[j]);
                printf("%c",temp);
                //output[idx] = (char)tolower(buff[j]);
                //idx ++;
            }
            else{
                printf("%c",buff[j]);
            }
            
        }
        if(i != argc-1){

            printf(" ");
        }
    }
    // if(flag == 1){

    //     printf(")");
    // }
    printf(")");
    return 0;
}
