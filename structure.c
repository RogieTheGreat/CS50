//
//  structure.c
//  ES
//
//  Created by Rogie M. Bernabe on 5/15/15.
//  Copyright (c) 2015 Rogie M. Bernabe. All rights reserved.
//

#include <stdio.h>
#include <string.h>

/*Struct*/

struct menu { //7 dis_name
    char dis_name[31];
    char type[15];
    float price;
float dummy;
};

struct restaurant { //max of 30 resto
    char name[31];
    char city[15];
    char tel[11];
    int rating;
    struct menu list[7];
};


/*File openers*/

void writer (FILE *f,struct restaurant x){ 
    fwrite(&x,sizeof(struct restaurant),1,f);
}

struct restaurant reader(FILE *f){ 
    struct restaurant s;
    fread(&s, sizeof(struct restaurant),1,f);
    return s;
}

/*Add Resto*/

void add_resto(int number,int number_of_resto){ //rememeber to ask the person how many resto and dishes
    int i;
    FILE*fp;
    struct restaurant s[30];
    fp = fopen("data.dat", "wb");
    
    for (i=number_of_resto; i<(number+number_of_resto) ; i++){
        
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("City: ");
        scanf("%s", s[i].city);
        printf("Telephone: ");
        scanf("%s", s[i].tel);
        printf("Rating: ");
        scanf("%d", &s[i].rating);

        writer(fp,s[i]);
        printf ("\n");
    }
           fclose(fp);
    //int main();
}

void add_menu(int number){
int i,j;
    FILE*fp;
struct restaurant s[30];
struct restaurant x[1];
fp = fopen("data.dat", "ab");
   // printf("%d",number);
        for (j=0; j<=0; j++) {
            printf("Dish Name: ");
            scanf("%s", s[number].list[j].dis_name);
            strcpy(x[0].list[j].dis_name, s[number].list[j].dis_name);
            printf("Dish Type: ");
            scanf("%s", s[number].list[j].type);
            printf("Price: ");
            scanf("%f", &s[number].list[j].price);
            
            writer(fp,s[number]);
        }
        printf ("\n");
        fclose(fp);
}



/*Reader Code*/

int number_data(int number){ //read & at the same time, count number of resto
    int i,k=0;
    FILE *fp;
    struct restaurant s[30];
    fp = fopen("data.dat", "rb");
    
    for (i=0;i<(30);i++ && k++){
        
        s[i] = reader(fp);
        if(i>0 && strcmp(s[i].name,s[i-1].name)==0 ){//&& strcmp(s[i].list[0].dis_name,s[i-1].list[0].dis_name)==0){
            //printf("Number of Resto:%d ", (k+1));
            //printf("\n");
            fclose(fp);
            return (k+1);
        }
    }
    fclose(fp);
    return 30;
}

int number_dishes(int number){ //count how many dishes
    int i,k=0;
    struct restaurant s[30];
    for (i=0;i<=7;i++ && k++){
        
        if( strcmp(s[number].list[i].dis_name, s[number].list[i-1].dis_name)==0){
            //printf("Number of dishes:%d ", (k+1));
            //printf("\n");
            break;
        }
    }
            return (k+1);
}

/*
 void print(int number){ //print an array of structure
    struct restaurant s[30];
        printf("Name\tCity\tTelephone #\tRating\n");
        printf("%s \t%s \t%s \t%12d\n", s[1].name, s[1].city, s[1].tel, s[1].rating);
}
*/


void print_menu(int number){ //print all array of structure
    int j;
    char ans;
    //FILE *f;
    struct restaurant s[30];
    
    printf("Name\tCity\tTelephone #\tRating\n");
    printf("%s \t%s \t%s \t%12d\n", s[number].name, s[number].city, s[number].tel, s[number].rating);
    
    
    printf("Dish Name\tDish Type\tPrice \t\n");
    for (j=0; j<number_dishes(number); j++) {
        printf("%s \t %13s \t %13f \t\n",s[number].list[j].dis_name, s[number].list[j].type, s[number].list[j].price);
    }
    printf("Would you like to add or delete (A/D)?> ");
    if (scanf("%c",&ans)=='a') {
      //  add_menu(number, f);
    }
   // fclose(f);
}

void question(int number){
    int error_handle;
    char ans;
    //FILE *f;
    if(error_handle!=1){
    printf("Would you like to add or delete (A/D)?> ");
        error_handle=1;
    }
    //printf("%d\n",number);
    scanf("%c",&ans);
    switch (ans) {
        case 'a':
            add_menu(number);
            break;
        case 'd':
            printf("Delete Function\n\n");
            break;
        default:
            question(number);
            break;
    }
    
}

int search_city (int number){ //parang print rin
    int i,j,k;
    struct restaurant s[30];
    char city[15];
    char ans;
    printf("\nCity> ");
    scanf("%s",city);
    printf("#\tName\tCity\tTelephone #\tRating\n");
    for (i=0;i<=number;i++){
        if(strcmp(s[i].city, city)==0){
        printf("%d\t %s \t%s \t%s \t%12d\n", (i+1),s[i].name, s[i].city, s[i].tel, s[i].rating);
        }
    }
    printf("#>");
    scanf("%d",&k);
    k-=1;
    //print_menu(k);
    
    printf("Name\tCity\tTelephone #\tRating\n");
    printf("%s \t%s \t%s \t%12d\n", s[k].name, s[k].city, s[k].tel, s[k].rating);
    
    printf("\nDish Name\tDish Type\tPrice \t\n");
    for (j=0; j<number_dishes(k); j++) {
        printf("%s \t%11s \t%13f\t\n",s[k].list[j].dis_name, s[k].list[j].type, s[k].list[j].price);
    }
    printf("%d",k);
    return k;
    /*printf("Would you like to add or delete (A/D)?> ");
    if(scanf("%s",city)=='a'){
        return k;
    }
    else{
        return 0;
    }
    */

}
int search_rating (int number){ //parang print rin
    int i,j,rating,k;
    char ans;
    struct restaurant s[30];
    scanf("%d",&rating);
    printf("#\tName\tCity\tTelephone #\tRating\n");
    for (i=0;i<number;i++){
        
        if(s[i].rating== rating){
             printf("%d\t %s \t%s \t%s \t%12d\n", (i+1),s[i].name, s[i].city, s[i].tel, s[i].rating);
        }
        
    }
    printf("#>");
    scanf("%d",&k);
    k-=1;
    printf("Name\tCity\tTelephone #\tRating\n");
    printf("%s \t%s \t%s \t%12d\n", s[k].name, s[k].city, s[k].tel, s[k].rating);
    
    printf("\nDish Name\tDish Type\tPrice \t\n");
    for (j=0; j<number_dishes(k); j++) {
        printf("%s \t%11s \t%13f\t\n",s[k].list[j].dis_name, s[k].list[j].type, s[k].list[j].price);
    }
    printf("Would you like to add or delete (A/D)?> ");
    if(scanf("%s",&ans)=='a'){
        return 1;
    }
    else{
        return 0;
    }

}
int search_price (int number){ //parang print rin
    int i,j,k;
    float min,max;
    char ans;
    printf("Min> ");
    scanf("%f",&min);
    printf("Max> ");
    scanf("%f",&max);
    
    struct restaurant s[30];
    printf("#\tName\tCity\tTelephone #\tRating\n");
    for (i=0;i<number;i++){
        for (j=0; j<number_dishes(number); j++) {
                if (s[i].list[j].price<=max && s[i].list[j].price>=min) {
                    printf("%d\t %s \t%s \t%s \t%12d\n", (i+1),s[i].name, s[i].city, s[i].tel, s[i].rating);
                }
        }
    }
    {
    printf("#>");
    scanf("%d",&k);
    k-=1;
    printf("Name\tCity\tTelephone #\tRating\n");
    printf("%s \t%s \t%s \t%12d\n", s[k].name, s[k].city, s[k].tel, s[k].rating);
    
    printf("\nDish Name\tDish Type\tPrice \t\n");
    for (j=0; j<number_dishes(k); j++) {
        printf("%s \t%11s \t%13f\t\n",s[k].list[j].dis_name, s[k].list[j].type, s[k].list[j].price);
    }
    printf("Would you like to add or delete (A/D)?> ");
    if(scanf("%c",&ans)=='a'){
        return 1;
    }
    else{
        return 0;
    }

    }/*Print Menu*/
    }

/*End*/


int main()
{
    int number;
    //FILE *fp; //pointer for reader
    //FILE *fptr; //pointer for writer

    int number_of_resto;
    char ans;
    {
    //writer Code
    //FILE *fptr;
    //add_resto(fptr);
    //add_menu(fptr);
    //fclose(fptr);
    //
    
    
    /*Reader Code */ //It must read first!!
    }//Trash
    
    
    /*Menu Code*/
    number_of_resto = number_data(1);
    //fclose(fp);
    {
    printf("\nBotchog App: %d Restaurants\n\n", number_of_resto);
        //print_menu

    printf("A Add Restaurant\n");
    printf("C Search by City\n");
    printf("R Search by Rating\n");
    printf("P Search by Price\n");
    printf("X Exit\n\n");
    printf("Enter> ");
    }

    /*Print Result*/
    char q='\0';
    scanf("%c",&q);
    switch (q) {
        case 'a':
            printf("Add Restaurant\n");
            printf("How many Restaurant?> ");
            scanf("%d",&number);
            add_resto(number,number_of_resto);
            //fclose(fptr);
            //return main();
            break;
        case 'c':
            printf("Search by City\n");
            question(search_city(number_of_resto));
            break;
        case 'r':
            printf("Search by Rating\n");
            search_rating(number_of_resto);
            if (number=='1') {
                add_menu(number);
            }
            else {
                return main();
            }

            break;
        case 'p':
            printf("Search by Price\n");
            search_rating(number_of_resto);
            if (number=='1') {
                add_menu(number);
                //fclose(fptr);
            }
            else {
                return main();
            }

            break;
        case 'x':
            return 0;
            break;
        default:
            printf("\n");
            //return main();
            break;
    }
    return main();

  
            //fclose(fptr);
 //   fclose(fp);


            /*End*/
    
    printf("\n");
    
    

}
