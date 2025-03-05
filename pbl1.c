#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//SinhVien
struct SinhVien
{
    char HoTen[50];
    char GioiTinh[3];
    char NgaySinh[10];
};
struct SinhVien SV;


FILE *fp, *fu;

//Func quan ly sinh vien
void ThemSinhVien();
void XoaSinhVien();
void SapXepSinhVien();
void TimSinhVien();
void CapMaSinhVien();
void CapEmail();
void XuatDanhSachSinhVien();

//Main
int main()
{
    fp = fopen("DanhSachSinhVien.txt", "rb+");

    int chon;

    printf("Chuong trinh quan ly sinh vien\n\n");

    

    printf("1 ... Them sinh vien\n");
    printf("2 ... Xoa sinh vien\n");
    printf("3 ... Sap xep sinh vien\n");    
    printf("4 ... Tim sinh vien\n");
    printf("5 ... Cap ma sinh vien\n");
    printf("6 ... Cap email\n");
    printf("7 ... Xuat danh sach sinh vien\n"); 
    printf("8 ... Thoat\n");

    scanf("%d", &chon);
    switch (chon)
    {
        case 1:
            ThemSinhVien();
            break;
        case 2: 
            XoaSinhVien();
            break;
        case 3:
            SapXepSinhVien();
            break;
        case 4:
            TimSinhVien();
            break;
        case 5:
            CapMaSinhVien();
            break;
        case 6:
            CapEmail();
            break;
        case 7:
            XuatDanhSachSinhVien();
            break;
        case 8:
            exit(0);
            break;
        default:
            exit(0);
            break;
    }
}


void ThemSinhVien()
{
    system("cls");

    fseek(fp, 0, SEEK_END);

    
    char another = 'y';
    while (another == 'y')
    {
        fopen("DanhSachSinhVien.txt", "wb+");

        printf("\nNhap ho ten: ");
        scanf("%s", SV.HoTen);

        printf("\nNhap gioi tinh: ");
        scanf("%s", SV.GioiTinh);

        printf("\nNhap ngay sinh (format: dd/mm/yyyy):");
        scanf("%s", SV.NgaySinh);

        fwrite(&SV, sizeof(SV), 1, fp);


        printf("\nBan co muon nhap them sinh vien khac khong? (Y/N): ");
        scanf("%c", &another);
    }
}


void XoaSinhVien()
{

}

void SapXepSinhVien()
{

}

void TimSinhVien()
{

}

void CapMaSinhVien()
{

}

void CapEmail()
{

}

void XuatDanhSachSinhVien()
{
    
}