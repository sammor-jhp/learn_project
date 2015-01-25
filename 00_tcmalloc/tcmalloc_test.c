#include <stdio.h>
#include <memory.h>
#include <sys/time.h>
#include <stdlib.h>
void func()
{
   int lIndex = 0;
   char *pcMemTmp = NULL;
   for (lIndex = 0; lIndex < 1000000; lIndex++)
   { 
       pcMemTmp = (char *)malloc(1024);
       if (NULL == pcMemTmp)
       {
           printf("pcMemTmp is Null \r\n");
	   return ;
       }

       memset(pcMemTmp, 0x2, 1024);
   }
}

long showtime()
{
   struct timeval t_start; 
   gettimeofday(&t_start, NULL); 
  //printf("sec:%ld, usec:%ld\r\n", t_start.tv_sec, (long)t_start.tv_usec/1000);
   return ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000;; 
}

int main()
{
   long llBegin, llEnd;
   llBegin = showtime();
   func();
   llEnd = showtime();
   printf("used %ld ms\r\n", llEnd - llBegin);
}
