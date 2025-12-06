#include <stdio.h>

int main() {

    int a[200], size, opt;
    int i, pos, num, item, flag, k, t;

    printf("How many elements? ");
    scanf("%d", &size);

    printf("Enter %d values:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n===== MENU (ARRAY OPERATIONS) =====\n");
        printf("1. Show Elements\n");
        printf("2. Insert New Value\n");
        printf("3. Remove Value\n");
        printf("4. Find Element\n");
        printf("5. Modify Element\n");
        printf("6. Sort Values\n");
        printf("7. Quit\n");
        printf("Choose option: ");
        scanf("%d", &opt);

        switch (opt) {

            case 1:
                printf("Array: ");
                for (i = 0; i < size; i++)
                    printf("%d ", a[i]);
                printf("\n");
                break;

            case 2:
                printf("Insert at position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &num);

                if (pos < 1 || pos > size + 1) {
                    printf("Invalid position!\n");
                } else {
                    for (i = size; i >= pos; i--)
                        a[i] = a[i - 1];
                    a[pos - 1] = num;
                    size++;
                    printf("Value inserted.\n");
                }
                break;

            case 3:
                printf("Delete position: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > size) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos - 1; i < size - 1; i++)
                        a[i] = a[i + 1];
                    size--;
                    printf("Value deleted.\n");
                }
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &item);

                flag = 0;
                for (i = 0; i < size; i++) {
                    if (a[i] == item) {
                        printf("Found at position %d\n", i + 1);
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    printf("Value not found.\n");
                break;

            case 5:
                printf("Enter position to change: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > size) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter new value: ");
                    scanf("%d", &num);
                    a[pos - 1] = num;
                    printf("Value updated.\n");
                }
                break;

            case 6:
                for (i = 0; i < size - 1; i++) {
                    for (k = i + 1; k < size; k++) {
                        if (a[i] > a[k]) {
                            t = a[i];
                            a[i] = a[k];
                            a[k] = t;
                        }
                    }
                }
                printf("Sorted successfully.\n");
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option.\n");
        }

    } while (opt != 7);

    return 0;
}