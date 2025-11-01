#include <stdio.h>

void updateSector(int grid[5][5], int rows, int cols) {
    int r, c, flag, action;
    printf("Enter row (0-%d): ", rows - 1);
    scanf("%d", &r);
    printf("Enter column (0-%d): ", cols - 1);
    scanf("%d", &c);
    if (r >= rows || c >= cols || r < 0 || c < 0) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("Select status flag to modify:\n");
    printf("0 - Power Status (1 = ON, 0 = OFF)\n");
    printf("1 - Overload Warning (1 = Overloaded, 0 = Normal)\n");
    printf("2 - Maintenance Required (1 = Yes, 0 = No)\n");
    printf("Enter flag number: ");
    scanf("%d", &flag);

    printf("Enter 1 to set or 0 to clear this flag: ");
    scanf("%d", &action);

    if (action == 1)
        grid[r][c] |= (1 << flag); 
    else
        grid[r][c] &= ~(1 << flag);   

    printf("Sector [%d][%d] updated successfully.\n", r, c);
}

void querySector(int grid[5][5], int rows, int cols) {
    int r, c;
    printf("Enter row (0-%d): ", rows - 1);
    scanf("%d", &r);
    printf("Enter column (0-%d): ", cols - 1);
    scanf("%d", &c);
    if (r >= rows || c >= cols || r < 0 || c < 0) {
        printf("Invalid coordinates!\n");
        return;
    }

    int status = grid[r][c];
    printf("\nStatus for Sector [%d][%d]:\n", r, c);
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & 2) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & 4) ? "YES" : "NO");
}

void runDiagnostic(int grid[5][5], int rows, int cols) {
    int ol= 0, m = 0;
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (grid[i][j] & 2)
                ol++;
            if (grid[i][j] & 4)
                m++;
        }
    }
    printf("\nSystem Diagnostic Report:\n");
    printf("Total Overloaded Sectors: %d\n", ol);
    printf("Total Sectors Requiring Maintenance: %d\n", m);
}

int main() {
    int grid[5][5] = {0};
    int choice;
    int rows = 5, cols = 5;

    do {
        printf("\n===== IESCO Power Grid Monitoring System =====\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSector(grid, rows, cols);
                break;
            case 2:
                querySector(grid, rows, cols);
                break;
            case 3:
                runDiagnostic(grid, rows, cols);
                break;
            case 4:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice, Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
