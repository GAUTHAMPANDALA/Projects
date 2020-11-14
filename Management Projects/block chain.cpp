#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "openssl/crypto.h"
#define SHA256_DIGEST_LENGTH 32
unsigned char *SHA256(const unsigned char *d, size_t n, unsigned char *md);struct block{
 unsigned char prevHash[SHA256_DIGEST_LENGTH];
 int blockData;
 struct block *link;
}*head;void addBlock(int);
void verifyChain();
void alterNthBlock(int,int);
void hackChain();
int hashCompare(unsigned char*,unsigned char*);
void hashPrinter();
unsigned char* toString(struct block);
void printBlock();
void printAllBlocks();//SHA256(src,size,dest)
//src and dest are of type unsigned char*
/*To maintain blockchain integrity we will do three things allocate memory to current
block,calculate previous block hash, set value os previous hash,set data value and
leave next link to null */void addBlock(int data)
{
 if (head==NULL)
 {
   head=malloc(sizeof(struct block));
   SHA256("",sizeof(""),head->prevHash);
   head->blockData=data;
   return;
 }
 struct block *currentBlock=head;
 while(currentBlock->link)
      currentBlock=currentBlock->link; struct block *newBlock=malloc(sizeof(struct block));
 currentBlock->link=newBlock; //join new block to current
 newBlock->blockData=data; //assign data to newblock
 SHA256(toString(*currentBlock),sizeof(*currentBlock),newBlock->prevHash);
}/* Suppose if we have new blocks in chain and if you want to verify if any data was tampered or modified, it will print data in the blocks and verify data in blocks. To verify we will calculate the hash of previous block and match oit with value of hash of previous block with hash variable of current block . IF both are same then block has been verified */void verifyChain()
{
    if(head==NULL)
      {
  printf("Blockchain is empty! try again after adding some block!\n");
  return;
      }
      struct block *curr=head->link,*prev=head;
      int count=1;
      while(curr)
       {
   printf("%d\t[%d]\t",count++,curr->blockData);
   hashPrinter(SHA256(toString(*prev),sizeof(*prev),NULL),SHA256_DIGEST_LENGTH);
   printf(" - ");
   hashPrinter(curr->prevHash,SHA256_DIGEST_LENGTH);
   if(hashCompare(SHA256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
      printf("Verified!\n");
   else
      printf("Verification Failed\n");
      prev=curr;
      curr=curr->link;      }
}
void alterNthBlock(int n,int newData)
{
     struct block *curr=head;
     int count=0;     // i have added
     if(curr==NULL)
     {
       printf("Nth block does not exist!\n");
       return;
      }
     while(count!=n)
     {
       if(curr->link==NULL && count!=n)
       {
  printf("Nth Block does not exist!\n");
  return;
 }
     else if(count==n)
   break;
 curr=curr->link;
 count++;
     }
     printf("Before: ");
     printBlock(curr);
     curr->blockData=newData;
     printf("\nAfter: ");
     printBlock(curr);
     printf("\n");
}void hackChain()
{
  struct block *curr=head,*prev;
     if(curr==NULL)
      {
 printf("BlockChain is empty!");
 return;
       }
      while(1)
      {
       prev=curr;
       curr=curr->link;
       if(curr==NULL)
       return;
       if(!hashCompare(SHA256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
       {
       hashPrinter(SHA256(toString(*prev),sizeof(*prev),curr->prevHash),SHA256_DIGEST_LENGTH);
       printf("\n");
       }
    }
}
unsigned char *toString(struct block b)
{
 unsigned char *str=malloc(sizeof(unsigned char)*sizeof(b));
  memcpy(str,&b,sizeof(b));
  return str;
}
void hashPrinter(unsigned char hash[],int length)
{
  int i=0;    // I have added
  for(i=0;i<length;i++)
      printf("%02x",hash[i]);
}int hashCompare(unsigned char *str1,unsigned char *str2)
{
 for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
    if(str1[i] != str2[i])
      return 0;
    return 1;
}void printBlock(struct block *b)
{
   printf("%p\t",b);
   hashPrinter(b->prevHash,sizeof(b->prevHash));
   printf("\t[%d]\t",b->blockData);
   printf("%p\n",b->link);
}void printAllBlocks()
{
   struct block *curr=head;
   int count=0;
   while(curr)
   {
      printBlock(curr);
      curr=curr->link;
   }
}int main()
{
int c,n,r;
/*
    printf("1)addBlock\n2)add n blocks\n3)alterNthBlock\n4)printAllBlocks\n5)VerifyChain\n6)hackChain\n");*/
    printf("1)addBlock\n");
  while(1)
  {
     printf("Choice: ");
     scanf("%d",&c);
     switch(c)
     {
 case 1:
     printf("Enter data: ");
     scanf("%d",&n);
     addBlock(n);
     break;
  case 2:
     printf("How many blocksto enter?: ");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
  r=rand()%(n*10);
  printf("Entering: %d\n",r);
  addBlock(r);
      }
      break;
   case 3:
      printf("Which block to alter?: ");
      scanf("%d",&n);
      printf("Enter value: ");
      scanf("%d",&r);
      alterNthBlock(n,r);
      break;
   case 4:
      printAllBlocks();
      break;
    case 5:
       verifyChain();
       break;
    case 6:
       hackChain();
       break;
     default:
      printf("Wrong choice!\n");
      break;
    }

      }
       return 0;
}
