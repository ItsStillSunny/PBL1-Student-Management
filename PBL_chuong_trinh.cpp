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
    char GioiTinh[3];
    char NgaySinh[30];
    char DiaChi[30];
    int stt;
    char email[100];
    char MSSV[20];
    
};

typedef struct SinhVien SinhVien;

FILE *fp, *fu;

//Func quan ly sinh vien
void XoaXuongDong(char s[]);
void ThemSinhVien(SinhVien SV);
void CapNhatSinhVien();
void XoaSinhVien(SinhVien sv[], int n);
void SapXepSinhVien(SinhVien sv[], int n);
void TimSinhVien(SinhVien SV, int n);
void CapMaSinhVien();
void CapEmail();
void XuatThongTinSV(SinhVien SV);
void XuatDanhSachSinhVien(SinhVien SV, int n);

//Main
int main()
{
	SinhVien SV, sv[200];
	int n;
    int chon;

    printf("\nCHUONG TRINH QUAN LI DANH SACH SINH VIEN\n\n");
    do{
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
        	    ThemSinhVien(SV);
			    break;
            case 2: 
                XoaSinhVien(sv,n);
                break;
            case 3:
                SapXepSinhVien(sv,n);
                break;
            case 4:
                TimSinhVien(SV,n);
                break;
            case 5:
                CapMaSinhVien();
                break;
            case 6:
                CapEmail();
                break;
            case 7:
                XuatDanhSachSinhVien(SV,n);
                break;
            case 8:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }
   while(chon != '8');
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

void ThemSinhVien(SinhVien SV)
{
    system("cls");

    fp = fopen("DanhSachSinhVien.txt", "ab+"); 
    if (fp == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    
    char another = 'y';
    while (another == 'y')
    {
    	printf("\nSinh vien thu:");
    	scanf("%d",&SV.stt);
    	
    	getchar(); 
        printf("\nNhap ho va ten lot: ");
        gets(SV.HoLot);
        
        printf("\nNhap ten: ");
        scanf("%s", SV.Ten);

        printf("\nNhap gioi tinh: ");
        scanf("%s", SV.GioiTinh);

        printf("\nNhap ngay sinh (format: dd/mm/yyyy):");
        scanf("%s", SV.NgaySinh);
        
        getchar(); 
        printf("\nNhap dia chi: ");
        gets(SV.DiaChi);

        fwrite(&SV, sizeof(SV), 1, fp);

        printf("\nBan co muon nhap them sinh vien khac khong? (Y/N): ");
        scanf(" %c", &another); 
    }
    fclose(fp);
}

void CapNhatSinhVien()
{
	
}

void XoaSinhVien(SinhVien sv[], int n){
	char ID[20];
	int found = 0; 
	printf("Nhap MSSV cua sinh vien can xoa: ");
	scanf("%s",ID);
	
	for( int i=1; i<=n; i++){
		if(strcmp(sv[i].MSSV,ID)==0){
			found = 1;
			for( int j=i; i<=n; j++){
				sv[j] = sv[j+1];
			}
			printf("Da xoa sinh vien co MSSV la %s ra khoi danh sach!",ID);
			break;
		}
	}
	if(found == 0){
		printf("Sinh vien co MSSV la %s khon ton tai",ID);
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
	printf("\n%d  %-15s %-20s %-10s %-15s %-10s %-20s %-5s",SV.stt, SV.MSSV, SV.HoLot, SV.Ten, SV.NgaySinh, SV.GioiTinh, SV.DiaChi, SV.email);
}

void TimSinhVien(SinhVien SV, int n){
	char ID[20];
	int found = 0;
	printf("Nhap MSSV cua sinh vien can tim kiem: ");
	scanf("%s",ID);
	
	fp = fopen("DanhSachSinhVien.txt","rb");
	if(fp == NULL ){
		printf("FILE KHONG TON TAI!\n");
		return;
	}
	
	while(fread(&SV, sizeof(SV),1,fp)==1){
		if(strcmp(ID,SV.MSSV) == 0){
			found = 1; // da tim thay sinh vien can tim kiem. 
			XuatThongTinSV(SV);
			break;
		}
	}
	if(found == 0){
		printf("Sinh vien co MSSV la %s khong ton tai!\n", ID);
	}
	fclose(fp);

}

void CapMaSinhVien()
{

}

void CapEmail()
{

}

void XuatDanhSachSinhVien(SinhVien SV, int n){
	
	fp = fopen("DanhSachSinhVien.txt", "rb");
	if(fp==NULL){
		printf("FILE KHONG TON TAI!");
		exit(0);
	}
	
	printf("\n%d  %-15s %-20s %-10s %-10s %-15s %-10s %-20s %-5s","STT", "MSSV", "Ho va ten lot", "Ten", "Ngay sinh", "Gioi tinh", "Dia chi", "Email");
	
	while(fread(&SV, sizeof(SV),1,fp)==1){
		XuatThongTinSV(SV);
	}
	
	fclose(fp);
}
