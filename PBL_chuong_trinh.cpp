#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct PhanLoai{
	int NienKhoa;
	char Khoa[50];
};

struct SinhVien{
    char HoLot[20];
    char Ten[10];
    char GioiTinh[10];
    char NgaySinh[30];
    char DiaChi[30];
    int stt;
    char email[100];
    char MSSV[20];  
};

struct SinhVien SV;
//size SV
long int size = sizeof(SV);

FILE *fp, *fp_delete;

//Func quan ly sinh vien
void XoaXuongDong(char s[]);
void ThemSinhVien();
void CapNhatSinhVien();
void XoaSinhVien();
void SapXepSinhVien(SinhVien sv[], int n);
void TimSinhVien();
const char* CapMaSinhVien(int n, int nam, int count);
const char* CapEmail(const char* MSSV);
void XuatThongTinSV(SinhVien SV);
void XuatDanhSachSinhVien();

//Main
int main()
{

    // opening the file 
	fp = fopen("DanhSachSinhVien.txt", "rb+"); 

	// showing error if file is 
	// unable to open. 
	if (fp == NULL) { 
		fp = fopen("DanhSachSinhVien.txt", "wb+"); 
		if (fp == NULL) { 
			printf("\nCannot open file..."); 
			exit(1); 
		} 
	} 

	SinhVien SV, sv[200];
	int n;
    int chon;

    

start:
    printf("\nCHUONG TRINH QUAN LI DANH SACH SINH VIEN\n\n");
        printf("=============MENU=================\n");
        printf("1 ... Them sinh vien\n");
        printf("2 ... Xoa sinh vien\n");
        printf("3 ... Sap xep sinh vien\n");    
        printf("4 ... Tim sinh vien\n");
        printf("5 ... Cap ma sinh vien\n"); 
        printf("6 ... Cap email\n");
        printf("7 ... Xuat danh sach sinh vien\n"); 
        printf("8 ... Thoat\n");

        printf("\nHay nhap lua chon cua ban:");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
        	    ThemSinhVien();
			    break;
            case 2: 
                XoaSinhVien();
                break;
            case 3:
                SapXepSinhVien(sv,n);
                break;
            case 4:
                TimSinhVien();
                break;
            case 5:
                const char* CapMaSinhVien(int n, int nam, int count);
                break;
            case 6:
                const char* CapEmail(const char* MSSV);
                break;
            case 7:
                XuatDanhSachSinhVien();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Lua chon khong hop le \nNhap bat ky de tro lai menu");
                char temp[100];
                scanf("%s", &temp);
                goto start;
                break;
        }
}

//supplementary funcs
int HowManyNumb(int n)
{
    int i = 0;
    while (n > 0)
    {
        n = n / 10;
        i++;
    }
    return i;
}

const char* After(int n)
{
    static char temp[4];
    int i = HowManyNumb(n);
    int Rep = 4 - i;
    for (int j = 0; j < Rep; j++)
    {
        temp[j] = '0';
    }
    
    char IntStorage[4];
    sprintf(IntStorage, "%d", n);
    strcat(temp, IntStorage);
    return temp;
}

void XoaXuongDong(char s[]){
	if(s[strlen(s)-1] == '\n')
	    s[strlen(s)-1]='\0';
}

void sosanhSinhVien(SinhVien *a, SinhVien *b){
	SinhVien temp = *a;
	*a = *b;
	*b = temp;
}
              
//real funcs
void ThemSinhVien()
{
    char NienKhoa[3] = "24";
    char Khoa[4];
    char DuoiEmail[30] = "@sv1.dut.udn.vn";

    if (fp == NULL) 
    {
        printf("Khong the mo file.\n");
        return;
    }
    fseek(fp, 0, SEEK_END);
    
    char another = 'y';
    while (another == 'y')
    {
    	getchar();
        printf("\nNhap ho va ten lot: ");
        gets(SV.HoLot);
        
        printf("\nNhap ten: ");
        gets(SV.Ten);

        printf("\nNhap gioi tinh: ");
        gets(SV.GioiTinh);

        printf("\nNhap ngay sinh (format: dd/mm/yyyy):");
        gets(SV.NgaySinh);
        
        printf("\nNhap dia chi: ");
        gets(SV.DiaChi);

        int MaKhoa;

        int CoKhi = 1, CNTT = 1, CoKhiGT = 1, CNDL = 1, Dien = 1, DTVT = 1, Hoa = 1, XDCD = 1, XDCTT = 1, MT = 1, QLDA = 1, KT = 1, KHCNTT = 1;

        printf("Danh sach ma khoa:");
        printf("\n 101: Co khi \t102: Cong nghe thong tin \t103: Co khi giao thong \t104: CN Nhiet - DL");
        printf("\n 105: Dien \t106: Dien tu vien thong \t107: Hoa \t109: XD Cau Duong");  
        printf("\n 110: XD Dan dung & Cong nghiep \t111: XD Cong trinh thuy \t117: Moi truong");
        printf("\n 118: Quan ly du an \t121: Kien truc \t123: Khoa hoc Cong nghe tien tien");      
        printf("\nNhap ma khoa cua ban: ");
        
        fwrite(&SV, size,1, fp);

            
        system("cls");
        printf("\nBan co muon nhap them sinh vien khac khong? (Y/N): ");
        scanf(" %c", &another);    
    }
}

void CapNhatSinhVien()
{
    char another = 'y';
	char TempHoLot[20];
    char TempTen[10];

    while (another == 'y')
    {
    printf("\nNhap ho lot can tim: ");
    scanf("%s", TempHoLot);
    printf("\nNhap ten can tim: ");
    scanf("%s", TempTen);
    }

}

void XoaSinhVien()
{
    system("cls");
    char MSSV_Delete[20];
    char another = 'y';
    
    while (another == 'y')
    {
        printf("Nhap MSSV can xoa: ");
        scanf("%s", MSSV_Delete);
        
        fp_delete = fopen("DanhSachSinhVien_PostDelete.txt", "wb");
        rewind(fp);

        while (fread(&SV, size, 1, fp) == 1)
        {
            if (strcmp (SV.MSSV, MSSV_Delete) != 0)
            {
                fwrite(&SV, size, 1, fp_delete);
            }
        }

        fclose(fp);
        fclose(fp_delete);
        remove("DanhSachSinhVien.txt");
        rename("DanhSachSinhVien_PostDelete.txt", "DanhSachSinhVien");
        fp = fopen("DanhSachSinhVien.txt", "rb+");

        printf("Ban co muon xoa them sinh vien khac khong? \n");
        printf("Y/N \n");

        fflush(stdin);
        scanf("%s", another);
    }
}

void SapXepSinhVien(SinhVien sv[], int n){
	for( int i=1; i<=n-1; i++){
		for( int j=i+1; j<=n; j++){
			
			if(strcmp(sv[i].Ten,sv[j].Ten) > 0)
			    sosanhSinhVien(&sv[i],&sv[j]);
			    
			else if(strcmp(sv[i].Ten,sv[j].Ten) == 0){
				
				if(strcmp(sv[i].HoLot,sv[j].HoLot) >0)
				    sosanhSinhVien(&sv[i],&sv[j]);
			}
		}
	}
}

void XuatThongTinSV(SinhVien SV){
    system("cls");
	printf("\n%d  %-15s %-20s %-10s %-15s %-10s %-20s %-5s",SV.stt, SV.MSSV, SV.HoLot, SV.Ten, SV.NgaySinh, SV.GioiTinh, SV.DiaChi);
    exit(0);
}

void TimSinhVien()
{
    char another = 'y';
    char MSSV_Find[20];

    while (another == 'y')
    {
        printf("Nhap MSSV sinh vien can tim: ");
        scanf("%s", MSSV_Find);

        rewind(fp);

        int found = 0;
        while (fread(&SV, size, 1, fp) == 1)
        {
            if (strcmp(SV.MSSV, MSSV_Find) == 0)
            {
                printf("\nThong tin sinh vien:\n");
                printf("Ho lot: %s\n", SV.HoLot);
                printf("Ten: %s\n", SV.Ten);
                printf("Gioi tinh: %s\n", SV.GioiTinh);
                printf("Ngay sinh: %s\n", SV.NgaySinh);
                printf("Dia chi: %s\n", SV.DiaChi);
                printf("MSSV: %s\n", SV.MSSV);
                printf("Email: %s\n", SV.email);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Khong tim thay sinh vien voi MSSV: %s\n", MSSV_Find);
        }

        printf("\nTiep tuc tim sinh vien? (Y/N): ");
        fflush(stdin);
        scanf("%s", another);
    }
}

const char* CapMaSinhVien(int n, int nam, int count) // Lay MSSV theo cau truc So khoa + Nien khoa + STT
{
    //idea
    // MSSV = Khoa (int n) + NienKhoa (int nam) + SoThuTu (int count)
    //Khoa
    char Khoa[4];
    sprintf(Khoa, "%d", n);
    //NienKhoa
    char NienKhoa[4];
    sprintf(NienKhoa, "%d", nam); // Correct format specifier for integer
    //SoThuTu
    char STT[5];
    const char *temp = After(count);
    strcpy(STT, temp);
    count++;
    //MSSV 
    strcat(Khoa, NienKhoa);
    strcat(Khoa, STT);
    
    return Khoa;
} 

const char* CapEmail(const char* MSSV)
{
    static char email[100];
    strcpy(email, MSSV);
    char DuoiEmail[30] = "@sv1.dut.udn.vn";
    strcat(email, DuoiEmail);
    return email;
}

void XuatDanhSachSinhVien()
{
	system("cls");
    rewind(fp);

    
    printf("Ho lot: \tTen: \tGioi Tinh: \tDia chi: \t\tNgay sinh:");
    
    while (fread(&SV, size, 1, fp) == 1)
    {
        printf("\n%s \t%s \t%s \t\t%s \t%s",
             SV.HoLot, SV.Ten, SV.GioiTinh, SV.DiaChi, SV.NgaySinh);
    }
    
}
