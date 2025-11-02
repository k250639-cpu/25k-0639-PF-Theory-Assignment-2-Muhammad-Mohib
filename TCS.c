#include <stdio.h>
#include <string.h>

void reverseString(char message[]) {
    int len = strlen(message);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = message[i];
        message[i] = message[len - i - 1];
        message[len - i - 1] = temp;
    }
}

void toggleBits(char message[]) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] ^= (1 << 1);  
        message[i] ^= (1 << 4); 
    }
}

void encodeMessage(char message[]) {
    reverseString(message);
    toggleBits(message);
    printf("Encoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    toggleBits(message);  
    reverseString(message);
    printf("Decoded Message: %s\n", message);
}

int main() {
    char message[100];
    int choice;

    do {
        printf("\n===== TCS Secure Message System =====\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                break;

            case 2:
                printf("Enter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
