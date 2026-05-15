#include "NhanVien.h"
#include <iomanip>

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - mã nhân viên rỗng
        - họ tên rỗng
        - tuổi = 0
        - số điện thoại rỗng
        - email rỗng
        - lương cơ bản = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho tất cả thuộc tính
*/
NhanVien::NhanVien() {
    maNhanVien = "";
    hoTen = "";
    tuoi = 0;
    soDienThoai = "";
    email = "";
    luongCoBan = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng nhân viên

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý vì không cấp phát động
*/
NhanVien::~NhanVien() {
}

/*
INPUT:
    - mã nhân viên
    - họ tên
    - tuổi
    - số điện thoại
    - email
    - lương cơ bản

OUTPUT:
    Thông tin nhân viên được nhập hợp lệ

HƯỚNG GIẢI THUẬT:
    - Nhập chuỗi bằng getline
    - Kiểm tra tuổi > 0
    - Kiểm tra lương cơ bản >= 0
*/
void NhanVien::Nhap() {
    cin.ignore();

    cout << "Nhap ma nhan vien: ";
    getline(cin, maNhanVien);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    do {
        cout << "Nhap tuoi: ";
        cin >> tuoi;

        if(tuoi <= 0)
            cout << "Tuoi phai > 0!\n";

    } while(tuoi <= 0);

    cin.ignore();

    cout << "Nhap so dien thoai: ";
    getline(cin, soDienThoai);

    cout << "Nhap email: ";
    getline(cin, email);

    do {
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;

        if(luongCoBan < 0)
            cout << "Luong co ban >= 0!\n";

    } while(luongCoBan < 0);
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất toàn bộ thông tin nhân viên:
        - mã nhân viên
        - họ tên
        - tuổi
        - số điện thoại
        - email
        - lương

HƯỚNG GIẢI THUẬT:
    - In lần lượt từng thuộc tính
    - Gọi hàm TinhLuong() để xuất lương
*/
void NhanVien::Xuat() const {
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << soDienThoai << endl;
    cout << "Email: " << email << endl;

    cout << "Luong: "
         << fixed << setprecision(0)
         << TinhLuong() << endl;
}
