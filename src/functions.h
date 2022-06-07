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
};

void option();
void modify_option();
void add(FILE *fp);
void read(FILE *fp);
void search(FILE *fp);
void modify(FILE *fp);
void del(FILE *fp);
