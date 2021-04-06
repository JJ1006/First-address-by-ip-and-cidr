#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#define MAX 100

void decimalToBinary(long long *a,long long num,int index)
{
    long long temp[100]={0},count=0;
    while(num>0)
    {
        temp[count]=num%2;
        num=num/2;
        //printf("%lld",temp[count]);
        count++;
    }
    for(;count<8;)
    {
        temp[count]=0;
                //printf("%lld",temp[count]);

        count++;
    }
    count--;
    for(int i=index,k=0;k<8;i++,k++)
    {
        a[i]=temp[count-k];
    }
}

long long Binarytodecimal(long long *a,long long s_index,int l_index)
{
    long long num=0,i,k;
     for(i=s_index,k=7;i<l_index;i++,k--)
     {
         num+=a[i]*(1<<k);
     }
     return num;
}


int main()
{
  long long arr[5];
  long long i;
  int res = mkfifo("myfifo",0766);
  int res1 = mkfifo("myfifo1",0766);
  res = open("myfifo",O_RDONLY);
  read(res,arr,sizeof(long long)*5);

  // ---------------------
  long long binary_array[32]={0};
  decimalToBinary(binary_array,arr[0],0);
  decimalToBinary(binary_array,arr[1],8);
  decimalToBinary(binary_array,arr[2],16);
  decimalToBinary(binary_array,arr[3],24);

  int del=32-arr[4],k;
  for(i=del,k=31;i>0;k--,i--)
  {
      binary_array[k]=0;
  }

  arr[0]=Binarytodecimal(binary_array,0,8);
  arr[1]=Binarytodecimal(binary_array,8,16);
  arr[2]=Binarytodecimal(binary_array,16,24);
  arr[3]=Binarytodecimal(binary_array,24,32);


  // ---------------------
  res1 = open("myfifo1",O_WRONLY);
  write(res1,arr,sizeof(long long)*5);


  return 0;
}
