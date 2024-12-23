#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[50];
    float purchasePrice;
    float sellingPrice;
    int quantity;
} Product;

Product products[100];
int productCount = 0;
float revenue = 0;

void addProduct() {
    printf("Nhap thong tin san pham:\n");
    char id[20];
    printf("Ma san pham: "); scanf("%s", id);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            int additionalQty;
            printf("San pham da ton tai. Nhap so luong muon them: ");
            scanf("%d", &additionalQty);
            products[i].quantity += additionalQty;
            revenue -= additionalQty * products[i].purchasePrice;
            printf("Da cap nhat so luong san pham.\n");
            return;
        }
    }

    strcpy(products[productCount].id, id);
    printf("Ten san pham: "); getchar(); fgets(products[productCount].name, 50, stdin); strtok(products[productCount].name, "\n");
    printf("Gia nhap: "); scanf("%f", &products[productCount].purchasePrice);
    printf("Gia ban: "); scanf("%f", &products[productCount].sellingPrice);
    printf("So luong: "); scanf("%d", &products[productCount].quantity);
    revenue -= products[productCount].quantity * products[productCount].purchasePrice;
    productCount++;
    printf("Da them san pham thanh cong!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("Danh sach san pham trong!\n");
        return;
    }
    printf("Danh sach san pham:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Ma: %s, Ten: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
               products[i].id, products[i].name, products[i].purchasePrice, products[i].sellingPrice, products[i].quantity);
    }
}

void updateProduct() {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", id);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Ten san pham: "); getchar(); fgets(products[i].name, 50, stdin); strtok(products[i].name, "\n");
            printf("Gia nhap: "); scanf("%f", &products[i].purchasePrice);
            printf("Gia ban: "); scanf("%f", &products[i].sellingPrice);
            printf("So luong: "); scanf("%d", &products[i].quantity);
            printf("Da cap nhat san pham thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da nhap.\n");
}

void sortProducts() {
    char order;
    printf("Sap xep theo gia tang (nhap 't') hoac giam (nhap 'g'): ");
    scanf(" %c", &order);
    int reverse = (order == 'g');
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            if ((reverse && products[i].sellingPrice < products[j].sellingPrice) ||
                (!reverse && products[i].sellingPrice > products[j].sellingPrice)) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo gia!\n");
}

void searchProduct() {
    char keyword[50];
    printf("Nhap ten san pham can tim: ");
    getchar(); fgets(keyword, 50, stdin); strtok(keyword, "\n");
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i].name, keyword)) {
            printf("Ma: %s, Ten: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",
                   products[i].id, products[i].name, products[i].purchasePrice, products[i].sellingPrice, products[i].quantity);
        }
    }
}

void sellProduct() {
    char id[20];
    int quantity;
    printf("Nhap ma san pham can ban: ");
    scanf("%s", id);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            if (products[i].quantity == 0) {
                printf("Het hang!\n");
                return;
            }
            printf("Nhap so luong can ban: ");
            scanf("%d", &quantity);
            if (quantity > products[i].quantity) {
                printf("Khong con du hang!\n");
                return;
            }
            products[i].quantity -= quantity;
            revenue += quantity * products[i].sellingPrice;
            printf("Ban san pham thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da nhap.\n");
}

void displayRevenue() {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Cap nhat thong tin san pham\n");
        printf("4. Sap xep san pham theo gia\n");
        printf("5. Tim kiem san pham\n");
        printf("6. Ban san pham\n");
        printf("7. Doanh thu hien tai\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: updateProduct(); break;
            case 4: sortProducts(); break;
            case 5: searchProduct(); break;
            case 6: sellProduct(); break;
            case 7: displayRevenue(); break;
            case 8: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);
    return 0;
}

