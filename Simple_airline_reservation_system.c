#include <stdio.h>

int seats[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int sentinel = 1; 
int seatNumber;
int option = 0;
int i;

void FirstClass();
void Economy();
void boardingPass();


//main function 
void main(void)	{

	//loop while needed 
	while(sentinel == 1)	{
		printf("Please type 1 for first class\n");
		printf("Please type 2 for economy\n");
		printf("please type 3 to QUIT\n");
		scanf("%d", &option);
		
		//option = 3 == quit progrm 
		if(option == 3)	{
			break;
		}
		else if(option == 1)	{//put customer in first class
			FirstClass();	//calls first class function 
		}
		else if(option == 2)	{// put customer in economy 
			Economy();	//calls economy function 
		}
	}
}

//first class function 
void FirstClass()	{
	for(i = 0; i < 5; i++)	{
		if(seats[i] == 1 && i < 4)	{
		//i++; //seats are available 
		} 
		else if(i == 4 && seats[i] == 1)	{
			printf("All seats in First Class are booked.\n");
			printf("Please press 1 to book a seat in Economy\n");
			scanf("%d", &option);
			
			//seats are full in first class so put in economy
			if(option == 1)	{
				Economy(); //calls economy function 
				option = 2; //set option to economy 
			}
			else	{
				printf("Next flight leaves in 3 hours\n");
			}
		}
		else	{
		//book the customer for the flight 
			seats[i] = 1;
			seatNumber = i;
			boardingPass(); //print the boarding pass 
			break;	//break
		}//end if statement 
	}//end loop 
}//end first class function 


//economy class function 
void Economy()	{
	for(i = 5; i < 10; i++)	{
		if(seats[i] == 1 && i < 9)	{
			//seats are availabe do nothing
		}
		else if(i == 9 && seats[i] == 1)	{ // all seats are booked 
			printf("All seats in Economy are booked.\n");
			printf("Please press 1 to book a seat in First Class\n");
			scanf("%d", &option);
				
			//if option == 1 then put customer in first class
			if(option == 1)	{
				FirstClass(); // call first class function 
				option = 1; //change option to first class
			}
			else	{
			//notify customer of next flight 
				printf("Next flight leaves in 3 hours\n");
			}
		}
		else	{
		//boook the customer in economy 
			seats[i] = 1;
			seatNumber = i; 
			boardingPass();	//print boarding pass
			break;
		}
	}
}//end economy function 

//boarding pass function 
void boardingPass()	{
	printf("Seat Number: %d\n", seatNumber);
	
	if(option == 1)	{
		printf("Class: First Class\n\n");
	}
	else if(option == 2)	{
		printf("Class: Economy\n\n");
	}
}//end of boarding pass function 
