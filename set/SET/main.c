//Program made by Abhiram Shibu and Abhijith N Raj
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int size;
    char *set[103710];
}set;
void set_init(set *A)
{
    A->size=0;
    //A->set[A->size]=malloc(sizeof(char)*1000);
    //A->set[A->size]='\0';
}


void set_insert(set *A,char item[])
{
    int i;
    for(i=0;i<A->size;i++)
    {
        if(!strcmp(A->set[i],item))
        {
            printf("%s%s",item," present in A\n");
        }
        else
        {
            printf("%s%s",item," not present in A\n");
        }
    }
    (*A).set[(*A).size]=malloc(sizeof(char)*1000);
    //printf("Adding value into %d",(*A).size);
    strcpy(&A->set[A->size],item);
    (*A).size++;
}

/*set *union(set *A,set *B
{
    set un;
    int i=0,j=0;
    set temp;
    for(i=0;i<A->size;i++)
    {
        for(j=0;j<B->size;i++)
        {
            if
        }
    }

}*/

/*void set_deleteitem(set *A,int index)
{
    set temp;
    int i=0;
    printf("caled\n");
    for(i=0;i<A->size;i++)
    {
        if(i==index)
        {
            continue;
            printf("skipping",A->set[i]);
        }
        else
        {
            set_insert(&temp,A->set[i]);
        }
    }

    A=&temp;
}*/

/*void set_unique(set *A)
{
    int i=0;
    set temp;
    set *a_temp;
    a_temp=A;
    int j=0;
    char *val;
    val=malloc(sizeof(char)*1000);
    for(i=0;i<A->size;i++)
    {
        strcpy(val,&A->set[i]);
        for(j=i+1;j<A->size;j++)
        {
        if(!strcmp(val,&A->set[j]))
        {
            set_insert(&temp,val);

            set_deleteitem(&A,i);
        }

        }
    }

    set_disp(&temp);
}*/



void set_disp(set *A)
{
    int i;
    printf("\n{");
    for(i=0;i<(A->size);i++)
    {
        //printf("%d",i);
        printf(" %s",&A->set[i]);
        if(i!=A->size-1)
        {
            printf(",");
        }
    }
    printf("}\n");
}
void menu(set *A,set *B)
{
    char c=NULL;
    printf("\nWelcome to basic set operations program");
    printf("\n================Main Menu==============");
    printf("\nOption         Description             ");
    printf("\n---------------------------------------");
    printf("\n1               A Union B              ");
    printf("\n2               A Inter B              ");
    printf("\n3               A   -   B              ");
    printf("\n4                  EXIT                ");
    printf("\n---------------------------------------");
    printf("\n\nEnter an option :");
    scanf(" %c",&c);
    printf("%c",c);
    if(c=='1')
    {
        printf("\nOption 1 selected.");
    }
    else if(c=='2')
    {
        printf("\nOption 2 selected.");
    }
    else if(c=='3')
    {
        printf("\nOption 3 selected.");
    }
    else if(c=='4')
    {
        printf("\nOption 4 selected. Exiting..");
        return;
    }
    else
    {
        printf("\nSorry invalid option. Please try again");
        menu(A,B);
    }
}
int main()
{
    set A;
    set B;
    char buff[1000];
    set_init(&A);
    while(1)
    {
        printf("Enter a element in set A [/0=end]:");
        scanf("%s",buff);
        if(!strcmp(buff,"/0"))
            break;
        set_insert(&A, buff);
    }
    //("Size %d, set %s",A.size,&A.set[0]);
    //set_disp(&A);
    set_init(&B);
    while(1)
    {
        printf("Enter a element in set A [/0=end]:");
        scanf("%s",buff);
        if(!strcmp(buff,"/0"))
            break;
        set_insert(&B, buff);
    }
    //("Size %d, set %s",A.size,&A.set[0]);
    set_disp(&B);
    menu(&A,&B);
}
