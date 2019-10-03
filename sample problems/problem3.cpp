int sumofallprime(int x){
    int sum = 0;
    for(int i=2;i<x;i++){
        int fl = 0;
        for(int j = 2;j*j<=i;j++){
            if(i%j == 0){
                fl = 1;
                break;
            }
        }
        if(fl == 0)
            sum = sum + i;
    }
    return sum;
}