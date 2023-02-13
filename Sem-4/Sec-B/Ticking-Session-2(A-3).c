/*

Problem solving 3

You have a grid of pixels S of size m x n. Each pixel has a brightness value corresponding to it. You can perform an operation where you remove the brightest pixel from each row, if there are multiples of such pixels, remove all of them. Add the minimum of these deleted pixels to your final answer.

Input Format

2 3			// m and n
1 2 4		// grid S
3 3 1 

Output Format

6 

Testcase 1
Input

2 3
1 1 2
1 0 0 
Output

1
*/

//Solution 
// only 3/4 TC'S passed 
#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n;
    int final_ans;
  
    scanf("%d %d",&m,&n);
      int min_arr[m]; 
    int count_arr[m];
    for(int i=0;i<m;i++){
        int a[n];
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        int size=n;
        int min;
        //Sort the array 
        for(int i=0;i<=size-2;i++){  
        // i 0 to n-1, j i+1 to n-2
        min=i;
        for(int j=i+1;j<=size-1;j++){
            if(a[j]<a[min]){
                min=j;
                //swap a[i],a[min]
                int temp_v=a[i];
                a[i]=a[min];
                a[min]=temp_v;
            }
        }
        }
        // Largest value is a[n-1];
        int ogv=a[n-1];
        int largv=a[n-1];
        //Finding if it is repeated
        int count=0;
        for(int ic=0;ic<n;ic++){
            if(a[ic]==largv)
              count++;
        }
        
        largv=largv*count;
        min_arr[i]=ogv;
        count_arr[i]=largv;
        }
        int sval,position;
         sval=min_arr[0];
        position = 0;
	    for(int ip = 0; ip <m; ip++) {
	   
		if(sval > min_arr[ip]) {
			sval = min_arr[ip];
			position = ip;
		}
	}
	//printf("position is %d\n",position);
	//printf("%d\n",count_arr[1]);
	printf("%d",count_arr[position]);

        

       
       
}


