#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;
//khai bao class hang hoa

class HangHoa{
    private:
        string _strMaHang;
        string _strTenHang;
        string _strNoiSanXuat;
        string _strMauSac;
        double _dGiaBan;
        string _strNgayNhapKho;
        int _iSoLuong;
    public:
        string getMaHang(){return _strMaHang;}
        string getTenHang(){return _strTenHang;}
        string getNoiSanXuat(){return _strNoiSanXuat;}
        string getMauSac(){return _strMauSac;}
        double getGiaBan(){return _dGiaBan;}
        string getNgayNhapKho(){return _strNgayNhapKho;}
        int getSoLuong(){return _iSoLuong;}

        void setMaHang(string _MaHang){_strMaHang=_MaHang;}
        void setTenHang(string _TenHang){_strTenHang=_TenHang;}
        void setNoiSanXuat(string _NoiSX){_strNoiSanXuat=_NoiSX;}
        void setMauSac(string _MauSac){_strMauSac=_MauSac;}
        void setGiaBan(double _GiaBan){_dGiaBan=_GiaBan;}
        void setNgayNhapKho(string _NgayNhapKho){_strNgayNhapKho=_NgayNhapKho;}
        void setSoLuong(int _sl){_iSoLuong=_sl;}

        void nhap();
        void docHangHoa(ifstream &filein);
        void xuatThongTin();

        friend istream& operator>>(istream& is,HangHoa &h){
            cout<<endl<<"Vui long nhap cac thong tin sau cho hang hoa: ";
            cout<<endl<<"Nhap ma hang hoa: ";
            getline(is,h._strMaHang);
            while(h._strMaHang.size()!=4){
                cout<<"Ma hang nhap khong chinh xac, vui long nhap lai ! "<<endl;
                cout<<"Nhap ma hang hoa: ";
                getline(is,h._strMaHang);
            }
            cout<<"Nhap ten hang hoa: ";
            getline(is,h._strTenHang);
            cout<<"Nhap noi san xuat: ";
            getline(is,h._strNoiSanXuat);
            cout<<"Nhap phan loai mau sac: ";
            getline(is,h._strMauSac);
            cout<<"Nhap gia ban: ";
            is>>h._dGiaBan;
            is.ignore();
            cout<<"Nhap ngay nhap kho: ";
            getline(is,h._strNgayNhapKho);
            cout<<"Nhap so luong hang hoa: ";
            is>>h._iSoLuong;
            is.ignore();

            return is;
        }
        

};

void HangHoa::nhap(){
            cout<<endl<<"Vui long nhap cac thong tin sau cho hang hoa: ";
            cout<<endl<<"Nhap ma hang hoa: ";
            getline(cin,this->_strMaHang);
            
            while(_strMaHang.size()!=4){
                cout<<"Ma hang nhap khong chinh xac, vui long nhap lai ! "<<endl;
                cout<<"Nhap ma hang hoa: ";
                getline(cin,_strMaHang);
            }
            cout<<"Nhap ten hang hoa: ";
            getline(cin,_strTenHang);
            cout<<"Nhap noi san xuat: ";
            getline(cin,_strNoiSanXuat);
            cout<<"Nhap phan loai mau sac: ";
            getline(cin,_strMauSac);
            cout<<"Nhap gia ban: ";
            cin>>_dGiaBan;
            cin.ignore();
            cout<<"Nhap ngay nhap kho: ";
            getline(cin,_strNgayNhapKho);
            cout<<"Nhap so luong hang hoa: ";
            cin>>_iSoLuong;
            cin.ignore();
        }
        void HangHoa::docHangHoa(ifstream &filein){
            getline(filein,_strMaHang,',');
            getline(filein,_strTenHang,',');
            getline(filein,_strNoiSanXuat,',');
            getline(filein,_strMauSac,',');
            filein>>_dGiaBan;
            filein.ignore();
            getline(filein,_strNgayNhapKho,',');
            filein>>_iSoLuong;
            //xoa cai xuong dong
            string temp;
            getline(filein,temp);

        }
        void HangHoa::xuatThongTin(){
            cout<<_strMaHang<<"\t"<<_strTenHang<<"\t\t"<<_strNoiSanXuat<<"\t\t"<<_strMauSac<<"\t\t"<<_dGiaBan<<"\t\t"<<_strNgayNhapKho<<"\t"<<_iSoLuong<<"\n";
        }



/*----------------------------------LIST HANG HOA------------------------------*/

//khai bao danh sach hang hoa
class ListHangHoa:public HangHoa{
    HangHoa *_pHangHoa;//khai bao con tro quan ly mang dong
    int _iTongSoLuong;

    public:
    int getSoLuong();
    void docList_HH(ifstream& is);
    void docListHangHoa(ifstream& is);
    void ghiListHangHoa(ofstream&fileout);
    
    void xuatListHangHoa();

    //Tim kiem thong tin hang hoa
    void timHangHoaTheoTenHang();
    bool kiemHangHoaTheoMaHang(string mahang,int so);
    double timGiaBanTheoMaHang(string mahang);
//Cac ham de quan ly hang hoa o day
    //them 1 hang hoa moi vao list
    void themHangHoa();
    //xoa hang hoa theo ma hang
    void xoaHangHoaTheoMaHang(string mahang);
    //cap nhat so luong theo ma
    void capNhatSoLuongTheoMa(string mahang,int so);
    void giamSoLuongTheoMa(string mahang,int so);

};

int ListHangHoa::getSoLuong(){return _iTongSoLuong;}
    void ListHangHoa::docListHangHoa(ifstream& is){
        int dem=0;
        //B1:tim so luong hang hoa trong file txt- tim so dong de cap phat mang dong
        while(is.eof()==false){//doc den khi con tro ve cuoi file
            string x;
            getline(is,x);//doc nguyen dong
            dem++;
        }
        _iTongSoLuong=dem;
        //B2: CapPhat mang dong hang hoa
        _pHangHoa=new HangHoa[_iTongSoLuong];
        //B3: Cho con tro chi vi ve dau file
        is.seekg(is.beg,is.beg);
        //B4:doc danh sach hang hoa
        docList_HH(is);

    }
    void ListHangHoa::docList_HH(ifstream& is){
        for(int i=0;i<_iTongSoLuong;i++){
            _pHangHoa[i].docHangHoa(is);//doc thong tin hang hoa thu i
        }
    }
    
    void ListHangHoa::ghiListHangHoa(ofstream&fileout){
        for(int i=0;i<_iTongSoLuong;i++){
            fileout<<_pHangHoa[i].getMaHang()<<",";
            fileout<<_pHangHoa[i].getTenHang()<<",";
            fileout<<_pHangHoa[i].getNoiSanXuat()<<",";
            fileout<<_pHangHoa[i].getMauSac()<<",";
            fileout<<_pHangHoa[i].getGiaBan()<<",";
            fileout<<_pHangHoa[i].getNgayNhapKho()<<",";
            fileout<<_pHangHoa[i].getSoLuong();
            if(i!=_iTongSoLuong-1) fileout<<endl;
        }
    }
    
    void ListHangHoa::xuatListHangHoa(){
        cout<<"Ma Hang\tTen Hang\t\tNoi San Xuat\t\tMau Sac\t\tGia Ban\t\tNgay Nhap Kho\tSo luong\n";
        for(int i=0;i<_iTongSoLuong;i++){
            _pHangHoa[i].xuatThongTin();
        }
    }

    //Tim kiem thong tin hang hoa
    void ListHangHoa::timHangHoaTheoTenHang(){
        
        string _strHangTim;
        cout<<"Nhap ten hang hoa can tim kiem: ";
        getline(cin,_strHangTim);
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            
            if(stricmp(_pHangHoa[i].getTenHang().c_str(),_strHangTim.c_str()) == 0){
                _pHangHoa[i].xuatThongTin();
                return;
            }
        }
        cout<<"Khong tim thay san pham"<<endl;
    }
    bool ListHangHoa::kiemHangHoaTheoMaHang(string mahang,int so){
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pHangHoa[i].getMaHang().c_str(),mahang.c_str()) == 0 && _pHangHoa[i].getSoLuong()>so){
                return true;
            }
        }
        return false;
    }
    double ListHangHoa::timGiaBanTheoMaHang(string mahang){
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pHangHoa[i].getMaHang().c_str(),mahang.c_str()) == 0){
                return _pHangHoa[i].getGiaBan();
            }
        }
        return 0;
    }
//Cac ham de quan ly hang hoa o day
    //them 1 hang hoa moi vao list
    void ListHangHoa::themHangHoa(){
        int newSize=_iTongSoLuong+1;
        HangHoa *temp=new HangHoa[newSize];
        for(int i=0;i<_iTongSoLuong;i++){
            temp[i]=_pHangHoa[i];
        }
        delete[]_pHangHoa;
        _pHangHoa=temp;
        _iTongSoLuong=newSize;
        _pHangHoa[_iTongSoLuong-1].nhap();
        for(int i=0;i<_iTongSoLuong-1;i++){
            if(_pHangHoa[_iTongSoLuong-1].getMaHang()==_pHangHoa[i].getMaHang()){
                cout<<"Ma hang bi trung !!!"<<endl;
                int k;
                cout<<"De them so luong hang hoa voi ma hang tren, nhan phim 1"<<endl;
                cout<<"De nhap lai, nhan phim 2";
                cout<<"Nhap k: ";
                cin>>k;
                while(k!=1 && k!=2){
                    cout<<"Nhap chua chinh xac, vui long nhap lai"<<endl;
                    cout<<"Nhap k: ";
                    cin>>k;
                }
                if(k==1){
                    //chay lai size cu
                    newSize=_iTongSoLuong-1;
                    temp=new HangHoa[newSize];
                    for(int i=0;i<newSize;i++){
                        temp[i]=_pHangHoa[i];
                    }
                    delete[]_pHangHoa;
                    _pHangHoa=temp;
                    _iTongSoLuong=newSize;
                    //tang sl hang hoa

                }
                if(k==2){
                    _pHangHoa[_iTongSoLuong-1].nhap();
                }
            }
        } 
    }
    //xoa hang hoa theo ma hang
    void ListHangHoa::xoaHangHoaTheoMaHang(string mahang){
        int vitri=-1;
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pHangHoa[i].getMaHang().c_str(),mahang.c_str()) == 0){
                vitri=i;break;
            }
        }
        if(vitri==-1) cout<<"Khong tim thay ma hang nay\n";
        else{
        for(int i=vitri;i<_iTongSoLuong-1;i++){
            _pHangHoa[i]=_pHangHoa[i+1];
        }
        int newSize=_iTongSoLuong-1;
        HangHoa *temp=new HangHoa[newSize];
        for(int i=0;i<newSize;i++){
            temp[i]=_pHangHoa[i];
        }
        delete[]_pHangHoa;
        _pHangHoa=temp;
        _iTongSoLuong=newSize;
        }
    }
    //cap nhat so luong theo ma
    void ListHangHoa::capNhatSoLuongTheoMa(string mahang,int so){
        for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
            if(stricmp(_pHangHoa[i].getMaHang().c_str(),mahang.c_str()) == 0){
                _pHangHoa[i].setSoLuong(_pHangHoa[i].getSoLuong()+so);
            }
        }
    }
    void ListHangHoa::giamSoLuongTheoMa(string mahang,int so){
        cout<<mahang<<" "<<so<<endl;
        if(kiemHangHoaTheoMaHang(mahang,so)){
            for(int i=0;i<_iTongSoLuong;i++){
            //stricmp so sanh ko phan biet hoa thuong, chuyen ve char C
                if(stricmp(_pHangHoa[i].getMaHang().c_str(),mahang.c_str()) == 0){
                    _pHangHoa[i].setSoLuong(_pHangHoa[i].getSoLuong()-so);
                }
            }
        }
        
            else{
            cout<<"\nSo luong hang trong kho khong du de thuc hien"<<endl;
            }
        
        
    }

//KHAI BAO BIEN 
ListHangHoa listhh;
ifstream filein;
ofstream fileout;

