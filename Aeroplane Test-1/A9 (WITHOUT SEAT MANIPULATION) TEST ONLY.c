#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Packages {char Pkg_no[50],destination[80],Airline[100],Depart[40];}; // structure to add packages.
typedef struct Packages pkg;
struct Users {char FirstName[100],LastName[100],destination[100],Pkg_no[50],ticketClass[50],ticketQuantity[15],price[100],ID[20];} ;// structure to add users.
typedef struct Users usr;
void AddPackage(void); // function to add trips (ADMIN)
void CheckPackage(void); // function to read all trips
void SearchByDestination(void); //function to search trips
void SearchByAirlines(void); // function to search trips
void EditPackage(void); // function to edit trip info (ADMIN)
void DeletePackage(void); // function to delete packages (ADMIN)
void AddUser(void); // function to buy tickets
void ReadAllUsers(void); // function to read all buyers
void SearchUser(void); // function to search for an user (ADMIN)
void EditUser(void); // function to edit user info (ADMIN) / (USER)
void DeleteUser(void); // function to delete a user (ADMIN) / (USER)
int ticketPrice(char class[],int quantity); // Function to show and calculate ticket price.
int main ()
{
    //AddPackage();
    //CheckPackage();
    //SearchByDestination();
    //SearchByAirlines();
    //EditPackage();
    //DeletePackage();
    ReadAllUsers();
    //AddUser();
    //SearchUser();
    //EditUser();
    DeleteUser();


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
        printf("%d \n",i+1);
        printf("Enter pakage no : \n");
        scanf("%s",list[i].Pkg_no);
        printf("Enter Destination : \n");
        scanf("%s",list[i].destination);
        printf("Enter Airlines Name : \n");
        scanf("%s",list[i].Airline);
        printf("Enter departure date  [DD/MM/YY] : \n");
        scanf("%s",list[i].Depart);
        system("cls"); // clears console screen

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
        fprintf(fp,"%s %s %s %s \n",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart);
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
        fscanf(fp,"%s %s %s %s ",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart);
        i++;
    }
    fclose(fp);
    // dotted lines and bars are added for a better looking output in console .
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
    for(j=0;j<i;j++) // the while loop iterates line+1 times till end of file. so for loop must run i-1 times.
    {

        printf("||%10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);
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
        fscanf(fp,"%s %s %s %s ",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart);
        i++;
    }
    fclose(fp);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i;j++)
    {
        compare=strcmp(destination,list[j].destination);
        if(compare==0)
        {

            printf("||%10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);

        }
    }
    printf("------------------------------------------------------------------------------------------- \n");
    if(compare !=0)
        {
            printf("DESTINATION NOT FOUND !!!! \n");
        }
    else return;
}
void SearchByAirlines(void)
{
    printf("TO SEARCH BY AIRLINES TYPE THE NAME OF AIRLINES IN UPPERCASE WITH CORRECT SPELLING \n");
    char air[80];
    printf("Enter airline \n");
    gets(air);
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
        fscanf(fp,"%s %s %s %s ",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart);
        i++;
    }
    fclose(fp);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i;j++)
    {
        compare=strcmp(air,list[j].Airline);
        if(compare==0)
        {

            printf("||%10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);

        }
    }
    printf("------------------------------------------------------------------------------------------- \n");
    if(compare !=0)
        {
            printf("AIRLINES NOT FOUND !!!! \n");
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
        fscanf(fp,"%s %s %s %s ",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart);
        i++;
    }
    fclose(fp);
    char Pack[50];
    printf("ENTER PACKAGE NO IN THIS FORMAT 'PKG1' \n");
    gets(Pack);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE||  \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i;j++)
    {
        compare=strcmp(Pack,list[j].Pkg_no);
        if(compare==0)
        {

            printf("||%10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);
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
    for(j=0;j<i;j++)
    {
        fprintf(fp2,"%s %s %s %s  \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);
    }
    // opens new file pointer to edit package.

    return ;
}
void DeletePackage(void)
{
    pkg list[100];
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
        fscanf(fp,"%s %s %s %s ",list[i].Pkg_no,list[i].destination,list[i].Airline,list[i].Depart);
        i++;
    }
    fclose(fp);
    char Pack[50];
    printf("ENTER PACKAGE NO YOU WANT TO DELETEIN THIS FORMAT 'PKG1' \n");
    gets(Pack);
    int compare=0;
    printf("||PACKAGE N0|| ||DESTINATION|| ||AIRLINES|| ||DEPARTURE|| \n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(l=0,j=0;j<i;j++,l++)
    {
        compare=strcmp(Pack,list[j].Pkg_no);
        if(compare==0)
        {
           printf("||%10s     %10s     %10s     %10s|| \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);
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
     for(j=0;j<i;j++)
    {
            if(j==l)
            {
                continue;
            }

            fprintf(fp2,"%s %s %s %s  \n",list[j].Pkg_no,list[j].destination,list[j].Airline,list[j].Depart);

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
   int k;
   printf("enter your first name \n");
   fflush(stdin);
   gets(list.FirstName);
   printf("enter your last name \n");
   gets(list.LastName);
   printf("enter travel destination \n");
   gets(list.destination);
   printf("enter package number in the format 'PKG1' \n");
   gets(list.Pkg_no);
   printf("enter ticket class (cross class not available) \n");
   printf("CLASS BASED TICKET PRICES ARE FIXED FOR ALL DESTINATIONS \n");
    printf("============================= \n");
    printf("|| ECONOMY    - $200 EACH ||\n");
    printf("|| BUSINESS   - $300 EACH ||\n");
    printf("|| FIRSTCLASS - $500 EACH ||\n");
    printf("============================= \n");
    printf("enter ticket class in uppercase as shown above \n");
    gets(list.ticketClass);
   printf("enter total number of tickets \n");
   gets(list.ticketQuantity);
   printf("please confirm ticket quantity ; \n");
   scanf("%d",&k);
   int ticketFunc = ticketPrice(list.ticketClass,k); // takes input from ticketPrice return .
   //printf("%d",ticketFunc);
   FILE *ticks;
   ticks=fopen("tickets.txt","w");
   fprintf(ticks,"%d",ticketFunc);
   fclose(ticks);
   FILE *scn;
   scn=fopen("tickets.txt","r");
   fscanf(scn,"%s",list.price);
   fclose(scn);
   printf("enter your id \n");
   printf("user ID should be first 3 letters of first name followed by package number \n");
   printf("for example : first name is HENRY and package is PKG3 then ID is : HEN3 \n");
   fflush(stdin);
   gets(list.ID);


   FILE *fp;
   fp=fopen("users.txt","a");
   if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
   fprintf(fp,"%s %s %s %s %s %s %s %s \n",list.FirstName,list.LastName,list.destination,list.Pkg_no,list.ticketClass,list.ticketQuantity,list.price,list.ID);
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
void ReadAllUsers(void)
{
    usr list[100];
    int i=0,j;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("users.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s\n ",list[i].FirstName,list[i].LastName,list[i].destination,list[i].Pkg_no,list[i].ticketClass,list[i].ticketQuantity,list[i].price,list[i].ID);
        i++;
    }
    fclose(fp);
    // dotted lines and bars are added for a better looking output in console .
    printf("||FIRST NAME     LAST NAME     DST     PKG     CLASS        TICKET Q        PRICE        ID||\n");
    printf("------------------------------------------------------------------------------------------- \n");
    for(j=0;j<i;j++) // the while loop iterates line+1 times till end of file. so for loop must run i-1 times.
    {

        printf("||%10s %10s %10s %10s %10s %10s %10s %10s|| \n",list[j].FirstName,list[j].LastName,list[j].destination,list[j].Pkg_no,list[j].ticketClass,list[j].ticketQuantity,list[j].price,list[j].ID);
    }
    printf("------------------------------------------------------------------------------------------- \n");
    return ;
}
void SearchUser(void)
{
     printf("TO SEARCH USER ENTER THE USER ID \n");
    char usid[80];
    printf("Enter ID \n");
    gets(usid);
    usr list[100];
    int i=0,j;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("users.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s\n ",list[i].FirstName,list[i].LastName,list[i].destination,list[i].Pkg_no,list[i].ticketClass,list[i].ticketQuantity,list[i].price,list[i].ID);
        i++;
    }
    fclose(fp);
    int compare=0;
    printf("||FIRST NAME     LAST NAME     DST     PKG     CLASS        TICKET Q        PRICE        ID||\n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i;j++)
    {
        compare=strcmp(usid,list[j].ID);
        if(compare==0)
        {

            printf("||%10s %10s %10s %10s %10s %10s %10s %10s|| \n",list[j].FirstName,list[j].LastName,list[j].destination,list[j].Pkg_no,list[j].ticketClass,list[j].ticketQuantity,list[j].price,list[j].ID);
            break;
        }

    }
    printf("------------------------------------------------------------------------------------------- \n");

    if(compare !=0)
        {
            printf("ID NOT FOUND !!!! \n");
        }
    else return;
}
void EditUser(void)
{
    printf("TO EDIT USER DETAILS ENTER THE USER ID \n");
    char usid[80];
    printf("Enter ID \n");
    gets(usid);
    usr list[100];
    int i=0,j;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("users.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s\n ",list[i].FirstName,list[i].LastName,list[i].destination,list[i].Pkg_no,list[i].ticketClass,list[i].ticketQuantity,list[i].price,list[i].ID);
        i++;
    }
    fclose(fp);
    int compare=0;
    printf("||FIRST NAME     LAST NAME     DST     PKG     CLASS        TICKET Q        PRICE        ID||\n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(j=0;j<i;j++)
    {
        compare=strcmp(usid,list[j].ID);
        if(compare==0)
        {

            printf("||%10s %10s %10s %10s %10s %10s %10s %10s|| \n",list[j].FirstName,list[j].LastName,list[j].destination,list[j].Pkg_no,list[j].ticketClass,list[j].ticketQuantity,list[j].price,list[j].ID);
            break;
        }

    }
    printf("------------------------------------------------------------------------------------------- \n");

    if(compare !=0)
        {
            printf("ID NOT FOUND !!!! \n");
        }
    else
        {
    printf("Enter new first Name \n");
    scanf("%s",list[j].FirstName);
    printf("Enter new last Name \n");
    scanf("%s",list[j].LastName);
    printf("Enter new ID (first 3 letters of your first name and pkg no) \n");
    scanf("%s",list[j].ID);
    }
     // Saves this list to a file.
     FILE *fp2;
    fp2=fopen("users.txt","w");
    if (fp2==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    for(j=0;j<i;j++)
    {

        fprintf(fp2,"%s %s %s %s %s %s %s %s\n ",list[j].FirstName,list[j].LastName,list[j].destination,list[j].Pkg_no,list[j].ticketClass,list[j].ticketQuantity,list[j].price,list[j].ID);
    }
    fclose(fp2);
    // opens new file pointer to edit users.
    return;
}
void DeleteUser(void)
{
    printf("TO DELETE USER DETAILS ENTER THE USER ID \n");
    char usid[80];
    printf("Enter ID \n");
    gets(usid);
    usr list[100];
    int i=0,j,l;
    // Opening file to read the packages
    FILE *fp;
    fp=fopen("users.txt","r");
    if (fp==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
    // While loop below copies data from file to structure.
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %s %s %s\n ",list[i].FirstName,list[i].LastName,list[i].destination,list[i].Pkg_no,list[i].ticketClass,list[i].ticketQuantity,list[i].price,list[i].ID);
        i++;
    }
    fclose(fp);
    int compare=0;
    printf("||FIRST NAME     LAST NAME     DST     PKG     CLASS        TICKET Q        PRICE        ID||\n");
    printf("------------------------------------------------------------------------------------------- \n");
     for(l=0,j=0;j<i;j++,l++)
    {
        compare=strcmp(usid,list[j].ID);
        if(compare==0)
        {

            printf("||%10s %10s %10s %10s %10s %10s %10s %10s|| \n",list[j].FirstName,list[j].LastName,list[j].destination,list[j].Pkg_no,list[j].ticketClass,list[j].ticketQuantity,list[j].price,list[j].ID);
            break;
        }

    }
    printf("------------------------------------------------------------------------------------------- \n");

    if(compare !=0)
        {
            printf("ID NOT FOUND !!!! \n");
        }

        else printf("USER DELTED \n");
    char name_file[100]="users.txt";
    FILE *fp2;
    fp2= fopen("temporary.txt","w");
    if (fp2==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
     for(j=0;j<i;j++)
    {
            if(j==l)
            {
                continue;
            }

            fprintf(fp2,"%s %s %s %s %s %s %s %s\n ",list[j].FirstName,list[j].LastName,list[j].destination,list[j].Pkg_no,list[j].ticketClass,list[j].ticketQuantity,list[j].price,list[j].ID);
    }
    fclose(fp2);
    remove(name_file);
    rename("temporary.txt",name_file);
    return ;
}
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

  //  printf("%s %s %s %d %d %d QUANTITY %d",EC,BS,FS,compareE,compareB,compareF,quantity);
    if (compareE==0)
    {
        price = 200*quantity;
    //    printf("\n %d",price);
        return price;
    }
    else if (compareB==0)
    {
        price = 200*quantity;
   //     printf("\n %d",price);
        return price;
    }
    else if (compareF==0)
    {
        price = 200*quantity;
//    printf("\n %d",price);
        return price;
    }
    else return -1;

   //return;
}
