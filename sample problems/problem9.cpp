void add(int A[][10], int B[][10], int C[][10])  
{  
    int i, j;  
    for (i = 0; i < N; i++)  
        for (j = 0; j < N; j++)  
            C[i][j] = A[i][j] + B[i][j];  
}  
  