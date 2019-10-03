void uniquewords(char *filename){
    int chararr[26];
    FILE *fptr = fopen(filename, "r"); 
    if (fptr == NULL){ 
        printf("Cannot open file \n"); 
    } 
   
    char c = fgetc(fptr);
    char listofwords[1000][50];
    int k = 0;
    while (c != EOF) 
    { 
        char s[50];
        s[0] = c;
        int i = 0;
        while(c!=' '){
            c = fgetc(fptr); 
            s[i] = c;
            i = i+1;
        }
        s[i] = '\0';
        bool isunique = true;
        for(int k1 = 0;k1<k;k++){
            int k2 = 0;
            while(listofwords[k1][k2]!='\0' and s[k2]!='\0' and s[k2]!=listofwords[k1][k2]){
                k2++;
            }
            if(listofwords[k1][k2]=='\0' and s[k2]=='\0'){
                isunique = false;
                break;
            }
        }
        if(isunique == true){
            for(int k1 = 0;k1<=i;k1++)
                listofwords[k][k1] = s[k1];
        }
        c = fgetc(fptr); 

    } 
    fclose(fptr); 
    for(int k1 = 0;k1<k;k++){
            int k2 = 0;
            while(listofwords[k1][k2]!='\0'){
                cout<<listofwords[k1][k2++];
            }
            cout<<"\n";
        }
}