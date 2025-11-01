#include <stdio.h>
#include <string.h>

void customerInfo(char name[], char cnic[]) {
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", name);
    printf("Enter CNIC: ");
    scanf(" %[^\n]", cnic);
    printf("Customer info saved successfully.\n");
}

void displayInventory(int codes[], char items[][50], int quantities[], float prices[], int count) {
    int i;
    printf("\n<---- Product Code | Item Name | Quantity | Price ---->\n");
    for (i = 0; i < count; i++) {
        printf("%d | %s | %d | %.2f\n", codes[i], items[i], quantities[i], prices[i]);
    }
}

void addItem(int codes[], char items[][50], int quantities[], float prices[], int *count) {
    if (*count >= 100) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }
    printf("Enter Product Code: ");
    scanf("%d", &codes[*count]);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", items[*count]);
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);
    printf("Enter Price: ");
    scanf("%f", &prices[*count]);
    (*count)++;
    printf("Item added to inventory.\n");
}

float addToCart(int codes[], char items[][50], int quantities[], float prices[], int count) {
    int code, qty, i, found = 0;
    float total = 0;
    while (1) {
        printf("Enter Product Code to add to cart (0 to stop): ");
        scanf("%d", &code);
        if (code == 0)
            break;
        for (i = 0; i < count; i++) {
            if (codes[i] == code) {
                found = 1;
                printf("Enter Quantity: ");
                scanf("%d", &qty);
                if (qty > quantities[i]) {
                    printf("Not enough stock available.\n");
                } else {
                    quantities[i] -= qty;
                    total += qty * prices[i];
                    printf("Added %d of %s to cart.\n", qty, items[i]);
                }
                break;
            }
        }
        if (!found)
            printf("Product not found.\n");
        found = 0;
    }
    return total;
}

float applyPromo(float total) {
    char code[20];
    printf("Enter Promo Code (or press Enter to skip): ");
    scanf(" %[^\n]", code);
    if (strcmp(code, "Eid2025") == 0) {
        printf("Promo code applied! 25%% discount.\n");
        total *= 0.75;
    } else if (strlen(code) > 0) {
        printf("Invalid promo code.\n");
    }
    return total;
}

void showInvoice(char name[], char cnic[], float total, float discountedTotal) {
    printf("\n========== INVOICE ==========\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("Total Bill (without discount): %.2f\n", discountedTotal == total ? total : discountedTotal / 0.75);
    if (discountedTotal != total)
        printf("Discounted Bill (with Eid2025): %.2f\n", discountedTotal);
    else
        printf("Final Bill: %.2f\n", total);
    printf("=============================\n");
}

int main() {
    int codes[100];
    char items[100][50];
    int quantities[100];
    float prices[100];
    int count = 0;
    int choice;
    char name[50], cnic[20];
    float total = 0, discountedTotal = 0;

    do {
        printf("\n===== Supermarket Management System =====\n");
        printf("1. Enter Customer Information\n");
        printf("2. Add Item to Inventory\n");
        printf("3. Display Inventory\n");
        printf("4. Update Inventory\n");
        printf("5. Add Item to Cart\n");
        printf("6. Display Total Bill\n");
        printf("7. Show Invoice\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInfo(name, cnic);
                break;
            case 2:
                addItem(codes, items, quantities, prices, &count);
                break;
            case 3:
                displayInventory(codes, items, quantities, prices, count);
                break;
            case 4:
                displayInventory(codes, items, quantities, prices, count);
                printf("\nEnter Product Code to update: ");
                int code, qty, i, found = 0;
                scanf("%d", &code);
                for (i = 0; i < count; i++) {
                    if (codes[i] == code) {
                        printf("Enter new quantity: ");
                        scanf("%d", &qty);
                        quantities[i] = qty;
                        printf("Inventory updated.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("Product not found.\n");
                break;
            case 5:
                total = addToCart(codes, items, quantities, prices, count);
                printf("Cart total: %.2f\n", total);
                break;
            case 6:
                discountedTotal = applyPromo(total);
                printf("Total after discount (if any): %.2f\n", discountedTotal);
                break;
            case 7:
                showInvoice(name, cnic, total, discountedTotal);
                break;
            case 8:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
