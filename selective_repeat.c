#include<stdio.h>
#include<math.h>
int main()
{
	printf("==========SELECTIVE REPEAT ARQ ==========");
	printf("\n\t\t\tS. DHANYA ABHIRAMI\n\n");
	int noframes,windowsize,sent=0,nak,m,i,j=0;
	printf("Enter number of frames: ");
	scanf("%d",&noframes);
	printf("Enter m: ");
	scanf("%d",&m);
	//Window Size
	windowsize=(int)pow(2,m-1);
	printf("Window Size: %d\n",windowsize);
	int seq_no[noframes];
	//Sequence Number allocation
	for(i=0;i<noframes;i++)
	{
		seq_no[i]=i%(int)pow(2,m);
	}
	int ch;
	while(1)
	{
		for( i = 0; i < windowsize; i++)
			{			
				printf("Sending Frame: %d Sequence Number: %d\n",sent,seq_no[sent]);
				sent++;
				if(sent==noframes)
					break;
			}
			ch=1;
			while(ch==1)
			{
			printf("Error occured? 1/0: ");
			scanf("%d",&ch);
			if (ch==0)
				break;
			printf("Enter nak received: ");
			scanf("%d",&nak);
			printf("Sending Frame: %d Sequence Number: %d\n",nak,seq_no[nak]);
			}
			if(sent==noframes)
				break;
	}
	printf("Frames sent\n");
return 0;
}
