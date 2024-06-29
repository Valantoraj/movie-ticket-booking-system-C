                    //MOVIE TICKET BOOKING SYSTEM PROGRAM


#include <stdio.h>          //Header files inclusion
#include<stdlib.h>
#include<string.h>
#include <conio.h>

struct main{
    char choice;;
    spf

    char name[49];
}s;
void menu(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
          int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);     //Function declaration

void BookTicket(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
                int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);

void CancelTicket(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
                  int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);

void BookingRecords(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
                    int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);

void HelpMenu(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
              int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);

void Exit(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
          int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);

void Display(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
             int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x);




//FUNCTION DISPLAY :  To display the movie name, price list, screening time

void Display(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
             int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){

    for(int j=0;j<5;j++){
        printf("Movie Name    : %s\n",movie_list[j]);
        printf("Ticket Price  : %d\n",price_list[j]);
        printf("Screening Time: ");
        for(int k=0;k<4;k++){
            printf("%d-->%.2f hrs   ",k+1,show_time[j][k]);
        }
    printf("\n\n");
    }
}

//FUNCTION BOOKTICKET : To enable the user to book tickets

void BookTicket(char (*movie_list)[50],int *price_list,float (*show_time)[4],int n,int (*show_seat)[4],\
                int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){
    Display(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
    char movie_name[50];
    int count=0,show_choice,ticket_choice;
    printf("\nEnter the movie of your choice: ");       //Gets the user's input for movie of interest
    scanf("\n%[^\n]s",movie_name);
    for(int i=0;i<5;i++){
        if(strcmpi(movie_list[i],movie_name)==0){       //If the movie is running in the theatre then display the show timings that are available
            system("cls");
            count++;
            printf("Movie name            : %s\n",movie_list[i]);
            printf("Ticket price is       : %d\n",price_list[i]);
            printf("Available show timings: ");
            for(int k=0;k<4;k++){
                printf("%d -->%.2f hrs   ",k+1,show_time[i][k]);
            }
            printf("\nEnter the show of your choice: ");        //Gets the user's choice of show
            scanf("%d",&show_choice);
            system("cls");
            if(show_choice>4){
                printf("There are only 4 shows displayed per day...\n\n");
                printf("Press any key to continue...");
                if(getch()){
                    menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
                }
            }
            if((show_seat[i][show_choice-1])==0){              //checks if the tickets are available for the specified show
                printf("The are no tickets left for this show...\n\n");
                printf("Press any key to continue...");
                if(getch()){
                    menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
                }
            }
            printf("Movie name                 : %s\n",movie_list[i]);
            printf("Ticket price               : %d\n",price_list[i]);
            printf("Show Time                  : %.2f\n",show_time[i][show_choice-1]);
            printf("Availabe seats             : %d\n",show_seat[i][show_choice-1]);
            printf("Enter the number of tickets: ");        //gets the number of tickets from the user
            scanf("%d",&ticket_choice);
            system("cls");
            if(ticket_choice<=show_seat[i][show_choice-1]){     //if specified number of tickets are available it executes the statements
            show_seat[i][show_choice-1]-=ticket_choice;
            printf("Movie name         : %s\n",movie_list[i]);
            printf("Ticket price       : %d\n",price_list[i]);
            printf("Show Time          : %.2f\n",show_time[i][show_choice-1]);
            printf("Total price        : %d\n",ticket_choice*price_list[i]);
            printf("\nAre you sure to confirm booking(Y/N)");       //asks the user to confirm booking
            char confirm_booking;
            redo_confirm_booking:
            confirm_booking=getch();
            putch(confirm_booking);
            if(confirm_booking=='y'){             //If user enters y then it continues to ticket display screen
                    Book_booking_id[x]=x+1;
                    strcpy(Book_movie_name[x],movie_list[i]);
                    Book_show_time[x]=show_time[i][show_choice-1];
                    Book_numof_tickets[x]=ticket_choice;
                    Book_total_price[x]=ticket_choice*price_list[i];
                    system("cls");
                    printf("Booking Done...\n");
                    printf("Booking details:\n\n");
                    printf("Booking Id        : %d\n",Book_booking_id[x]);
                    printf("Movie Name        : %s\n",Book_movie_name[x]);
                    printf("Show Time         : %.2f\n",Book_show_time[x]);
                    printf("Number Of Tickets : %d\n",Book_numof_tickets[x]);
                    printf("Total Price       : %d\n",Book_total_price[x]);
                    x+=1;
                    printf("Press any key to proceed...");      //upon pressing of any key it moves to the menu of the ticket booking system
                    if(getch()){
                    menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
                    }
            }
            else if(confirm_booking=='n'){      //if user had entered n prior it cancels the booking
                printf("\n\nBooking cancelled...");
                printf("\n\nPress any key to proceed...");
                if(getch()){
                menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
            }
            }
            else{                   //If user fails to enter y or n then it moves to redo_confirm_booking
                printf("\n\nPress only Y or N...");
                goto redo_confirm_booking;
            }
            }
            else{           //If the specified number of tickets are not available then it displays it
                printf("\nYou entered %d tickets but there are only %d tickets\n",ticket_choice,show_seat[i][show_choice-1]);
                printf("Press any key to go to menu..");        //upon pressing of any key it moves to the menu of the ticket booking system
                if(getch()){
                menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
                }
            }
        }
    }
    if(count==0){       //If the entered movie name is not in the movie_list then it displays it
        printf("\n\nSorry the mentioned movie is not been screened in our theatre\n\n");
        printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
        if(getch()){
            menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
        }
    }

}


//FUNCTION CANCELTICKET : It helps us to cancel the movie with requested booking id

void CancelTicket(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
                  int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){


    int book_cancel,test_count=0;
    printf("Enter the booking id you want to cancel: ");        //gets the booking id that you want to cancel
    scanf("%d",&book_cancel);
    if(book_cancel==Book_booking_id[x-1]){      //If the booking id is the end limit
        printf("Booking Id        : %d\n",Book_booking_id[x-1]);
        printf("Movie Name        : %s\n",Book_movie_name[x-1]);
        printf("Show Time         : %.2f\n",Book_show_time[x-1]);
        printf("Number Of Tickets : %d\n",Book_numof_tickets[x-1]);
        printf("Total Price       : %d\n\n\n",Book_total_price[x-1]);
        printf("Are you sure that you want to cancel the above booking(Y/N):");     //Confirmation for cancellation
        char cancel_confirm_l=getch();
        putch(cancel_confirm_l);
        if(cancel_confirm_l=='y'){          //If user enters y then booking is cancelled
        Book_booking_id[x-1]=0;
        strcpy(Book_movie_name[x-1]," ");
        Book_show_time[x-1]=0;
        Book_numof_tickets[x-1]=0;
        Book_total_price[x-1]=0;
        x-=1;
        test_count=1;
        printf("\nBooking Cancelled...\n\n");
    }
        else {              //Otherwise the booking will not be cancelled
        printf("\n");
        printf("\nBooking has not been cancelled...\n\n");
        }
        printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
        if(getch()){
            menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
        }
    }
    for(int b=0;b<x-1;b++){         //If booking id is not the end limit
        if(Book_booking_id[b]==book_cancel){        //If booking id matches then asks for confirmation
            test_count=1;
            printf("Booking Id        : %d\n",Book_booking_id[b]);
            printf("Movie Name        : %s\n",Book_movie_name[b]);
            printf("Show Time         : %.2f\n",Book_show_time[b]);
            printf("Number Of Tickets : %d\n",Book_numof_tickets[b]);
            printf("Total Price       : %d\n\n\n",Book_total_price[b]);
            printf("Are you sure that you want to cancel the above booking(Y/N):");     //Asks for connfirmation
            char cancel_confirm=getch();
            if(cancel_confirm=='y'){        //If users enters y then cancels booking
                for(int c=b+1;c<x;c++){
                    Book_booking_id[c-1]=Book_booking_id[c];
                    strcpy(Book_movie_name[c-1],Book_movie_name[c]);
                    Book_show_time[c-1]=Book_show_time[c];
                    Book_numof_tickets[c-1]=Book_numof_tickets[c];
                    Book_total_price[c-1]=Book_total_price[c];
                }
                Book_booking_id[x-1]=0;
                strcpy(Book_movie_name[x-1],"");
                Book_show_time[x-1]=0;
                Book_numof_tickets[x-1]=0;
                Book_total_price[x-1]=0;

                x-=1;
                printf("\n\nBooking Cancelled...\n\n");
                printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
                if(getch()){
                    menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
                }

            }
        }
    }
    if(test_count==0){      //If the entered booking id is invalid
        printf("There is no such booking id...\n\n");
        printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
        if(getch()){
            menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
        }
    }
}

//FUNCTION BOOKINGRECORDS : To view the booking records

void BookingRecords(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
                    int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){


    system("cls");
    printf("Booking Record...\n\n");
    if(x==0){             //If no booking is done prior
        printf("There is no bookings yet...\n\n");
    }
    else{                 //If there are booking records display the same
    for(int a=0;a<x;a++){
        printf("Booking Id        : %d\n",Book_booking_id[a]);
        printf("Movie Name        : %s\n",Book_movie_name[a]);
        printf("Show Time         : %.2f\n",Book_show_time[a]);
        printf("Number Of Tickets : %d\n",Book_numof_tickets[a]);
        printf("Total Price       : %d\n\n\n",Book_total_price[a]);
    }
        printf("To download the booking record press 'Y' \n\n");
    char booking_data=getch();
    if(tolower(booking_data)=='y'){     //Store booking records in file
        FILE *file;
        file=fopen("booking records.txt","w");
        fprintf(file,"%s","Booking record...");
        for(int c=0;c<x;c++){
        fprintf(file,"\n\nBooking Id        :%d\nMovie Name        :%s\nShow Time         :%.2f\nNumber Of Tickets :%d\nTotal Price       :%d",Book_booking_id[c],Book_movie_name[c],Book_show_time[c],Book_numof_tickets[c],Book_total_price[c]);
        }
        printf("\n\nBooking record has been stored...\n\n");
        fclose(file);
    }
    }

    printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
    if(getch()){
        menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
    }
}

//FUNCTION HELPMENU : To guide the user

void HelpMenu(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
              int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){


    printf("\t\t\t\tHELP MENU\n\n\
==> In booking tickets you will be displayed with the available movies.\n\n\
==> In cancellation section enter the booking id present in the booking record generated.\n\n\
==> You can view your entire booking record in the Booking record menu.\n\n\
==> The records will be stored in a file named 'Booking records.txt'.\n\n\
==> No refunds will be provided.\n\n");
    printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
    if(getch()){
        menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
    }
}

//FUNCTION EXIT : The exit operation is performed here

void Exit(char (*movie_list)[50],int (*price_list),float (*show_time)[4],int n,int (*show_seat)[4],\
          int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){


    char exit_confirmation;
    int rating;
    printf("Are you sure you want to exit.(Y/N)");      //confirmation for exiting
    exit_confirmation=getch();
    if((exit_confirmation)=='y'){       //If user enters y then asks for ratings and exit
        system("cls");
        printf("Thank you for booking through our ticket booking portal!!!\n\n");
        printf("Rate your experience with us: ");     //Gets the rating from user
        scanf("%d",&rating);
        printf("\nThank you for your rating...\n\n");
        exit(0);          //Exit code
    }
    else{       //If user enters other than y goes to the main menu
        menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
    }
}

//FUNCTION MENU : It is the main menu

void menu(char (*movie_list)[50],int *price_list,float (*show_time)[4],int n,int (*show_seat)[4],\
          int *Book_booking_id,char (*Book_movie_name)[50],float *Book_show_time,int *Book_numof_tickets,int *Book_total_price,int x){


    system("cls");
    printf("-------------------------------------------------------------------------------------------------\n");      //Main menu layout
    printf("|                                                                                               |\n");
    printf("|                                         -- MENU --                                            |\n");
    printf("|                                                                                               |\n");
    printf("| 1.Book Ticket \t 2.Cancel Ticket\t 3.Booking records\t 4.Help menu\t 5.Exit |\n");
    printf("|                                                                                               |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    s.choice=getch();       //Gets the input from the user
    system("cls");
    switch(s.choice){       //Switch case to call functions
        case '1':
            BookTicket(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
            break;
        case '2':
            CancelTicket(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
            break;
        case '3':
            BookingRecords(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
            break;
        case '4':
            HelpMenu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
            break;
        case '5':
            Exit(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
            break;
        default:
            printf("Enter a valid option(between 1-5)...\n");
            menu(movie_list,price_list,show_time,n,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
    }
}

//MAIN FUNCTION : It initiates the program execution

int main()
{


    char movie_list[5][50]={"Adventure Island","Peaky Blinders","Shutter Island","Interstellar","Game Of Thrones"};
    int price_list[5]={190,120,150,160,130};
    float show_time[5][4]={{10.15,13.30,16.45,20.30},{11.15,13.45,15.30,17.40},{8.45,12.15,16.0,18.45},{7.10,9.05,11.15,14.40},{11.25,17.45,19.50,22.45}};
    int show_seat[5][4]={{5,6,7,8},{3,4,5,6},{2,3,4,5},{2,3,2,3},{2,2,4,5}};
    int Book_booking_id[19];
    char Book_movie_name[19][50];
    float Book_show_time[19];
    int Book_numof_tickets[19];
    int Book_total_price[19];
    int x=0;
    printf("-------------------------------------------------------------\n");      //Welcome screen
    printf("|                                                           |\n");
    printf("| -- WELCOME TO OUR THEATRE'S MOVIE TICKET BOOKING SYSTEM-- |\n");
    printf("|                                                           |\n");
    printf("-------------------------------------------------------------\n\n");
    printf("Press any key to continue...");     //upon pressing of any key it moves to the menu of the ticket booking system
    if(getch()){
        menu(movie_list,price_list,show_time,5,show_seat,Book_booking_id,Book_movie_name,Book_show_time,Book_numof_tickets,Book_total_price,x);
    }
    return 0;
}
