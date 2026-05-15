#include "GiaoDichNhaPho.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo giao dịch nhà phố mặc định

HƯỚNG GIẢI THUẬT:
    - loại nhà rỗng
    - địa chỉ rỗng
*/
GiaoDichNhaPho::GiaoDichNhaPho() {
    loaiNha = "";
    diaChi = "";
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng giao dịch nhà phố
*/
GiaoDichNhaPho::~GiaoDichNhaPho() {
}

/*
INPUT:
    Thông tin giao dịch nhà phố

OUTPUT:
    Giao dịch nhà phố hợp lệ

ĐIỀU KIỆN:
    - loại nhà:
        + cao cap
        + thuong

HƯỚNG GIẢI THUẬT:
    - Gọi nhập lớp cha
    - Kiểm tra loại nhà
    - Nhập địa chỉ
*/
void GiaoDichNhaPho::Nhap() {
    GiaoDich::Nhap();

    cin.ignore();
    do {
    cout << "\nNhap loai nha: ";
    getline(cin, loaiNha);

    if (loaiNha != "cao cap" && loaiNha != "thuong")
    {
        cout << "Loai nha khong hop le!\n";
    }
    } while(loaiNha != "cao cap" && loaiNha != "thuong");
    
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

/*
INPUT:
    Thông tin giao dịch nhà phố

OUTPUT:
    Xuất giao dịch nhà phố

HƯỚNG GIẢI THUẬT:
    - Gọi xuất lớp cha
    - Xuất loại nhà và địa chỉ
*/
void GiaoDichNhaPho::Xuat() const {
    GiaoDich::Xuat();
    cout << "Loai nha: " << loaiNha << endl;
    cout << "Dia chi: " << diaChi << endl;
}

/*
INPUT:
    Diện tích, đơn giá, loại nhà

OUTPUT:
    Thành tiền giao dịch nhà phố

HƯỚNG GIẢI THUẬT:
    - Nếu nhà cao cấp:
        tính bình thường
    - Nếu nhà thường:
        giảm 10%
*/
double GiaoDichNhaPho::TinhThanhTien() const {
    if(loaiNha == "cao cap")
        return dienTich * donGia;

    return dienTich * donGia * 0.9;
}