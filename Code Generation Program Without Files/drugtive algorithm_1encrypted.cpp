#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m=0;
char encryptioncode(char st[14],int k ,int k1,int c1)
{
	int i,n,j=0,c=0,p=49;
	n=strlen(st);
	// encryption starts
	for(i = 0;i<n; i++)
	{ 

	 if(i==0)
	 {
	 	if(m>9)
	 	{
	 		m=0;
		 }
		 if(st[i]=='a'-41 ||st[i]=='a'-42 || st[i]=='a'-40 )
		 {
	 			st[i]=st[i]-c1;
	 			c1--;
	 		
		 }
		  else
	  	      st[i]=st[i]+m;
	  	m++;
	 	
	 }
	 else if(j%2==0 && j%3!=0)
	 {
	 	st[i]=st[i]+k;
	 	j++;
	 	
	 }
	  else if(j%3==0 && j%2!=0 )
	 {
	 	st[i]=st[i]+k1;
	 	j++;	 	
	 }
	 else
	 {
	 	if(c==0)
		 {		 
	    st[i]=st[i]+k;
	 	 c=2;
	    }
		 else 
		 {
		 	st[i]=st[i]+k1;
	 	    c=0;	
	    }
	     j++;
	 }		 	
	 
	 if((st[i]>=90 && st[i]<=96 ) || (st[i]>=123&& st[i]<=126))					// checks for special charecters and assings as variables
	 	{
	 	st[i]='a'-p;
	 	p--;
	 	
		 }
	  
	 
	 }
	 
	 
	 
	//printf("\n%d\n",strlen(st));
  		
					    
   printf("Encrypted string: %s\n", st);	 // printing the encrypted string s
}
int main()

{
	long long int n,k=33,k1=49,c1=5;
    char c[3];
    printf("Enter the company code \n");
	scanf("%s",c);	
	char b[4];
	printf("Enter the batch number \n ");
	scanf("%s",b);
	printf("Enter the number of medicines per batch \n ");
	scanf("%lld",&n);
	char s[14];		   					// temporaray string to copy the compnay,batch number and medicene_id concated string.
	char s1[7];				            //Temporaray string for medicene_id to string conversion.
	char t[7]={0000000};			  	//Temporaray string for code and batch number storage.
	char s6[7];						//creating that size of array string
    long long int m_id,m_id1=0;
	strcat(t,c);					   // concading the t and  code of company.
	//printf("%s\n",t);
	strcat(t,b);					   // concading the t which has  code of company and batch number.
	//printf("%s\n",t);
	for(m_id=0;m_id<n;m_id++)
	{	
	char s2[7]={0000000};										//temporary string always becoming zero to concate c and medicene_id.
	char s1[7]={0000000};										//Temporaray string always becoming zero for medicene_id to string conversion.	
	char s[14]={'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49};					//temporaray string always becoming zero to copy the compnay,batch number and medicene id concated string.
	//printf("s is: %s\n",s);
    char s6[7]={'a'-41,'a'-42,'a'-40,'a'-41,'a'-40,'a'-42,'a'-40};													//creating that size of array string	
	m_id1=0;													//variable always stores m-id
	m_id1=m_id;														//copying medicene_id to temporary variable to be converted into string.
	
    if(k1>65|| k<17)										// encryption key designing
	{
			k1=49;	k=33;
			
	}
													// encryption key designing.
	ltoa(m_id1,s1,7);											//temporary string converting  medicene_id to string.
    strcat(s2,t);											//temporary string always  concating  c and medicene id.
    strcat(s2,s1);											//temporary string  concating c and string changed medicene id ((as not to change c we used s2.))
	strcpy(s,s2);											//copying the compnay,batch number and medicene_id concated string.
	if (strlen(s)<14)
	{
		int d1=14-strlen(s);
		//printf("\n d1 is as %d\n",d1);								// finding the number of places to implant zero
		//printf("s6 is: %s\n",s6);
	    strncat(s,s6,d1);												// concating the remaing places after the number  with zeros(before important)
	}
										
	printf("non encrypted code is:  %s\n",s); 		    //printing the non encrypted code compnay,batch number and medicene_id concated string.
	encryptioncode(s,k,k1,c1);										//calling the function for encrypting the string to be printed on medicene.
	//printf("s lenght is: %d\n",strlen(s));
	k1++;k--;
    }
	
	printf("m_id repeated is: %d\n",m_id);	
    return 0;    
}
