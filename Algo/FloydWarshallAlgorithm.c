#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define n 5 //no of vertices

int floydWarshall(int D[n][n]){
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                // i = rows, j = columns, k = D(matrix)
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    return D;
}

void printMatrix(int matrix[n][n]){
    for (int i = 0; i < n; i++){
        printf("\t%d",i);
    }
    printf("\n");
    for (int i = 0; i < 40; i++){
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d |\t",i);
        for (int j = 0; j < n; j++){
            printf("%d%d",matrix[i][j]);
            printf("\t");
        }
        printf("\n");        
    }
    printf("\n");
}

int main(){
    int D[n][n] = { {1,2,3,4,45},
                    {12,45,78,12,56},
                    {0,34,78,1,67},
                    {12,67,3,78,23},
                    {234,78,23,78,2}};


    printf("Initial Matrix\n");
    printMatrix(D);
    printf("Shortest Path among all\n");
    printMatrix(floydWarshall(D));

    return 0;
}
