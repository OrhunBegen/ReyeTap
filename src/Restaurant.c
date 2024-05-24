#include "Restaurant.h"
int menu();
void createTitle();

int main() {
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
   /* else if(choice == 5){
        BringTheDailyReport();
        goto baslangic;
    }
   else if(choice == 6){
        BringTheAnalysis();
        goto baslangic;
   }
   else if(choice == 7){
       BringTheMostOrderedFood();
       goto baslangic;
   }*/
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
    printf("5. Display the daily report\n");
    printf("6. Display the analysis\n");
    printf("7. Display the most ordered food\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);
    return x;
}


void createTitle(){
    printf("\n\t RESTAURANT APPLICATION \n\n");

}


