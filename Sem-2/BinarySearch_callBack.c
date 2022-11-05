/*Implement a binary search using callbacks

Input Format

k - the size of the array
N - input elements
key - element to be searched

Output Format

print " FOUND" and with its position
else
print "NOT FOUND"*/
#include<stdio.h>
void search(int a[], int l, int r,int x, int(*ptr)(int ,int));
int comp(int ,int);
int main(){
    int k;
    int a[k];
    scanf("%d\n", &k);
    for(int i=0; i<k; i++){
        scanf("%d\n", &a[i]);
    }
    int x;
    scanf("%d\n",&x);
    search(a,0,k,x,comp);

}
int comp(int a, int b){
    return a==b;
}
void search(int a[], int l, int r, int x,int(*p)(int ,int))
{
    int mid = (l+r)/2;
    if(l>r){
        printf("NOT FOUND\n");
    }
    else{
        if(p(a[mid],x)){
            printf("FOUND\n%d",mid+1);
        }
        else if(x>a[mid]){
            return search(a,mid+1,r,x,p);
        }
        else if(x<a[mid]){
            return search(a,l,mid-1,x,p);
        }
        else{
            printf("NOT FOUND\n");
        }

    }
}