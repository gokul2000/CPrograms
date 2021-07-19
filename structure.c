#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countOfShops=0,freeSpace=2;
typedef struct Date
{
    int day;
    int month;
    int year;
} date;
typedef struct Item{
    char name[101];
    int price;
    date dateOfItemPurchased;
}item;
typedef struct Customer{
  char name[101];
  char mobileNo[100];
  int age;
  char gender;
  item * itemList;
  int availableSpace;
  int countOfItems;
}customer;
void printItem(item i){
    printf("%s price %d was purchased on %02d:%02d:%04d\n",i.name,i.price,i.dateOfItemPurchased.day,i.dateOfItemPurchased.month,i.dateOfItemPurchased.year);
}
void printCustomer(customer c)
{
    printf("Name %s\nAge : %d\n", c.name, c.age);
    printf("Mobile No %s\n", c.mobileNo);
    for(int i=0;i<c.countOfItems;i++)
    printItem(c.itemList[i]);
}
void printCustomers(customer *c, int n)
{
    for (int i = 0; i < n; i++){
        printf("%d ",i+1);
        printCustomer(c[i]);
        printf("*************************************************");
    }
}
typedef struct Shop{
    char shopName[101];
    customer *allCustomer;
    int countOfAllCustomers;
    customer * frequentCustomer;
    int countOfFrequentCustomers;
    int availableFreeSpaceForAllCustomers,availableFreeSpaceForFavCustomers;


}shop;
void printShop(shop s){
    printf("Shop Name : %s",s.shopName);
    printf("\n Customers of Shop \n");
    printCustomers(s.allCustomer,s.countOfAllCustomers);
    printf("\n Frequent Customers of Shop \n");
    printCustomers(s.frequentCustomer,s.countOfFrequentCustomers);
}
shop * listOfShops;
void addShop(shop sh){
    if(countOfShops>=freeSpace){
    freeSpace*=2;
    listOfShops=realloc(listOfShops,freeSpace);
    }
    listOfShops[countOfShops]=sh;
}
void loginToShop(int index){
    int flag=1;
    shop s= listOfShops[index];
    do{
        printf("1.Add a Customer..");
        printf("\n2.Add a Frequent Customer..");
        printf("\n3.Print Customers...");
        printf("\n4.Print Frequent Customers");
        int choice;
        customer c;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            
            printf("Enter customer Name");
            char name[101];
            scanf("\n%[^\n]s", name);
            printf("Enter Mobile Number");
            char mobileNo[101];
            scanf("\n%[^\n]s", mobileNo);
            printf("Enter Age");
            int age;
            scanf("%d",&age);
            char gender;
            printf("Enter M or F");
            scanf("\n%c",&gender);
            printf("Enter no Of itemsPurchased");
            int number ;scanf("%d",&number);
            strcpy(c.name,name);strcpy(c.mobileNo,mobileNo);c.age=age;c.gender=gender;
            c.availableSpace=number+1;c.countOfItems=number;
            c.itemList=malloc(sizeof(item)*c.availableSpace);
            for(int i=0;i<number;i++)
            {
                item it;
                printf("Enter Item %d name",i+1);
                char name[101];scanf("\n%[^\n]s", name);
                printf("Enter Item %d price",i+1);
                int price ; scanf("%d",&price);
                int day,month,year ; 
                printf("Enter date as follows day month and year");
                scanf("%d %d %d",&day,&month,&year);
                date d ; d.day=day;d.month=month;d.year=year;
                strcpy(it.name,name);it.price=price;it.dateOfItemPurchased=d;
                c.itemList[i]=it;

            }
            s.allCustomer[s.countOfAllCustomers]=c;
            s.countOfAllCustomers+=1;
            break;
        case 3:
            printCustomers(s.allCustomer,s.countOfAllCustomers);
        
        default:
            break;
        }

    }while(flag==1);
    
}
int main()
{
    listOfShops= malloc(sizeof(shop)*freeSpace);
    int flag=1;
    do
    {
        printf("1. Create a Shop\n");
        printf("2. Select your Shop\n");
        printf("Enter other to stop\n");
        int input;
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("Enter shop Name");
            char name[101];
            scanf("\n%[^\n]s",name);
            shop s;
            strcpy(s.shopName,name);
            s.countOfAllCustomers=0;
            s.countOfFrequentCustomers=0;
            s.availableFreeSpaceForAllCustomers=10;
            s.availableFreeSpaceForFavCustomers=10;
            s.allCustomer=malloc(sizeof(customer)*s.availableFreeSpaceForAllCustomers);
            s.frequentCustomer=malloc(sizeof(customer)*s.availableFreeSpaceForFavCustomers);
            addShop(s);
            countOfShops++;
            break;
        case 2:
            printf("Enter your option starts from 0...\n");
            for(int i=0;i<countOfShops;i++)
            printf("%d : %s\n",i,listOfShops[i].shopName);
            int choice;
            scanf("%d",&choice);
            loginToShop(choice);
            break;
        default:
            flag=0;
            break;
        }

    } while (flag==1);
    
    
}