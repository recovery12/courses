/*14MCME10*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,current_num=n,prev_num=n,current_freq=1,mode_freq=1,mode=n;

	printf("enter the first term:");
	scanf("%d",&n);
	if (n==-1)
    {
		return 0;
	}
	
	while(current_num!=-1)
	{
		printf("enter the next term:");
		scanf("%d",&current_num);

		if(current_num==prev_num)
		{
			current_freq=current_freq+1;
		}
		else
		{
			if(current_freq>=mode_freq)
			{
				mode_freq = current_freq;				
				mode=prev_num;		
			}
			current_freq=1;
			prev_num = current_num;
		}
	}	
	printf("The mode is %d\n",mode);
	printf("And it has occurred %d times\n",mode_freq);
	return 0;
} 
	    