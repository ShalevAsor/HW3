#include <stdio.h>

//#include <string.h>
#define LINE 256
#define WORD 30
int visit=0;
int isVisited=0;
int counter=0;
int LINEINDEX=0;
int theWordIsDone=0;
int LineIsDone=0;
int temp=1,temp2=0;
int word_index=0;
int level=0;


/**
This method return the line length 
from the input.
**/
int getLine(char s[]){
char input;
int counter=0;
while((input=getchar())!='\n'&&input!=EOF){

 *(s+counter)=input;   
counter++;}
if(input==EOF){
    return -1;
}
return counter;

}
void getLineByString(char *c,char s){
  //printf("%c",s);

//if(s!= '\n'){
    if(temp!=0){
  printf("%c",s);
 *(c+LINEINDEX)=s;
    LINEINDEX++;
}
else{
     printf("%c",s);
LineIsDone=1;
temp=1;

}
     

    


}
/**
This method return the number of letters in the word 
and insert each char to the given array.
**/
int getWord(char w[]){
int counter=0;
char input;
while((input=getchar())!='\n'&&input!=EOF){
if(input=='\t'||input==' '){
    break;
}
else{
    *(w+counter)=input;
    counter++;
}
}
    return counter;
}
/**
This method works like getWord but the difference is this method get a String
**/
void getWordByString(char w[],char s,int* done){

   if(s!='\n'&&s!='\t'&&s!=' '){
    *(w+counter)=s;
    counter++;
}
else{
    //theWordIsDone=1;
    *done=1;
}
}
/**
This method return 1 if str2 is a substring of str1 
else return 0
**/
// int substring(char* str1,char* str2){
// int ans=0,sumofsizes=0,length=0;
// int i=0,sizestr1=0,sizestr2=0;
// while(*(str1+i)){//get the size of each String
//     sizestr1++;
//     i++;
// }
// i=0;
// while(*(str2+i)){
// sizestr2++;
// i++;
// }
// sumofsizes=sizestr1-sizestr2;// if the substring size is bigger then the string the answer is 0 (false)
// if(sumofsizes<0){
//    return 0; 
// }

// for(i=0;i<sumofsizes;i++){
// for(int j=0;j<sizestr2;j++){
//     if(*(str1+j+i)==*(str2+j)){
//         length++;//if the length size will be equal to the str2 size than the ans should be true
//     }
//     else{
//         length=0;//get out from the second for loop and init the length to zero
//         break;
//     }
// }
// }
// if(sizestr2==length){
//     ans=1;
// }

// return ans;
// }
/**
This method return 1 if Str1 is equals to Str2
else return 0
**/
int strEquals(char *str1,char *str2){
int i=0,ans=0;
while(*(str1+i)){
if(*(str1+i)==*(str2+i)){
    ans=1;
}
else{
    return 0;
}
i++;
}
return ans;    
}
/**
This method return 1 if the String s is similar to the String t by the given n 
**/
// int similar(char* t,char* s,int n){
// int counter=n,tSize=0,ans=0,sIndex=0;
// int x=0;
// // while(t[x]){
// //     printf("%c",t[x]);
// //     x++;
// // }
// if(n==0&&strEquals(t,s)==1){
//     return 1;
// } 
// while(*(t+tSize)!='\0'){
// tSize++;
// }
// for(int i=0;i<tSize;i++){
// if(*(s+sIndex)!=*(t+i)){
// counter--;
// i--;
// }
// if(counter<0){
//     return 0;
// }
// else{
//     ans=1;
// }
// sIndex++;
// }
// return ans;
// }
/**
This method print the given array
**/
void print_arr(char arr[],int length){
    int i=0;
   // while(*(arr+i)!='\n'){
        while(i<length){
        printf("%c",*(arr+i));
        i++;
    }
   
}
//----subsring second version--------------------------

int substring(char* str1,char* str2){
int ans=0,sumofsizes=0,length=0;
int i=0,sizestr1=0,sizestr2=0;
while(i<LINEINDEX){//get the size of each String

    sizestr1++;
    i++;
}
i=0;
while(i<counter){
sizestr2++;
i++;
}
i=0;
sumofsizes=sizestr1-sizestr2;// if the substring size is bigger then the string the answer is 0 (false)
if(sumofsizes<0){
   return 0; 
}

for(i=0;i<sumofsizes;i++){
for(int j=0;j<sizestr2;j++){
    if(*(str1+j+i)==*(str2+j)){
        //printf("[%d]",sizestr1);
       // printf("[%d]",length);
       // printf("%c",*(str1+j+i));
        length++;//if the length size will be equal to the str2 size than the ans should be true
        if(sizestr2==length){
    
    return 1;
}
    }
    else{
        length=0;//get out from the second for loop and init the length to zero
        break;
    }
}
}
//printf("[%d]",length);
if(sizestr2==length){
    
    ans=1;
}

return ans;
}
/**
This method print all the line in the text that the given word appears
**/
// void print_lines(char* str){
// char word[WORD];
// getWordByString(word,str);
// char line[LINE];
// //getWord(word);
// while((getLine(line))!=-1){
// if(substring(line,word)==1){
//     print_arr(line);
// }
// }
// }
//----------------
// void print_lines(char* str){
// char word[WORD];
// getWordByString(word,str);
// char line[LINE];
// //getWord(word);
// while((getLine(line))!=-1){
// if(substring(line,word)==1){
//     print_arr(line);
// }
// }
// }
//----------------
int inputIslegal(char c){
   // if(c!='(space)'&&c!='(newline)'&&c!='(space)'){
        if(c!=' '&&c!='\n'&&c!='\t'&&c!='\r'){
        return 1;
    }//}
    else{
        return 0;
    }
}


void init_line(char c[],int length){
int i=0;
while(i<length){
    *(c+i)=0;
    i++;
}


}

void getWordByStrings(char w[],char s,int* done){
   if(s!='\n'&&s!='\t'&&s!=' '){
    //   printf("%c",s);
    *(w+counter)=s;
    counter++;
}
else{
  //  printf("%c",s);
    //theWordIsDone=1;
    *done=1;
}
}
//-------------second-------------------//
int similar(char* t,char* s,int n){
int count=n,tSize=0,ans=0,sIndex=0;
int x=0;

// while(sIndex<word_index){
//     printf("%c",*(t+sIndex));
//     sIndex++;
// }
// printf("\n");
// sIndex=0;
if(n==0&&strEquals(t,s)==1){

    return 1;
} 
if(counter>word_index){
    return 0;
}
for(int i=0;x<word_index;i++){
if(*(t+x)!=*(s+i)){
count--;
i--;
}
if(count<0){
    return 0;
}
else{ 
  //  printf("visit");
    ans= 1;
}
x++;
}
return ans;
}

int main(){
    /**
//getLineTest------------------//
char s[LINE];
int i=0;
int sum=getLine(s);
printf("the sum is :%d \n",sum);
printf("the array elements are:\n");
while(i<sum){
printf("%c,", s[i]);
    i++;
}
//getWordTest--------------//
char w[WORD];
i=0,sum=getWord(w);
printf("the sum of the Word is:%d\n",sum);
printf("the array elements are:\n");
while(i<sum){
    printf("%c,", w[i]);
    i++;
}
//substringTest---------------------//
char b[]={'s','h','a','\0'};
char a[]={'n','a','s','h','a','l','\0'};
printf("the results are :%d\n",substring(a,b));
//strEqualsTest--------------------------//
char c[]={'a','b','c','\0'};
char d[]={'a','b','c','\0'};
printf("str c is equals to d (1)? %d",strEquals(c,d));
printf("str c is equals to d (1)? %d",strEquals(d,c));
char e[]={'a','b','c','e','\0'};
printf("str c is equals to d (0)? %d",strEquals(e,d));
//similarTest------------------------------//
char g[]={'a','b','c','\0'};
char f[]={'a','b','b','c','\0'};
printf("str f is similar to g (1)?%d\n",similar(g,f,1));
printf("str g is similar to f (0)?%d\n",similar(f,g,1));
char x[]={'a','b','c','\0'};
char y[]={'a','b','b','e','c','\0'};
printf("str y is similar to x (1)?%d\n",similar(x,y,2));
**/
// //print_linesTest------------------------------------//
// char input;
// int a=0,b=0;
// char word[WORD];
// char line[LINE];
// int i=0,index=0,isVisited=0,wordisvisited=0,lineVisited=1;
// while((input=(getchar()!=EOF))){
//    printf("%c",input);
//     //while(scanf("%c", &input)==1&&input!=EOF){
// //if(input!='\0'&&input!=' '&&input!='\t'&&wordisvisited==0){
// if((inputIslegal(input)==1)&&wordisvisited==0){
// *(word+i)=input;
// printf("%c",input);
// printf("%c",word[i]);
// i++;
// //continue;
// }
// else{
// wordisvisited=1;}
// i=0;
// // while(word[i]){
// //     printf("%c",word[i]);
// //     i++;
// // }

// if(input=='a'&&wordisvisited==1){//a
// isVisited=1;
// a=1;
// }
// if(input=='b'&&wordisvisited==1){//b
// isVisited=1;
//     b=1;
// }
// if(a){
// if(input!='\n'&&input!=EOF&&wordisvisited==1&&lineVisited!=2){
//     *(line+index)=input;
//     printf("%c",line[index]);
//     index++;
//     continue;
// }
// else{
//     lineVisited=2;
// }
// //lineVisited=2;
// if(substring(line,word)==1&&lineVisited==2){
//     index=0;
//     //printf("visit");
//     //print_arr(line);
//     while(*(line+index)!='\n'&&*(line+index)!=EOF){
//         printf("%c",line[index]);
//         index++;
//     }
//     lineVisited=1;
// }
// else{
//     lineVisited=1;
// }
// }


// //-----------

// return 0;
// }
//print_linesTest------------------------------------//-------------------------------------------
// char input;
// int a=0,b=0;
// char word[WORD];
// char line[LINE];
// int i=0,index=0;
// int lineVisited=1;
// while(scanf("%c", &input)==1&&input!=EOF){
// if(inputIslegal(input)==1&&visit==0){
// *(word+i)=input;
// i++;
// }
// else{
// //wordisvisited=1;
// visit=1;
// }

// if(input=='a'&&visit==1&&isVisited==0){//a
// //printf("visit");
// isVisited=1;
// a=1;
// }
// if(input=='b'&&visit==1&&isVisited==0){//b
// isVisited=1;
// b=1;
// }
// if(a){
// if(input!='\n'){
//     *(line+index)=input;
//     index++;
//     continue;
// }
// // else{
// //     lineVisited=1;
// // }20
// if((substring(line,word))==1){
//     index=0;
//     print_arr(line);
//     // while(*(line+index)!='\n'){
//     //     printf("%c",*(line+index));
//     //     index++;
//     // }
//    // lineVisited=0;
// }
// // else{
// //     lineVisited=0;
// // }
// }
// if(b){

// }
// }
// //-----------
char input;
char word[WORD];
char line[LINE];
char word_for_b[WORD];
int b_done=0;
int a=0,b=0,isVisited=0;
int e=0;
int i=0;
int z=0;
int indexer=0;
while(scanf("%c", &input)!=EOF){
 //while((input=getchar())!=EOF){   



if(theWordIsDone==0){
getWordByString(word,input,&theWordIsDone);}


if(input=='a'&&theWordIsDone==1&&isVisited==0){//a case
a=1;
isVisited=1;//mark the case as visited
continue;

}
if(input=='b'&&theWordIsDone==1&&isVisited==0){//b case

b=1;
isVisited=1;//mark the case as visited
continue;
}

if(a==1&&isVisited&&theWordIsDone==1){
    
    if(LineIsDone==0){
     if(input!='\n'){
         *(line+LINEINDEX)=input;
         LINEINDEX++;
     }   
     else{
         if(LINEINDEX!=0){
         *(line+LINEINDEX)=input;
         LINEINDEX++;
         LineIsDone=1;}

     }
    }
    if(LineIsDone==1){
        

     
        if(substring(line,word)==1){
        // printf("visit");
          print_arr(line,LINEINDEX);
        }
     // init_line(line,LINEINDEX);
        LINEINDEX=0;
        LineIsDone=0;
    }

}

if(b==1&&theWordIsDone==1){
      
//getWordByString(word_for_b,input,&b_done);

// if(b_done==0){
//        if(input=='\n'){
//     continue;
// }
if(input!='\t'&&input!=' '&&input!='\r'&&input!='\n'&&b_done==0){
    
   //printf("%c",input);
    *(word_for_b+word_index)=input;
    word_index++;
    // if(input=='\n'){
    //     word_index--;
    // }
 
  //printf("[%d]",word_index);
   continue;
}
else{
    
    if(word_index!=0){
  //printf("[%d]",word_index);
  //printf("\n");
    b_done=1;
    }
    
}




// if(b_done==1&&word_index!=0){
//     while(indexer<word_index){
//        printf("%c",word_for_b[indexer]);
//         indexer++;
//     }
//     indexer=0;
//     printf("[%d]",word_index);
//      printf("\n");
// }


if(b_done==1&&word_index!=0){

  if(similar(word_for_b,word,1)==1){
  //printf("visit,");
    while(indexer<word_index){
     printf("%c",word_for_b[indexer]);
        indexer++;
    }
   printf("\n");
   indexer=0;
   word_index=0;
   b_done=0;
   

  }

else{
    word_index=0;
    b_done=0;
}

}

}
}

return 0;
}