#include "NhanVienVanPhong.h"

/*
INPUT:
    Không có

OUTPUT:
    - Khởi tạo số ngày làm = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho thuộc tính
*/
NhanVienVanPhong::NhanVienVanPhong() {
    soNgayLam = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    - Hủy đối tượng nhân viên văn phòng

HƯỚNG GIẢI THUẬT:
    - Destructor rỗng vì không cấp phát động
*/
NhanVienVanPhong::~NhanVienVanPhong() {
}

/*
INPUT:
    - Họ tên
    - Ngày sinh
    - Số ngày làm

OUTPUT:
    - Lưu thông tin nhân viên văn phòng

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Nhap() của lớp cha
    - Nhập số ngày làm
    - Kiểm tra số ngày làm >= 0
*/
void NhanVienVanPhong::Nhap() {
    NhanVien::Nhap();

    do{
        cout << "Nhap so ngay lam: ";
        cin >> soNgayLam;

        if(soNgayLam < 0){
            cout << "So ngay lam phai >= 0!\n";
        }

    } while(soNgayLam < 0);
}

/*
INPUT:
    Không có

OUTPUT:
    - Trả về lương nhân viên văn phòng

HƯỚNG GIẢI THUẬT:
    - Tính lương theo công thức:
        lương = số ngày làm * 100000
*/
double NhanVienVanPhong::TinhLuong() const {
    return soNgayLam * 100000;
}

/*
INPUT:
    Không có

OUTPUT:
    - Xuất thông tin nhân viên văn phòng:
        + họ tên
        + ngày sinh
        + lương
        + số ngày làm

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Xuat() của lớp cha
    - Xuất thêm số ngày làm
*/
void NhanVienVanPhong::Xuat() const {
    NhanVien::Xuat();
    cout << "So ngay lam: " << soNgayLam << endl;
}