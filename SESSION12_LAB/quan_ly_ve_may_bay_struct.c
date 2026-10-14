#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct FlightTicket {
    char pnrCode[15];
    char passengerName[50];
    int ticketClass;
    float baggageWeight;
    float baggageFee;
};

int main() {
    struct FlightTicket danhSachVe[MAX_SIZE];
    int soLuong = 0;
    int choice;
    int i, j;
    int viTri;
    char pnrInput[15];
    char temp;

    do {
        printf("\n============================================\n");
        printf(" HE THONG BAN VE VA CHECK-IN MAY BAY\n");
        printf("============================================\n");
        printf("1. Them ve may bay moi\n");
        printf("2. Hien thi danh sach ve\n");
        printf("3. Cap nhat hanh ly theo PNR\n");
        printf("4. Xoa ve theo PNR\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        while ((temp = getchar()) != '\n' && temp != EOF);

        switch (choice) {
            case 1:
                if (soLuong >= MAX_SIZE) {
                    printf("Danh sach ve da day, khong the them moi!\n");
                    break;
                }

                printf("\nNhap ma PNR: ");
                fgets(danhSachVe[soLuong].pnrCode,
                      sizeof(danhSachVe[soLuong].pnrCode), stdin);

                for (j = 0; danhSachVe[soLuong].pnrCode[j] != '\0'; j++) {
                    if (danhSachVe[soLuong].pnrCode[j] == '\n') {
                        danhSachVe[soLuong].pnrCode[j] = '\0';
                        break;
                    }
                }

                printf("Nhap ho ten hanh khach: ");
                fgets(danhSachVe[soLuong].passengerName,
                      sizeof(danhSachVe[soLuong].passengerName), stdin);

                for (j = 0; danhSachVe[soLuong].passengerName[j] != '\0'; j++) {
                    if (danhSachVe[soLuong].passengerName[j] == '\n') {
                        danhSachVe[soLuong].passengerName[j] = '\0';
                        break;
                    }
                }

                printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");
                scanf("%d", &danhSachVe[soLuong].ticketClass);
                while ((temp = getchar()) != '\n' && temp != EOF);

                printf("Nhap khoi luong hanh ly (kg): ");
                scanf("%f", &danhSachVe[soLuong].baggageWeight);
                while ((temp = getchar()) != '\n' && temp != EOF);

                if (danhSachVe[soLuong].ticketClass == 3) {
                    danhSachVe[soLuong].baggageFee = 0.0f;
                } else if (danhSachVe[soLuong].baggageWeight > 7.0f) {
                    danhSachVe[soLuong].baggageFee =
                        (danhSachVe[soLuong].baggageWeight - 7.0f) * 50000.0f;
                } else {
                    danhSachVe[soLuong].baggageFee = 0.0f;
                }

                printf("Them ve thanh cong! Cuoc phat hanh ly qua can: %.0f VND\n",
                       danhSachVe[soLuong].baggageFee);

                soLuong++;
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }

                printf("\n====================================================================================================\n");
                printf("%-5s | %-12s | %-25s | %-12s | %-13s | %-18s\n",
                       "STT", "Ma PNR", "Ho ten hanh khach",
                       "Hang ve", "Hanh ly (kg)", "Cuoc qua can");
                printf("====================================================================================================\n");

                for (i = 0; i < soLuong; i++) {
                    if (danhSachVe[i].ticketClass == 1) {
                        printf("%-5d | %-12s | %-25s | %-12s | %-13.1f | %-15.0f VND\n",
                               i + 1, danhSachVe[i].pnrCode,
                               danhSachVe[i].passengerName, "Eco",
                               danhSachVe[i].baggageWeight,
                               danhSachVe[i].baggageFee);
                    } else if (danhSachVe[i].ticketClass == 2) {
                        printf("%-5d | %-12s | %-25s | %-12s | %-13.1f | %-15.0f VND\n",
                               i + 1, danhSachVe[i].pnrCode,
                               danhSachVe[i].passengerName, "Deluxe",
                               danhSachVe[i].baggageWeight,
                               danhSachVe[i].baggageFee);
                    } else {
                        printf("%-5d | %-12s | %-25s | %-12s | %-13.1f | %-15.0f VND\n",
                               i + 1, danhSachVe[i].pnrCode,
                               danhSachVe[i].passengerName, "Business",
                               danhSachVe[i].baggageWeight,
                               danhSachVe[i].baggageFee);
                    }
                }

                printf("====================================================================================================\n");
                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }

                printf("Nhap ma PNR can cap nhat hanh ly: ");
                fgets(pnrInput, sizeof(pnrInput), stdin);

                for (j = 0; pnrInput[j] != '\0'; j++) {
                    if (pnrInput[j] == '\n') {
                        pnrInput[j] = '\0';
                        break;
                    }
                }

                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Khong tim thay ve co ma PNR da nhap!\n");
                } else {
                    printf("Tim thay hanh khach: %s\n",
                           danhSachVe[viTri].passengerName);

                    printf("Nhap trong luong hanh ly moi (kg): ");
                    scanf("%f", &danhSachVe[viTri].baggageWeight);
                    while ((temp = getchar()) != '\n' && temp != EOF);

                    if (danhSachVe[viTri].ticketClass == 3) {
                        danhSachVe[viTri].baggageFee = 0.0f;
                    } else if (danhSachVe[viTri].baggageWeight > 7.0f) {
                        danhSachVe[viTri].baggageFee =
                            (danhSachVe[viTri].baggageWeight - 7.0f) * 50000.0f;
                    } else {
                        danhSachVe[viTri].baggageFee = 0.0f;
                    }

                    printf("Cap nhat thanh cong! Phi hanh ly qua can moi: %.0f VND\n",
                           danhSachVe[viTri].baggageFee);
                }
                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }

                printf("Nhap ma PNR can xoa: ");
                fgets(pnrInput, sizeof(pnrInput), stdin);

                for (j = 0; pnrInput[j] != '\0'; j++) {
                    if (pnrInput[j] == '\n') {
                        pnrInput[j] = '\0';
                        break;
                    }
                }

                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Khong tim thay ve co ma PNR da nhap!\n");
                } else {
                    for (i = viTri; i < soLuong - 1; i++) {
                        danhSachVe[i] = danhSachVe[i + 1];
                    }

                    soLuong--;

                    printf("Da xoa thanh cong ve co ma PNR: %s\n", pnrInput);
                }
                break;

            case 5:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

    } while (choice != 5);

    return 0;
}
