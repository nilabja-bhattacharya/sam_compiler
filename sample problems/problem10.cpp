void multiply(int mat1[][10],  
              int mat2[][10],  
              int res[][10]) 
{ 
    int i, j, k; 
    for (i = 0; i < 10; i++) 
    { 
        for (j = 0; j < 10; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < 10; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
  