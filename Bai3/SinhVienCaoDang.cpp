#include "SinhVienCaoDang.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo điểm thi tốt nghiệp = 0

HƯỚNG GIẢI THUẬT:
    - Gán diemThiTotNghiep = 0
*/
SinhVienCaoDang::SinhVienCaoDang() {
    diemThiTotNghiep = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng sinh viên cao đẳng

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý
*/
SinhVienCaoDang::~SinhVienCaoDang() {
}

/*
INPUT:
    - Thông tin sinh viên
    - Điểm thi tốt nghiệp

OUTPUT:
    Sinh viên cao đẳng được nhập đầy đủ

HƯỚNG GIẢI THUẬT:
    - Gọi SinhVien::Nhap()
    - Nhập điểm thi tốt nghiệp
    - Kiểm tra điểm thuộc [0,10]
*/
void SinhVienCaoDang::Nhap() {
    SinhVien::Nhap();

    do {
        cout << "Nhap diem thi tot nghiep: ";
        cin >> diemThiTotNghiep;

        if(diemThiTotNghiep < 0 || diemThiTotNghiep > 10)
            cout << "Diem phai tu 0 -> 10!\n";

    } while(diemThiTotNghiep < 0 || diemThiTotNghiep > 10);
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất thông tin sinh viên cao đẳng

HƯỚNG GIẢI THUẬT:
    - Gọi SinhVien::Xuat()
    - Xuất điểm thi tốt nghiệp
*/
void SinhVienCaoDang::Xuat() const {
    SinhVien::Xuat();
    cout << "Diem thi tot nghiep: " << diemThiTotNghiep << endl;
}

/*
INPUT:
    Không có

OUTPUT:
    true:
        nếu đủ điều kiện tốt nghiệp
    false:
        nếu không đủ điều kiện

HƯỚNG GIẢI THUẬT:
    - Kiểm tra:
        + tongTinChi >= 120
        + diemTrungBinh >= 5
        + diemThiTotNghiep >= 5
*/
bool SinhVienCaoDang::DuDieuKienTotNghiep() const {
    return tongTinChi >= 120 &&
           diemTrungBinh >= 5 &&
           diemThiTotNghiep >= 5;
}