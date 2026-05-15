#include "NhanVienSanXuat.h"

/*
INPUT:
    Không có

OUTPUT:
    - Khởi tạo:
        + lương căn bản = 0
        + số sản phẩm = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho các thuộc tính
*/
NhanVienSanXuat::NhanVienSanXuat() {
    luongCanBan = 0;
    soSanPham = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    - Hủy đối tượng nhân viên sản xuất

HƯỚNG GIẢI THUẬT:
    - Destructor rỗng vì không cấp phát động
*/
NhanVienSanXuat::~NhanVienSanXuat() {
}

/*
INPUT:
    - Họ tên
    - Ngày sinh
    - Lương căn bản
    - Số sản phẩm

OUTPUT:
    - Lưu thông tin nhân viên sản xuất

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Nhap() của lớp cha
    - Nhập lương căn bản và kiểm tra >= 0
    - Nhập số sản phẩm và kiểm tra >= 0
*/
void NhanVienSanXuat::Nhap() {
    NhanVien::Nhap();

    do{
        cout << "Nhap luong can ban: ";
        cin >> luongCanBan;

        if(luongCanBan < 0){
            cout << "Luong can ban phai >= 0!\n";
        }

    } while(luongCanBan < 0);

    do{
        cout << "Nhap so san pham: ";
        cin >> soSanPham;

        if(soSanPham < 0){
            cout << "So san pham phai >= 0!\n";
        }

    } while(soSanPham < 0);
}

/*
INPUT:
    Không có

OUTPUT:
    - Trả về lương nhân viên sản xuất

HƯỚNG GIẢI THUẬT:
    - Tính lương theo công thức:
        lương = lương căn bản + số sản phẩm * 5000
*/
double NhanVienSanXuat::TinhLuong() const {
    return luongCanBan + soSanPham * 5000;
}

/*
INPUT:
    Không có

OUTPUT:
    - Xuất thông tin nhân viên sản xuất:
        + họ tên
        + ngày sinh
        + lương
        + lương căn bản
        + số sản phẩm

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Xuat() của lớp cha
    - Xuất thêm lương căn bản và số sản phẩm
*/
void NhanVienSanXuat::Xuat() const {
    NhanVien::Xuat();
    cout << "Luong can ban: " << luongCanBan << endl;
    cout << "So san pham: " << soSanPham << endl;
}