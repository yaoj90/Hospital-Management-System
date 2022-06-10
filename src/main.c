#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct patient{
    char name[16];
    char address[16];
    char disease[16];
    char comment[16];
    unsigned long personalNumber, phoneNumber;
    unsigned int age;
}p;

void option();
void modify_option();
void add();
void read();
void search();
void modify();
void del();

unsigned int recsize = sizeof(struct patient);

int main() 
{
        unsigned int choice;       
        printf("Hospital Management System\n");
     
        while(1)
        {
                option();
                printf("ENTER  YOUR CHOICE\n");
                scanf("%u",&choice);
                switch(choice)
                {
                        case 1:
                                add();
                                break;
                        case 2:
                                
                                read();                   
                                break;
                        case 3:
                                search();                       
                                break;
                        case 4:
                                modify();                       
                                break;      
                        case 5:
                                del();                       
                                break;    
                        case 0:
                                exit(0);
                }
        }
}


void option()
{
    printf("\nENTER YOUR FOLLOWING CHOICE\n");
    printf("1 ==> ADD RECORD\n");
    printf("2 ==> READ ALL RECORD\n");
    printf("3 ==> SEARCH RECORD\n");
    printf("4 ==> MODIFY RECORD\n");
    printf("5 ==> DELETE RECORD\n");
    printf("0 ==> EXIT\n");
}

void modify_option()
{
    printf("\nENTER YOUR FOLLOWING MODIFICATION CHOICE\n");
    printf("1 ==> NEW NAME\n");
    printf("2 ==> NEW AGE\n");
    printf("3 ==> NEW PHONE NUMBER\n");
    printf("4 ==> NEW ADDRESS\n");
    printf("5 ==> NEW DISEASE\n");
    printf("6 ==> NEW COMMENT\n");
    printf("0 ==> EXIT\n");
}

void add()
{   
    FILE *fp = fopen("HealthData","a+"); 
    fseek(fp,0,SEEK_END) ;   
    printf("\nENTER PERSONAL NUMBER\n");
    scanf("%lu", &p.personalNumber);
    printf("\nENTER NAME\n");
    scanf("%s", p.name);
    printf("\nENTER AGE\n");
    scanf("%u", &p.age);
    printf("\nENTER PHONE NUMBER\n");
    scanf("%lu", &p.phoneNumber);
    printf("\nENTER ADDRESS\n");
    scanf("%s", p.address);
    printf("\nENTER DISEASE\n");
    scanf("%s", p.disease);
    printf("\nENTER COMMENT\n");
    scanf("%s", p.comment);
    fwrite(&p,recsize,1,fp);
    fclose(fp);
}

void read()
{
    FILE *fp = fopen("HealthData","a+"); 
    rewind(fp);   
    printf("\n%20s %10s %10s %20s %10s %10s %10s", "Personal number","Name", "Age","Phone number","Address","Disease","Comment");    
                       
    while(fread(&p,recsize,1,fp)==1)
    printf("\n%20lu %10s %10u %20lu %10s %10s %10s", p.personalNumber, p.name, p.age, p.phoneNumber, p.address, p.disease, p.comment); 
    fclose(fp);   
}

void search()
{
    FILE *fp = fopen("HealthData","r+"); 
    struct patient temp;
    int searchFlag = 0;
    printf("ENTER PERSONAL NUMBER\n");
    scanf("%lu", &temp.personalNumber); 
    rewind(fp);       
    while(fread(&p,recsize,1,fp))
    {
        if(p.personalNumber== temp.personalNumber)
        {
                searchFlag = 1;
                printf("\n%20s %10s %10s %20s %10s %10s %10s", "Personal number","Name", "Age","Phone number","Address","Disease","Comment");    
                printf("\n%20lu %10s %10u %20lu %10s %10s %10s", p.personalNumber, p.name, p.age, p.phoneNumber, p.address, p.disease, p.comment); 
        }
    }
    if(!searchFlag) 
    printf("\nCANNOT FIND THE RECORD");
    fclose(fp);
}

void modify()
{
    FILE *fp = fopen("HealthData","r+"); 
    struct patient temp;
    FILE *fp1 = fopen("HealthData_temp","w");
    unsigned int choice = 1000, searchFlag = 0;
          
    printf("ENTER PERSONAL NUMBER\n");
    scanf("%lu", &temp.personalNumber); 
    // Move fp file pointer to beginning
    rewind(fp);
    while(fread(&p,recsize,1,fp))
    {
        if(p.personalNumber == temp.personalNumber)
        {
            searchFlag = 1;
            while(choice != 0)
            {
                modify_option();
                printf("ENTER  YOUR CHOICE\n");
                scanf("%u",&choice);
                switch(choice)
                {
                    case 1:
                            printf("\nENTER NEW NAME\n");
                            scanf("%s",p.name);
                            break;
                    case 2: 
                            printf("\nENTER NEW AGE\n");
                            scanf("%u",&p.age);             
                            break;
                    case 3: 
                            printf("\nENTER NEW PHONE NUMBER\n");
                            scanf("%lu",&p.phoneNumber);             
                            break;
                    case 4: 
                            printf("\nENTER NEW ADDRESS\n");
                            scanf("%s",p.address);             
                            break;

                    case 5: 
                            printf("\nENTER NEW DISEASE\n");
                            scanf("%s",p.disease);             
                            break;
                    case 6: 
                            printf("\nENTER NEW COMMENT\n");
                            scanf("%s",p.comment);             
                            break;
                    case 0:             
                            break;
                    }
            }
        
        }
        fwrite(&p,recsize,1,fp1);
    }
        if(!searchFlag) 
        printf("\nCANNOT FIND THE RECORD");
        /* Close all open files */
        fclose(fp);
        fclose(fp1);
        /* Delete HealthData file and rename HealthData1 file as HealthData */

        remove("HealthData");
        rename("HealthData_temp","HealthData");
}

void del()
{
    FILE *fp = fopen("HealthData","r+"); 
    struct patient temp;
    FILE *fp1 = fopen("HealthData_temp","w");
           
    printf("ENTER PERSONAL NUMBER\n");
    scanf("%lu", &temp.personalNumber); 
    // Move fp file pointer to beginning
    rewind(fp);
    while(fread(&p,recsize,1,fp) == 1)
    {
        if(p.personalNumber != temp.personalNumber)
        {
            fwrite(&p,recsize,1,fp1);
        }            
    }
        /* Close all open files */
        fclose(fp);
        fclose(fp1);
        /* Delete HealthData file and rename HealthData1 file as HealthData */

        remove("HealthData");
        rename("HealthData_temp","HealthData");   
}

