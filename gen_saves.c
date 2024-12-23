#include "inventory.h"

void saveUser(const char* username, const char* password, int isOwner) {
    FILE *file = fopen("./csv/users.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s,%s,%d\n", username, password, isOwner);
    fclose(file);
}

void saveProducts(struct Product products[], int productCount) {
    FILE *file = fopen("./csv/products.csv", "w");
    if (file == NULL) {
        printf("Error opening products file!\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%s,%s,%.2f,%d\n", products[i].name, products[i].description, products[i].price, products[i].stock);
    }

    fclose(file);
}

void saveCoupons(struct Coupon coupons[], int couponCount) {
    FILE *file = fopen("./csv/coupons.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < couponCount; i++) {
        fprintf(file, "%s,%.2f,%s\n", coupons[i].code, coupons[i].discount, coupons[i].expiryDate);
    }
    fclose(file);
}

void saveThreshold(int threshold) {
    FILE *file = fopen("./csv/threshold.txt", "w");
    if (file == NULL) {
        printf("Error opening threshold file!\n");
        return;
    }

    fprintf(file, "%d", threshold);
    fclose(file);
}

void saveAutoPurchases(struct AutoPurchase autoPurchases[], int autoPurchaseCount) {
    FILE *file = fopen("./csv/autopurchase.csv", "w");
    if (file == NULL) {
        printf("Error opening autopurchase file!\n");
        return;
    }

    for (int i = 0; i < autoPurchaseCount; i++) {
        fprintf(file, "%s,%d,%s,%s,%s\n", autoPurchases[i].productName, autoPurchases[i].quantity, autoPurchases[i].couponCode, autoPurchases[i].purchaseDay, autoPurchases[i].lastPurchase);
    }
    fclose(file);
}

void saveAutoRestocks(struct AutoRestock autoRestocks[], int autoRestockCount) {
    FILE *file = fopen("./csv/autorestock.csv", "w");
    if (file == NULL) {
        printf("Error opening autorestock file!\n");
        return;
    }

    for (int i = 0; i < autoRestockCount; i++) {
        fprintf(file, "%s,%d,%s,%s\n", autoRestocks[i].productName, autoRestocks[i].quantity, autoRestocks[i].restockDay, autoRestocks[i].lastRestock);
    }
    fclose(file);
}

void logPurchase(const char* productName, int quantity, float totalPrice, float discount, const char* couponCode, const char* purchaseTime) {
    FILE *file = fopen("./csv/purchaselog.csv", "a");
    if (file == NULL) {
        printf("Error opening log file!\n");
        return;
    }

    fprintf(file, "%s,%d,%s,%.2f,%.2f,%s\n", productName, quantity, couponCode, discount, totalPrice, purchaseTime);
    fclose(file);
}

void logRestock(const char* productName, int quantity, const char* restockTime) {
    FILE *file = fopen("./csv/restocklog.csv", "a");
    if (file == NULL) {
        printf("Error opening log file!\n");
        return;
    }

    fprintf(file, "%s,%d,%s\n", productName, quantity, restockTime);
    fclose(file);
}

void logReportSummary(const char* date, int totalSales, float totalIncome, const char* mostSoldProduct, int mostSoldQuantity, const char* leastSoldProduct, int leastSoldQuantity) {
    FILE *file = fopen("./csv/reports.csv", "a");
    if (file == NULL) {
        printf("Error opening reports file!\n");
        return;
    }

    fprintf(file, "%s,%d,%.2f,%s,%d,%s,%d\n", date, totalSales, totalIncome, mostSoldProduct, mostSoldQuantity, leastSoldProduct, leastSoldQuantity);
    fclose(file);
}