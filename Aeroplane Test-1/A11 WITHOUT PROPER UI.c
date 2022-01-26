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
void EditUser(void); // function to edit user info (ADMIN)
void DeleteUser(void); // function to delete a user (ADMIN) / (USER)
int ticketPrice(char class[],int quantity); // Function to show and calculate ticket price.
struct admin {char nam[100],pass[30];};
int admincreate(void); // TO CREATE A SINGLE ADMIN ACCOUNT
int admincall(void); // CALL ADMIN TO ENTER ADMIN FUNCTIONS
void menuUSer (void);
void menuADmin(void);
int main ()
{
    printf("\n \t \t \t <WELCOME TO FLY-NSU> \n\n"); // temporary name .
    printf("\t \t <TO EXPLORE OUR PACKAGES AND BOOK A FLIGHT------>PRESS-1>\n");
    printf("\n \t\t ARE YOU AN ADMINISTRATOR ? ------>PRESS 2 TO ENTER ADMINSTRATOR SECTION \n");

    char p;
    scanf(" %c",&p);
    system("cls"); // clears console
    fflush(stdin);
    if(p=='1')
    {
        menuUSer;
        char c;

        while(1)
        {
            menuUSer();
            printf("enter a character input \n");
            fflush(stdin);
            scanf("%c",&c);

            if(c=='r' || c=='R')
            {
                fflush(stdin);
                CheckPackage();

            }
            else if (c=='b'||c=='B')
            {
                fflush(stdin);
                AddUser();

            }
            else if (c=='c'||c=='C')
            {

                fflush(stdin);
                DeleteUser();

            }
            else if (c=='m'||c=='M')
            {
                fflush(stdin);
                SearchByDestination();

            }
            else if (c=='n'||c=='N')
            {
                fflush(stdin);
               SearchByAirlines();

            }
             else if (c=='q'||c=='Q')
             {

                 break ;
             }
           else { printf("incorrect input \n");}

        }
    }
    else if (p=='2')
    {
        int k=0;
        printf("\t \t WANT TO CREATE AN ADMIN ACCOUNT ? PRESS 3 \n");
        printf("\t \t TO LOGIN TO ADMIN ACCOUNT PRESS 4");
        char d;
        scanf(" %c",&d);
        system("cls");

            printf("enter a character input \n");
            if(d=='3')
            {
                admincreate();
                printf("admin account created successfully \n");
                system("cls");
            }
            else if(d=='4')
            {
                printf(" \n YOU MUST FIRST LOGIN IN \n");
                int k= admincall();
                if (k==1)
            {
                menuADmin();
                char w;
                fflush(stdin);
                while(1)
                {
                menuADmin();
                printf("enter a character input \n");
                scanf(" %c",&w);
                if(w=='a' || w=='A')
                {
                    fflush(stdin);
                    AddPackage();
                }
                else if (w=='b' || w=='B')
                {
                    fflush(stdin);
                    CheckPackage();

                }
                else if (w=='c' || w=='C')
                {
                    fflush(stdin);
                    EditPackage();

                }
                else if (w=='d' || w=='D')
                {
                    fflush(stdin);
                    DeletePackage();

                }
                else if (w=='e' || w=='E')
                {
                    fflush(stdin);
                    ReadAllUsers();

                }
                else if (w=='f' || w=='F')
                {
                    fflush(stdin);
                    SearchUser();

                }
                else if (w=='g' || w=='G')
                {
                    fflush(stdin);
                    EditUser();

                }
                else if (w=='h' || w=='H')
                {
                    fflush(stdin);
                    DeleteUser();

                }
                else if (w=='q' || w=='Q')
                {
                    break;

                }
             else
             { printf("incorrect input \n");} }
                }
        }
        }

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
    fflush(stdin);
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
    fflush(stdin);
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
            printf("PACKAGGE NOT FOUND !!!! \n");
        }

    else
    {
    char c;
    printf("for destination press 'D' or 'd' \n");
    printf("for airlines press 'A' or 'a' \n");
    printf("for departure date 'T' or 't' \n");
    printf("which catagory to do want to edit ? \n");
    fflush(stdin);
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
    fclose(fp2);

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
   if (ticks==NULL)
        {
        printf("File operation failed!");
        return -1;
        }
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
   printf("TICKET PURCHASED :) HAVE A SAVE FLIGHT !!!! \n");
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

}

int admincreate(void)
{

     int i;

    struct admin a1;

    printf("enter user name \n");
    fflush(stdin);
    gets(a1.nam);
    printf("enter password \n");
    gets(a1.pass);

    FILE *fp;
    fp = fopen("ADMINACCOUNTS.txt","w");
        fprintf(fp,"%s %s \n",a1.nam,a1.pass);
        fclose(fp);
        return 0;
}

int admincall(void)
{
    char Usernam[100];
    char password[30];
    struct admin a2;
    int i;
    FILE *fp;
    fp = fopen("ADMINACCOUNTS.txt","r");

     fscanf(fp,"%s %s",a2.nam,a2.pass);


    int length;
    int c=1;

    if(c==1)
    {
        length=strlen(a2.pass);
    }

    printf("enter user name \n");
    fflush(stdin);
    gets(Usernam);
    fflush(stdin);
    printf("enter password\n");

    for(i=0;i<length;i++)
    {
      password[i]= getch();
       printf("*");
    }
     password[i]='\0';
    int compuser=0,compass=0;
    if(c==1)
    {
    compuser=strcmp(a2.nam,Usernam);
    compass=strcasecmp(a2.pass,password);
    }
   // printf("%d %d %s %s",compuser,compass,a2.nam,Usernam);
    if(compass==0 && compuser==0)
    {
        printf(" \n LOGIN SUCCESSFUL !!! \n");
        return 1;
    }
   else printf("\n incorrect username or password \n");

    return -1;
}
void menuUSer (void)
{
    printf("\t \t > to check packages press r \n");
        printf("\t \t > to book a flight press b \n");
        printf("\t \t > to cancel a flight press c \n");
        printf("\t \t > to search by destination press m \n");
        printf("\t \t > to search by airlines press n \n");
        printf("\t \t > to quit press q\n \n");
        printf("NOTE : IF YOU ENTER INCORRECT DETAILS, YOU HAVE TO RE ENTER THAT SECTION TO CORRENT IT \n");
        return;
}
void menuADmin(void)
{
    printf("\t \t > to add packages press a \n");
    printf("\t \t > to check all packages b \n");
    printf("\t \t > to edit package press  c \n");
    printf("\t \t > to delete package press  d \n");
    printf("\t \t > to read all users press  e \n");
    printf("\t \t > to search users press  f \n");
    printf("\t \t > to edit users press  g \n");
    printf("\t \t > to delete users press  h \n");
    printf("\t \t > to quit press q\n \n");
    printf("NOTE : IF YOU ENTER INCORRECT DETAILS, YOU HAVE TO RE ENTER THAT SECTION TO CORRENT IT \n");
    return ;
}
