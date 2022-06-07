#include"functions.h"

struct patient p;
unsigned int recsize = sizeof(p);

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

void add(FILE *fp)
{   
    int ch;   
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
    while((ch = fgetc(stdin))!= EOF && ch != '\n');
}

void read(FILE *fp)
{
    rewind(fp);                          
    while(fread(&p,recsize,1,fp)==1)
    printf("\n%lu %s %u %lu %s %s %s", p.personalNumber, p.name, p.age, p.phoneNumber, p.address, p.disease, p.comment);    
}

void search(FILE *fp)
{
    struct patient temp;
    int check = 0;
    printf("ENTER PERSONAL NUMBER\n");
    scanf("%lu", &temp.personalNumber); 
    rewind(fp);       
    while(fread(&p,recsize,1,fp)==1)
    {
        if(p.personalNumber== temp.personalNumber)
        {check = 1;
        printf("\n%lu %s %u %lu %s %s %s", p.personalNumber, p.name, p.age, p.phoneNumber, p.address, p.disease, p.comment);}
    }
    if(check !=1) 
    printf("\nCANNOT FIND THE RECORD");
}

void modify(FILE *fp)
{
    struct patient temp;
    FILE *fp1 = fopen("HealthData_temp","w");
    unsigned int choice = 1000, check = 0;
    char ch;
          
    printf("ENTER PERSONAL NUMBER\n");
    scanf("%lu", &temp.personalNumber); 
    // Move fp file pointer to beginning
    rewind(fp);
    while(fread(&p,recsize,1,fp) == 1)
    {
        if(p.personalNumber == temp.personalNumber)
        {
            check = 1;
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
        if(check !=1) 
        printf("\nCANNOT FIND THE RECORD");
        /* Close all open files */
        fclose(fp);
        fclose(fp1);
        /* Delete HealthData file and rename HealthData1 file as HealthData */

        remove("HealthData");
        rename("HealthData_temp","HealthData");
        fp = fopen("HealthData","r+");
        while((ch = fgetc(stdin))!= EOF && ch != '\n');    
}

void del(FILE *fp)
{
    struct patient temp;
    FILE *fp1 = fopen("HealthData_temp","w");
    char ch;
           
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
        fp = fopen("HealthData","r+");
        while((ch = fgetc(stdin))!= EOF && ch != '\n');
    
}

