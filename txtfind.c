#include <stdio.h>
#define LINE 256
#define WORD 30
int counter=0,word_index=0,LineIsDone=0;
int LINEINDEX=0,theWordIsDone=0;


/**
This method return the line length 
by the given line.
**/
int getLine(char s[]){
char input;
int index_of_line=0;
while((input=getchar())!='\n'&&input!=EOF){//as long as the line did not over
*(s+index_of_line)=input;//insert the chars to s   
index_of_line++;}
if(input==EOF){
    return -1;
}
return index_of_line;//return the number of chars in s
}


/**
 return the number of letters in the word 
and insert each char to the given array.
**/
int getWord(char w[]){
int index_of_word=0;
char input;
while((input=getchar())!='\n'&&input!=EOF){
if(input=='\t'||input==' '){
    break;
}
else{
    *(w+index_of_word)=input;
    index_of_word++;
}
}
    return index_of_word;
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
    *done=1;
}
}

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
print the given array
**/
void print_arr(char arr[],int length){
    int i=0;
        while(i<length){
        printf("%c",*(arr+i));
        i++;
    }
}
/**
return 1 if str2 is a substring of str1 
else return 0
**/
int substring(char* str1,char* str2){
int ans=0,sum_of_sizes=0,length=0;
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
sum_of_sizes=sizestr1-sizestr2;// if the substring size is bigger then the string the answer is 0 (false)
if(sum_of_sizes<0){
   return 0; 
}

for(i=0;i<sum_of_sizes;i++){
for(int j=0;j<sizestr2;j++){
    if(*(str1+j+i)==*(str2+j)){
       
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

if(sizestr2==length){
    
    ans=1;
}

return ans;
}

/**
This method return 1 if the String s is similar to the String t by the given n 
**/
int similar(char* t,char* s,int n){
int number_of_changes=n,ans=0,similar_word_index=0;

if(n==0&&strEquals(t,s)==1){
    return 1;
} 
if(counter>word_index){//counter=number of chars in t,word_index=number of chars in s
    return 0;
}
for(int i=0;similar_word_index<word_index;i++){
if(*(t+similar_word_index)!=*(s+i)){
number_of_changes--;
i--;
}
if(number_of_changes<0){//if number of changes <0 s and t are not similars 
    return 0;
}
else{ 
    ans= 1;
}
similar_word_index++;
}
return ans;
}

int main(){
char input;
char word[WORD];
char line[LINE];
char word_for_b[WORD];
int b_done=0;
int a=0,b=0,isVisited=0;
int indexer=0;
while(scanf("%c", &input)!=EOF){
if(theWordIsDone==0){//if the given word isnt done yet
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

if(a&&theWordIsDone==1){//a case 
    if(LineIsDone==0){
     if(input!='\n'){
         *(line+LINEINDEX)=input;//get the line into the array
         LINEINDEX++;
     }   
     else{
         if(LINEINDEX!=0){
         *(line+LINEINDEX)=input;
         LINEINDEX++;
         LineIsDone=1;}

     }
    }
    if(LineIsDone==1){//all the line in the array
        if(substring(line,word)==1){//and the word is substring of the line
          print_arr(line,LINEINDEX);//print the line
        }
        LINEINDEX=0;//equate to zero for the next line
        LineIsDone=0;
    }

}

if(b&&theWordIsDone==1){//b case
if(input!='\t'&&input!=' '&&input!='\r'&&input!='\n'&&b_done==0){
    
*(word_for_b+word_index)=input;//insert the input to the array of the word
word_index++;
continue;
}
else{
    
    if(word_index!=0){
    b_done=1;//the word is done and all the chars are iserted to the array
    }
    
}

if(b_done&&word_index!=0){//if the word is done 

  if(similar(word_for_b,word,1)==1){//and it similar to the given word with one change
    while(indexer<word_index){//print the word
     printf("%c",word_for_b[indexer]);
        indexer++;
    }
   printf("\n");
   indexer=0;//for the next word
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
