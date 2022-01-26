#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Packages {char Pkg_no[50],destination[80],Airline[100],Depart[40],seats[30];}; // structure to add packages.
typedef struct Packages pkg;
struct Users {char FirstName[100],LastName[100],destination[100],Pkg_no[50],ticketClass[50]; int ticketQuantity;}; // structure to add users.
typedef struct Users usr;
void AddPackage(void);
void CheckPackage(void);
void SearchByDestination(void);
void EditPackage(void);
void DeletePackage(void);
void AddUser(void);
int main ()
{
    //AddPackage();
    //CheckPackage();
    //SearchByDestination();
    //EditPackage();
    //DeletePackage();
    AddUser();
    return 0;
}
void AddPackage(void)
{
    printf("Welcome to Administrator panel -ADD PACKAGES section \n");
    pkg list[11];
    int i,n;
    printf("\n you can enter a maximum of 10 packages \n");
    printf("\n HOW MANY PACKAGES DO YOU WANT TO ADD ? \n");
    scanf("%d",&n);
    if(n>10)
    {
         printf("\n you can enter a maximum of 10 packages \n");
         printf("\n Please re-enter the number of packages \n");
         scanf("%d",&n);
    }
    // Takes input to the structure - Packages
    for(i=0;i<n;i++)
    {
        printf("Enter pakage no : \n");
        scanf("%s",list[i].Pkg_no);
        printf("Enter Destination : \n");
        scanf("%s",list[i].destination);
        printf("Enter Airlines Name : \n");
        scanf("%s",list[i].Airline);
        printf("Enter departure date  [DD/MM/YY] : \n");
        scanf("%s",list[i].Depart);
        printf("Enter no. of seats : \n");
        scanf("%s",list[i].seats);

    }
    // Opening file to save these packages
    FILE *fp;
    fp=fopen("packages.txt","w");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }

    // Saves this list to a file.
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s %s %s %s %s \n",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart,list[i].seats);
    }
    fclose(fp);
    return;
}
void CheckPackage(void)
{
    pkg list[11];
    int i=0,j;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("packages.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart,list[i].seats);
        i++;
    }
    fclose(fp);
    // dotted lines and bars are added for a better looking output in console .
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE||  ||TOTAL SEATS|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
    for(j=0;j<i-1;j++) // the while loop iterates line+1 times till end of file. so for loop must run i-1 times.
    {

        printf("||%10s     %10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart,list[j].seats);
    }
    printf("------------------------------------------------------------------------------------------- \n");
    return ;
}
void SearchByDestination(void)
{
    printf("TO SEARCH BY DESTINATION TYPE THE NAME OF DESTINATION IN UPPERCASE WITH CORRECT SPELLING \n");
    char destination[80];
    printf("Enter destination \n");
    gets(destination);
    pkg list[11];
    int i=0,j;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("packages.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart,list[i].seats);
        i++;
    }
    fclose(fp);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE||  ||TOTAL SEATS|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i-1;j++)
    {
        compare=strcmp(destination,list[j].destination);
        if(compare==0)
        {

            printf("||%10s     %10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart,list[j].seats);

        }
    }
    printf("------------------------------------------------------------------------------------------- \n");
    if(compare !=0)
        {
            printf("DESTINATION NOT FOUND !!!! \n");
        }
    else return;
}
void EditPackage(void)
{
    char op;
    pkg list[11];
    int i=0,j;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("packages.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart,list[i].seats);
        i++;
    }
    fclose(fp);
    char Pack[50];
    printf("ENTER PACKAGE NO IN THIS FORMAT 'PKG1' \n");
    gets(Pack);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE||  ||TOTAL SEATS|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i-1;j++)
    {
        compare=strcmp(Pack,list[j].Pkg_no);
        if(compare==0)
        {

            printf("||%10s     %10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart,list[j].seats);
            break;
        }
    }
    printf("------------------------------------------------------------------------------------------- \n");
    if(compare !=0)
        {
            printf("DESTINATION NOT FOUND !!!! \n");
        }

    else
    {
    char c;
    printf("for destination press 'D' or 'd' \n");
    printf("for airlines press 'A' or 'a' \n");
    printf("for departure date 'T' or 't' \n");
    printf("for no. of seats 'S' or 's' \n");
    printf("which catagory to do want to edit ? \n");
    scanf(" %c",&c);
        switch (c)
    {
        case 'D':
        {
        printf("Enter Destination : \n");
        scanf("%s",list[j].destination);
        break ;
        }
        case 'd':
        {
        printf("Enter Destination : \n");
        scanf("%s",list[j].destination);
        break ;
        }
        case 'A':
        {
        printf("Enter Airlines Name : \n");
        scanf("%s",list[j].Airline);
        break ;
        }
        case 'a':
        {
        printf("Enter Airlines Name : \n");
        scanf("%s",list[j].Airline);
        break ;
        }
        case 'T':
        {
        printf("Enter departure date  [DD/MM/YY] : \n");
        scanf("%s",list[j].Depart);
        break ;
        }
        case 't':
        {
        printf("Enter departure date  [DD/MM/YY] : \n");
        scanf("%s",list[j].Depart);
        break ;
        }
        case 'S':
        {
        printf("Enter no. of seats : \n");
        scanf("%s",list[j].seats);
        break ;
        }
        case 's':
        {
        printf("Enter no. of seats : \n");
        scanf("%s",list[j].seats);
        break ;
        }
        default :
        printf("INCORRECT INPUT \n");
    }

    }
     // Saves this list to a file.
     FILE *fp2;
    fp2=fopen("packages.txt","w");
    if (fp2==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    for(j=0;j<i-1;j++)
    {
        fprintf(fp2,"%s %s %s %s %s \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart,list[j].seats);
    }
    // opens new file pointer to edit package.

    return ;
}
void DeletePackage(void)
{
    pkg list[11];
    int i=0,j,l;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("packages.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart,list[i].seats);
        i++;
    }
    fclose(fp);
    char Pack[50];
    printf("ENTER PACKAGE NO YOU WANT TO DELETEIN THIS FORMAT 'PKG1' \n");
    gets(Pack);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE||  ||TOTAL SEATS|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(l=0,j=0;j<i-1;j++,l++)
    {
        compare=strcmp(Pack,list[j].Pkg_no);
        if(compare==0)
        {
           printf("||%10s     %10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart,list[j].seats);
            break;
        }
    }
    printf("------------------------------------------------------------------------------------------- \n");
    if(compare !=0)
        {
            printf("PACKAGE NOT FOUND !!!! \n");
        }
    else printf("PACKAGE DELTED \n");
    char name_file[100]="packages.txt";
    FILE *fp2;
    fp2= fopen("temporary.txt","w");
    if (fp2==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
     for(j=0;j<i-1;j++)
    {
            if(j==l)
            {
                continue;
            }

            fprintf(fp2,"%s %s %s %s %s \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart,list[j].seats);

    }
    fclose(fp2);
    remove(name_file);
    rename("temporary.txt",name_file);

    return ;
}
void AddUser(void)
{
    printf("WELCOME TO PACKAGE SELECTION MODULE \n ");
    char z;
    CheckPackage();
    printf("\n The list of packages available are added above ^ \n");
    printf("to purchase ticket press any button. To exit, press 'q' \n \n");
    scanf(" %c",&z);
    if(z=='q' || z=='Q')
    {
        return;
    }

   usr list;
   printf("enter your first name \n");
   fflush(stdin);
   gets(list.FirstName);
   printf("enter your last name \n");
   gets(list.LastName);
   printf("enter travel destination \n");
   gets(list.destination);
   printf("enter package number in the formar 'PKG1' \n");
   gets(list.Pkg_no);
   printf("enter ticket class (cross class not available) \n");
   printf("[Economy] [Business] [First] \n");
    gets(list.ticketClass);
   printf("enter total number of tickets \n");
    scanf("%d",&list.ticketQuantity);
   FILE *fp;
   fp=fopen("users.txt","a");
   if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
   fprintf(fp,"%s %s %s %s %s %d\n",list.FirstName,list.LastName,list.destination,list.Pkg_no,list.ticketClass,list.ticketQuantity);
   fclose(fp);
   fflush(stdin);
   char op;
   do
  {

    printf("Continue for next passenger? [y/n] \n");
    scanf("%s",&op);
    switch(op)
    {
    case 'y':
    system("cls"); // this is used to clear the console
     AddUser();
     break;
    case 'n':
    printf("\n");
    printf("Have a safe trip  !!!!!!\n");
    break;
    default:
    printf("Press either y or n \n");
    break;
    }
  } while(op!='n');
   return;
}
