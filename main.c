#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,e,n1,n2,v;
    scanf("%d %d",&n,&e);


    int A[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=999;
        }
    }

    for(int N=0;N<e;N++){
        scanf("%d %d %d",&n1,&n2,&v);
        A[n1][n2]=v;
        A[n2][n1]=v;
    }
    int S,E;
    scanf("%d %d",&S,&E);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %02d",A[i][j]);
        }
        printf("\n");
    }printf("==============================\n");

    int B[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            B[i][j]=A[i][j];
        }
    }
    for (int i=0;i<n;i++){
        B[i][i] = 0;
    }

    for(int k = 1;k<n;k++){
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                if (B[i][j] > (B[i][k] + B[k][j])){
                    B[i][j] = (B[i][k] + B[k][j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf(" %5d",B[i][j]);
            }
            printf("\n");
    }
    printf("B[%d][%d]=%d",S,E,B[S][E]);
    return 0;
}
