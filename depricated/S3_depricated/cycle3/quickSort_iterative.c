#include<stdio.h>
#include "stack.h"
int partition(int a[],int ll,int ul){
        int loc=ll;
        int temp=0;
        while(ll<ul){
            while(a[loc]<=a[ul] && loc<ul){
                ul=ul-1;
            }
            if(a[loc]>a[ul]){                                    
                temp=a[loc];
                a[loc]=a[ul];
                a[ul]=temp;
                loc=ul;
                ll=ll+1;
            }
            while(a[loc]>=a[ll] && loc>ll){
                ll=ll+1;
            }
            if(a[loc]<a[ll]){
                temp=a[loc];
                a[loc]=a[ll];
                a[ll]=temp;
                loc=ll;
                ul=ul-1;
            }
        }
        return loc;
}
void quickSort(int a[], int l, int h)
{
    listPointer * stackL=NULL, * stackH=NULL;
    push(&stackL,l);
    push(&stackH,h);
    while (True)
    {
        h = pop(&stackH);
        l = pop(&stackL);
        if(h==-1 || l==-1){
            break;
        }
        int p = partition( a, l, h );

        if ( p-1 > l )                                                     //Add left task to stack
        {
            push(&stackL,l);
            push(&stackH,p - 1);
        }

        if ( p+1 < h )                                                    //Add right task to stack
        {
            push(&stackL,p + 1);
            push(&stackH,h);
        }
    }
}
int * getArray(int n){
    int * a=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&(a[i]));
    }
    return a;
}
int main(){
    printf("Enter the number of elements:");
    int n;
    scanf("%d",&n);
    int *a=getArray(n);
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("Index: %d, value: %d\n",i,a[i]);
    }
    return 0;
}
