#include <stdio.h>
#include<string.h>
int main() 
{
	int sc_ch, first_ch, i,j,str1=0,str2=0;
	char clock_ch1[50], illumination_level1[5], illumination_level2[5], clock_ch2[50],time_on1[20],time_off1[20],time_on2[20],time_off2[20],output[5],an_choice;
	printf("Enter the choices:\n");
	printf("1. Manual Control\n 2.Ambient Control \n 3.Clock");
	scanf("%d",&first_ch);

	switch(first_ch)
	{
		
		case 1: printf("\n Enter 1 for ON and 0 for off");
				scanf("%d", &sc_ch);
				if(sc_ch==0)
					strcpy(output,"OFF");
				else if(sc_ch==1)
					strcpy(output,"ON");
				else
					printf("You entered wrong choice. Please try again");
				break;
		case 2:
		
			break;
		case 3: printf("Please enter the string in the form Timeon,timeoff,illumination_level=9.00pm,10.00pm,50\n");
				scanf("%s",&clock_ch1);
				for(i=0;clock_ch1[i]!='\0';i++)
				{
					printf("%c\n",clock_ch1[i]);
					if(clock_ch1[i]==',')
					{
					    str1=str1+1;
					}
				}
				if(str1==2)
				{
					for(i=0;clock_ch1[i]==',';i++)
					{
						time_on1[i]=clock_ch1[i];
					}
					for(i,j=0;clock_ch1[i]==',';i++,j++)
					{
						time_off1[j]=clock_ch1[i];
					}
			        for(i,j=0;clock_ch1[i]!='\0';i++,j++)
			        {
			            illumination_level1[j]=clock_ch1[i];
			        }
			        printf("\non time: %s,\noff time %s, \n illumination_level%s",time_on1,time_off1,illumination_level1);
					printf("Do you want to schedule another time? Press Y or N");
					scanf("%c",&an_choice);
					if(an_choice=="Y"||an_choice=="y")
					{
						printf("Please enter the string in the form Timeon,timeoff,illumination_level=9.00pm,10.00pm,50");
						scanf("%s",clock_ch2);
						for(i=0;clock_ch2[i]!='\0';i++)
						{
							if(clock_ch2[i]==',')
							str2++;
						}
						if(str2==2)
						{
							for(i=0;clock_ch1[i]==',';i++)
							{
								time_on2[i]=clock_ch2[i];
							}
							for(i,j=0;clock_ch2[i]==',';i++,j++)
							{
								time_off2[j]=clock_ch2[i];
							}
							for(i,j=0;clock_ch1[i]!='\0';i++,j++)
			                {
			                    illumination_level2[j]=clock_ch1[i];
			                }
						    printf("\non time: %s,\noff time %s, \n illumination_level%s",time_on2,time_off2,illumination_level2);
						    
						}
					    else
							printf("Wrong schedule. Please try both schedule again");
					}
				}
				else
					printf("Wrong schedule. Please try again");
				
			break;
	}
	printf("\n Thank you for your time");
	printf("\n%s",output);
	return 0;
}