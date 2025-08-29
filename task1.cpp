#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    char isbn[20];
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void loadBooks() {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        return; 
    }
    bookCount = 0;
    while (fscanf(file, "%s %s %s",
                  library[bookCount].title,
                  library[bookCount].author,
                  library[bookCount].isbn) == 3) {
        bookCount++;
        if (bookCount >= MAX_BOOKS) break;
    }
    fclose(file);
}

void saveBooks() {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("Could not save data!\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s %s %s\n",
                library[i].title,
                library[i].author,
                library[i].isbn);
    }
    fclose(file);
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter book title (one word): ");
    scanf("%s", library[bookCount].title);
    printf("Enter author (one word): ");
    scanf("%s", library[bookCount].author);
    printf("Enter ISBN: ");
    scanf("%s", library[bookCount].isbn);

    bookCount++;
    printf("Book added!\n");
    saveBooks();
}

void deleteBook() {
    char isbn[20];
    printf("Enter ISBN to delete: ");
    scanf("%s", isbn);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted!\n");
            saveBooks();
            return;
        }
    }
    printf("Book not found!\n");
}

void searchBook() {
    char isbn[20];
    printf("Enter ISBN to search: ");
    scanf("%s", isbn);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            printf("\nBook found:\n");
            printf("Title : %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN  : %s\n", library[i].isbn);
            return;
        }
    }
    printf("Book not found!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("\nAll Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Title : %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("ISBN  : %s\n", library[i].isbn);
    }
}

int main() {
    int choice;
    loadBooks();

    do {
        printf("\n===== Library Menu =====\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addBook();
        } else if (choice == 2) {
            deleteBook();
        } else if (choice == 3) {
            searchBook();
        } else if (choice == 4) {
            displayBooks();
        } else if (choice == 5) {
            printf("Exiting... Data saved!\n");
        } else {
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

