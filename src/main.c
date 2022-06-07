#include"functions.h"

int main() 
{
        FILE *fp; 
        unsigned int choice;
        
        fp = fopen("HealthData","r+");
        if(fp == NULL)
        {
                fp = fopen("HealthData","w+");
                if(fp==NULL)
                {
                        puts("CANNOT OPEN FILE");
                        exit(1);
                }
        }
  
        printf("Hospital Management System\n");

     
        while(1)
        {
                option();
                printf("ENTER  YOUR CHOICE\n");
                scanf("%u",&choice);
                switch(choice)
            {
                case 1:
                        add(fp);
                        break;
                case 2:
                        
                        read(fp);                   
                        break;
                case 3:
                        search(fp);                       
                        break;
                case 4:
                        modify(fp);                       
                        break;      
                case 5:
                        del(fp);                       
                        break;    
                case 0:
                        fclose(fp);
                        exit(0);
                }
        }
}



