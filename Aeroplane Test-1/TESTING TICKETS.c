#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ticketPrice(char class1[],int quantity)
{
    /*printf("CLASS BASED TICKET PRICES ARE FIXED FOR ALL DESTINATIONS \n");
    printf("============================= \n");
    printf("|| ECONOMY    - $200 EACH ||\n");
    printf("|| BUSINESS   - $300 EACH ||\n");
    printf("|| FIRSTCLASS - $500 EACH ||\n");
    printf("============================= \n"); */



    char EC[80]="ECONOMY";
    char BS[80]="BUSINESS";
    char FS[80]="FIRSTCLASS";
    int price ;



    int x,compareE=0,compareB=0,compareF=0;
    compareE=strcmp(class1,EC);
    compareB=strcmp(class1,BS);
    compareF=strcmp(class1,FS);

    printf("%s %s %s %d %d %d QUANTITY %d",EC,BS,FS,compareE,compareB,compareF,quantity);
    if (compareE==0)
    {
        price = 200*quantity;
        printf("\n PRICE :%d    \n ",price);
        return price;
    }
   /* else if (compareB==0)
    {
        price = 300*quantity;
        return price;
    }
    else if (compareF==0)
    {
        price = 500*quantity;
        return price;
    } */

    //return;
}

int main()
{
    char str[100]="ECONOMY";
    int k=5;
    int z = ticketPrice(str,k);
    printf("%d",z);
}
