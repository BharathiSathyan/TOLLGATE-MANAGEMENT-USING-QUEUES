#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

int j=1;
int f=0;
int v=0;
/* Define a vehicle struct for the linked list*/
struct vehicle
{
    int r_no;
    struct vehicle* next;
};

/* Define the stack struct*/
struct Stack
{
    struct vehicle* top;
};


/* Check if the stack is empty*/
int isStackEmpty(struct Stack* stack)
{
    return stack->top == NULL;
}

/* Push an element onto the stack
*/void push(struct Stack* stack, int r_no)
{
    struct vehicle* newvehicle =(struct vehicle*)malloc(sizeof(struct vehicle));
    newvehicle->r_no = r_no;
    newvehicle->next = stack->top;
    stack->top = newvehicle;
}

/* Pop an element from the stack*/
    int pop(struct Stack* stack)
    {
        if (isStackEmpty(stack))
        {
            printf("Error: Stack is empty !\n");
            return -1;
        }

    struct vehicle* temp = stack->top;
    int r_no = temp->r_no;
    stack->top = temp->next;

    free(temp);
    return r_no;
    }
/* Initialize a new stack*/
void initStack(struct Stack* stack)
{
    stack->top = NULL;
}

/* ---------------------------------------------------------------------------Define the queue struct*/
struct Queue
{
    struct Stack stack1;
    struct Stack stack2;
};


void initQueue(struct Queue* queue)
{
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}/* Initialize a new queue*/


int isQueueEmpty(struct Queue* queue)
{
    return isStackEmpty(&queue->stack1) && isStackEmpty(&queue->stack2);
}


void enqueue(struct Queue* queue, int r_no)
{
    push(&queue->stack1, r_no);
}


int dequeue(struct Queue* queue)
{
    if (isQueueEmpty(queue))
        {
        printf("Error: Queue is empty!\n");
        return -1;
       }

    if (isStackEmpty(&queue->stack2))
        {
            while (!isStackEmpty(&queue->stack1))
            {
                push( &queue->stack2,pop(&queue->stack1) );
            }
        }

    return pop(&queue->stack2);
}


int main()
{
    char c;


    int  i,r_no;
    struct Queue queue;/*ambulance*/
    struct Queue lane1 ,lane2 ,lane3;
    int c1=0,c2=0,c3=0,c4=0;
    int vehicle_type, toll_fare,t1=0,t2=0,t3=0,t4=0;
redo:
    t1=0;
    t2=0;
    t3=0;
    t4=0;
    c1=0;
    c2=0;
    c3=0;
    c4=0;
    initQueue(&queue);
    initQueue(&lane1);
    initQueue(&lane2);
    initQueue(&lane3);

   printf(" \t\t\t\t\t\t\t\t  COIMBATORE\n");
   printf(" \t\t\t\t\t\t\t\tCBE TOLL PLAZA\n");
   printf(" \t\t\t\t\t\t\t\tWELCOMES YOU!!\n");
   printf("\t\t\t\t\t\t\t  .________________________.\n");
   printf("\t\t\t\t\t\t\t  |     |     |     |      | \n");
   printf("\t\t\t\t\t\t\t  |     |     |     |      | \n");
   printf("\t\t\t\t\t\t\t  |     |     |     |      | \n");
   printf("\t\t\t\t\t\t\t  |LANE | LANE| LANE| LANE | \n");
   printf("\t\t\t\t\t\t\t  |  1  |  2  |  3  |  4   |\n");
   printf("\t\t\t\t\t\t\t  |     |     |     |      | \n");
   printf("\t\t\t\t\t\t\t  |     |     |     |      | \n");
   printf("\t\t\t\t\t\t\t  |_LMV_|_HMV_|GOODS|_AMBN_|\n");


//system("color 0");

printf("\n\t\t\t\t\t\t\t\tWelcome to Toll Gate\n");
system("color 2");
//system("COLOR B");
   do{
        //system("color 05");
       printf("\tEnter Vehicle Type:\n1 for Car(LMV)\n2 for Bus(HMV)\n3 for Truck(GOODS)\n4 for Ambulance(AMBN)\n : ");
       scanf("%d", &vehicle_type);

       switch(vehicle_type)
       {
          case 1:
             printf("MOVE TO LANE :1\n");
             toll_fare =50;
             c1++;
             t1+=toll_fare;
             if(c1>4)
             {
                 printf("LANE 1 is Full\tPlease Wait!!\n");
             }
             break;

          case 2:
             printf("MOVE TO LANE :2\n");
             toll_fare =75;
             c2++;
             t2+=toll_fare;
             if(c2>4)
             {
                 printf("LANE 2 is Full\tPlease Wait!!\n");
             }
             break;

          case 3:
            printf("MOVE TO LANE :3\n");
             toll_fare =150;
             c3++;
             t3+=toll_fare;
             if(c3>4)
             {
                 printf("LANE 3 is Full\tPlease Wait!!\n");
             }
             break;

          case 4:
             printf("MOVE TO LANE :4\n");
             toll_fare =0;
             c4++;
             t4+=toll_fare;
             printf("Non-Stop!!!\n");
             break;

          default:
             printf("Invalid Vehicle Type\n");
             return 0;
        }
        printf("\n IS There another vehicle ENTERING??(Y/N)\n");

        scanf("\n%c",&c);
        sleep(2);
        system("cls");
   }while( ((c=='y' )||(c=='Y')) && (c1<=4 || c2<=4 || c3<=4 ));



    /*if(vehicle_type!=4)DEQUEUING*/
system("cls");
    printf("\t\t\t\t\tSCANNING YOUR VEHICLE REGISTRATION NUMBER ....\n");

    printf("\t\t\t\t\t\t\t\tDEQUQUING\n");

/*------------------------------------------------------------------------------------------*/
    if(c4!=0)
    {
         printf("\nPriority 1:  LANE 4 (Medical Emergency) /=!=\\  \n");
        for(i=1;i<=c4;i++)
                enqueue(&queue,i);

        while (!isQueueEmpty(&queue))
        {
            int carNumber = dequeue(&queue);
            printf("Ambulance no: %d Dequeued\n",carNumber);
        }

        printf("\nAll vehicle have passed through the LANE 4\n");
        printf("Total fare in Lane 4 = Rs.%d\n",t4);
        sleep(6);
        system("cls");
    }

/*------------------------------------------------------------------------------------------*/

    if(c1!=0)
        {
            printf("\nPriority 2:  LANE 1 (Private LMV vehicle) \n");
            for(i=1;i<=c1;i++)
            {
                printf("\nEnter your registration number \n");
                scanf("%d",&r_no);
                enqueue(&lane1,r_no);
                int carNumber=dequeue(&lane1);
                printf("\nFare = Rs.50\n");
                printf("TN 37 CW%d dequeued\n", carNumber);
            }
            printf("\nAll vehicle have passed through the LANE 1\n");
            printf("Total fare in Lane 1 = Rs.%d\n",t1);
            sleep(6);
            system("cls");
        }
/*------------------------------------------------------------------------------------------*/
    if(c2!=0)
    {
        printf("\nPriority 3:  LANE 2 (public vehicle && Cars) \n");
       for(i=1;i<=c2;i++)
        {
            printf("\nEnter your registration number \n");
            scanf("%d",&r_no);
            enqueue(&lane2,r_no);
            int carNumber=dequeue(&lane2);
            printf("\nFare = Rs.75\n");
            printf("TN 66 MJ%d dequeued\n", carNumber);
        }
        printf("\nAll vehicle have passed through the LANE 2\n");
        printf("Total fare in Lane 2 = Rs.%d\n",t2);
        sleep(6);
        system("cls");
    }

/*------------------------------------------------------------------------------------------*/
   if(c3!=0)
   {
       printf("\nPriority 4:  LANE 3 (Goods transport) \n");
          for(i=1;i<=c3;i++)
        {
            printf("\nEnter your registration number \n");
            scanf("%d",&r_no);
            enqueue(&lane3,r_no);
            int carNumber=dequeue(&lane3);
            printf("\nFare = Rs.150\n");
            printf("KL 89 AM%d dequeued\n", carNumber);
        }
        printf("\nAll vehicle have passed through the LANE 3\n");
        printf("Total fare in Lane 3 = Rs.%d\n",t3);
        sleep(6);
        system("cls");
   }

/*------------------------------------------------------------------------------------------*/


   int total=0;
   total=t1+t2+t3+t4;
   int ve;
   ve=c1+c2+c3+c4;
   f+=total;
   v+=ve;
   printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
   printf("\n\t\t\t\t\t\tToll Vehicles passed in TOLLGATE (round %d): %d\n",j,ve);
   printf("\t\t\t\t\t\t\tToll Fare Collected :Rs. %d\n", total);
 printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    c1=c2=c3=c4=0;
    printf("\nAll cars have passed through the tollgate.\n");

    printf("\n IS There any other vehicle coming up (y/n) ?\n");
    scanf("\n%c",&c);
    if(c=='y' || c=='Y')
    {
        j++;
        printf("CLEARING THE LANES....\n");
        sleep(4);
        system("cls");
        goto redo;
    }
    sleep(1);
    system("cls");
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
   printf("\n\t\t\t\t\t\tToll Vehicles passed in TOLLGATE Today: %d\n",v);
   printf("\t\t\t\t\t\t\tToll Fare Collected :Rs. %d\n", f);
   printf("\n\t\t\t\t\t\t\tTHANKYOU VISIT AGAIN!!!\n");
   printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

return 0;
}
