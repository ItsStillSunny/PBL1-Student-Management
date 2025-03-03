#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//SinhVien
struct SinhVien
{
    char HoLot[20];
    char Ten[10];
    char GioiTinh[3];
    char NgaySinh[10];
    char DiaChi[50];
} SinhVien;

//Pointer
struct Node {
	struct Node *next;
	struct Symbol *element;
};

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
    FILE *fp, *fu;
    struct SinhVien sinhvien[100];
    //opening file
    fp = fopen("DanhSachSinhVien.txt", "ab");

    //input
    for (int i = -1; i < 100; i++)
    {
    printf("Ban dang o hoc sinh thu %d\n", i+2);

    printf("Nhap ho lot: ");
    scanf("%s", &sinhvien[i].HoLot);
    printf("Nhap ten: ");
    scanf("%s", &sinhvien[i].Ten);
    printf("Nhap gioi tinh: ");
    scanf("%s", &sinhvien[i].GioiTinh);
    printf("Nhap ngay sinh: ");
    scanf("%s", &sinhvien[i].NgaySinh);
    printf("Nhap dia chi: ");
    scanf("%s", &sinhvien[i].DiaChi);

    fwrite(&sinhvien[i], sizeof(sinhvien[i]),
		1, fp);

    fclose(fp);

    printf("Ban co muon nhap tiep khong? :\nN: Khong\nY: Co\n");
    {
        if (getchar() == 'N')
        {
            exit(0);
        }
        else if (getchar() == 'Y')
        {
            continue;
        }     
    }
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
