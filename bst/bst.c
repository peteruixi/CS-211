#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 256

struct bstNode {
    int val;
    struct bstNode* l_child;
    struct bstNode* r_child;
};
struct bstNode* insert(struct bstNode* ,int );
struct bstNode* delete(struct bstNode* ,int );
struct bstNode* search(struct bstNode* ,int );
void traverse(struct bstNode*);
void cleanUp(struct bstNode*);

int main(int argc, char * argv[]){
    
    char buf[SIZE];
    //fgets(buf, SIZE, stdin);
    struct bstNode* root = NULL;
    FILE* fp ;
    if(argc == 3){
        fp = fopen(argv[2],"r");
    }
    else{
        fp = stdin;
    }
    while(fgets(buf, SIZE, fp)!=NULL){
        
        char op[4];
        //printf("%lu\n",strlen(buf));
        long length = strlen(buf);
        //printf("%lu\n",strlen(buf)); strlen(buf)<4 &&
        int val;
        if(length ==2){
            strcpy(op,buf);
            //printf("%s",op);
        }
        else{

            strcpy(op,strtok(buf, " "));
        }
        if(strncmp(op,"p",1) ==0){
            traverse(root);
            printf("\n");
            continue;
            
        }
        //printf("buf:%s",buf);
        
        
        if(strcmp(op,"i")==0){
            val = atoi(strtok(NULL, " "));
            root = insert(root,val);
            
            
        }
        else if(strcmp(op,"s")==0){
            val = atoi(strtok(NULL, " "));
            root = search(root,val);
        }
        else if(strcmp(op,"d")==0){
            val = atoi(strtok(NULL, " "));
            root = delete(root,val);
        }
        else{
            continue;
        }
        
    }
    cleanUp(root);
    return EXIT_SUCCESS;
    
}


struct bstNode* insert(struct bstNode* root,int val){
    if(root ==NULL){
        struct bstNode *ptr;
        ptr = malloc(sizeof(struct bstNode));
        ptr->val=val;
        ptr->l_child= NULL;
        ptr->r_child=NULL;
        printf("inserted\n");
        return ptr;
    }
    else if( root->val == val){
        printf("not inserted\n");
        return root;
    }
    else if(root->val < val){
        root->r_child = insert(root->r_child,val);
    }
    else{
        root->l_child = insert(root->l_child,val);
        //printf("inserted\n");
    }
    //printf("not inserted\n");
    return root;
}

struct bstNode* search(struct bstNode* root,int val){
    if(root ==NULL){
        printf("absent\n");
        return root;
    }
    else if( root->val == val){
        printf("present\n");
        return root;
    }
    else if(root->val < val){
        search(root->r_child,val);
    }
    else{
        search(root->l_child,val);
    }
    return root;
}

void traverse(struct bstNode* root){
    if(root == NULL){
        return;
    }
    printf("(");
    if(root->l_child){
        traverse(root->l_child);
    }
    printf("%d",root->val);
    if(root->r_child){
        traverse(root->r_child);
    }
    printf(")");
}

void cleanUp(struct bstNode* root){
    
    if(root->r_child){
        cleanUp(root->r_child);
    }
    if(root->l_child){
        cleanUp(root->l_child);
    }
    free(root);
}
struct bstNode* minValueNode(struct bstNode* node)
{
    struct bstNode* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->l_child != NULL)
        current = current->l_child;
 
    return current;
}

struct bstNode* delete(struct bstNode* root,int val){
    if(root ==NULL){
        printf("absent\n");
        return root;
    }
    if(root->val < val){
        root->r_child = delete(root->r_child,val);
    }
    else if(root->val > val){
        root->l_child = delete(root->l_child,val);
        //printf("absent\n");
    }
    else{

        if (root->l_child == NULL) {
            struct bstNode* temp = root->r_child;
            free(root);
            printf("deleted\n");
            return temp;
        }
        else if (root->r_child == NULL) {
            struct bstNode* temp = root->l_child;
            free(root);
            printf("deleted\n");
            return temp;
        }
    
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct bstNode* temp = minValueNode(root->r_child);

        // Copy the inorder successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->r_child = delete(root->r_child, temp->val);
        
        
    }
    //printf("absent\n");
    return root;
}