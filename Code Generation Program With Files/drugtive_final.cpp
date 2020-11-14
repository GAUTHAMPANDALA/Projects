#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m=0;
FILE *p,*q;
int c1=0,p1=49;
char encryptioncode(char s[14],int k ,int k1)
{
	int i,n,c=1;
	n=strlen(s);
	for(i = 0;i<n; i++)
	{ 
	if(i!=0 && i%2==0 && i%3!=0)
	{
		s[i]=s[i]+k;
	}
	else if(i!=0 && i%2!=0 && i%3==0)
	{
		s[i]=s[i]+k1;
	}
	else
	{
		if(c%2==0)
		{
			s[i]=s[i]+k1;
			c++;
		}
		
		else
		{
			if(p1==39)
		   {
			p1=49;
		   }
			
			s[i]='a'-p1;
			p1--;
		}
	}
    
    }	    
   if(strlen(s)==14)
   {
   fprintf(p,"%d: unique code after Encrypted: %s\n",m,s);	 // printing the encrypted string s
   m++;
   }
}

int main()

{
	long long int n,k=33,k1=49;
    p = fopen("oneencrypted2.txt", "w");
    int code;
    printf("Enter the company code \n");
	scanf("%d",&code);	
	int batch;
	printf("Enter the batch number \n ");
	scanf("%d",&batch);
	printf("Enter the number of medicines per batch \n ");
	scanf("%lld",&n);
	int r=0;
	r=(batch*code)+batch+1;
	char s[14];		   													  // temporaray string to copy the compnay,batch number and medicene_id concated string.
	char s1[7];				         								     //Temporaray string for medicene_id to string conversion.
	char t[7]={'0','0','0','0','0','0','0'};							//Temporaray string for code and batch number storage.
	char s6[7];	
	char s5[7]={'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49};		//creating that size of array string
    sprintf(t, "%d",r); 										      //changing code,batch and batch product sum to string     
	if (strlen(t)<7)
	{
		int d=7-strlen(t);						// finding the number of places to implant zero
	    strncat(t,s5,d);	
	}
	fprintf(p,"code batch concated string: %s\n",t);
	long long int m_id,m_id1=0;
	for(m_id=0;m_id<n;m_id++)
	{	
	char s2[7]={0000000};										//temporary string always becoming zero to concate c and medicene_id.
	char s1[7]={0000000};										//Temporaray string always becoming zero for medicene_id to string conversion.	
	char s[14]={'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49};	//temporaray string always becoming zero to copy the compnay,batch number and medicene id concated string.
																															
    char s6[7]={'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49};		//creating that size of array string	
	m_id1=0;													//variable always stores m-id
	m_id1=m_id;													//copying medicene_id to temporary variable to be converted into string.
	
	 if(k1>65|| k<17)										// encryption key designing
	{
			k1=49;	k=33;
			
	}
	
	ltoa(m_id1,s1,10);									     //temporary string converting  medicene_id to string.
	strcat(s2,t);											//temporary string always  concating  c and medicene id.
    strcat(s2,s1);											//temporary string  concating c and string changed medicene id ((as not to change c we used s2.))
    strcpy(s,s2);											//copying the compnay,batch number and medicene_id concated string.
	if (strlen(s)<14)
	{
		int d1=14-strlen(s);
		//printf("\n d1 is as %d\n",d1);								// finding the number of places to implant zero
		//printf("s6 is: %s\n",s6);
	    strncat(s,s6,d1);
	
	}
	//printf("%s\n",s);

	fprintf(p,"unique code before encryption: %s\n",s);
	encryptioncode(s,k,k1);										//calling the function for encrypting the string to be printed on medicene.
	k1++;k--;
   
    }
	
	fprintf(p,"m_id repeated is: %d\n",m_id);	
	fclose(p);
    return 0;    
}
