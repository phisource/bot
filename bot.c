#include <stdio.h>
#include<string.h>
int main() 
{
	int first_ch, sc_ch, i,j,str1=0,str2=0;
	char clock_ch1[50], ch_3,illumination_level1[5], illumination_level2[5], clock_ch2[50],time_on1[20],time_off1[20],time_on2[20],time_off2[20],output[5]="OFF",an_choice,string[45];
float timeon,timeoff,illumination,timeon2,timeoff2,illumination2;	
printf("Enter the choices:\n");
	printf("1. Manual Control\n 2.Ambient Control \n 3.Clock\n");
	scanf("%d",&first_ch);
	switch(first_ch)
	{
		
		case 1: printf("\n Enter 1 for ON and 0 ,for off");
				scanf("%d", &sc_ch);
				if(sc_ch==0)
					strcpy(output,"OFF");
				else if(sc_ch==1)
					strcpy(output,"ON");
				else
					printf("You entered wrong choice. Please try again");
		
		printf("\n Output of LED is: %s ",output);
		break;
		
		case 2:
		
			break;
		case 3: printf("Please enter the string in the form Timeon,timeoff,illumination_level (time format will be 24 hours)=9.00,23.00,50\n");
				scanf("%s", clock_ch1);
				for(i=0;clock_ch1[i]!='\0';i++)
				{
					//printf("%c\n",clock_ch1[i]);
					if(clock_ch1[i]==',')
					{
					    str1=str1+1;
					}
				}

				if(str1==2)
				{
					
					for(i=0;clock_ch1[i]!=',';i++)
					{
						time_on1[i]=clock_ch1[i];
					}
					time_on1[i]='\0';
					timeon=atoi(time_on1);

					printf("\n ON time: %s", time_on1);
					
					for(i=i+1,j=0;clock_ch1[i]!=',';i++,j++)
					{
						time_off1[j]=clock_ch1[i];
					}
					time_off1[j]='\0';
					timeoff=atoi(time_off1);       	
					for(i=i+1,j=0;clock_ch1[i]!='\0';i++,j++)
			        	{
			            	illumination_level1[j]=clock_ch1[i];
			        	}
					illumination_level1[j]='\0';
					printf("\n Illumination Level: %s", illumination_level1);
					printf("\non time: %s, off time %s, illumination_level %s",time_on1,time_off1,illumination_level1);
					if(timeon>timeoff)
					{
						printf("\nAre you sure you entered the right time? It is coming more than 12 hours and power will be wasted. Please check.");
					}
					
						//if(sc_ch!='y'||sc_ch!='Y')
				}	
				else
					printf("Wrong schedule. Please try again with the correct format.");
		break;
		default:
			printf("wrong choice. Please select between 1-3");
	}
	

	printf("\n Thank you for your time. Your response is recorded.\n");
	
	return 0;
}
