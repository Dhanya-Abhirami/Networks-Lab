#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX_DELAY 5
void main()
{
	printf("==========STOP AND WAIT ARQ ==========");
	printf("\n\t\t\tS. DHANYA ABHIRAMI\n\t\t\t16BCE0965\n");
	int seed = time(NULL);
	srand(seed);
	int i=0,window_size,noframes,frame_no,ack_no,frame_delay,ack_delay,timer,time_left;
	printf("Enter number of frames: ");
	scanf("%d",&noframes);
	int seq_no[noframes],receiver_buffer[noframes];
	printf("Enter timer duration: ");
	scanf("%d",&timer);
	printf("SENDER\t\t\tDELAY\t\t\tCASE\t\t\tRECEIVER\n");
	//Sequence Number allocation
	for(i=0;i<noframes;i++)
	{
		seq_no[i]=i%2;
		receiver_buffer[i]=i%2;
	}
	//Window Size Allocation
	window_size=1;
	i=0;
	while(1)
	{
		frame_no = seq_no[i];
		if (i<noframes-1)
		ack_no = receiver_buffer[i+1];
		else
		ack_no = (receiver_buffer[i]+1)%2;
		printf("\nSending Frame %d",frame_no);
		frame_delay = rand()% (MAX_DELAY+1);
		printf("\t\tFrame Delay %d",frame_delay);
		fflush(stdout);
		sleep(frame_delay);
		if(frame_delay>timer && frame_delay<=MAX_DELAY)
		{
			printf("\t\tFrame Lost");
			continue;
		}
		printf("\t\tNormal");
		printf("\t\tSending Ack %d",ack_no);
		ack_delay = rand()% (MAX_DELAY+1);
		printf("\n\t\t\tAck Delay %d",ack_delay);
		fflush(stdout);
		sleep(ack_delay);
		if(ack_delay>timer && ack_delay<=MAX_DELAY)
		{
			printf("\t\tAck Lost");
			continue;
		}
		else if(frame_delay+ack_delay>timer)
		{
			printf("\t\tDelayed Ack");
			continue;
		}
		printf("\t\tNormal");
		printf("\nReceived Ack %d\n",ack_no);
		i+=window_size;
		printf("-------------------\n");
		if(i==noframes)
		break;
	}
	printf("\nFrames sent\n");
}