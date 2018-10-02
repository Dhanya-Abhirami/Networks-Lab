#include <stdio.h>
#include <math.h>
int main()
{
	printf("==========ISP SUBNET ALLOCATION==========\n");
	printf("\t\t\t\t\tS. DHANYA ABHIRAMI\n");
	printf("\t\t\t\t\t16BCE0965\n");
	int i,subnets;
	int ip1,ip2,ip3,ip4;
	// Network Address
	printf("Enter network address in dotted decimal: ");
	scanf("%d",&ip1);
	scanf("%d",&ip2);
	scanf("%d",&ip3);
	scanf("%d",&ip4);
	// Number of subnets
	printf("Enter number of subnets: ");
	scanf("%d",&subnets);
	int extra_ones = (int)(log(subnets)/log(2));
	int no_of_ones;	// Number of ones in default mask
	char class;
	if(ip1<=170)
	{class='A';
	no_of_ones = 8;
	}
	else if(ip1<=190)
	{class='B';
	no_of_ones = 16;
	}
	else
	{class='C';
	no_of_ones = 24;
	}
	// Subnet Mask
	char default_mask[32],subnet_mask[32];
	int j=0;
	for(i=0;i<32;i++)
	{
		if (i<no_of_ones)
		{subnet_mask[i] = '1';
		default_mask[i]='1';}
		else if (j<extra_ones)
		{
			default_mask[i]='0';
		subnet_mask[i] = '1';
		j+=1;
		}
		else
		{default_mask[i]='0';
		subnet_mask[i]='0';}
	}
	printf("Default Mask: ");
	for(i=0;i<32;i++)
	{
		printf("%c",default_mask[i]);
		if(i%8==7)
			printf(" ");
	}
	printf("\nSubnet Mask: ");
	for(i=0;i<32;i++)
	{
		printf("%c",subnet_mask[i]);
		if(i%8==7)
			printf(" ");
	}
	// Addressess per subnet
	int addresses_per_subnet = pow(2,32 - (no_of_ones + extra_ones));
	printf("\nNumber of address per subnet: %d",addresses_per_subnet);
	// Range of addressess
	printf("\nRange of Addressess\n");
	while(subnets>0)
	{
		subnets-=1;
		printf("%d %d %d %d --->",ip1,ip2,ip3,ip4);
		ip4+=addresses_per_subnet-1;
		printf("%d %d %d %d \n",ip1,ip2,ip3,ip4);
	    ip4+=1;
	    if (ip4==256)
		{
			ip4=0;
			ip3+=1;
			if(ip3==256)
				{
					ip3=0;
					ip2+=1;
					if(ip2==256)
					{
						ip2=0;
						ip1+=1;
					}
				}
		}
	}
	return 0;
}