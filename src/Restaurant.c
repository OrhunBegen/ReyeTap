#include "Restaurant.h"

// Elif yaren Şakar 434335
// Rümeysa Yurdakul 425487
// Orhun Begen 402520


int menu();
void createTitle();


int main() {
   DailyCreationOfTxt();
   createTitle();   
   int choice;
   baslangic:

    choice = menu();
   
    if(choice == 1){
        AddCustomFoodToTheFoodList();
        goto baslangic;
    }
    else if(choice == 2){
        RemoveTheSelectedFoodFromTheFoodList();
        RenumberTheFoodList();
        goto baslangic;
    }
    else if(choice == 3){
        CreateASampleFoodList();
        AdjustTheSelectedFoodFromTheFoodList();
        AddTitle();
        goto baslangic;
    }
    else if(choice == 4){
        BringTheFoodList();
        goto baslangic;
    }
    else if(choice == 5){
        DatesBetweenGetTheSellMoney();
       goto baslangic;
    }
    else if(choice == 6){
        DailyTotalSellMoney();
        goto baslangic;
    }
    else if(choice == 7){
        BringTheOrdersList();
        goto baslangic;
    }else if(choice == 8){
        BringTheMostProfitFood();
        goto baslangic;
    }else if(choice == 9){
        BringTheLeastProfitFood();
        goto baslangic;
    }else if(choice == 10){
        AproveOrDeclineSystem();
        goto baslangic;
    }else if(choice == 11){
        CleanEverythingInsideCooksDatFile();
        AdjustTheCooksNumero();
        goto baslangic;
    }
    else{
        printf("Invalid choice\n");
    }
    return 0; 
}
int menu(){
    int x;
    printf("1. Add a new order\n");
    printf("2. Remove an order\n");
    printf("3. Adjust an order\n");
    printf("4. Display the food list\n");
    printf("5. Bring the between two dates get the total sell money\n");
    printf("6. Display daily total sell money\n");
    printf("7. Bring the orders list\n");
    printf("8. Display the most ordered food\n");
    printf("9. Display the least ordered food\n");
    printf("10. Aprove or decline the order\n");
    printf("11. Adjust the cooks\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);
    return x;
}


void createTitle(){
    printf("\n\t RESTAURANT APPLICATION \n\n");

}


