#include <stdio.h>
#define ARRAYSIZE 50

// Question 1
//A:

/**
This method transfer i elements from the given adress
 to the right spot in the array.
**/
void shift_element(int* arr,int i){
while(i>=0){
*(arr+i+1)=*(arr+i);//transfer the left element one step to the right
i--;
}
}

//B:
/**
This method sorts the given array from the min element 
to the max element.  
**/
void insertion_sort(int* arr,int len){
int j;

for(int i=1;i<len;i++){
    int temp=*(arr+i);
    j=i-1;
     while(j>=0&&*(arr+j)>temp){
         *(arr+j+1)=*(arr+j);
         j--;}
         *(arr+j+1)=temp;
        }

}
/**
allows to the user to set input from a file.txt into the program
the default size is 50 numbers. 
**/
int main(){
int input,index=0;
int arr[ARRAYSIZE];
while(scanf("%d", &input)!=EOF||index<ARRAYSIZE){//get all the input until the file is readed or there is already
//ARRAYSIZE elements
*(arr+index)=input;//init the array to the given inputs
index++;
}
insertion_sort(arr,ARRAYSIZE);//sort the array
index=0;
while(index<ARRAYSIZE){//print each element with ","
    printf("%d,",*(arr+index));
    index++;
}
    return 0;
}
