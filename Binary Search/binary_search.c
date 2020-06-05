#include <stdio.h>

void binary_search(int b[], int n, int item);

void binary_search(int b[], int n, int item)
{
    int l=0;
    int u=n-1;
    int m;
    while(l<=u){
        m=l+u/2;
        if(item==b[m]){
            printf("Found");
            return 0;
        }
        else if(item<b[m]){
            u=m-1;
        }
        else if(item>b[m]){
            l=m+1;
        }
    }
    printf("Not found");
}

int main()
{
    int b[5]={1,2,3,4,5};
    binary_search(b, 5, 4);
}
