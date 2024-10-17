#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    struct Book *next;
} Book;


size_t myStrcspn(const char *s1, const char *s2) {
    size_t i = 0;
    while (s1[i] != '\0') {
        size_t j = 0;
        while (s2[j] != '\0') {
            if (s1[i] == s2[j]) {
                return i;
            }
            j++;
        }
        i++;
    }
    return i;
}


int myStrCmp(const char *s1, const char *s2) {
    if (*s1 == '\0' && *s2 == '\0') return 0;
    if (*s1 == '\0') return -1;
    if (*s2 == '\0') return 1;
    if (*s1 < *s2) return -1;
    if (*s1 > *s2) return 1;
    return myStrCmp(s1 + 1, s2 + 1);
}

void addBook(Book **inventory, int id, char *title, char *author, int quantity) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newBook->id = id;
    for (int i = 0; i < myStrcspn(title, "\n"); i++) {
        newBook->title[i] = title[i];
    }
    newBook->title[myStrcspn(title, "\n")] = '\0'; 
    for (int i = 0; i < myStrcspn(author, "\n"); i++) {
        newBook->author[i] = author[i];
    }
    newBook->author[myStrcspn(author, "\n")] = '\0'; 
    newBook->quantity = quantity;
    newBook->next = *inventory;
    *inventory = newBook; 
}

void updateBookQuantity(Book *inventory, int id, int newQuantity) {
    Book *current = inventory;
    while (current != NULL) {
        if (current->id == id) {
            current->quantity = newQuantity;
            printf("Book ID %d quantity updated to %d\n", id, newQuantity);
            return;
        }
        current = current->next;
    }
    printf("Book with ID %d not found\n", id);
}

void searchBooksByAuthor(Book *inventory, const char *author) {
    Book *current = inventory;
    int found = 0;
    
    while (current != NULL) {
        if (myStrCmp(current->author, author) == 0) {
            printf("ID: %d | Title: %s | Author: %s | Quantity: %d\n", 
                   current->id, current->title, current->author, current->quantity);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No books found by author '%s'.\n", author);
    }
}

void searchBooksByID(Book *inventory, int id) {
    Book *current = inventory;
    while (current != NULL) {
        if (current->id == id) {
            printf("ID: %d | Title: %s | Author: %s | Quantity: %d\n", 
                   current->id, current->title, current->author, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Book with ID %d not found.\n", id);
}

int main() {
    Book *inventory = NULL;
    int choice, id, quantity;
    char title[100], author[100];

    while (1) {
        printf("\n1. Add Book\n2. Update Book Quantity\n3. Search by Author\n4. Search by ID\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar(); // consume newline
                printf("Enter Book Title: ");
                fgets(title, sizeof(title), stdin);
                printf("Enter Author Name: ");
                fgets(author, sizeof(author), stdin);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addBook(&inventory, id, title, author, quantity);
                break;

            case 2:
                printf("Enter Book ID to update: ");
                scanf("%d", &id);
                printf("Enter new Quantity: ");
                scanf("%d", &quantity);
                updateBookQuantity(inventory, id, quantity);
                break;

            case 3:
                printf("Enter Author Name to search: ");
                fgets(author, sizeof(author), stdin);
                searchBooksByAuthor(inventory, author);
                break;

            case 4:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBooksByID(inventory, id);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
