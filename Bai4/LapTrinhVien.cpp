#include "LapTrinhVien.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - số giờ làm thêm = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định
*/
LapTrinhVien::LapTrinhVien() {
    soGioLamThem = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng lập trình viên

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý
*/
LapTrinhVien::~LapTrinhVien() {
}

/*
INPUT:
    - Thông tin nhân viên
    - số giờ làm thêm

OUTPUT:
    Lập trình viên được nhập đầy đủ thông tin

HƯỚNG GIẢI THUẬT:
    - Gọi NhanVien::Nhap()
    - Nhập số giờ làm thêm
    - Kiểm tra số giờ làm thêm >= 0
*/
void LapTrinhVien::Nhap() {
    NhanVien::Nhap();

    do {
        cout << "Nhap so gio lam them: ";
        cin >> soGioLamThem;

        if(soGioLamThem < 0)
            cout << "So gio lam them >= 0!\n";

    } while(soGioLamThem < 0);
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất thông tin lập trình viên:
        - thông tin nhân viên
        - số giờ làm thêm

HƯỚNG GIẢI THUẬT:
    - Gọi NhanVien::Xuat()
    - Xuất số giờ làm thêm
*/
void LapTrinhVien::Xuat() const {
    NhanVien::Xuat();
    cout << "So gio lam them: " << soGioLamThem << endl;
}

/*
INPUT:
    Không có

OUTPUT:
    Trả về lương của lập trình viên

HƯỚNG GIẢI THUẬT:
    - Công thức:
        lương = lương cơ bản + số giờ làm thêm * 200000
*/
double LapTrinhVien::TinhLuong() const {
    return luongCoBan + soGioLamThem * 200000;
}