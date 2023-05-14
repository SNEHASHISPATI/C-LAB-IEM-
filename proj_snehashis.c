#include <stdio.h>

int main()
{
    // Initialize balance and PIN
    int balance = 1000;
    int pin = 1234;

    // Welcome message
    printf("Welcome to the ATM!\n");

    // Prompt for PIN
    int inputPin;
    printf("Please enter your PIN: ");
    scanf("%d", &inputPin);

    // Check if PIN is correct
    if (inputPin == pin)
    {
        // PIN is correct, show menu
        int choice;
        do
        {
            printf("\nMenu:\n");
            printf("1. View Balance\n");
            printf("2. Withdraw Money\n");
            printf("3. Deposit Money\n");
            printf("4. Change PIN\n");
            printf("5. Exit\n");
            printf("Please enter your choice: ");
            scanf("%d", &choice);

            // Perform selected action
            switch (choice)
            {
            case 1:
                printf("Your balance is $%d\n", balance);
                break;
            case 2:
                // Withdraw money
                int withdrawAmount;
                printf("Enter amount to withdraw: ");
                scanf("%d", &withdrawAmount);
                if (withdrawAmount > balance)
                {
                    printf("Insufficient balance!\n");
                }
                else
                {
                    balance -= withdrawAmount;
                    printf("Withdrawal successful. Your new balance is $%d\n", balance);
                }
                break;
            case 3:
                // Deposit money
                int depositAmount;
                printf("Enter amount to deposit: ");
                scanf("%d", &depositAmount);
                balance += depositAmount;
                printf("Deposit successful. Your new balance is $%d\n", balance);
                break;
            case 4:
                // Change PIN
                int newPin, confirmPin;
                printf("Enter new PIN: ");
                scanf("%d", &newPin);
                printf("Confirm new PIN: ");
                scanf("%d", &confirmPin);
                if (newPin == confirmPin)
                {
                    pin = newPin;
                    printf("PIN changed successfully!\n");
                }
                else
                {
                    printf("PINs do not match. Please try again.\n");
                }
                break;
            case 5:
                // Exit
                printf("Thank you for using the ATM!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
            }
        } while (choice != 5);
    }
    else
    {
        // PIN is incorrect
        printf("Incorrect PIN. Please try again later.\n");
    }
    return 0;
}