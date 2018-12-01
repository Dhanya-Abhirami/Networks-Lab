#include <stdio.h>
#include <math.h>
int ham_calc(int position,int n,int hamming_encoded[])
{
	int count=0,i,j;
	i=position-1;
	while(i<n)
	{
		for(j=i;j<i+position;j++)
		{
			if(hamming_encoded[j] == 1)
				count++;
		}
		i=i+2*position;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}
int main()
{
	printf("==========HAMMING CODE==========");
	printf("\n\t\t\tS. DHANYA ABHIRAMI\n\n");
	printf("\n\nSENDER SIDE\n");
	int m,i,r = 0,n,j,k;
	printf("Enter message length: ");
	scanf("%d",&m);
	int message[m];
	printf("Enter message: ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&message[m-i-1]);
	}

	i=0;
	while(m>(int)pow(2,i)-(i+1))
	{
		r++;
		i++;
	}
	printf("Number of Redundancy bits :%d\n",r );
	n = r + m;
	int hamming_encoded[n];
	j=k=0;
	for(i=0;i<n;i++)
	{
		
		if(i==((int)pow(2,k)-1))
		{
			hamming_encoded[i]=0;
			k++;
		}
		else
		{
			hamming_encoded[i]=message[j];
			j++;
		}
	}
	printf("Redundancy bits\n");
	for(i=0;i<r;i++)
	{
		int position = (int)pow(2,i);
		int value = ham_calc(position,n,hamming_encoded);
		printf("r%d :%d\n",position,value );
		hamming_encoded[position-1]=value;
	}
	printf("Hamming Encoded Word : ");
	for(i=0;i<n;i++)
		printf("%d ",hamming_encoded[i]);
	printf("\n\nRECEIVER SIDE\n");
	printf("Enter Received Hamming Encoded Word: ");
	int received[n];
	for(i=0;i<n;i++)
		scanf("%d",&received[n-i-1]);

	int error_pos = 0;
	printf("Syndrome bits\n");
	for(i=0;i<r;i++)
	{
		int position = (int)pow(2,i);
		int value = ham_calc(position,n,received);
		printf("s%d :%d\n",position,value );
		if(value != 0)
			error_pos+=position;
	}
	if(error_pos == 0)
		printf("Message is correct\n");
	else
		{
			printf("Error detected at bit position: %d\n",error_pos);
			printf("Corrected Word: \n");
			for(i=0;i<n;i++)
			{
				if(n-i==error_pos)
					printf("%d ",received[n-i-1]^1 );
				else
				printf("%d ",received[n-i-1] ); 
			}
		}
		printf("\n");
	return 0;
}
