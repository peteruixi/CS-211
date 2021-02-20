#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Struct to hold the expected close brace character 
// and a pointer to the next element.
struct element {
    char close; // ), ], >, }
    struct element* next;
};

void clean(struct element* head,int flag){
    struct element* Head = head;
    struct element* temp = NULL;
    while (Head!= NULL){
        temp = Head;
        if(flag == 1){
            printf("%c",Head->close);
        }
        Head = Head->next;
        free(temp);
    }
}

int main(int argc, char* argv[])
{

    struct element *head = malloc(sizeof(struct element));
    head->next = NULL; // ->
    char * str = argv[1];
    //printf("%s\n",str);
    for (int i = 0; i < strlen(argv[1]);i++){
        //printf("buff: %c \n",buff);
        char buff = str[i];
        if(buff == '(' || buff == '[' || buff == '{' || buff == '<'){
            struct element *node = malloc(sizeof(struct element));
            if( buff == '('){
                node->close = ')';
            }
            else if(buff == '['){
                node->close = ']';
            }
            else if(buff == '{'){
                node->close = '}';
            }
            else if(buff == '<'){
                node->close = '>';
            }
            node->next = head->next;
            head->next = node;
            //printf("head.next.close: %c\n", head->next->close);
        }
        else if(buff == ')' || buff == ']' || buff == '}' || buff == '>'){
            //printf("head.next.close: %c\n", head->next->close);
            if(head->next != NULL ){
                if( buff == head->next->close){
                    //printf("else: head.next.close: %c\n", head->next->close);
                    struct element* temp = head->next;
                    head->next = head->next->next;
                    free(temp);
                }
                else{
                    printf("%d: %c",i,buff);
                    clean(head,0);
                    return EXIT_FAILURE;
                }
            }                
            else{
                printf("%d: %c",i,buff);
                clean(head,0);
                return EXIT_FAILURE;
            }
        }
        else{
            continue;
        }
    }
    if(head->next !=NULL){
        printf("open: ");
        // struct element* temp = head->next;
        // while (temp!= NULL){
        //     printf("%c",temp->close);
        
        //     temp = temp->next;
        // }
        clean(head->next,1);
        return EXIT_FAILURE;

    }
    
    //clean(head,0);
    //free(head);
    return EXIT_SUCCESS;
}
