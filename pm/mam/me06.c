/*14MCME06*/
#include<stdio.h>
int main()
{
	int mode = 0 ,mode_freq ,prev,curr,curr_freq ;

	/*where mode = mode of entire data
	* mode_freq = it isno of times the mode value is repeating
	* prev = it is the previous term of the data 
	* curr = it is the current value of the data which is stored
	* curr_freq = it is the current frequency of the data which is 
	*differ from modal frequency*/ 

	printf(" Enter the initial term  = ") ;
	scanf("%d",&curr ) ;
	
	if (curr == -1)
	{
		printf("%d",mode);
		return(0);

	}
    
        curr_freq = 1 ;
        prev = curr ;
        mode_freq =1 ;

	while (curr != -1)
	{
		printf(" Enter the next number =") ;
                scanf("%d",&curr ) ;

		if (prev == curr )
		{
			curr_freq++ ;
			mode = curr ;	
			mode_freq = curr_freq ;
		}
		else
		{	
		
			if (curr_freq>=mode_freq)
			{
				mode = prev ;
				mode_freq = curr_freq ;
				
			}
			
			 
			curr_freq= 1 ;
			prev = curr ;
			
		}
			
	}
			
		
	
	printf("mode=%d\n",mode) ;
	printf("mode_frequency=%d\n", mode_freq) ;
	return(0);
}
		