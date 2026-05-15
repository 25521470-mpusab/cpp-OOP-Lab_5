#include "KiemChungVien.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - số lỗi phát hiện = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định
*/
KiemChungVien::KiemChungVien() {
    soLoiPhatHien = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng kiểm chứng viên

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý
*/
KiemChungVien::~KiemChungVien() {
}

/*
INPUT:
    - Thông tin nhân viên
    - số lỗi phát hiện

OUTPUT:
    Kiểm chứng viên được nhập đầy đủ thông tin

HƯỚNG GIẢI THUẬT:
    - Gọi NhanVien::Nhap()
    - Nhập số lỗi phát hiện
    - Kiểm tra số lỗi phát hiện >= 0
*/
void KiemChungVien::Nhap() {
    NhanVien::Nhap();

    do {
        cout << "Nhap so loi phat hien: ";
        cin >> soLoiPhatHien;

        if(soLoiPhatHien < 0)
            cout << "So loi phat hien >= 0!\n";

    } while(soLoiPhatHien < 0);
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất thông tin kiểm chứng viên:
        - thông tin nhân viên
        - số lỗi phát hiện

HƯỚNG GIẢI THUẬT:
    - Gọi NhanVien::Xuat()
    - Xuất số lỗi phát hiện
*/
void KiemChungVien::Xuat() const {
    NhanVien::Xuat();
    cout << "So loi phat hien: " << soLoiPhatHien << endl;
}

/*
INPUT:
    Không có

OUTPUT:
    Trả về lương của kiểm chứng viên

HƯỚNG GIẢI THUẬT:
    - Công thức:
        lương = lương cơ bản + số lỗi phát hiện * 50000
*/
double KiemChungVien::TinhLuong() const {
    return luongCoBan + soLoiPhatHien * 50000;
}