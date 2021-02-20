#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int main(int argc, char* argv[])
{
    //int flag;
    if(argc < 2){
        return EXIT_SUCCESS;
    }
    //int len = strlen(argv[1]);
    int arr[256];
    //printf("%d ", len);
    int idx = 0;

    for(int i = 1; i<argc; i++){
        char* buff = argv[i];
        for(int j = 0; j<strlen(buff); j++){
    

            if(isupper(buff[j]) ==1 ){
                int temp = tolower(buff[j]);
                arr[idx] = temp;
                idx++;
            }
            else if(islower(buff[j]) ==1 ){
                //char * temp1 = &buff[j];
                //rintf("%c\n",buff[j]);
                int temp = (int)(buff[j]);
                //printf("%d\n",temp);
                arr[idx] = temp;
                idx++;
            }
            else{
                
                continue;
            }
            
        }
    }
    // for(int i =0; i<idx;i++){
        
    //     printf("%d ", arr[i]);
    // }
    bubble_sort(arr,idx);
    for(int i =0; i<idx;i++){
        char c = (char)arr[i];
        printf("%c", c);
    }
    return 0;
}
