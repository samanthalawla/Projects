//Algorithm: Lotta' Scoops Program 
//Date: April 9, 2022
//Developers: Tivona Newman, Samantha Lawla, Jaden Anthony, Madison Sujanani

#include <stdio.h>
#include <string.h>

void WritePrices();         //declaration of modules
void WriteCalories();
void DisplayMenu();
void OrderIceCream();
void AddNewFlavour();
void AddNewTopping();
void AddNewContainer();
void CalculatePrices(int);
void CalculateCalories(int);
void CheckOut();

typedef struct CUSTORDER{        //declaration of customer record
    
    char custname [30];
    char flav [30];
    char topping [30];
    char container [20];
    float total_cost;
    int calories;

}CustomerOrder;

typedef struct PRICES{         //declaration of prices record

    char containerName [15];
    float containerPrice;

}Prices;

typedef struct NUTRITIONALVAL{            //declaration of calories record
    
    char itemName [30];
    int itemCal;
    
}Calories;

typedef struct FLAVOURS{     //record for "Add New Flavour" module in order to append to the file to be created
    
    int id;
    char newFlav[30];
    
}flavours;

typedef struct TOPPINGS{      //record for "Add New Topping" module in order to append to the file to be created
    
    int id;
    char newTopp [30];
    
}toppings;

void WritePrices()
{
    Prices prices;                    //initializing prices
    strcpy(prices.containerName," ");
    prices.containerPrice = 0.0;

    FILE *PricesPtr;         // pointer for the prices file

   strcpy(prices.containerName,"SingleCone");
   prices.containerPrice = 400;

    
    PricesPtr = fopen ("Containers.txt", "w");     //opening and writing to container file
    
        if(PricesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
        fprintf(PricesPtr,"%s\t\t\t %.2f\n", prices.containerName, prices.containerPrice);
        }

    fclose(PricesPtr);           //closing container file

    strcpy(prices.containerName,"WaffleCone");
    prices.containerPrice = 500;

    PricesPtr = fopen ("Containers.txt", "a");    //opening and appending to container file
    
        if(PricesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
        fprintf(PricesPtr,"%s\t\t\t %.2f\n", prices.containerName, prices.containerPrice);
        }

    fclose(PricesPtr);                  //closing container file

    strcpy(prices.containerName,"DoubleWaffleCone");
    prices.containerPrice = 600;
    
    PricesPtr = fopen ("Containers.txt", "a");           //opening and appending to container file
    
        if(PricesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
        fprintf(PricesPtr,"%s\t\t\t %.2f\n", prices.containerName, prices.containerPrice);
        }

    fclose(PricesPtr);                       //closing container file


    strcpy(prices.containerName,"4.ozCup");
    prices.containerPrice = 400;

    PricesPtr = fopen ("Containers.txt", "a");           //opening and appending to container file
    
        if(PricesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
        fprintf(PricesPtr,"%s\t\t\t %.2f\n", prices.containerName, prices.containerPrice);
        }

    fclose(PricesPtr);                       //closing container file

    strcpy(prices.containerName,"8.ozCup");
    prices.containerPrice = 600;

    PricesPtr = fopen ("Containers.txt", "a");           //opening and appending to container file
    
        if(PricesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
        fprintf(PricesPtr,"%s\t\t\t %.2f\n", prices.containerName, prices.containerPrice);
        }

    fclose(PricesPtr);                   //closing container file


    strcpy(prices.containerName,"12.ozCup");
    prices.containerPrice = 800;

    PricesPtr = fopen ("Containers.txt", "a");           //opening and appending to container file
    
        if(PricesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
        fprintf(PricesPtr,"%s\t\t\t %.2f\n", prices.containerName, prices.containerPrice);
        }

    fclose(PricesPtr);                   //closing container file


    printf("Prices file ready!\n");

    WriteCalories();            //calling calories modules

}

void WriteCalories()
{
    Calories calories;
    strcpy(calories.itemName," ");      //initializing calories 
    calories.itemCal = 0;

    FILE * CaloriesPtr;            //file pointer for calories file

    strcpy(calories.itemName,"SingleCone");
    calories.itemCal = 50;

    CaloriesPtr = fopen ("Calories.txt","w");       //opening and writing to calories file
    
        if(CaloriesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
        }

    fclose(CaloriesPtr);             //closing calories file


    strcpy(calories.itemName,"WaffleCone");
    calories.itemCal = 50;

    CaloriesPtr = fopen ("Calories.txt","a");       //opening and appending to calories file
    
        if(CaloriesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
        }

    fclose(CaloriesPtr);             //closing calories file

    strcpy(calories.itemName,"DoubleWaffleCone");
    calories.itemCal = 100;

    CaloriesPtr = fopen ("Calories.txt","a");           //opening and appending to calories file
    
        if(CaloriesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
        }

    fclose(CaloriesPtr);             //closing calories file


    strcpy(calories.itemName,"4.ozCup");
    calories.itemCal = 150;

    CaloriesPtr = fopen ("Calories.txt","a");           //opening and appending to calories file
    
        if(CaloriesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
        }

    fclose(CaloriesPtr);                //closing calories file


    strcpy(calories.itemName,"8.ozCup");
    calories.itemCal = 300;

    CaloriesPtr = fopen ("Calories.txt","a");           //opening and appending to calories file
    
        if(CaloriesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
        }

    fclose(CaloriesPtr);            //closing calories file


    strcpy(calories.itemName,"12.ozCup");
    calories.itemCal = 450;

    CaloriesPtr = fopen ("Calories.txt","a");           //opening and appending to calories file
    
        if(CaloriesPtr == NULL)
            printf("File cannot be opened at this time.\n");
        else
        {
            fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
        }

    fclose(CaloriesPtr);                //closing calories file


    printf("Calories file ready!\n");

    DisplayMenu();              //calling menu module

}

void DisplayMenu()
{
    int choice;             //declaring the choice variable
    choice = 0;             //initializing the choice variable

    printf ("****************************************\n");
    printf ("FOR CUSTOMER\n");
    printf ("Enter '1' to Create your Ice-Cream Order:\n");
    printf ("****************************************\n");
    printf ("FOR EMPLOYEE\n");
    printf ("Enter '2' to Add New Flavour:\n");
    printf ("Enter '3' to Add New Topping:\n");
    printf ("Enter '4' to Add New Container:\n");
    printf ("******************************************\n");
    scanf ("%d", &choice);
    

    if (choice == 1)                //if statements for the choice input
    {
        OrderIceCream();
    }
    else if (choice == 2)
    {
        AddNewFlavour();
    }
    else if (choice == 3)
    {
        AddNewTopping();
    }
    else if (choice == 4)
    {
        AddNewContainer();
    }
    else if (choice != 1||2||3||4)  // if choice is not equal 1 OR 2 OR 3 OR 4
    {
        printf("Choose a valid option.\n");
        DisplayMenu();
    }
}

void OrderIceCream()
{
    FILE * CUSTORDERPtr;                    //pointer for customer file

    CustomerOrder customerorder;            
    
    strcpy (customerorder.custname," ");          //initializing customer 
    strcpy (customerorder.flav," ") ;
    strcpy (customerorder.topping," ");
    strcpy (customerorder.container," ");
    customerorder.total_cost = 0.0;
    customerorder.calories = 0;

    int flav, topping, container,enter;     //declaration of variables
    flav =0;                                //initialization of variables
    topping = 0;
    container = 0; 
    enter =0;

    printf("********************************\n");
    printf ("Please enter your name:");             //prompting for the customer's name
    scanf ("%s", customerorder.custname);           //accepting input fo the customer's name

    printf("********************************\n");
    printf("Please select an ice-cream flavour.\n");
    printf("Enter '1' for VANILLA\n");
    printf("Enter '2' for CHOCOLATE\n");
    printf("Enter '3' for STRAWBERRY\n");
    printf("Enter '4' for MANGO\n");
    printf("Enter '5' for COOKIES AND CREAM\n");
    printf("Enter '6' for PISTACHIO\n");
    printf("Enter '7' for BUBBLEGUM\n");
    printf("Enter '8' for MINT CHOCOLATE\n");
    printf("Enter '9' for COOKIE DOUGH\n");
    printf("Enter '10' for RUM AND RAISIN\n");
    printf("Enter '11' for BIRTHDAY CAKE\n");
    printf("Enter '12' for UBE (PURPLE YAM)\n");
    printf("Enter '13' for OREO CHEESECAKE\n");
    printf("Enter '14' for COTTON CANDY\n");
    printf("*********************************\n");
    scanf ("%d",&flav);

    int f=flav;

    switch(f)
    {
    case 1:
        strcpy(customerorder.flav,"Vanilla");           //switch case for flavors
        printf ("You've chosen Vanilla!\n");
        break;
    case 2:
        strcpy(customerorder.flav, "Chocolate");
        printf ("You've chosen Chocolate!\n");
        break;
    case 3:
        strcpy(customerorder.flav,"Strawberry");
        printf ("You've chosen Strawberry!\n");
        break;
    case 4:
        strcpy(customerorder.flav,"Mango");
        printf ("You've chosen Mango!\n");
        break;
    case 5:
        strcpy(customerorder.flav,"Cookies&Cream");
        printf("You've chosen Cookies & Cream!\n");
        break;
    case 6:
        strcpy(customerorder.flav,"Pistachio");
        printf("You've chosen Pistachio!\n");
        break;
    case 7:
        strcpy(customerorder.flav,"Bubblegum");
        printf("You've chosen Bubblegum!\n");
        break;
    case 8:
        strcpy(customerorder.flav,"MintChocolate");
        printf("You've chosen Mint Chocolate!\n");
        break;
    case 9:
        strcpy(customerorder.flav,"CookieDough");
        printf("You've chosen Cookie Dough!\n");
        break;
    case 10:
        strcpy(customerorder.flav,"Rum&Raisin");
        printf("You've chosen Rum & Raisin!\n");
        break;
    case 11:
	    strcpy(customerorder.flav,"BirthdayCake");	
	    printf("You've chosen Birthday Cake!\n");
        break;
	case 12:
		strcpy(customerorder.flav,"Ube(PurpleYam)");
        printf("You've chosen Ube (Purple Yam)!\n");
        break;
    case 13:
		strcpy(customerorder.flav,"OreoCheesecake");
        printf("You've chosen Oreo Cheesecake!\n");
        break;
    case 14:
		strcpy(customerorder.flav,"CottonCandy");
	    printf("You've chosen Cotton Candy!\n");
        break;
    default:
        printf("Choose a valid option. We will restart your order.\n");
        OrderIceCream();
        break;
    }

    printf("********************************\n");
    printf("Please select the topping of your choice.\n");
    printf("Enter '0' for NO TOPPINGS\n");
    printf("Enter '1' for RAINBOW SPRINKLES\n");
    printf("Enter '2' for CHOCOLATE SPRINKLES\n");
    printf("Enter '3' for CRUSHED NUTS\n");
    printf("Enter '4' for CRUSHED OREOS\n");
    printf("Enter '5' for CARAMEL DRIZZLE\n");
    printf("Enter '6' for  MARSHMALLOWS\n");
    printf("Enter '7' for WHIPPED CREAM\n");
    printf("Enter '8' for CEREAL (FRUITY PEBBLES)\n");
    printf("Enter '9' for CHERRIES\n");
    printf("Enter '10' for STRAWBERRIES\n");
    printf("********************************\n");
    scanf ("%d", &topping);

    int t=topping;

    switch(t)
    {
    case 0:
	    strcpy(customerorder.topping,"None");	            //switch case for toppings
	    printf("You've chosen no toppings.\n");
        break;
    case 1:
        strcpy(customerorder.topping,"RainbowSprinkles");
        printf ("You've chosen Rainbow Sprinkles!\n");
        break;
    case 2:
        strcpy(customerorder.topping,"ChocolateSprinkles");
        printf ("You've chosen Chocolate Sprinkles!\n");
        break;
    case 3:
        strcpy(customerorder.topping,"CrushedNuts");
        printf ("You've chosen Crushed Nuts!\n");
        break;
    case 4:
        strcpy(customerorder.topping,"CrushedOreos");
        printf ("You've chosen Crushed Oreos!\n");
        break;
    case 5:
        strcpy(customerorder.topping,"CaramelDrizzle");
        printf("You've chosen Caramel Drizzle!\n");
        break;
    case 6:
        strcpy(customerorder.topping,"Marshmallows");
        printf("You've chosen Marshmallows!\n");
        break;
    case 7:
        strcpy(customerorder.topping,"WhippedCream");
        printf("You've chosen Whipped Cream!\n");
        break;
    case 8:
        strcpy(customerorder.topping,"Cereal(FruityPebbles)");
        printf("You've chosen Cereal (Fruity Pebbles)!\n");
        break;
    case 9:
        strcpy(customerorder.topping,"Cherries");
        printf("You've chosen Cherries!\n");
        break;
    case 10:
        strcpy(customerorder.topping,"Strawberries");
        printf("You've chosen Strawberries!\n");
        break;
    default:
        printf("Choose a valid option.We will restart your order.\n");
        OrderIceCream();
        break;
    }

    printf("********************************************\n");
    printf("Please select the container of your choice.\n");
    printf("Enter '1' for a Single Cone\n");
    printf("Enter '2' for a Waffle Cone\n");
    printf("Enter '3' for a Double Waffle Cone\n");
    printf("Enter '4' for a 4.oz Cup\n");
    printf("Enter '5' for a 8.oz Cup\n");
    printf("Enter '6' for a 12.oz Cup\n");
    printf("********************************************\n");
    scanf("%d", &container);

    int c=container;

    switch(c)
    {
    case 1:
        strcpy(customerorder.container,"SingleCone");               //switch case for container/cup
        printf("You have selected a Single Cone!");
        break;
    case 2:
        strcpy(customerorder.container,"WaffleCone");
        printf("You have selected a Waffle Cone!");
        break;
    case 3:
        strcpy(customerorder.container,"DoubleWaffleCone");
        printf("You have selected a Double Waffle Cone!");
        break;
    case 4:
        strcpy(customerorder.container,"4.ozCup");
        printf("You have selected a 4.oz Cup!");
        break;
    case 5:
        strcpy(customerorder.container,"8.ozCup");
        printf("You have selected a 8.oz Cup!");
        break;
    case 6:
        strcpy(customerorder.container,"12.ozCup");
        printf("You have selected a 12.oz Cup!");
        break;
    default:
        printf("Please make a valid entry.We will restart your order.\n");
        OrderIceCream();
        break;
    }

    CUSTORDERPtr = fopen ("CustomerOrder.txt","a");        //opening and appending to customer order file

        if (CUSTORDERPtr == NULL) {
            printf ("File cannot be opened at this time!\n");
        }
        else
        {
            fprintf (CUSTORDERPtr,"%s\t\t %s\t\t %s\t\t %s\t\t", customerorder.custname, customerorder.flav, customerorder.topping, customerorder.container);
        }

    fclose(CUSTORDERPtr);                   //closing customer order file

    printf("\nData Added Succesfully to CUSTORDER File!\n");

    printf("********************************************\n");
    printf("Let's see your receipt!\n");
    printf("Enter '1' for a Single Cone\n");
    printf("Enter '2' for a Waffle Cone\n");
    printf("Enter '3' for a Double Waffle Cone\n");
    printf("Enter '4' for a 4.oz Cup\n");
    printf("Enter '5' for a 8.oz Cup\n");
    printf("Enter '6' for a 12.oz Cup\n");
    printf("********************************************\n");
    printf("Please re-enter the container you choose:\n");
    scanf("%d", &enter);

    CalculateCalories(enter);           //calling calories module
}

void CalculatePrices(int enter)
{
    FILE *PricesPtr;                //file pointer for prices 
    FILE *CUSTORDERPtr;             //file pointer for customer order 
    
    Prices prices;
    CustomerOrder customerorder;

    strcpy(prices.containerName," ");       //initializing container prices
    prices.containerPrice = 0.0;

    int val=0;
    float total=0.0;
       
    strcpy (customerorder.custname," ");    //initializing customer order 
    strcpy (customerorder.flav," ") ;
    strcpy (customerorder.topping," ");
    strcpy (customerorder.container," ");
    customerorder.total_cost = 0.0;
    customerorder.calories = 0;
   
    PricesPtr = fopen("Containers.txt","r");        //opening and reading container file

        if (PricesPtr == NULL)
            printf ("File cannot be opened at this time");
        else
        {
            val = fscanf (PricesPtr,"%s %f\n", prices.containerName, &prices.containerPrice);

            while (val > 0)
            {
                if (enter==1)
                {
                    if (strcmp(prices.containerName,"SingleCone")==0)   //comparison of element with desired string for an exact match
                    {
                        total = prices.containerPrice;  //placing element representing the total into new variable
                    }
                }
                else if (enter==2)
                {
                    if (strcmp(prices.containerName,"WaffleCone")==0)
                    {
                        total = prices.containerPrice;
                    }
                    
                }
                else if (enter==3)
                {
                   if (strcmp(prices.containerName,"DoubleWaffleCone")==0)
                    {
                        total = prices.containerPrice;
                    }
                }
                else if (enter==4)
                {
                   if (strcmp(prices.containerName,"4.ozCup")==0)
                    {
                        total = prices.containerPrice;
                    }
                }
                else if (enter==5)
                {
                    if (strcmp(prices.containerName,"8.ozCup")==0)
                    {
                        total = prices.containerPrice;
                    }
                }
                else if (enter==6)
                {
                    if (strcmp(prices.containerName,"12.ozCup")==0)
                    {
                        total = prices.containerPrice;
                    }
                }

                val = fscanf (PricesPtr,"%s %f\n", prices.containerName, &prices.containerPrice);     
            }

        } 

    fclose (PricesPtr);             //closing container file

    customerorder.total_cost = total;

    CUSTORDERPtr = fopen ("CustomerOrder.txt","a");     //opening and appending customer order file

        if (CUSTORDERPtr == NULL)
            printf ("File cannot be opened at this time");
        else
        {
            fprintf (CUSTORDERPtr,"%.2f\n",customerorder.total_cost);
        }

    fclose(CUSTORDERPtr);               //closing customer order file

    printf("Total Added!\n");

    CheckOut();                     //calling check out module
}

void CalculateCalories(int enter)
{
    FILE *CaloriesPtr;          //declaration of calories pointer
    FILE * CUSTORDERPtr;        //declaration of customer order pointer

    CustomerOrder customerorder;  
    Calories calories;
    
    int val=0;
    int cal=0;
    
    strcpy(calories.itemName," ");      //initializing calories record
    calories.itemCal = 0;

    strcpy (customerorder.custname," ");        //initializing customer order record
    strcpy (customerorder.flav," ") ;
    strcpy (customerorder.topping," ");
    strcpy (customerorder.container," ");
    customerorder.total_cost = 0.0;
    customerorder.calories = 0;
    
    CaloriesPtr = fopen("Calories.txt","r");        //opening and reading calories  file


        if (CaloriesPtr == NULL)
            printf ("File cannot be opened at this time");
        else
        {
            val = fscanf (CaloriesPtr,"%s %d\n", calories.itemName, &calories.itemCal);

            while (val > 0)
            {
                if (enter==1)
                {
                    if (strcmp(calories.itemName,"SingleCone")==0) //comparison of element with desired string for an exact match
                    {
                        cal = calories.itemCal;            //placing element representing the calories into new variable
                    }
                }
                else if (enter==2)
                {
                    if (strcmp(calories.itemName,"WaffleCone")==0)
                    {
                        cal = calories.itemCal;
                    }
                    
                }
                else if (enter==3)
                {
                   if (strcmp(calories.itemName,"DoubleWaffleCone")==0)
                    {
                        cal = calories.itemCal;
                    }
                }
                else if (enter==4)
                {
                   if (strcmp(calories.itemName,"4.ozCup")==0)
                    {
                       cal = calories.itemCal;
                    }
                }
                else if (enter==5)
                {
                    if (strcmp(calories.itemName,"8.ozCup")==0)
                    {
                        cal = calories.itemCal;
                    }
                }
                else if (enter==6)
                {
                    if (strcmp(calories.itemName,"12.ozCup")==0)
                    {
                        cal = calories.itemCal;
                    }
                }

                val = fscanf (CaloriesPtr,"%s %d\n", calories.itemName, &calories.itemCal);        
            }
        }
    fclose (CaloriesPtr);           //closing calories file

    customerorder.calories = cal;

    CUSTORDERPtr = fopen ("CustomerOrder.txt","a");         //opening and appending customer order file


        if (CUSTORDERPtr == NULL)
            printf ("File cannot be opened at this time.\n");
        else
        {
            fprintf (CUSTORDERPtr,"%d\t\t",customerorder.calories);
        }

    fclose(CUSTORDERPtr);               //closing customer order file

    printf("Calories Added!\n");

   CalculatePrices(enter);              //calling calculate prices module
}

void AddNewFlavour()
{
    FILE *flavoursPtr;              //declaration of flavours pointer

    flavours addFlav;  

    strcpy(addFlav.newFlav," ");        //initializing flavour record
    addFlav.id = 0;

    int num =0;
    
    printf("*********************************************************\n");
    printf("You have decided to add flavours to the menu!\n");
    printf("Enter '0' to exit.\n");
    printf("Enter any other integer to continue adding flavours.\n");
    printf("*********************************************************\n");
    scanf("%d", &num);

    if (num == 0) {
        printf("You have decided to stop entering flavours.\n");
    }
    else if (num != 0) {
        printf("Please enter the New Flavour.\n");
        scanf("%s", addFlav.newFlav);

        printf("Please enter a 4-digit ID for the New flavour:\n");
        scanf("%d", &addFlav.id);

        flavoursPtr = fopen("Flavours.txt", "a");       //opening and appending flavours file

        
            if (flavoursPtr == NULL) {
                printf("File cannot be opened at this time.\n");
            }
            else {
                fprintf(flavoursPtr,"%s\t %d\n", addFlav.newFlav, addFlav.id);
            }

        fclose (flavoursPtr);   //closing flavours file
        
        printf("New Flavour and ID added succesfully!\n");

        AddNewFlavour();    //calling the AddNewFlavour module to add a new entry
    }
}

void AddNewTopping()
{
    FILE * toppingsPtr;                 //declaration of toppings pointer

    toppings addTopp;

    strcpy (addTopp.newTopp, "");           //initializing toppings record
    addTopp.id = 0;
    int num =0;

    printf("*********************************************************\n");
    printf("You have decided to add toppings to the menu!\n");
    printf("Enter '0' to exit.\n");
    printf("Enter any other integer to continue adding toppings.\n");
    printf("**********************************************************\n");
    scanf("%d", &num);

    if (num == 0) {
        printf("You have decided to stop entering toppings.\n");
    }
    else if (num != 0) {

        printf("Please enter the New Topping here: \n");
        scanf("%s", addTopp.newTopp);
        
        printf("Please enter a 4-digit ID for the New Topping: \n");
        scanf("%d", &addTopp.id);

        toppingsPtr = fopen("Toppings.txt","a");            //opening and appending toppings file
        
            if (toppingsPtr == NULL)
                printf ("File cannot be opened at this time.\n");
            else
            {
                fprintf (toppingsPtr,"%s\t %d\n",addTopp.newTopp , addTopp.id);
            }

        fclose (toppingsPtr);               //closing toppings file

        printf("New Topping and ID added succesfully!\n");

        AddNewTopping(); //calling the AddNewTopping module to start another entry
    }
}

void AddNewContainer()
{
    FILE *PricesPtr;            //declaration of prices pointer

    Prices prices;

    strcpy(prices.containerName," ");           //initializing prices record
    prices.containerPrice = 0.0;
    int num=0;
 
    printf("*******************************************************************\n");
    printf("You have decided to add new containers and calories to the menu!\n");
    printf("Enter '0' to exit.\n");
    printf("Enter any other integer to continue adding containers and calories.\n");
    printf("*******************************************************************\n");
    scanf("%d", &num);

    if (num == 0) {
        printf("You have decided to stop entering containers and calories.\n");
    }
    else if (num != 0) 
    {

        printf("Please enter the new Cup/Container:\n");
        scanf("%s", prices.containerName);

        printf("Please enter the new price for the Cup/Container (eg.800.00):\n");
        scanf("%f", &prices.containerPrice);

        PricesPtr = fopen ("Containers.txt", "a");          //opening and appending containers file

        
            if(PricesPtr == NULL)
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(PricesPtr,"%s\t\t\t %f\n", prices.containerName, prices.containerPrice);
            }

        fclose(PricesPtr);                  //closing containers file
        
        printf("New Container/Cup and ID added succesfully!\n");

        Calories calories;                  
        strcpy(calories.itemName," ");          //initialzing calories record
        calories.itemCal = 0;

        FILE * CaloriesPtr;                 //declaring calories pointer

        printf("Please re-enter the new Cup/Container. \n");
        scanf("%s", calories.itemName);

        printf("Please enter the calorie amount for the new Cup/Container: \n");
        scanf("%d", &calories.itemCal);

        CaloriesPtr = fopen ("Calories.txt","a");          //opening and appending calories file

        
            if(CaloriesPtr == NULL)
                printf("File cannot be opened at this time.\n");
            else
            {
                fprintf(CaloriesPtr,"%s\t\t\t %d\n", calories.itemName, calories.itemCal);
            }

        fclose(CaloriesPtr);                //closing calorues file

        printf("New Calorie Amount for New Container/Cup added succesfully!\n");

        AddNewContainer();      //calling the AddNewContainer module to add a new entry
    }
}

void CheckOut()
{
    FILE * CUSTORDERPtr;                //declaring customer order pointer

    CustomerOrder customerorder;

    strcpy (customerorder.custname," ");           //initalizing customer order record
    strcpy (customerorder.flav," ") ;
    strcpy (customerorder.topping," ");
    strcpy (customerorder.container," ");
    customerorder.total_cost = 0.0;
    customerorder.calories = 0;
  
    int val=0;      //initializing val

    CUSTORDERPtr = fopen ("CustomerOrder.txt", "r");        //opening and reading customer order file
    
        if (CUSTORDERPtr == NULL) 
            printf("File cannot be opened at this time");
        else
        {
            val=fscanf(CUSTORDERPtr,"%s %s %s %s %d %f", customerorder.custname, customerorder.flav, customerorder.topping, customerorder.container,&customerorder.calories,&customerorder.total_cost);

            while (val > 0)
            {
                
                printf ("******************************************\n");        // print statements for checkout module
                printf ("Customer Name: %s\n", customerorder.custname);
                printf ("Ice Cream Flavour: %s\n", customerorder.flav);
                printf ("Ice Cream Topping: %s\n", customerorder.topping);
                printf ("Container Type: %s\n", customerorder.container);
                printf ("Calorie Amount: %d\n", customerorder.calories);
                printf ("Total Price: $%.2f\n", customerorder.total_cost);
                printf ("Thank you for ordering with Lotta' Scoops!\n");
                printf ("******************************************\n");
                    
                val=fscanf(CUSTORDERPtr,"%s %s %s %s %d %f", customerorder.custname, customerorder.flav, customerorder.topping, customerorder.container,&customerorder.calories,&customerorder.total_cost);
                  
            }
                
        } 

    fclose (CUSTORDERPtr);                  //closing customer order file
}

int main()
{
    printf ("Welcome to Lotta' Scoops!\n");
    printf ("        .-"  "-.	        \n");
    printf ("     *        *	    \n");
    printf ("     |        |	    \n");
    printf ("     *'---'--`*	    \n");
    printf ("    |          |	    \n");
    printf ("    *.--.---.-.*	    \n");
    printf ("    (_.--._.-._)	    \n");
    printf ("      |=-=-=-|         \n");
    printf ("       |=-=-|	        \n");
    printf ("        |=-|	        \n");
    printf ("         __	        \n");

    WritePrices();

    return 0;
}