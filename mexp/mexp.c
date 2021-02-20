#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    // Matrix A 
    FILE* matrix_a_fp = fopen(argv[1], "r");
    if (!matrix_a_fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    char buff[256];

    fscanf(matrix_a_fp, "%s", buff);
    char length_M = atoi(buff);
    char length_N = atoi(buff);
    //printf("length m: %d\n",length_M); 
    int** matrix_a = malloc( length_M * sizeof(int*) );
    for ( unsigned char i=0; i<length_M; i++ ) {
        matrix_a[i] = malloc( length_N * sizeof(int) );
    }
    // | | |
    // | | |   3 x 2
    // | | |
    int temp;
    for(int i = 0; i<length_M;i++){
        for(int j =0; j<length_N;j++){
            fscanf(matrix_a_fp,"%d ",&temp);
            matrix_a[i][j]=temp;
        }
    }
    int order;
    fscanf(matrix_a_fp, "%d", &order);
    
    
    //printf("order: %d\n",order); 
    // 6 0 
    // 6 0 
    // 4 2 
    fclose(matrix_a_fp);


    

    int** product = malloc(length_M * sizeof(int*));
    for(int i = 0; i<length_M; i++){
        product[i] = malloc(length_N * sizeof(int*));
    }
    int** temp_mat = malloc(length_M * sizeof(int*));
    for(int i = 0; i<length_M; i++){
        temp_mat[i] = malloc(length_N * sizeof(int*));
    }
    for(int i = 0; i<length_M;i++){
        for(int j =0; j<length_N;j++){
            temp_mat[i][j] = matrix_a[i][j];
        }
    }

 
    for(int z = 0; z<order-1;z++){
        int sum = 0;
        for(int i=0; i<length_M;i++){
            for(int j = 0; j<length_N;j++){
                for(int k = 0;k<length_M;k++){
                    sum += (temp_mat[i][k] * matrix_a[k][j]);
                    //printf("i: %d, k: %d\n",i,k); 
                }
                //printf("sum %d:\n ",sum);
                product[i][j] = sum;
                sum = 0;
            }
        }
        for(int i = 0; i<length_M;i++){
            for(int j =0; j<length_N;j++){
                temp_mat[i][j] = product[i][j];
            }
        }
    }
    
    for(int i = 0; i < length_M; i++){
        for(int j = 0; j<length_N;j++){
            if(j != length_N-1){

                printf("%d ", product[i][j]);
            }
            else{
                printf("%d", product[i][j]);
            }
        }
        printf("\n");
    }
    

    for ( unsigned char i=0; i<length_M; i++ ) {
        free( matrix_a[i] );
    }
    free(matrix_a);
    for ( unsigned char i=0; i<length_M; i++ ) {
        free( product[i] );
    }
    free(product);


    
    return 0;

}
