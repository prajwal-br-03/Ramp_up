#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    struct Book *next;
} Book;


void addBook(Book **inventory, int id, char *title, char *author, int quantity) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
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

void searchBooksByAuthor(Book *inventory, char *author) {
    Book *current = inventory;
    int found = 0;
    
    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
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
int main() {
    Book *inventory = NULL;

    
    addBook(&inventory, 1, "The C Programming Language", "Brian Kernighan", 5);
    addBook(&inventory, 2, "Effective C", "Robert C. Seacord", 10);
    addBook(&inventory, 3, "Clean Code", "Robert C. Martin", 7);

    
    updateBookQuantity(inventory, 2, 15);

    
    printf("\nBooks by 'Robert C. Martin':\n");
    searchBooksByAuthor(inventory, "Robert C. Martin");

    return 0;
}




