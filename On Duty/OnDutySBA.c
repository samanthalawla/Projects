#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main();
void SignUp();
void Login();
void Head_Duty();
void Select_Task();
void Pref_Duty();
void Assign_Duty();
void Duty_Checker();
void View_Queries();
void Ask_Volunteer();
void Duty_Desc();
void Volunteer();
void Leave_Queries();
void Teach_Notif();


typedef struct LOGIN{        //declaration of login record
    
    char sfullname [30];
    char fullname [30];
    char spassword [30];
    char password [15];
    char sposition [30];
    char shomeroom [5];
    char homeroom [5];

}LoginInfo;

typedef struct HEADDUTIES{  //declaration of head duty record
    char duty [40];
    char asspref [50];
    char location [20];
    char date [20];
    char time [10];  
}HeadDutyInfo;

typedef struct PREFDUTIES {     //declaration of sub-prefect duty record
    char duty [40];
    char asspref [50];
    char location [20];
    char date [20];
    char time [10];  
}PrefDutyInfo;

typedef struct DUTYDESCS {      //declaration of duty descriptions record
    char name [30];
    char preftype [40];
    char desc [1000];
}DutyDesc;

typedef struct QUERIES {        //declaration of queries record
    char username [30];
    char subject [30];
    char query [200];
}Queries;

typedef struct QUERYRES {       //declaration of query response record
    char username [30];
    char subject [30];
    char response [30];
}Queryres;

typedef struct ASKVOL {         //declaration of ask volunteers record
    char duty [40];
    char location [20];
    char date [20];
    char time [10];
    int prefs;
}AskVol;

typedef struct VOL {            //declaration of volunteers record
    char fullname [30];
    char dutyname [30];
    
}Vol;

void SignUp()
{
    FILE * LOGINPtr;

    LoginInfo logininfo; 

    strcpy(logininfo.sfullname," ");        //intializing user login info
    strcpy(logininfo.fullname, " ");    
    strcpy(logininfo.spassword, " ");
    strcpy(logininfo.password," ");
    strcpy(logininfo.shomeroom, " ");
    strcpy(logininfo.homeroom," ");
    strcpy(logininfo.sposition," ");

    int choice;

    printf("\n");
    printf("*********Sign Up!*********\n");
    
    printf("Please enter your full name. First and last name. (Eg: JaneDoe, or MaryBrown.)\n"); //collecting user info for sign up
    scanf("%s", logininfo.sfullname);
    
    printf("Please enter your homeroom.\n");
    scanf("%s", logininfo.shomeroom);

    printf("Please enter your position.(eg.Head_Girl)\n");
    scanf("%s", logininfo.sposition);
    
    printf("Please create a password. (Maximum 15 characters)\n");
    scanf("%s", logininfo.spassword);

    LOGINPtr = fopen ("UserLoginInfo.txt","a");        //opening and appending to user login info file

        if (LOGINPtr == NULL) 
        {
            printf ("File cannot be opened at this time!\n");
        }
        else
        {
            fprintf (LOGINPtr,"%s\t\t %s\t\t %s\t\t %s\n", logininfo.sfullname, logininfo.shomeroom, logininfo.sposition, logininfo.spassword);
        }

    fclose(LOGINPtr);   //closing of file  


    printf("\n");
    printf("Sign Up Successful!\n");        // sign up confirmation print out
    printf("\n");
    printf ("Enter '0' to Exit or '1' to Login:\n");    // choice to log out or login
    scanf("%d", &choice);


    if (choice == 0)
    {
        printf ("\n");
        printf ("Logged Out!\n");                      // log out operations
        printf("Thank you for using ON DUTY PREFECT SCHEDULER!");
        main();
    }
    else if (choice == 1)
    {
        Login();    //redirecting to login
    }
    else
    {
        printf("Invalid number. Restarting...");  //invalid operation
        main();
    }

    
}

void Login()
{

    FILE * LOGINPtr;    // pointer for login file
    
    LoginInfo logininfo;  

    strcpy(logininfo.sfullname," ");        //intializing user login info
    strcpy(logininfo.fullname, " ");    
    strcpy(logininfo.spassword, " ");
    strcpy(logininfo.password," ");
    strcpy(logininfo.shomeroom, " ");
    strcpy(logininfo.homeroom," ");
    strcpy(logininfo.sposition," ");
    int val, pos;     

    val = 0;        
    pos = 0;
    
    printf("\n");
    printf("*********Login!*********\n");

    printf ("Please enter your full name. First and last name. (Eg: JaneDoe, or MaryBrown.)\n");
    scanf ("%s", logininfo.fullname);                   //collecting user login info

    printf ("Please enter your homeroom.\n");
    scanf ("%s", logininfo.homeroom);

    printf ("Please enter your password:\n");
    scanf ("%s", logininfo.password);

                
    if(strcmp(logininfo.password, "helloworld12")==0 || strcmp(logininfo.password, "yellowflower")==0 || 
    strcmp(logininfo.password, "cocopuffs4")==0 || strcmp(logininfo.password, "77cooltree")==0 || strcmp(logininfo.password, "open3doors")==0
    || strcmp(logininfo.password, "Telephone90")==0 || strcmp(logininfo.password, "pizza1234")==0 || strcmp(logininfo.password, "dynamite678")==0
    || strcmp(logininfo.password, "funhouse#15")==0 || strcmp(logininfo.password, "pillowfight1")==0 
    || strcmp(logininfo.password, "umbrellarain5")==0)      //compaaring passwords to allow login
    {
        printf("\n");
        printf("Successful! Login Almost Complete!\n"); //confirmation of login printout
    }   
    else
    {
        printf("\n");
        printf("Incorrect name, homeroom or password. Please try again.\n");    //incorrect of login information
        Login();
    }



    printf("\n");
    printf ("Please enter the number that corresponds with your position. \n");
    printf ("1 - HEAD GIRL\n");
    printf ("2 - HEAD BOY\n");
    printf ("3 - DEPUTY HEAD GIRL\n");
    printf ("4 - DEPUTY HEAD BOY\n");
    printf ("5 - SENIOR PREFECT\n");         //allows user to select their position in the council for verification
    printf ("6 - PREFECT\n");
    printf ("7 - SUB-PREFECT\n");
    printf ("8 - PREFECT COORDINATOR\n");
    printf ("9 - ADMINISTRATION\n");        
     
    scanf ("%d", &pos);

    LOGINPtr = fopen("UserLoginInfo.txt","r");        //opening and reading user login info file

        if (LOGINPtr == NULL) 
        {
            printf ("File cannot be opened at this time!\n");
        }
        else
        {
            val = fscanf (LOGINPtr,"%s %s %s %s \n", logininfo.sfullname, logininfo.shomeroom, logininfo.sposition, logininfo.spassword); //used to scan through file

            while (val > 0)
            {
                if (pos==1)             //comparing positions to open the correct module
                {
                    if (strcmp(logininfo.sposition, "Head_Girl")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Head_Duty();
                    }
                    
                }     
                else if (pos==2) 
                {
                    if (strcmp(logininfo.sposition, "Head_Boy")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Head_Duty();
                    }
                }
                else if (pos==3) 
                {
                    if (strcmp(logininfo.sposition, "Deputy_Head_Girl")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Head_Duty();
                    }
                    
                }
                else if (pos==4) 
                {
                    if (strcmp(logininfo.sposition, "Deputy_Head_Boy")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Head_Duty();
                    }
                    
                }
                else if (pos==5) 
                {
                    if (strcmp(logininfo.sposition, "Senior_Prefect")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Pref_Duty();
                    }
                    
                }
                else if (pos==6) 
                {
                    if (strcmp(logininfo.sposition, "Prefect")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Pref_Duty();
                    }
                    
                }
                else if (pos==7) 
                {
                    if (strcmp(logininfo.sposition, "Sub_Prefect")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Pref_Duty();
                    }
                    
                }
                else if (pos==8) 
                {
                    if (strcmp(logininfo.sposition, "Prefect_Coordinator")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Head_Duty();
                    }
                    
                }
                else if (pos==9) 
                {
                    if (strcmp(logininfo.sposition, "Administration")==0) 
                    {
                        printf("\n");
                        printf("Successful Login!\n");
                        Teach_Notif();
                    }
                    
                }
                else if (pos != 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9) 
                {
                    printf("\n");
                    printf("Invalid Position Entered. Restarting Login Process.\n");
                    Login();
                }
            
                val = fscanf (LOGINPtr,"%s %s %s %s\n", logininfo.sfullname, logininfo.shomeroom, logininfo.sposition, logininfo.spassword);
            }
            
        }
                        
    fclose(LOGINPtr);       //closing of file

}

void Head_Duty()
{

    // N.B - Module for UPPER COUNCIL (Head Girl/Boy, Deputy Head Girl/Boy, Prefect Coordinator) 

    int task, val;
    task=0;
    val=0;
    char hdisplayname [40];
    char hteachname [40];

    FILE * LOGINPtr;

    LoginInfo logininfo;  

    strcpy(logininfo.sfullname," ");        //intializing user login info
    strcpy(logininfo.fullname, " ");    
    strcpy(logininfo.spassword, " ");
    strcpy(logininfo.password," ");
    strcpy(logininfo.shomeroom, " ");
    strcpy(logininfo.homeroom," ");
    strcpy(logininfo.sposition," ");

    FILE * HEADDUTIESPtr;

    HeadDutyInfo headdutyinfo;         
          
    strcpy(headdutyinfo.duty, " ");    //intializing head duty info
    strcpy(headdutyinfo.asspref," ");
    strcpy(headdutyinfo.location, " ");
    strcpy(headdutyinfo.date," ");
    strcpy(headdutyinfo.time," ");

    printf("\n");
    printf("Please re-enter your full name:\n");    //collecting name to compare to duties file and display
    scanf("%s", hdisplayname);

    printf("\n");
    printf("Welcome, %s !\n", hdisplayname);        //dispalying user's name
    
    printf("\n");
    printf("The following table shows your current duties.\n");
    printf("\n");
    printf("*************************************************************************************************************\n");
    printf("Duty\t\t\t\t Prefects\t\t  Location\t\t Date\t\t  Time\t\t \n");  //TABLE HEADINGS
    printf("*************************************************************************************************************\n");


    HEADDUTIESPtr = fopen("HeadDuties.txt", "r");        //opening and reading duties file

        if (HEADDUTIESPtr == NULL) 
        {

            printf("Table unable to be shown. No duties found.\n");
            
        }
        else
        {

            val = fscanf (HEADDUTIESPtr,"%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  //determines that lines of file 

            while(val > 0)  //used to scan through file
            {

                if (strcmp(headdutyinfo.asspref,"MaryBrown")==0 && strcmp(hdisplayname,"MaryBrown")==0 
                || strcmp(headdutyinfo.asspref,"Entire_council")==0 ) //comparisons to print duties for user
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  //duty printout
                }
                else if (strcmp(headdutyinfo.asspref,"TaviaJones")==0 && strcmp(hdisplayname,"TaviaJones")==0 || strcmp(headdutyinfo.asspref,"Entire_council")==0)
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  
                }
                else if (strcmp(headdutyinfo.asspref,"JasonMyers")==0 && strcmp(hdisplayname,"JasonMyers")==0 || strcmp(headdutyinfo.asspref,"Entire_council")==0)
                {
                    
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  
                
                }
                else if (strcmp(headdutyinfo.asspref,"TylerWilliams")==0 && strcmp(hdisplayname,"TylerWilliams")==0 || strcmp(headdutyinfo.asspref,"Entire_council")==0)
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  
                } 
                else if (strcmp(headdutyinfo.asspref,"MarkChoi")==0 && strcmp(hdisplayname,"MarkChoi")==0 || strcmp(headdutyinfo.asspref,"Entire_council")==0)
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  
                } 


                val = fscanf (HEADDUTIESPtr,"%s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty, headdutyinfo.asspref,headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);  

            }
            
                
        }

    fclose(HEADDUTIESPtr);  //closing file
            

    printf("*********************************************************************************************************\n");
    printf("\n");
    printf("ENTER 1 - To notify your teacher of your duties \n");
    printf("ENTER 2 - To set duty reminders \n");                   //menu for actions
    printf("ENTER 3 - To perform a task \n");
    printf("ENTER 4 - To exit \n");
    scanf ("%d", &task);

    if (task==1) {

        printf("Please enter your teacher's full name:");
        scanf ("%s", hteachname);           //collects teacher's name
        printf ("Notified Teacher!\n");     //notified teacher confimation printout
        Head_Duty();
   
    }
    else if (task == 2)
    {
        printf ("Reminders Set!\n");        //reminders set confirmation printout
        Head_Duty();
    }
    else if (task == 3)
    {
        Select_Task();          //directs to selecting task options
        
    }
    else if (task == 4)
    {
        printf ("\n");
        printf ("Logged Out!\n");           // logs out user
        printf("Thank you for using ON DUTY PREFECT SCHEDULER!");
        main();         //return to starting screen
    }
    else {
        printf("\n");
        printf("Invalid number entered.\n");        //invalid operation
        Head_Duty();
    }

}

void Select_Task()
{

    int stask;
    stask=0;
    
    printf("\n");
    printf("***************************************************************\n");
    printf ("Please enter the number of the task you would to perform:\n");
    printf ("1 - Assign Duty/Meeting\n");
    printf ("2 - Duty Checker\n");
    printf ("3 - View Queries\n");              //menu for actions
    printf ("4 - Ask for Volunteers\n");
    printf ("5 - Return to Home\n");
    printf("***************************************************************\n");
    scanf ("%d", &stask);

    int t;
    t = stask;

    switch (t)      //directs user to selected module
    {
        case 1:
            Assign_Duty(); 
        break;
        case 2:
            Duty_Checker();
        break;
        case 3:
            View_Queries();
        break;
        case 4:
            Ask_Volunteer();
        break;
        case 5:
            Head_Duty();
        default:
            printf("\n");
            printf("Please enter a valid number.\n");       //invalid operation
            Select_Task();

    }

}

void Pref_Duty()
{
    // N.B - Module for LOWER COUNCIL (Senior Prefects, Sub-Prefects, Prefect)

    FILE * LOGINPtr;

    LoginInfo logininfo;  

    strcpy(logininfo.sfullname," ");        //intializing user login info
    strcpy(logininfo.fullname, " ");    
    strcpy(logininfo.spassword, " ");
    strcpy(logininfo.password," ");
    strcpy(logininfo.shomeroom, " ");
    strcpy(logininfo.homeroom," ");
    strcpy(logininfo.sposition," ");

    FILE * PREFDUTIESPtr;

    PrefDutyInfo prefdutyinfo;
            
    strcpy(prefdutyinfo.duty, " ");         //intializing prefect duty info
    strcpy(prefdutyinfo.asspref," ");
    strcpy(prefdutyinfo.location, " ");
    strcpy(prefdutyinfo.date," ");
    strcpy(prefdutyinfo.time," ");

    int ptask, val;

    ptask=0;
    val = 0;                    //intialization of variables
    char pdisplayname [40];
    char pteachname [40];

    printf("\n");
    printf("Please re-enter your full name:\n");
    scanf("%s", pdisplayname);      //collecting name to compare to duties file and display

    printf("\n");
    printf("Welcome, %s !\n", pdisplayname); //dispalying user's name
    

    printf("\n");
    printf("The following table shows your current duties.\n");
    printf("\n");
    printf("*************************************************************************************************************\n");
    printf("Duty\t\t Prefects\t\t  Location\t\t Date\t\t  Time\t\t \n");  //TABLE HEADINGS
    printf("*************************************************************************************************************\n");

    PREFDUTIESPtr = fopen("PrefectDuties.txt", "r");        //opening and reading duties file
    
        if (PREFDUTIESPtr == NULL) 
        {
            printf("Table unable to be shown. No duties found.\n");
        }
        else
        {
           val = fscanf (PREFDUTIESPtr,"%s\t\t %s\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty, prefdutyinfo.asspref, 
           prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);  //determines that lines of file 

            while(val > 0)  //used to scan through file
            {

                if (strcmp(prefdutyinfo.asspref,"SashaHills")==0 && strcmp(pdisplayname,"SashaHills")==0 
                || strcmp(prefdutyinfo.asspref,"Entire_council")==0 )   //comparisons to print duties for user
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty, prefdutyinfo.asspref, 
                    prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);   //duty printout
                }
                else if (strcmp(prefdutyinfo.asspref,"YelenaAnwell")==0 && strcmp(pdisplayname,"YelenaAnwell")==0 
                || strcmp(prefdutyinfo.asspref,"Entire_council")==0)
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty, prefdutyinfo.asspref, 
                    prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);  
                }
                else if (strcmp(prefdutyinfo.asspref,"EricKnight")==0 && strcmp(pdisplayname,"EricKnight")==0 
                || strcmp(prefdutyinfo.asspref,"Entire_council")==0)
                {    
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty, prefdutyinfo.asspref, 
                    prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);  
                }
                else if (strcmp(prefdutyinfo.asspref,"KaiPowell")==0 && strcmp(pdisplayname,"KaiPowell")==0 
                || strcmp(prefdutyinfo.asspref,"Entire_council")==0)
                {
                    printf ("%s\t\t %s\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty, prefdutyinfo.asspref, 
                    prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);  
                } 

                val = fscanf (PREFDUTIESPtr,"%s\t\t %s\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty, prefdutyinfo.asspref, 
                prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);  

            }
        }

    fclose(PREFDUTIESPtr);  //closing file



    printf("***********************************************************************************************************************************************\n");
    printf("\n");
    printf ("Please enter the number of the task you would like to perform:\n");        //menu for actions
    printf ("1 - Notify your teacher of your duties \n");
    printf ("2 - Set duty reminders \n");
    printf ("3 - Volunteer for Duty\n");
    printf ("4 - Leave Queries\n");
    printf ("5 - View description of an active duty\n");
    printf ("6 - Exit\n");
    scanf ("%d", &ptask);       //collects choice number

    int a;
    a = ptask;

    switch (a)
    {
        case 1:
            printf("Please enter your teacher's full name:");
            scanf ("%s", pteachname);           //collects teacher's name
            printf ("Notified Teacher!\n");     //notified teacher confimation printout
            Pref_Duty();

        break;
        case 2:
            printf ("Reminders Set!\n");        //reminders set confirmation printout
            Pref_Duty();
        break;
        case 3:
            Volunteer();            //directs to volunteer module
        break;
        case 4:
            Leave_Queries();        //directs to leave querie module
        break;
        case 5:
            Duty_Desc();        //directs to duty descriptions module
        break;
        case 6:
            printf ("\n");
            printf ("Logged Out!\n");       // logs out
            printf("Thank you for using ON DUTY PREFECT SCHEDULER!");
            main();
        default:
            printf("\n");
            printf("Please enter a valid number.");     //invalid operation
            Pref_Duty();

    }

}

void Volunteer()
{
    int num, val;
    char line[1000];

    val=0;
    num=0;

    FILE * ASKVOLPtr;

    AskVol askvol;

    askvol.prefs = 0;
    strcpy(askvol.duty, " ");
    strcpy(askvol.location, " ");
    strcpy(askvol.date, " ");
    strcpy(askvol.time, " ");


    printf("\n");
    printf("Now showing all Volunteer Oppourtunites\n");
    printf("\n");
    printf("*************************************************************************************************************\n");
    printf("Duty\t\t  Location\t\t Date\t\t  Time\t\t # of Volunteers\t\t\n");  //TABLE HEADINGS
    printf("*************************************************************************************************************\n");

    ASKVOLPtr = fopen("VolunteerDuties.txt", "r");        //opening and reading duties file
    
        if (ASKVOLPtr == NULL) 
        {
            printf("\n");
            printf("Table unable to be shown. No volunteer opportunities found.\n");
        }
        else
        {
            while (fgets(line, 1000, ASKVOLPtr))        //prints lines of file
            {   
                printf(line);
                printf("\n");
               
            }

        }

    fclose(ASKVOLPtr);

    printf("\n");
    printf("***********************************************************\n");
    printf("Would you like to volunteer for any oppourtunities listed?\n");
    printf("1 - Volunteer\n");              //menu actions
    printf("2 - Return to Home\n");
    printf("***********************************************************\n");
    scanf("%d", &num);

    if (num==1)
    {
        
        FILE * VOLPtr;

        Vol vol;         

        strcpy(vol.dutyname," ");          //intializing query response info
        strcpy(vol.fullname, " ");    


        printf("\n");
        printf("Please enter your full name.\n");
        scanf("%s", vol.fullname);
        printf("Please enter the volunteer opportunity you wish to sign up for.\n");
        scanf("%s", vol.dutyname); 
    

        VOLPtr = fopen ("Volunteers.txt", "a");     //opening and writing inputted info to volunteers file

            if(VOLPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(VOLPtr,"%s\t\t %s\n", vol.dutyname, vol.fullname);
            }

        fclose(VOLPtr); 

        printf("\n");
        printf("Thank you for volunteering!\n");

        Volunteer();
    }
    else if (num==2) 
    {
        FILE * LOGINPtr;

        LoginInfo logininfo;  

        strcpy(logininfo.sfullname," ");        //intializing user login info
        strcpy(logininfo.fullname, " ");    
        strcpy(logininfo.spassword, " ");
        strcpy(logininfo.password," ");
        strcpy(logininfo.shomeroom, " ");
        strcpy(logininfo.homeroom," ");
        strcpy(logininfo.sposition," ");   

        LOGINPtr = fopen("UserLoginInfo.txt","r");        //opening and reading user login info file

            if (LOGINPtr == NULL) 
            {
                printf ("File cannot be opened at this time!\n");
            }
            else
            {

                if (strcmp(logininfo.sposition, "Head_Girl")==0)   //comparing saved login info to send the user to the correct home page
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Head_Boy")==0)  
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Deputy_Head_Girl")==0)  
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Deputy_Head_Boy")==0)   
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Prefect_Coordinator")==0)   
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Senior_Prefect")==0)    
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Prefect")==0)
                {
                    Pref_Duty();
                }
                else if (strcmp(logininfo.sposition, "Sub_Prefect")==0)
                {
                    Pref_Duty();
                }

            }

        fclose(LOGINPtr);       //closing file
    }
    

}

void Leave_Queries()
{
    int num, val;
    char line[1000];        //declaration of variables

    num=0;              //intialization of variables
    val=0;

    printf("\n");
    printf("***************************************************\n");
    printf("What would you like to do?\n");                                 //menu actions
    printf("1 - Create a query\n");
    printf("2 - Check for a response for preivous queries\n");
    printf("3 - Return to Home\n");
    printf("***************************************************\n");
    scanf("%d", &num);


    if (num==1)
    {

        FILE * QUERIESPtr; 

        Queries queries;         

        strcpy(queries.username," ");    //intializing query info
        strcpy(queries.subject, " ");    
        strcpy(queries.query," ");


            
        printf("\n");
        printf("Please enter your full name\n");            //collecting information for queries
        scanf("%s", queries.username);
        printf("Please enter the subject of the query you wish to make\n");
        scanf("%s", queries.subject);
        printf("Please enter the query (Use underscores '_' to replace spaces)\n");
        scanf("%s", queries.query); 
            
        QUERIESPtr = fopen ("Queries.txt", "a");     //opening and writing inputted info to head duties file

            if(QUERIESPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(QUERIESPtr,"%s\t\t %s\t\t\t %s\n", queries.username, queries.subject, queries.query);
            }

        fclose(QUERIESPtr); 

        printf("\n");
        printf("Query Submitted!\n");       // confirmation print out of query
        Leave_Queries();

    }
    else if (num==2)
    {   
        printf("\n");
        printf("Now showing all responses to previous queries\n");
        printf("*************************************************************************************************************\n");
        printf("Name\t\t  Subject\t\t Responses\t\t \n");  //TABLE HEADINGS
        printf("*************************************************************************************************************\n");
        
        FILE * QUERYRESPtr;

        QUERYRESPtr = fopen("QueryResponses.txt", "r");        //opening and reading query responses file

            if (QUERYRESPtr == NULL) 
            {
                printf("\n");
                printf("Table unable to be shown. No reponses to queries found.\n");
            }
            else
            {
                while (fgets(line, 1000, QUERYRESPtr))
                {   
                    printf(line);       //prints lines of file
                
                }
            }

        fclose(QUERYRESPtr);    //closing file
        
        printf("*************************************************************************************************************\n");
        Leave_Queries();    

    }
    else if (num==3)
    {
        FILE * LOGINPtr;

        LoginInfo logininfo;  

        strcpy(logininfo.sfullname," ");        //intializing user login info
        strcpy(logininfo.fullname, " ");    
        strcpy(logininfo.spassword, " ");
        strcpy(logininfo.password," ");
        strcpy(logininfo.shomeroom, " ");
        strcpy(logininfo.homeroom," ");
        strcpy(logininfo.sposition," ");

        LOGINPtr = fopen("UserLoginInfo.txt","r");        //opening and reading user login info file

            if (LOGINPtr == NULL) 
            {
                printf ("File cannot be opened at this time!\n");
            }
            else
            {
                val = fscanf (LOGINPtr,"%s\t\t %s\t\t %s\t\t %s\n", logininfo.sfullname, logininfo.shomeroom, 
                logininfo.sposition, logininfo.spassword);

                while (val > 0)
                {
                    if (strcmp(logininfo.sposition, "Senior_Prefect")==0)   //comparing saved login info to send tthe user to the correct home page
                    {
                        Pref_Duty();
                    }
                    else if (strcmp(logininfo.sposition, "Prefect")==0)
                    {
                        Pref_Duty();
                    }
                    else if (strcmp(logininfo.sposition, "Sub_Prefect")==0)
                    {
                        Pref_Duty();
                    }

                    val = fscanf (LOGINPtr,"%s\t\t %s\t\t %s\t\t %s\n", logininfo.sfullname, logininfo.shomeroom, 
                    logininfo.sposition, logininfo.spassword);

                }
            }

        fclose(LOGINPtr);   //closing file 
    }

}
 
void Assign_Duty()
{

    int group;
    group=0;
    
    printf("\n");
    printf("Firstly, which group(s) do you wish to assign a duty/meeting for?\n");
    printf("1 - Head and Deputy Head Girls/Boys\n");
    printf("2 - Senior Prefects, Prefects & Sub-Prefects\n");
    printf("3 - Entire council\n");
    scanf("%d", &group);                            // specifying group to assign duties


    if (group==1)
    {
        char temp;

        FILE * HEADDUTIESPtr; 

        HeadDutyInfo headdutyinfo;         
          
        strcpy(headdutyinfo.duty, " ");             //intializing head duty info
        strcpy(headdutyinfo.asspref," ");
        strcpy(headdutyinfo.location, " ");
        strcpy(headdutyinfo.date," ");
        strcpy(headdutyinfo.time," ");

        printf("\n");
        printf("Please enter the duty\n");                      //collecting duty information
        scanf("%s", headdutyinfo.duty); 
        printf("Please enter the prefects for this duty\n");
        scanf("%s", headdutyinfo.asspref);
        printf("Please enter the location of the duty\n");
        scanf("%s", headdutyinfo.location);
        printf("Please enter the date this duty should occur\n");
        scanf("%s", headdutyinfo.date);
        printf("Please enter the time the duty should occur\n");
        scanf("%s", headdutyinfo.time);


        HEADDUTIESPtr = fopen ("HeadDuties.txt", "a");     //opening and writing inputted info to head duties file

            if(HEADDUTIESPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(HEADDUTIESPtr," %s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty,  headdutyinfo.asspref, headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);
            }

        fclose(HEADDUTIESPtr); 


        FILE * DUTYDESCSPtr;

        DutyDesc dutydesc;

        strcpy(dutydesc.name, " ");    //initializing the duty description file info
        strcpy(dutydesc.preftype, " ");
        strcpy(dutydesc.desc, " ");
        
        printf("\n");
        printf("Lastly, please re-enter the name of the duty, and create a description of what it will entail\n");     //creating a duty description
        printf("Name:");
        scanf("%s", dutydesc.name);
        strcpy(dutydesc.preftype, "(Head & Deputy Head Girls/Boys)");
        printf("Description:");
        scanf("%s", dutydesc.desc);

        

        DUTYDESCSPtr = fopen ("DutyDescriptions.txt", "a");     //opening and writing inputted info to head duties file
    
            if(DUTYDESCSPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(DUTYDESCSPtr,"%s\t\t %s\t\t %s\n", dutydesc.name, dutydesc.preftype, dutydesc.desc);
            }

        fclose(DUTYDESCSPtr);       //closing file

        printf("\n");
        printf("New Duty Added to Head and Deputy Head Girls/Boys File: %s\n", headdutyinfo.duty);      //displaying the duty added to the file
        printf("\n");

        Select_Task();

    }
    else if (group==2)
    {
        
        FILE * PREFDUTIESPtr;

        PrefDutyInfo prefdutyinfo;
            
        strcpy(prefdutyinfo.duty, " ");         //intializing prefect duty info
        strcpy(prefdutyinfo.asspref," ");
        strcpy(prefdutyinfo.location, " ");
        strcpy(prefdutyinfo.date," ");
        strcpy(prefdutyinfo.time," ");

        printf("\n");
        printf("Please enter the duty\n");                          //collecting duty information
        scanf("%s", prefdutyinfo.duty);
        printf("Please enter the prefects for this duty\n");
        scanf("%s", prefdutyinfo.asspref);
        printf("Please enter the location of the duty\n");
        scanf("%s", prefdutyinfo.location);
        printf("Please enter the date this duty should occur\n");
        scanf("%s", prefdutyinfo.date);
        printf("Please enter the time the duty should occur\n");
        scanf("%s", prefdutyinfo.time);


        PREFDUTIESPtr = fopen ("PrefectDuties.txt", "a");     //opening and writing inputted info to prefect duties file

            if(PREFDUTIESPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(PREFDUTIESPtr,"%s\t\t %s\t\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty,  prefdutyinfo.asspref, prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);
            }

        fclose(PREFDUTIESPtr); 



        FILE * DUTYDESCSPtr;

        DutyDesc dutydesc;

        strcpy(dutydesc.name, " ");    //initializing the duty description file info
        strcpy(dutydesc.preftype, " ");
        strcpy(dutydesc.desc, " ");

        printf("\n");
        printf("Lastly, please re-enter the name of the duty, and create a description of what it will entail\n");
        printf("Name:");                    // collecting information 
        scanf("%s", dutydesc.name);
        printf("Description:");
        scanf("%s", dutydesc.desc);

        strcpy(dutydesc.preftype,"(Prefects)");

            DUTYDESCSPtr = fopen ("DutyDescriptions.txt", "a");     //opening and writing inputted info to head duties file
        
                if(DUTYDESCSPtr == NULL) 
                    printf("File cannot be opened at this time.\n");
                else
                {
                    fprintf(DUTYDESCSPtr,"%s\t\t %s\t\t %s\n", dutydesc.name, dutydesc.preftype, dutydesc.desc);
                }

            fclose(DUTYDESCSPtr);       // closing file

        printf("\n");
        printf("New Duty Added to Senior Prefects, Prefect & Sub Prefect File: %s", prefdutyinfo.duty); //displaying the duty added to the file
        printf("\n");

        Select_Task();      //directing to selection module
    }
    else if (group==3)
    {

        FILE * PREFDUTIESPtr;

        PrefDutyInfo prefdutyinfo;
            
        strcpy(prefdutyinfo.duty, " ");         //intializing prefect duty info
        strcpy(prefdutyinfo.asspref," ");
        strcpy(prefdutyinfo.location, " ");
        strcpy(prefdutyinfo.date," ");
        strcpy(prefdutyinfo.time," ");

        FILE * HEADDUTIESPtr; 

        HeadDutyInfo headdutyinfo;         
          
        strcpy(headdutyinfo.duty, " ");         //intializing head duty info
        strcpy(headdutyinfo.asspref," ");
        strcpy(headdutyinfo.location, " ");
        strcpy(headdutyinfo.date," ");
        strcpy(headdutyinfo.time," ");
        
        printf("\n");
        printf("ASSIGNING TO SENIOR PREFECTS, PREFECTS & SUB PREFECTS\n");
        printf("-------------------------------------------------------\n");
        printf("Please enter the duty\n");              //collecting duty to add to file
        scanf("%s", prefdutyinfo.duty);
        printf("Please enter the prefects for this duty = (Entire_council)\n");
        scanf("%s", prefdutyinfo.asspref);
        printf("Please enter the location of the duty\n");
        scanf("%s", prefdutyinfo.location);
        printf("Please enter the date this duty should occur\n");
        scanf("%s", prefdutyinfo.date);
        printf("Please enter the time the duty should occur\n");
        scanf("%s", prefdutyinfo.time);


        PREFDUTIESPtr = fopen ("PrefectDuties.txt", "a");     //opening and writing inputted info to prefect duties file

            if(PREFDUTIESPtr == NULL)
            {
                printf("File cannot be opened at this time.\n");
            }        
            else
            {
                fprintf(PREFDUTIESPtr," %s\t\t %s\t\t\t %s\t\t %s\t\t %s\n", prefdutyinfo.duty,  prefdutyinfo.asspref, prefdutyinfo.location, prefdutyinfo.date, prefdutyinfo.time);
            }       

        fclose(PREFDUTIESPtr);      //closing file

        printf("\n");
        printf("ASSIGNING TO HEAD AND DEPUTY HEAD GIRLS/BOYS\n");
        printf("-------------------------------------------------------\n");
        printf("Please re-enter the duty\n");                //collecting duty again to add to file
        scanf("%s", headdutyinfo.duty);
        printf("Please re-enter the prefects for this duty = (Entire_council)\n");
        scanf("%s", headdutyinfo.asspref);
        printf("Please re-enter the location of the duty\n");
        scanf("%s", headdutyinfo.location);
        printf("Please re-enter the date this duty should occur\n");
        scanf("%s", headdutyinfo.date);
        printf("Please re-enter the time the duty should occur\n");
        scanf("%s", headdutyinfo.time);

        HEADDUTIESPtr = fopen ("HeadDuties.txt", "a");     //opening and writing inputted info to head duties file

            if(HEADDUTIESPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(HEADDUTIESPtr," %s\t\t %s\t\t %s\t\t %s\t\t %s\n", headdutyinfo.duty,  headdutyinfo.asspref, headdutyinfo.location, headdutyinfo.date, headdutyinfo.time);
            }
            
        fclose(HEADDUTIESPtr);  //closing file


        FILE * DUTYDESCSPtr;

        DutyDesc dutydesc;

        strcpy(dutydesc.name, " ");    //initializing the duty description file info
        strcpy(dutydesc.preftype, " ");
        strcpy(dutydesc.desc, " ");

        printf("\n");
        printf("Lastly, please re-enter the name of the duty, and create a description of what it will entail\n");
        printf("Name:");                //collecting information for duty description
        scanf("%s", dutydesc.name);
        printf("Description:");
        scanf("%s", dutydesc.desc);

        strcpy(dutydesc.preftype,"(Entire Council)");

            DUTYDESCSPtr = fopen ("DutyDescriptions.txt", "a");     //opening and writing inputted info to head duties file
        
                if(DUTYDESCSPtr == NULL) 
                    printf("File cannot be opened at this time.\n");
                else
                {
                fprintf(DUTYDESCSPtr,"%s\t\t %s\t\t %s\n", dutydesc.name, dutydesc.preftype, dutydesc.desc);
                }

            fclose(DUTYDESCSPtr); //closing file

        printf("\n");
        printf("New Duty Added to Files of all Council Members %s", prefdutyinfo.duty); //displaying the duty added to the file
        printf("\n");

        Select_Task();      //directing to task selection module

    }
    

}

void View_Queries()
{

    int num, val;
    char line[1000];    //declaration of variables

    val=0;
    num=0;      //intialization of variables

    printf("\n");
    printf("Now showing all Queries\n");
    printf("*************************************************************************************************************\n");
    printf("Full Name\t\t  Subject\t\t Queries\t\t \n");  
    printf("*************************************************************************************************************\n");

    FILE * QUERIESPtr;

    QUERIESPtr = fopen("Queries.txt", "r");        //opening and reading duties file
    
        if (QUERIESPtr == NULL) 
        {
            printf("\n");
            printf("Table unable to be shown. No queries found.\n");
        }
        else
        {
            while (fgets(line, 1000, QUERIESPtr))
            {   
                printf(line);       //prints lines of file
                printf("\n");
               
            }

        }

    fclose(QUERIESPtr);

    printf("****************************************************************************************************************************\n");
    printf("\n");
    printf("***********************************************************\n");
    printf("Would you like to respond to any of the queries listed?\n");
    printf("1 - Respond to a Query\n");     //menu for actions
    printf("2 - Return to Home\n");
    printf("***********************************************************\n");
    scanf("%d", &num);

    if (num==1)
    {
        
        FILE * QUERYRESPtr;

        Queryres queryres;         

        strcpy(queryres.username," ");          //intializing query response info
        strcpy(queryres.subject, " ");    
        strcpy(queryres.response," ");


        printf("\n");
        printf("Please enter your name\n");     //collecting query info
        scanf("%s", queryres.username);
        printf("Please enter the subject of the query you wish to respond to\n");
        scanf("%s", queryres.subject);
        printf("Please enter the query response\n");
        scanf("%s", queryres.response); 
    

        QUERYRESPtr = fopen ("QueryResponses.txt", "a");     //opening and writing inputted info to head duties file

            if(QUERYRESPtr == NULL) 
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(QUERYRESPtr,"%s\t\t %s\t\t\t %s\n", queryres.username, queryres.subject, queryres.response);
            }

        fclose(QUERYRESPtr); // closing file

        View_Queries();
    }
    else if (num==2) 
    {
        Head_Duty();        //directs to head prefect council members' module
    }
    else if (num != 1 || 2)
    {
        printf("\n");
        printf("Invalid number entered.\n");        //invalid operation
        View_Queries();
    }


}

void Ask_Volunteer()
{
    
    FILE * ASKVOLPtr;

    AskVol askvol;

    
    strcpy(askvol.duty, " ");
    strcpy(askvol.location, " ");
    strcpy(askvol.date, " ");
    strcpy(askvol.time, " ");
    askvol.prefs = 0;

    printf("\n");
    printf("Please enter the duty\n");              //collects info for volunteer duty
    scanf("%s", askvol.duty); 
    printf("Please enter the location of the duty\n");
    scanf("%s", askvol.location);
    printf("Please enter the date this duty should occur\n");
    scanf("%s", askvol.date);
    printf("Please enter the time the duty should occur\n");
    scanf("%s", askvol.time);
    printf("Please enter the number of prefects for this duty\n");
    scanf("%d", &askvol.prefs);

    ASKVOLPtr = fopen ("VolunteerDuties.txt", "a");     //opening and writing inputted info to head duties file
        
        if(ASKVOLPtr == NULL) 
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(ASKVOLPtr," %s\t\t %s\t\t %s\t\t %d\n", askvol.duty, askvol.location, askvol.date, askvol.time, &askvol.prefs);    
        }

    fclose(ASKVOLPtr); // closing file

    printf("\n");
    printf("Volunteer Duty Uploaded!\n");       //confirmation printout for volunteer
    Select_Task();          //directing to task selection module 

}

void Duty_Checker()
{

    FILE * HEADDUTIESPtr;

    HeadDutyInfo headdutyinfo;         
          
    strcpy(headdutyinfo.duty, " ");         //intializing head duty info
    strcpy(headdutyinfo.asspref," ");
    strcpy(headdutyinfo.location, " ");
    strcpy(headdutyinfo.date," ");
    strcpy(headdutyinfo.time," ");

    FILE * PREFDUTIESPtr;

    PrefDutyInfo prefdutyinfo;

    strcpy(prefdutyinfo.duty, " ");         //intializing prefect duty info
    strcpy(prefdutyinfo.asspref," ");
    strcpy(prefdutyinfo.location, " ");
    strcpy(prefdutyinfo.date," ");
    strcpy(prefdutyinfo.time," ");

    int num, val;           //declaration of variable 
    char line[1000];

    num=0;          //intialization of variable
    val = 0;

    printf("\n");
    printf("Now showing all active duties\n");
    printf("*************************************************************************************************************\n");
    printf("Duty\t\t\t Prefects\t\t  Location\t\t Date\t\t  Time\t\t \n");  //TABLE HEADINGS
    printf("*************************************************************************************************************\n");

    HEADDUTIESPtr = fopen("HeadDuties.txt", "r");        //opening and reading duties file

        if (HEADDUTIESPtr == NULL) 
        {

            printf("Table unable to be shown. No duties found.\n");
            
        }
        else
        {
            while (fgets(line, 1000, HEADDUTIESPtr))
            {                
                printf(line);      
            }

        }

    fclose(HEADDUTIESPtr);      // closing file

        
    PREFDUTIESPtr = fopen("PrefectDuties.txt", "r");        //opening and reading duties file
    
        if (PREFDUTIESPtr == NULL) 
        {
            printf("Table unable to be shown. No duties found.\n");
        }
        else
        {
            while (fgets(line, 1000, PREFDUTIESPtr))
            {   
                printf(line);          
            
            }

        }

    fclose(PREFDUTIESPtr);      //closing file

    printf("*********************************************************************************************************\n");
    printf("\n");
    printf("Press 1 to return Home\n");         
    scanf("%d", &num);                          //collecting data 

    if (num == 1)
    {
        FILE * LOGINPtr;

        LoginInfo logininfo;  

        strcpy(logininfo.sfullname," ");        //intializing user login info
        strcpy(logininfo.fullname, " ");    
        strcpy(logininfo.spassword, " ");
        strcpy(logininfo.password," ");
        strcpy(logininfo.shomeroom, " ");
        strcpy(logininfo.homeroom," ");
        strcpy(logininfo.sposition," ");   

        LOGINPtr = fopen("UserLoginInfo.txt","r");        //opening and reading user login info file

        if (LOGINPtr == NULL) 
        {
            printf ("File cannot be opened at this time!\n");
        }
        else
        {
            val = fscanf (LOGINPtr,"%s\t\t %s\t\t %s\t\t %s\t\t %s\n", logininfo.sfullname, logininfo.shomeroom, logininfo.sposition, logininfo.spassword);  //determines lines of file

            while (val > 0)  //used to scan through file     
            {
                if (strcmp(logininfo.sposition, "Head_Girl")==0)   //comparing saved login info to send the user to the correct home page
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Head_Boy")==0)  
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Deputy_Head_Girl")==0)  
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Deputy_Head_Boy")==0)   
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Prefect_Coordinator")==0)   
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Senior_Prefect")==0)    
                {
                    Head_Duty();
                }
                else if (strcmp(logininfo.sposition, "Prefect")==0)
                {
                    Pref_Duty();
                }
                else if (strcmp(logininfo.sposition, "Sub_Prefect")==0)
                {
                    Pref_Duty();
                }

            }
        }

        fclose(LOGINPtr);       //closing file
    }
    else 
    {
        printf("\n");
        printf("Invalid number entered\n");     //invalid operation
        Duty_Checker();         // directing to duty checker module

    }

}

void Duty_Desc()
{
    int num, val, count;        //declaration of variables

    num=0;
    val=0;          //intialization of variables
    count=0;


    printf("\n");
    printf("Now showing name, prefect type, and description for all active duties\n");
    printf("************************************************************************************************************\n");
     printf("Full Name\t\t\t  Prefect Type\t\t Duty Decsription\n");  
    printf("*************************************************************************************************************\n");

    FILE * DUTYDESCSPtr;

    DutyDesc dutydesc;

    strcpy(dutydesc.name, " ");    //initializing the duty description file info
    strcpy(dutydesc.preftype, " ");
    strcpy(dutydesc.desc, " ");
        

    DUTYDESCSPtr = fopen("DutyDescriptions.txt", "r");        //opening and reading duties file
    
        if (DUTYDESCSPtr == NULL) 
        {
            printf("Table unable to be shown. No duties found.\n");
        }
        else
        {
            
            val = fscanf (DUTYDESCSPtr,"%s\t\t %s\t\t %s\n", dutydesc.name, dutydesc.preftype, dutydesc.desc);  //determines lines of file

            while(val > 0)  //used to scan through file
            {
                if (strcmp(dutydesc.preftype,"(Prefects)")==0)
                {
                    printf("%s\t\t %s\t\t %s\n", dutydesc.name, dutydesc.preftype, dutydesc.desc);      //prints lines from file
                }

                val = fscanf (DUTYDESCSPtr,"%s\t\t %s\t\t %s\n", dutydesc.name, dutydesc.preftype, dutydesc.desc); 

            }

        }

    fclose(DUTYDESCSPtr);     //closing the file


    printf("*****************************************************************\n");
    printf("\n");
    printf ("Press 1 to return Home\n");            
    scanf("%d", &num);          //choice for returning to prefect duty module

    if (num==1)
    {
        FILE * LOGINPtr;

        LoginInfo logininfo;  

        strcpy(logininfo.sfullname," ");        //intializing user login info
        strcpy(logininfo.fullname, " ");    
        strcpy(logininfo.spassword, " ");
        strcpy(logininfo.password," ");
        strcpy(logininfo.shomeroom, " ");
        strcpy(logininfo.homeroom," ");
        strcpy(logininfo.sposition," ");

        LOGINPtr = fopen("UserLoginInfo.txt","r");        //opening and reading user login info file

        if (LOGINPtr == NULL) 
        {
            printf ("File cannot be opened at this time!\n");
        }
        else
        {

            
            if (strcmp(logininfo.sposition, "Head_Girl")==0)   //comparing saved login info to send the user to the correct home page
            {
                Head_Duty();
            }
            else if (strcmp(logininfo.sposition, "Head_Boy")==0)  
            {
                Head_Duty();
            }
            else if (strcmp(logininfo.sposition, "Deputy_Head_Girl")==0)  
            {
                Head_Duty();
            }
            else if (strcmp(logininfo.sposition, "Deputy_Head_Boy")==0)   
            {
                Head_Duty();
            }
            else if (strcmp(logininfo.sposition, "Prefect_Coordinator")==0)   
            {
                Head_Duty();
            }
            else if (strcmp(logininfo.sposition, "Senior_Prefect")==0)    
            {
                Pref_Duty();
            }
            else if (strcmp(logininfo.sposition, "Prefect")==0)
            {
                Pref_Duty();
            }
            else if (strcmp(logininfo.sposition, "Sub_Prefect")==0)
            {
                Pref_Duty();
            }

        }

        fclose(LOGINPtr);       //closing file
    }
    else 
    {
        printf("\n");
        printf("Invalid Number Entered.\n");        //invalid operation
        Duty_Desc();                //directing to duty description module
    }

}

void Teach_Notif()
{

    FILE * HEADDUTIESPtr;

    HeadDutyInfo headdutyinfo;         
          
    strcpy(headdutyinfo.duty, " ");         //intializing head duty info
    strcpy(headdutyinfo.asspref," ");
    strcpy(headdutyinfo.location, " ");
    strcpy(headdutyinfo.date," ");
    strcpy(headdutyinfo.time," ");

    FILE * PREFDUTIESPtr;

    PrefDutyInfo prefdutyinfo;

    strcpy(prefdutyinfo.duty, " ");         //intializing prefect duty info
    strcpy(prefdutyinfo.asspref," ");
    strcpy(prefdutyinfo.location, " ");
    strcpy(prefdutyinfo.date," ");
    strcpy(prefdutyinfo.time," ");

    int num, val;
    char line[1000];        // declaration of variables

    num=0;          //intialization of variables
    val = 0;

    printf("\n");
    printf("These are your students that have upcoming duties\n");
    printf("**********************************************************************************************************************\n");
    printf("Duty\t\t\t\t Prefects\t\t\t Location\t\t Date\t\t\t  Time\t \n");  //TABLE HEADINGS
    printf("**********************************************************************************************************************\n");

    HEADDUTIESPtr = fopen("HeadDuties.txt", "r");        //opening and reading duties file

        if (HEADDUTIESPtr == NULL) 
        {

            printf("Table unable to be shown. No duties found.\n");
            
        }
        else
        {
            while (fgets(line, 1000, HEADDUTIESPtr))
            {                
                printf(line);       //prints lines from file
            }

        }

    fclose(HEADDUTIESPtr);      //closing file

        
    PREFDUTIESPtr = fopen("PrefectDuties.txt", "r");        //opening and reading duties file
    
        if (PREFDUTIESPtr == NULL) 
        {
            printf("Table unable to be shown. No duties found.\n");
        }
        else
        {
            while (fgets(line, 1000, PREFDUTIESPtr))
            {   
                printf(line);       //prints lines fom file
            
            }

        }

    fclose(PREFDUTIESPtr);      //closing file

    printf("\n");
    printf ("----PLEASE TRY TO EXCUSE YOUR STUDENTS AT LEAST 5 MINUTES BEFORE THEIR DUTIES----");      //reminder printout
    printf("\n");

}

int main()
{

    int num;
    num=0;

    printf("\n");
    printf("\n");
    printf("----------------------------- ON DUTY PREFECT SCHEDULER -----------------------------\n");
    printf("\n");
    printf("Select 1 to Sign Up, or 2 to Login!\n");
    scanf("%d",&num);       //choice for signup and login

    if(num==1)
    {
        SignUp();           // directing to sign up module
    }
    else if(num==2)
    {
        Login();            //directing to login up module
    }
    else if(num != 1,2)
    {
    printf("Please enter a valid number.\n");       //invalid operation
        main();
    }

    return 0;
   
}