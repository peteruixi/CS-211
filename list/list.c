#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct node{
    int value;
    struct node* next;
};
int size;
#define SIZE 256


struct node* insert(struct node*, struct node*);
struct node* delete(struct node*, int val);
void traverse(struct node*);

void clean(struct node* head){
    struct node* Head = head;
    struct node* temp = NULL;
    while (Head!= NULL){
        temp = Head;
        Head = Head->next;
        free(temp);
    }
}

int main(int argc, char * argv[]){
    
    char buf[SIZE];
    //fgets(buf, SIZE, stdin);
    struct node* head = NULL;
    FILE* fp ;
    if(argc == 3){
        fp = fopen(argv[2],"r");
    }
    else{
        fp = stdin;
    }
    while(fgets(buf, SIZE, fp)!=NULL){
        char op[2];
        strcpy(op,strtok(buf, " "));
        int val = atoi(strtok(NULL, " "));
        //printf("op: %s val:%d\n",op,val);
        if(strcmp(op,"i")==0){
            struct node *node = malloc(sizeof(struct node));
            node->value = val;
            node->next = NULL;
            head = insert(head,node);
            traverse(head);
            
        }
        else if(strcmp(op,"d")==0){
            if(head != NULL){
                // int check = search(head,val);
                // if(check == 1){
                head = delete(head,val);
                traverse(head);
                // }
                
            }
            else{
                printf("0 :\n");
            }

        }
        // else{
        //     continue;
        // }
        
    }
    clean(head);
    return EXIT_SUCCESS;
    
}
//check if node exist then insert
struct node* insert(struct node* head, struct node* node){
   
    if(head == NULL){
        size++;
        return node;
    }
    if(head->value == node->value){
        return head;
    }
    if(head->value>node->value){
        node->next=head;
        size++;
        return node;
    }
    struct node* prev = head;
    struct node* next = head->next;
    while(next!=NULL ){
        if(node->value>next->value){
            prev=prev->next;
            next=next->next;
        }
        else if(node->value == next->value){
            return head;
        }
        else{
            break;
        }
    }
    size++;
    node->next = next;
    prev->next = node;
    return head;

}
//delete node from linked list
struct node* delete(struct node* head, int val){
    if(head->value == val){
        struct node* temp = head->next;
        free(head);
        size--;
        return temp;
    }
    struct node* prev = head;
    struct node* next = head->next;
    while(next!=NULL && next->value!=val){
        prev=prev->next;
        next=next->next;
    }
    if(next ==NULL){
        return head;
    }
    else{
        prev->next = next->next;
        free(next);
        size--;
    }
    return head;
    

}
//print linked list
void traverse(struct node* head){
    struct node* temp = head;
    printf("%d :",size);
    while(temp!=NULL){
        printf(" %d",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
