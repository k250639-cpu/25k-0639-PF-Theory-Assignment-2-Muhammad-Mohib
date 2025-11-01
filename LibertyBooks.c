#include <stdio.h>
#include <string.h>

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= 100) {
        printf("Inventory full! Cannot add another book.\n");
        return;
    }
    int isbn, i, qty;
    float price;
    char title[50];
    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    for (i = 0; i < *count; i++) {
        if (isbns[i] == isbn) {
            printf("Book with this ISBN already exists! Enter additional quantity: ");
            scanf("%d", &qty);
            quantities[i] += qty;
            printf("Updated quantity for existing book.\n");
            return;
        }
    }
    isbns[*count] = isbn;
    printf("Enter Title: ");
    scanf(" %[^\n]", title);
    strcpy(titles[*count], title);
    printf("Enter Price: ");
    scanf("%f", &price);
    prices[*count] = price;
    printf("Enter Quantity: ");
    scanf("%d", &qty);
    quantities[*count] = qty;
    (*count)++;
    printf("Book added successfully!\n");
}
void processSale(int isbns[], int quantities[], int count) {
    int isbn, qty, i, found = 0;
    printf("Enter ISBN to sell: ");
    scanf("%d", &isbn);
    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &qty);
            if (qty > quantities[i]) {
                printf("Error: Not enough stock available!\n");
            } else {
                quantities[i] -= qty;
                printf("Sale processed successfully! Remaining stock: %d\n", quantities[i]);
            }
            break;
        }
    }
    if (!found)
        printf("Book with given ISBN not found!\n");
}
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int i, found = 0;
    printf("\n--- Low Stock Report (Quantity < 5) ---\n");
    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No books with low stock.\n");
}
int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;
    do {
        printf("\n===== Liberty Books Inventory System =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addNewBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
