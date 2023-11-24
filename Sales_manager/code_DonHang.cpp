#include <iostream>
#include <fstream>
#include<conio.h>
#include<string.h>
#include<math.h>
#include "code_HangHoa.cpp"
#include "code_admin.cpp"
using namespace std;

ifstream foi;
ofstream fot;

class DonHang:public HangHoa{
protected:
    string _strMaHangDat[100];
    int _iSoLuongMatHang[100];
    double _dTongTien;
    string _strTenKhach;
    string _strDiaChi;
    string _strSoDienThoai;
    string _strNgayDatHang;
    int _iLoaiMatHang;
    public:
    // khoi tạo
    DonHang(int _iSoLuongMatHang[]={0},double _dTongTien=0,string _strTenKhach="",
    string _strDiaChi="",string _strSoDienThoai="", string _strNgayDatHang="",
    int _iLoaiMatHang=0){
        this->_dTongTien=_dTongTien;
        this->_strTenKhach=_strTenKhach;
        this->_strDiaChi=_strDiaChi;
        this->_strSoDienThoai=_strSoDienThoai;
        this->_strNgayDatHang=_strNgayDatHang;
        this->_iLoaiMatHang=_iLoaiMatHang;
    }
    //sao chép
    DonHang(const DonHang&a){
        _dTongTien=a._dTongTien;
        _strTenKhach=a._strTenKhach;
        _strDiaChi=a._strDiaChi;
        _strSoDienThoai=a._strSoDienThoai;
        _strNgayDatHang=a._strNgayDatHang;
        _iLoaiMatHang=a._iLoaiMatHang;
    }
    //hàm get
    double getTongTien();
    string getTenKhach();
    string getDiaChi();
    string getSoDienThoai();
    string getNgayDatHang();
    int getLoaiMatHang();
    //hàm set
    void setTongTien(double _dTongTien);
    void setTenKhach(string _strTenKhach);
    void setDiaChi(string _strDiaChi);
    void setSoDienThoai(string _strSoDienThoai);
    void setNgayDatHang(string _strNgayDatHang);
    void setLoaiMatHang(int _iLoaiMatHang);

    void nhapThongTinKhachHang();
    bool timHangCanMua();
    void taoDonHang();
    void xuatDonHang();
    void ghiDonHang(ofstream &fileout);
    void docDonHang(ifstream &filein,int i);
//cac ham de xu ly don hang o day

void xoaXuLyDonHang();

   ~ DonHang(){};
};
    //hàm get
    double DonHang::getTongTien(){return _dTongTien;}
    string DonHang::getTenKhach(){ return _strTenKhach;};
    string DonHang::getDiaChi(){return _strDiaChi;};
    string DonHang::getSoDienThoai(){return _strSoDienThoai;}
    string DonHang::getNgayDatHang(){return _strNgayDatHang;}
    int DonHang::getLoaiMatHang(){return _iLoaiMatHang;}
    //hàm set
    void DonHang::setTongTien(double _dTongTien){this->_dTongTien=_dTongTien; }
    void DonHang::setTenKhach(string _strTenKhach){this->_strTenKhach=_strTenKhach;}
    void DonHang::setDiaChi(string _strDiaChi){this->_strDiaChi=_strDiaChi;}
    void DonHang::setSoDienThoai(string _strSoDienThoai){this->_strSoDienThoai=_strSoDienThoai;}
    void DonHang::setNgayDatHang(string _strNgayDatHang){this->_strNgayDatHang=_strNgayDatHang;}
    void DonHang::setLoaiMatHang(int _iLoaiMatHang){this->_iLoaiMatHang=_iLoaiMatHang;}


    void DonHang::nhapThongTinKhachHang(){
        //nhap thong tin khach hang
        cout<<"Nhap ten khach hang: ";
        getline(cin,_strTenKhach);
        cout<<"Nhap dia chi khach hang: ";
        getline(cin,_strDiaChi);
        cout<<"Nhap so dien thoai khach hang: ";
        getline(cin,_strSoDienThoai);
        cout<<"Nhap ngay dat hang: ";
        getline(cin,_strNgayDatHang);
        //nhap danh sach hang hoa khach dat
        cin.clear();
    }
    bool DonHang::timHangCanMua(){
        cout<<"Nhap ma san pham can mua: ";
        getline(cin,_strMaHangDat[_iLoaiMatHang]);
        //cout<<_strMaHangDat[_iLoaiMatHang].size()<<endl;
        while(_strMaHangDat[_iLoaiMatHang].size()!=4){
                cout<<"Ma hang nhap khong chinh xac, vui long nhap lai ! "<<endl;
                cout<<"Nhap ma hang hoa: ";
                getline(cin,_strMaHangDat[_iLoaiMatHang]);
        }
        

        cout<<"Nhap so luong can mua: ";
        cin>>_iSoLuongMatHang[_iLoaiMatHang];
        cin.ignore();
        if(listhh.kiemHangHoaTheoMaHang(_strMaHangDat[_iLoaiMatHang],_iSoLuongMatHang[_iLoaiMatHang])){
            cout<<"Da cho vao gio hang"<<endl;
            _iLoaiMatHang++;
            return true;
        } 
        else{
            cout<<"San pham sai ma hoac khong du so luong trong kho!"<<endl;
            return false;
        }
        
    }
    void DonHang::taoDonHang(){
        cout<<"TAO DON HANG MOI"<<endl;
        nhapThongTinKhachHang();
        cout<<"Nhap va tim kiem hang hoa can mua"<<endl;
        int k;
        nhapdon:
        if(timHangCanMua()){
            cout<<"De chon tiep san pham nhan phim 1"<<endl;
            cout<<"De hoan thanh don hang nhan phim 2"<<endl;
            cout<<"Nhap lua chon cua ban: ";
            cin>>k;
            if(k!=1 &&k!=2) {
                cout<<"nhap khong chinh xac, vui long nhap lai";
                cin>>k;
            }
            else{
                if(k==1) {cin.ignore();goto nhapdon;}
                if(k==2) {
                    //ghiDonHang(fileout);
                    cout<<"Tong cong: ";
                    for(int i=0;i<_iLoaiMatHang;i++){
                        _dTongTien+=listhh.timGiaBanTheoMaHang(_strMaHangDat[i])*_iSoLuongMatHang[i];
                    }
                    cout<<_dTongTien<<endl;
                    cout<<"Don hang dang cho xu li"<<endl;
                }
            }
        }
        else{//truong hop nhap sai ma hoac so luong
            cout<<"De chon tiep san pham nhan phim 1"<<endl;
            cout<<"De hoan thanh don hang nhan phim 2"<<endl;
            cin>>k;
            if(k!=1 &&k!=2) {
                cout<<"nhap khong chinh xac, vui long nhap lai";
                cin>>k;
            }
            else{
                if(k==1) {cin.ignore();goto nhapdon;}
                if(k==2) {
                    cout<<"Tong cong: ";
                    for(int i=0;i<_iLoaiMatHang;i++){
                        _dTongTien+=listhh.timGiaBanTheoMaHang(_strMaHangDat[i]);
                    }
                    cout<<_dTongTien<<endl;
                    cout<<"Don hang dang cho xu li"<<endl;
                }
            }
        }
    }
    void DonHang::xuatDonHang(){
        cout<<endl<<"Ten khach hang: "<<_strTenKhach<<endl;
        cout<<"Dia chi: "<<_strDiaChi<<endl;
        cout<<"So dien thoai: "<<_strSoDienThoai<<endl;
        cout<<"Ngay dat hang: "<<_strNgayDatHang<<endl;
        cout<<"Danh sach hang dat: "<<endl;
        double dTongTien=0;
        for(int i=0;i<_iLoaiMatHang;i++){
            cout<<_strMaHangDat[i]<<"-"<<_iSoLuongMatHang[i]<<endl;
        }
        for(int i=0;i<_iLoaiMatHang;i++){
            //cout<<_strMaHangDat[i]<<"-"<<_iSoLuongMatHang[i]<<endl;
            dTongTien+=listhh.timGiaBanTheoMaHang(_strMaHangDat[i])*_iSoLuongMatHang[i];
        }
        _dTongTien=dTongTien;
        cout<<"Tong tien: "<<_dTongTien<<endl<<endl;
    }
    void DonHang::ghiDonHang(ofstream &fileout){
        fileout<<_strTenKhach<<","<<_strDiaChi<<","<<_strSoDienThoai<<","<<_strNgayDatHang<<","<<"\n";
        for(int i=0;i<_iLoaiMatHang;i++){
            fileout<<_strMaHangDat[i]<<",";
            fileout<<_iSoLuongMatHang[i];
            if(i!=_iLoaiMatHang-1)
                fileout<<"\n";
            else{
                fileout<<"\n";
                fileout<<".";
            }
            
        }
        //de tach cac don trong file ra
    }
    void DonHang::docDonHang(ifstream &filein,int i){
        int dem=0;
        nhaytro:
        filein.seekg(0,filein.beg);
        if(i!=0){
            dem=0;
            while(filein.eof()==false){//doc den khi con tro ve cuoi file
                string x;
                getline(filein,x);//doc nguyen dong
                if(x==".") dem++;
                if(dem==i){
                    goto nhapthongtin;
                }
                
            }
        }
        nhapthongtin:
        getline(filein,_strTenKhach,',');
        getline(filein,_strDiaChi,',');
        getline(filein,_strSoDienThoai,',');
        getline(filein,_strNgayDatHang,',');
        string temp;
        getline(filein,temp);

        //dem so loai hang dat
        filein.seekg(0,filein.cur);
        int demsl=0;
        while(filein.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(filein,x);//doc nguyen dong
            if(x!=".") demsl++;
            else break;
        }
        _iLoaiMatHang=demsl;
        //cout<<_iLoaiMatHang<<endl;

        //tim tro lai vi tri cu
        filein.seekg(0,filein.beg);
        if(i!=0){
            dem=0;
            while(filein.eof()==false){//doc den khi con tro ve cuoi file
                string x;
                getline(filein,x);//doc nguyen dong
                if(x==".") dem++;
                if(dem==i){
                    goto nhaplist;
                }
                
            }
        }

        //nhap list hang dat
        nhaplist:
        string phanDu;
        getline(filein,phanDu);
        for(int i=0;i<_iLoaiMatHang;i++){
            getline(filein,_strMaHangDat[i],',');
            //cout<<_strMaHangDat[i]<<"day ne"<<endl;
            filein>>_iSoLuongMatHang[i];
            //cout<<_iSoLuongMatHang[i]<<"nua ne"<<endl;
            filein.ignore();
        }
    }
//cac ham de xu ly don hang o day

void DonHang::xoaXuLyDonHang(){
    for(int i=0;i<_iLoaiMatHang;i++){
        listhh.giamSoLuongTheoMa(_strMaHangDat[i],_iSoLuongMatHang[i]);
    }
}


/*-------------------LIST DON HANG---------------------------*/

//khai bao danh sach DON HANG
class ListDonHang:public DonHang{
protected:
    DonHang *_pDonHang;
    int _iSoLuongDon;
    
public:
    int getSoLuong();
    void docListDonHang_test(ifstream& is);
    void docListDonHang(ifstream& is);
    void docList_DH(ifstream& is);
    void themDonHang();
    void xoaDonHangLoi();
    void xoaDonHang();

    void ghiListDonHang(ofstream&fileout);
    void xuatListDonHang();
    void xoaXuLyListDonHang();
};
//LISTDONHANG
int ListDonHang::getSoLuong(){return _iSoLuongDon;}
    void ListDonHang::docListDonHang_test(ifstream& is){
        int dem=0;
        //B1:tim so luong hang hoa trong file txt- tim so dong de cap phat mang dong
        while(is.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(is,x);//doc nguyen dong
            if(x==".")
                dem++;
        }
        //cout<<dem<<endl;
        _iSoLuongDon=dem;
        _pDonHang=new DonHang[_iSoLuongDon];
        int j=0;
        while(is.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(is,x);//doc nguyen dong
            if(x!="."){
                
                string temp;
                getline(is,temp);
            }
                
        }
        
    }
    void ListDonHang::docListDonHang(ifstream& is){
        int dem=0;
        //B1:tim so luong hang hoa trong file txt- tim so dong de cap phat mang dong
        while(is.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(is,x);//doc nguyen dong
            if(x==".")
                dem++;
        }
        
        _iSoLuongDon=dem;
        //B2: CapPhat mang dong hang hoa
        _pDonHang=new DonHang[_iSoLuongDon];
        //B3: Cho con tro chi vi ve dau file
        is.seekg(is.beg,is.beg);
        //B4:doc danh sach hang hoa
        docList_DH(is);
        
    }
    void ListDonHang::docList_DH(ifstream& is){
        for(int i=0;i<_iSoLuongDon;i++){
            _pDonHang[i].docDonHang(is,i);//doc thong tin thu i
        }
    }
    void ListDonHang::themDonHang(){
        int newSize=_iSoLuongDon+1;
        DonHang *temp=new DonHang[newSize];
        for(int i=0;i<_iSoLuongDon;i++){
            temp[i]=_pDonHang[i];
        }
        delete[]_pDonHang;

        _pDonHang=temp;
        _iSoLuongDon=newSize;
        _pDonHang[_iSoLuongDon-1].taoDonHang();
        if(_pDonHang[_iSoLuongDon-1].getLoaiMatHang()==0){
            xoaDonHangLoi();
        }
    }
    void ListDonHang::xoaDonHangLoi(){
        int newSize=_iSoLuongDon-1;
        DonHang* temp=new DonHang[newSize];
        for(int i=0;i<newSize;i++){
            temp[i]=_pDonHang[i];
        }
        delete[]_pDonHang;
        _pDonHang=temp;
        _iSoLuongDon=newSize;
    }
    void ListDonHang::xoaDonHang(){
        int newSize=_iSoLuongDon-1;
        cout<<newSize<<endl;
        DonHang* temp=new DonHang[newSize];
        for(int i=0;i<newSize;i++){
            temp[i]=_pDonHang[i+1];
            
        }
        delete[]_pDonHang;
        _pDonHang=temp;
        _iSoLuongDon=newSize;
    }

    void ListDonHang::ghiListDonHang(ofstream&fileout){
        for(int i=0;i<_iSoLuongDon;i++){
            _pDonHang[i].ghiDonHang(fileout);
            if(i!=_iSoLuongDon-1) fileout<<"\n";
        }
    }
    void ListDonHang::xuatListDonHang(){
        for(int i=0;i<_iSoLuongDon;i++){
            cout<<"\t\t\tDon hang thu "<<i+1<<endl;
            _pDonHang[i].xuatDonHang();
        }
    }
    void ListDonHang::xoaXuLyListDonHang(){
        foi.open("DonHang.txt",ios_base::in);
        docListDonHang(foi);
        foi.close();

        for(int i=0;i<_iSoLuongDon;i++){
            _pDonHang[i].xoaXuLyDonHang();
            
        }
        int iSLuong_temp=_iSoLuongDon;
        for(int i=0;i<iSLuong_temp;i++){
            xoaDonHang();
        }
        
    }


//khai bao bien listdonhang
ListDonHang listdh;

