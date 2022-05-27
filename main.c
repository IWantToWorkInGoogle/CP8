#include "list.h"

int main() {
    list* l1 = create_list();

    bool programDo = true;

    while(programDo) {
        printf("Menu:\n1)Print list\n2)Insert new element\n3)Delete element\n4)Size of list\n5)Function\n6)Exit\n");
        char* input;
        printf("\n\nChoose the command: ");
        scanf("%s",input);
        int ind;
        int command = atoi(input);
        switch (command) {
            case 1:
                printf("The list:\n");
                print_list(l1);
                break;
            case 2:
                printf("Choose the index: ");
                scanf("%d",&ind);
                printf("Insert the value: ");
                scanf("%s",input);
                insert(l1,ind,input);
                break;
            case 3:
                printf("Choose the index: ");
                scanf("%s",input);
                int k = atoi(input);
                erase(l1,k);
                break;
            case 4:
                printf("The size of list: %d\n",size(l1));
                break;
            case 5:
                printf("Function:\n");
                printf("Clear all elements in list if there is an element with given value.\n");
                printf("Insert the value: ");
                scanf("%s",input);
                function(l1,input);
                break;
            case 6:
                printf("The program is done!\nGoodbye!\n");
                programDo = false;
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
        printf("\nPress something to continue: ");
        scanf("%s",input);
        system("clear");
    }

    delete_list(l1);
    return 0;
}
