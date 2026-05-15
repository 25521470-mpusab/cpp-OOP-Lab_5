#include "NhanVien.h"
#include <iomanip>

/*
INPUT:
    Không có
OUTPUT:
    Khởi tạo đối tượng nhân viên với:
        - họ tên rỗng
        - ngày sinh rỗng
        - lương = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho các thuộc tính
*/
NhanVien::NhanVien() {
    hoTen = "";
    ngaySinh = "";
    luong = 0;
}

/*
INPUT:
    Không có
OUTPUT:
    Hủy đối tượng nhân viên

HƯỚNG GIẢI THUẬT:
    - Destructor rỗng vì không cấp phát động
*/
NhanVien::~NhanVien() {

}

/*
INPUT:
    - Họ tên
    - Ngày sinh dạng dd/mm/yyyy

OUTPUT:
    - Lưu thông tin vào đối tượng nhân viên

HƯỚNG GIẢI THUẬT:
    - Xóa bộ nhớ đệm bằng cin.ignore()
    - Nhập họ tên bằng getline()
    - Nhập ngày sinh dạng chuỗi
*/
void NhanVien::Nhap() {
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
}

/*
INPUT:
    Không có

OUTPUT:
    - Xuất:
        + họ tên
        + ngày sinh
        + lương

HƯỚNG GIẢI THUẬT:
    - In thông tin nhân viên
    - Gọi hàm TinhLuong() để tính lương
    - Dùng fixed và setprecision(0) để xuất đẹp
*/
void NhanVien::Xuat() const {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Luong: "
    << fixed << setprecision(0)
    << TinhLuong() << endl;
}

/*
INPUT:
    Không có

OUTPUT:
    - Trả về tuổi của nhân viên

HƯỚNG GIẢI THUẬT:
    - Lấy 4 ký tự cuối của chuỗi ngày sinh
    - Chuyển năm sinh từ string sang int
    - Lấy năm hiện tại trừ năm sinh
*/
int NhanVien::TinhTuoi() const {

    // Lấy năm sinh từ chuỗi dd/mm/yyyy
    string nam = ngaySinh.substr(6, 4);

    int namSinh = stoi(nam);

    return 2026 - namSinh;
}