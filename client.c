#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX 100

int main()
{

  char ipr[100];
  // long long a,b,c,d,rem,
  long long arr[5], ans[5];
  long long i;
  printf("Please Enter IP address\n");
  gets(ipr);
  sscanf(ipr,"%lld.%lld.%lld.%lld/%lld",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);

  int res = open("myfifo",O_WRONLY);
  write(res,arr,sizeof(long long)*5);

  int res1 = open("myfifo1",O_RDONLY);
  read(res1,ans,sizeof(long long)*5);

  printf("First Address is: %lld.%lld.%lld.%lld",ans[0],ans[1],ans[2],ans[3]);

  return 0;
}
