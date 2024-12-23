#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char title[50];
    char author[50];
    float price;
    char category[30];
} Book;

Book books[100];
int bookCount = 0;

void addBook() {
    printf("Nhap thong tin sach:\n");
    printf("Ma sach: "); scanf("%s", books[bookCount].id);
    printf("Ten sach: "); getchar(); fgets(books[bookCount].title, 50, stdin); strtok(books[bookCount].title, "\n");
    printf("Tac gia: "); fgets(books[bookCount].author, 50, stdin); strtok(books[bookCount].author, "\n");
    printf("Gia tien: "); scanf("%f", &books[bookCount].price);
    printf("The loai: "); getchar(); fgets(books[bookCount].category, 30, stdin); strtok(books[bookCount].category, "\n");
    bookCount++;
    printf("Da them sach thanh cong!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("Danh sach sach trong!\n");
        return;
    }
    printf("Danh sach sach:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Ma: %s, Ten: %s, Tac gia: %s, Gia: %.2f, The loai: %s\n",
               books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
    }
}

void deleteBook() {
    char id[20];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", id);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].id, id) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Da xoa sach thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay ma sach!\n");
}

void sortBooks() {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].price > books[j].price) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Da sap xep sach theo gia tang dan!\n");
}

void searchBook() {
    char keyword[50];
    printf("Nhap ten sach can tim: ");
    getchar(); fgets(keyword, 50, stdin); strtok(keyword, "\n");
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, keyword)) {
            printf("Ma: %s, Ten: %s, Tac gia: %s, Gia: %.2f, The loai: %s\n",
                   books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Them sach\n");
        printf("2. Hien thi danh sach sach\n");
        printf("3. Xoa sach\n");
        printf("4. Sap xep sach theo gia\n");
        printf("5. Tim kiem sach theo ten\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: deleteBook(); break;
            case 4: sortBooks(); break;
            case 5: searchBook(); break;
            case 6: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 6);
    return 0;
}

