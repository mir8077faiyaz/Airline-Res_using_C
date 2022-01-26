#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Packages {char Pkg_no[50],destination[80],Airline[100],Depart[40],seats[30];}; // structure to add packages.
typedef struct Packages pkg;
void AddPackage(void);
void CheckPackage(void);
void SearchByDestination(void);
int main ()
{
    //AddPackage();
    //CheckPackage();
    SearchByDestination();
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
    printf("TO SEARCH BY DESTINATION TYPE THE NAME OF DESTINATION IN LOWERCASE WITH CORRECT SPELLING \n");
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
