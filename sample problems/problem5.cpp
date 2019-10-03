void swap(int *a, int *b){
    int *c = a;
    a = b;
    b = c;
}

void printcombi(int *arr, int s, int e){
    if(s == e){
        for(int i=0;i<e;i++)
            printf("%d ",arr[i]);
        printf("/n");
    }
    for(int i=s+1;i<e;i++){
        swap(&arr[i], &arr[s]);
        printcombi(arr, s+1, e);
        swap(&arr[i], &arr[s]);
    }
}


void allcombi(int n){
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i] = i+1;
    printcombi(arr, 0, n);
}