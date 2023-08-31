#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listofcad();
void registration(char* k,int l);
void castvote(int i,int j);
void votedisplay();
void deregistration(int i);
typedef struct voter_info
{
  char name[50];
  int age;
  int aadhaarno;
  int voterid;
  int votestatus;
  struct voter_info *next;
}node;
node *head=NULL,*new,*temp,*t,*prev,*temp1;
int cunt1=0,cunt2=0,cunt3=0,cunt4=0;
int u=1000;

int main()
{
   int choice,chu,cha,vcast,rm,age,pwd;
   char ch,name[30],user[10];
   printf("\n\n\n");
   printf("\n\n\n\t\t\t  ~~~~~WELCOME TO ONLINE VOTING~~~~~ \n\n\n");
   printf("   INSTRUCTIONS:-\n");
   printf("   1.You can cast vote only once\n");
   printf("   2.Your age should be 18 or above 18\n");
   printf("   3.First you should register to cast vote\n");
   printf("   4.If you have entered wrong details you can deregister it and register again\n");
   do
   {
   printf("\n\t\t1. Registration\n\t\t2. CastVote\n\t\t3. List of Candidates\n\t\t4. Winner\n\t\t5. Votes Secured by each candidate\n\t\t6. Deregistration\n\t\t7. EXIT\n");
   printf("\n\t\t Enter choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1: do
             {
               printf("\n\tEnter your Name: ");
               scanf("%s",name);
               printf("\tEnter your Age: ");
               scanf("%d",&age);
                if(age>=18)
                {
                   registration(name,age);
                }
                else
                {
                 printf("\n\t You are not eligible for registration as your age is below 18\n");
                }
                printf("\n\tDo you want to continue? press 'y' for yes: ");
                scanf(" %c",&ch);
              }while(ch=='y');
              break;
     case 2:
             printf("\n\tEnter your Voter Id: ");
             scanf("%d",&chu);
             printf("\tEnter your Aadhaar Number: ");
             scanf("%d",&cha);
             castvote(chu,cha);
             break;
      case 3:
             listofcad();
             break;
      case 4:
              printf("\n\tEnter User Id: ");
              scanf("%s",&user);
              printf("\tEnter Password: ");
              scanf("%d",&pwd);
              if(pwd==1234)
              {
              if(cunt2<cunt1&&cunt3<cunt1&&cunt4<cunt1)
              printf("\n\tWinner is Y.S.JAGAN MOHAN REDDY - %d \n",cunt1);
              else if(cunt1<cunt2&&cunt3<cunt2&&cunt4<cunt2)
              printf("\n\tWinner is NARA CHANDRA BABU NAIDU - %d \n",cunt2);
              else if(cunt1<cunt3&&cunt2<cunt3&&cunt4<cunt3)
              printf("\n\tWinner is PAWAN KALYAN - %d \n",cunt3);
              else if(cunt1<cunt4&&cunt2<cunt4&&cunt3<cunt4)
              printf("\n\tWinner is CHANDRA SEKHAR RAO - %d \n",cunt4);
              }
              else
              {
                  printf("\n\tIncorrect User Id or Password\n\tIt needs Authorised User Id and Password\n\n");
              }
              break;
      case 5:
              votedisplay();
              break;
      case 6:
              printf("\tEnter your Voter Id:");
              scanf("%d",&rm);
              deregistration(rm);
              break;
      case 7: printf("\n EXIT");
              break;
      default:printf("\n\t Enter a valid choice 1-7\n");
              break;
   }
}while(choice!=7);
}
void listofcad()
{
     printf("\n\n\t\t\t List of the candidates \n");
     printf("\t\t1. Y.S.JAGAN MOHAN REDDY             1.FAN\n");
     printf("\t\t2. NARA CHANDRA BABU NAIDU           2.CYCLE\n");
     printf("\t\t3. PAWAN KALYAN                      3.GLASS\n");
     printf("\t\t4. CHANDRA SEKHAR RAO                4.CAR\n");
}
void registration(char* k,int l)
{
  if(head==NULL)
  {
    new=(node *)malloc(sizeof(node));
    strcpy(new->name,k);
    new->age=l;
    printf("\tEnter your Aadhar number: ");
    scanf("%d",&new->aadhaarno);
    new->votestatus=0;
    new->voterid=u++;
    new->next=NULL;
    head=new;
    printf("\tYour Voter Id is %d\n",new->voterid);
    }
    else
    {
    new=(node *)malloc(sizeof(node));
    strcpy(new->name,k);
    new->age=l;
    printf("\tEnter your Aadhar number: ");
    scanf("%d",&new->aadhaarno);
    new->votestatus=0;
    new->voterid=u++;
    new->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=new;
    printf("\tYour Voter Id is %d\n",new->voterid);
  }
}
void deregistration(int i)
{
  temp1=head;
  while(temp1->voterid!=i)
  {
    prev=temp1;
    temp1=temp1->next;
  }
  prev->next=temp1->next;
  free(temp1);
}
void votedisplay()
{
  printf("\n\n\t\tY.S.JAGAN MOHAN REDDY -    %d \n",cunt1);
  printf("\t\tNARA CHANDRA BABU NAIDU -  %d \n",cunt2);
  printf("\t\tPAWAN KALYAN -             %d \n",cunt3);
  printf("\t\tCHANDRA SEKHAR RAO -       %d \n",cunt4);
}
void castvote(int i,int j)
{
             int vc;
             t=head;
             while(t->aadhaarno!=j&&t->next!=NULL)
                  t=t->next;

             if(t->aadhaarno!=j)
             {
                 printf("\n\n\tYou have not registered!\n\tPlease register to cast vote\n\n");
             }
             else if(t->aadhaarno==j&&t->votestatus==0)
             {
                 listofcad();
                 printf("\n\tEnter the number of the candidate you want to vote: ");
                 scanf("%d",&vc);
                 printf("\tThanks for vote\n\n");
                 t->votestatus=1;
                 switch(vc)
                 {
                    case 1: cunt1++;
                            break;
                    case 2: cunt2++;
                            break;
                    case 3: cunt3++;
                            break;
                    case 4: cunt4++;
                            break;
                    default: printf("Enter a valid choice 1-4");
                             break;
                 }
             }
             else if(t->votestatus == 1)
             {
                 printf("\n\n\tYou have already voted!\n\tThank You\n\n");
             }
}
