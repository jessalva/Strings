#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//printing possible permutations using backtracking
void permute(char* a,int l,int r)
{
  if(l==r)
  {
    printf("%s",a);//print the string is n-1 character have been locked
    return;
  }
  for(int i=l;i<=r;i++)
  {
    swap(&a[l],&a[i]);//swap with another character if ABC swap B in place of A
    permute(a,l+1,r);//lock ith character and recursively call permute
    swap(&a[l],&a[i]);//swap back the change made
    printf("\n");
  }
}

//swapping character using call by reference
void swap(char* a,char* b)
{
  char temp=*b;
  *b=*a;
  *a=temp;
}


int main()
{
  char str[10];
  printf("Enter String:");
  scanf("%s",str);
  int len=strlen(str);
  printf("=======================\nPossible Permutations\n");
  permute(str,0,len-1);
}
