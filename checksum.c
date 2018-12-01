#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* complement(char *sum){
	int i;
	char *complement = (char *)malloc(sizeof(char)*(strlen(sum)));
	for (i = 0; i < strlen(sum); ++i)
	{
		if(sum[i]=='0')
			complement[i]='1';
		else
			complement[i]='0';
	}
	return (complement);
}

char* add(char *a, char *b)
{
	int i;
	char *sum = (char *)malloc(sizeof(a));
	for(i=0;i<strlen(a);i++)
	sum[i]='0';
	char carry='0';
	for (i = strlen(a)-1; i >=0; i--)
	{
		if(a[i]=='0' && (b[i]=='0' && carry=='0'))
        {
            sum[i]='0';
            carry='0';
        }
        else if(a[i]=='0' && b[i]=='0' && carry=='1')
        {
            sum[i]='1';
            carry='0';
        }
        else if(a[i]=='0' && b[i]=='1' && carry=='0')
        {
            sum[i]='1';
            carry='0';
        }
        else if(a[i]=='0' && b[i]=='1' && carry=='1')
        {
            sum[i]='0';
            carry='1';
        }
        else if(a[i]=='1' && b[i]=='0' && carry=='0')
        {
            sum[i]='1';
            carry='0';
        }
        else if(a[i]=='1' && b[i]=='0' && carry=='1')
        {
            sum[i]='0';
            carry='1';
        }
        else if(a[i]=='1' && b[i]=='1' && carry=='0')
        {
            sum[i]='0';
            carry='1';
        }
        else if(a[i]=='1' && b[i]=='1' && carry=='1')
        {
            sum[i]='1';
            carry='1';
        }
	}
	
	if(carry=='1')
		{
			char* one = (char *)malloc(sizeof(char)*(strlen(a)));
			for (i = 0; i < strlen(a)-1; ++i)
			{
				one[i]='0';
			}
			one[strlen(a)-1]='1';
			sum=add(sum,one);
		}
	return (sum);
}

char* append_bits(char *message,char *checksum){
	int i;
	int message_length = strlen(message);
	int checksum_length = strlen(checksum);
	char *result;
	result = (char *)malloc(sizeof(char)*(message_length+checksum_length));
	for(i=0;i<message_length;i++)
	result[i]=message[i];
	for(i=0;i<checksum_length;i++)
	result[message_length+i]=checksum[i];
	return(result);
}

int main(){
	printf("==========CHECKSUM==========");
	printf("\n\t\t\tS. DHANYA ABHIRAMI\n\n");
	int n,k,i,j;
	printf("Enter number of bits in message: ");
	scanf("%d",&n);
	printf("Enter number of sections: ");
	scanf("%d",&k);
	char message[n];
	printf("\nSENDER SIDE\n");
	printf("Enter the message: ");
	scanf("%s",message);
	char *sections[k];int p=n/k;
	for (i = 0; i < k; i++)
	{
		sections[i]=(char *)malloc(sizeof(char)*(n/k));
		for(j=0;j<n/k;j++)
			sections[i][j]=message[p*i+j];
	}
	char *sum= (char *)malloc(sizeof(char)*(n/k));
	sum=sections[0];	
	for (i=1;i<k;i++){
		sum=add(sum,sections[i]);
	}
	printf("Sum: %s\n",sum);
	char *checksum= (char *)malloc(sizeof(char)*(n/k));
	checksum=complement(sum);
	printf("Checksum: %s\n", checksum );
	char *sent_message= (char *)malloc(sizeof(char)*(n+n/k));
	sent_message = append_bits(message,checksum);
	printf("Message sent as :");
	for(i=0;i<n+n/k;i++)
		printf("%c",sent_message[i]);
	printf("\n\nRECEIVER SIDE\n");
	char received_message[n+n/k];
	printf("Enter received message: ");
    scanf("%s",received_message);
    char *received_sections[k+1];
    p=n/k;
    for (i = 0; i < k+1; i++)
	{
		received_sections[i]=(char *)malloc(sizeof(char)*(n/k));
		for(j=0;j<(n/k);j++)
			received_sections[i][j]=received_message[p*i+j];
	}
	sum=received_sections[0];	
	for (i=1;i<k+1;i++){
		sum=add(sum,received_sections[i]);
	}
	printf("Sum: %s\n",sum);
	checksum=complement(sum);
	printf("Checksum: %s\n", checksum );
	int flag=0;
	for (i = 0; i < strlen(checksum); ++i)
	{
		if(checksum[i]!='0'){
			flag=1;break;
		}
	}
	if(flag==0)
		printf("Message is correct\n");
	else
		printf("Message is corrupted!\n");
	return (0);
}
