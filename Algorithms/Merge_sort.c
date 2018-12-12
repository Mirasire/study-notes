#include <stdio.h>
#include <stdlib.h>

void Merge(int *number,int q,int p,int r); //用来排序
void Merge_sort(int *number,int q,int r); //用来拆数组
void print(int *number,int n);

int main()
{
    int number[17]={6,12,3,5,2,6,1322,7,8,98,63,23,98,77,23,56,107};
    print(number,17);
    Merge_sort(number,0,17);
    return 0;
}

void print(int *number,int n)
{
    for(int i=0; i<n; i++)
        printf("%d\t",number[i]);
    printf("\n");
    return;
}

void Merge(int *number,int p,int q,int r)
{
    int n1=q-p+1,n2=r-q;
    int ia=0,ib=0,i=0;
    int *B = &number[q+1];
    int *A = (int *)malloc(sizeof(int)*n1);
    for(int i=0,j=p; i<n1; i++)
        A[i] = number[j++];
    while(ia < n1 && ib < n2)
    {
        if(*(A+ia) <= *(B+ib))
            *(&number[p]+i++) = *(A+ia++);
        else
            *(&number[p]+i++) = *(B+ib++);
    }
    int end = n1+n2;
    while(i < end)
    {
        if(ia <= ia)
            *(&number[p]+i++) = *(A+ia++);
        else
            *(&number[p]+i++) = *(B+ib++);
    }
    print(number,r);
    free(A);
    return;
}

void Merge_sort(int *number,int p,int r)
{
    if(p >= r)
        return;
    else
    {
        int q = (p+r)/2;
        Merge_sort(number,p,q);
        Merge_sort(number,q+1,r);
        Merge(number,p,q,r);
        print(number,r);
    }
}