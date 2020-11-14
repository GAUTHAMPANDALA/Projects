#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char encryptioncode(char st[14])
{
	int i,n;
	n=strlen(st);
	for(i = 0;i<n; i++)
	{
	st[i] = st[i]*3;						 //the key for encryption is 3 that is added to ASCII value
	printf("\n%d\n",strlen(st));
  		
	}				    
   printf("\nEncrypted string: %s\n", st);	 // printing the encrypted string s
}
int main()

{
	long long int n;
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
	printf("%s\n",t);
	strcat(t,b);					   // concading the t which has  code of company and batch number.
	printf("%s\n",t);
	for(m_id=0;m_id<n;m_id++)
	{	
	char s2[7]={0000000};										//temporary string always becoming zero to concate c and medicene_id.
	char s1[7]={0000000};										//Temporaray string always becoming zero for medicene_id to string conversion.	
	char s[14]={'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49,'a'-49};					//temporaray string always becoming zero to copy the compnay,batch number and medicene id concated string.
	//printf("s is: %s\n",s);
    char s6[7]={'a'-41,'a'-41,'a'-41,'a'-41,'a'-41,'a'-41,'a'-41};													//creating that size of array string	
	m_id1=0;													//variable always stores m-id
	m_id1=m_id;													//copying medicene_id to temporary variable to be converted into string.
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
										
	//printf("\n non encrypted code is:  %s\n",s); 		    //printing the non encrypted code compnay,batch number and medicene_id concated string.
	printf("%s\n",s);
	//encryptioncode(s);										//calling the function for encrypting the string to be printed on medicene.

    }
	printf("s lenght is: %d\n",strlen(s));
	printf("m_id repeated is: %d\n",m_id);	
    return 0;    
}
