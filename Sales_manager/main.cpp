#include<bits/stdc++.h>
#include<conio.h>
#include "code_DonHang.cpp"
using namespace std;

void thoatChuongTrinh();
void docListHangHoaFull();
void docListDonHangFull();
void giaoDien1();
void quaylaiTrangChu();
void giaoDienDangNhap();
void docListNhanVienFull();
void giaoDienNhanVien();
void quanLyHangHoa();

int main(){
    
    filein.open("HangHoa.txt",ios_base::in);
    listhh.docListHangHoa(filein);
    //listhh.xuatListHangHoa();
    filein.close();

    foi.open("DonHang.txt",ios_base::in);
    ListDonHang listdh;
    listdh.docListDonHang(foi);
    foi.close();
    
    giaoDien1();
    return 0;
}


void thoatChuongTrinh(){
    system("cls");//xoa man hinh
    cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ Cam on va hen gap lai! ============|\n";
    getch();
	exit(0);
}


void docListHangHoaFull(){
    filein.open("HangHoa.txt",ios_base::in);
    listhh.docListHangHoa(filein);
    listhh.xuatListHangHoa();
    filein.close();
}

void docListDonHangFull(){
    foi.open("DonHang.txt",ios_base::in);
    listdh.docListDonHang(foi);
    foi.close();
    listdh.xuatListDonHang();
}

void giaoDien1(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ CHAO MUNG DEN VOI CUA HANG ============|";
	int j;
	system("cls");
	cout<<"\n\t\t   HE THONG QUAN LY CUA HANG\n";	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Hien thi thong tin hang hoa\n\n\t\t   2. Tim kiem thong tin hang hoa\n\n\t\t   3. Dat hang\n\n\t\t   4. Quan ly\n\n\t\t   5. Thoat"  ;
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nNhap lua chon cua ban: ";

	cin>>j;
    switch(j){
        case 1:
            system("cls");
            cout<<"\t\t\tDANH SACH HANG HOA TRONG KHO\n\n";
            docListHangHoaFull();
            quaylaiTrangChu();
            break;
        
        case 2:
            system("cls");
            cin.ignore();
            listhh.timHangHoaTheoTenHang();
            quaylaiTrangChu();
            break;

        case 3:
            system("cls");
            foi.open("DonHang.txt",ios_base::in);
            listdh.docListDonHang(foi);
            foi.close();
            //listdh.xuatListDonHang();
            cin.ignore();
            listdh.themDonHang();
            fot.open("DonHang.txt",ios_base::out);
            listdh.ghiListDonHang(fot);
            fot.close();
            quaylaiTrangChu();
            break;

        case 4:
            system("cls");
            cin.ignore();
            giaoDienDangNhap();
            break;
        case 5:
            thoatChuongTrinh();
    }
}
void quaylaiTrangChu(){
    cout<<endl<<"Nhap 1 de quay lai trang chu\nNhap 2 de thoat chuong trinh\n";
    int i;
    cout<<"Nhap lua chon cua ban: ";
    cin>>i;
        if(i==1) giaoDien1();
        if(i==2) thoatChuongTrinh();
        if(i!=1 &&i!=2){
            cout<<"Nhap khong chinh xac, vui long nhap lai!"<<endl;
            cout<<endl<<"Nhap 1 de quay lai trang chu\nNhap 2 de thoat chuong trinh\n";
            cin>>i;
        }
}
void giaoDienDangNhap(){

    int iSoLanDangNhap=0;
    docListNhanVienFull();
    string strUser,strPass;
    dangnhap:
    strUser="",strPass="";
    char cKiTu;
    system("cls");
    cout<<"\n=============================================================\n";
    cout<<"\n\t\t   DANG NHAP HE THONG\n";	
	cout<<"\n=============================================================\n";

    cout<<"\n\n\n\n\t\tUser: ";
        getline(cin,strUser);
    cout<<"\n\n\n\n\t\tPassword: ";
    for(int z=0;z<3;z++)
	{
		cKiTu=getch();
        strPass+=cKiTu;
		system("cls");
        cout<<"\n=============================================================\n";
        cout<<"\n\t\t   DANG NHAP HE THONG\n";	
	    cout<<"\n=============================================================\n";
        cout<<"\n\n\n\n\t\tUser: "<<strUser;
        
        cout<<"\n\n\n\n\t\tPassword: ";
		for(int i=1;i<=z+1;i++)
		{
			cout<<"*";
		}
	}

    if(listnv.checkDangNhap(strUser,strPass)){
        cout<<endl<<"Dang nhap thanh cong!"<<endl;
        system("pause");
        system("cls");
        giaoDienNhanVien();

    }
    else{
        iSoLanDangNhap++;
        if(iSoLanDangNhap==3){
            cout<<"\n\nTruy cap bi tu choi..\n\n";
            getch();
            getch();
            
            exit(0);
        }
        else{
            goto dangnhap;
        }
        
    }
}

void docListNhanVienFull(){
    ifile.open("Admin.txt",ios_base::in);
    listnv.docListNhanVien(ifile);
    ifile.close();
}
void giaoDienNhanVien(){
    cin.clear();
    int i;
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tMENU QUAN LY\n1. Xu ly don hang\n2. Quan ly hang hoa\n3. Exit \n4. Dang xuat";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Nhap lua chon cua ban :";
	cin>>i;

    switch(i){
        case 1:
            cin.ignore();
            //xuat list don hang dang ton tai
            system("cls");
            cout<<"\n\t\t\tDANH SACH DON HANG CHO XU LY\n\n";
            docListDonHangFull();
            getch();
            system("cls");

            //xuat list hang hoa
            cout<<"\n\t\t\tDANH SACH HANG HOA VA SO LUONG TRONG KHO\n\n";
            docListHangHoaFull();
            getch();
            system("cls");

            cout<<"Dang xu ly don hang..."<<endl;
            getch();

            //xu ly don hang, ghi lai file hang hoa
            listdh.xoaXuLyListDonHang();
            fileout.open("HangHoa.txt",ios_base::out);
            listhh.ghiListHangHoa(fileout);
            fileout.close();

            //ghi lai file don hang
            fot.open("DonHang.txt",ios_base::out);
            listdh.ghiListDonHang(fot);
            fot.close();

            //xuat lai hang hoa sau khi da xu ly don hang
            system("cls");
            cout<<"\n\t\t\tDANH SACH HANG TRONG KHO SAU KHI THUC HIEN\n\n";
            docListHangHoaFull();
            //listhh.xuatListHangHoa();
            getch();
            cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
            system("pause");
            giaoDienNhanVien();
            break;

        case 2:
            cin.ignore();
            quanLyHangHoa();
            break;

        case 3:
            cout<<"Dang thoat chuong trinh...";
            system("cls");
            cout<<"\n\n\n\t\t\tThank You!!";
            getch();
            exit(0);
        case 4:
            cin.ignore();
            cout<<"Dang xuat thanh cong!!!"<<endl;
            system("pause");
            giaoDienDangNhap();
            break;
    }
}

void quanLyHangHoa(){
    string strMaHang;
    int i,iSo;
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tMENU QUAN LY HANG HOA\n1. Them hang hoa moi\n2. Xoa hang hoa theo ma hang\n3. Cap nhat so luong hang hoa\n4. Tro ve menu quan ly\n5. Thoat";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Nhap lua chon cua ban :\t";
	cin>>i;
    switch(i){
        case 1:
        system("cls");
        cin.clear();
        cin.ignore();
        listhh.themHangHoa();
        fileout.open("HangHoa.txt",ios_base::out);
        listhh.ghiListHangHoa(fileout);
        fileout.close();
        cout<<"Da them hang hoa <3\n";
        getch();
        cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
        system("pause");
        quanLyHangHoa();
        break;

        case 2:
        system("cls");
        cin.clear();
        cin.ignore();
        cout<<"\nNhap ma hang can xoa: ";
        getline(cin,strMaHang);
        listhh.xoaHangHoaTheoMaHang(strMaHang);
        fileout.open("HangHoa.txt",ios_base::out);
        listhh.ghiListHangHoa(fileout);
        fileout.close();
        cout<<"\n\t\t\tDANH SACH HANG TRONG KHO SAU KHI THUC HIEN\n";
        docListHangHoaFull();
        getch();
        cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
        system("pause");
        quanLyHangHoa();
        break;

        case 3:
        system("cls");
        cin.ignore();
        cout<<"\nNhap ma hang can cap nhat so luong: ";
        getline(cin,strMaHang);
        cout<<"\nNhap so luong ban muon them vao: ";
        cin>>iSo;
        cin.ignore();
        listhh.capNhatSoLuongTheoMa(strMaHang,iSo);
        fileout.open("HangHoa.txt",ios_base::out);
        listhh.ghiListHangHoa(fileout);
        fileout.close();
        cout<<"\n\t\t\tDANH SACH HANG TRONG KHO SAU KHI THUC HIEN\n";
        docListHangHoaFull();
        getch();
        cout<<"Nhan phim bat ky de tro lai trang quan ly \n";
        system("pause");
        quanLyHangHoa();
        break;
        
        case 4:
        system("cls");
        cin.ignore();
        giaoDienNhanVien();
        break;
        case 5:
        system("cls");
        thoatChuongTrinh();
    }
}