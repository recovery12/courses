

#include<stdio.h>
#include<stdlib.h>
int main()
{
        int mode=0, modefrequency=0;num, numfrequency=0, preveous, mode=0

 
        printf("Enter the first term:");
        scanf("%d", &num);
        preveous = num;
        if(num == -1)
              {  
                printf("Mode is:%d\n ", mode);
                return(0);
              }  
        while(num != -1)
                {
                if(num == preveous)
                        {

                        numfrequency++;
                        modefrequency = numfrequency;
                        }
                else
                        {
                        if(numfrequency >= modefrequency) 
                                {
                                mode = num;
                                modefrequency = numfrequency;
                                }
                        numfrequency = 1;
                        preveous = num;
                        }
 

                                                               
                printf("Enter next no:");
                scanf("%d",&num);
                }
                                                                
 printf("Mode for the given data is: %d\t Modefrequency is:%d\n", mode, modefrequency);
        return(0);
}

                                                              