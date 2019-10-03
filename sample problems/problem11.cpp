void alphabetfreq(char *filename){
    int chararr[26];
    FILE *fptr = fopen(filename, "r"); 
    if (fptr == NULL){ 
        printf("Cannot open file \n"); 
    } 
   
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        chararr[c] = chararr[c-'a'] + 1;
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
}