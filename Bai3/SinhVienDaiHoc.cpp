#include "SinhVienDaiHoc.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - tên luận văn rỗng
        - điểm luận văn = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định
*/
SinhVienDaiHoc::SinhVienDaiHoc() {
    tenLuanVan = "";
    diemLuanVan = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng sinh viên đại học

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý
*/

SinhVienDaiHoc::~SinhVienDaiHoc() {
}

/*
INPUT:
    - Thông tin sinh viên
    - Tên luận văn
    - Điểm luận văn

OUTPUT:
    Sinh viên đại học được nhập đầy đủ

HƯỚNG GIẢI THUẬT:
    - Gọi SinhVien::Nhap()
    - Nhập tên luận văn bằng getline
    - Nhập điểm luận văn
    - Kiểm tra điểm thuộc [0,10]
*/
void SinhVienDaiHoc::Nhap() {
    SinhVien::Nhap();

    cin.ignore();

    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);

    do {
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;

        if(diemLuanVan < 0 || diemLuanVan > 10)
            cout << "Diem phai tu 0 -> 10!\n";

    } while(diemLuanVan < 0 || diemLuanVan > 10);
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất thông tin sinh viên đại học

HƯỚNG GIẢI THUẬT:
    - Gọi SinhVien::Xuat()
    - Xuất tên luận văn
    - Xuất điểm luận văn
*/
void SinhVienDaiHoc::Xuat() const {
    SinhVien::Xuat();
    cout << "Ten luan van: " << tenLuanVan << endl;
    cout << "Diem luan van: " << diemLuanVan << endl;
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
        + tongTinChi >= 170
        + diemTrungBinh >= 5
        + diemLuanVan >= 5
*/

bool SinhVienDaiHoc::DuDieuKienTotNghiep() const {
    return tongTinChi >= 170 &&
           diemTrungBinh >= 5 &&
           diemLuanVan >= 5;
}