#include "KhachHangLoaiB.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - số năm thân thiết = 0

HƯỚNG GIẢI THUẬT:
    - Gán soNamThanThiet = 0
*/
KhachHangLoaiB::KhachHangLoaiB() {
    soNamThanThiet = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng khách hàng loại B

HƯỚNG GIẢI THUẬT:
    - Không xử lý thêm
*/
KhachHangLoaiB::~KhachHangLoaiB() {
}

/*
INPUT:
    fin: luồng đọc file

OUTPUT:
    Nhập:
        - thông tin khách hàng
        - số năm thân thiết

HƯỚNG GIẢI THUẬT:
    - Gọi Nhap() lớp KhachHang
    - Đọc số năm thân thiết
    - Kiểm tra số năm thân thiết >= 0
*/
void KhachHangLoaiB::Nhap(ifstream& fin) {
    KhachHang::Nhap(fin);

    fin >> soNamThanThiet;

     if(soNamThanThiet < 0){
        cout << "So nam than thiet khong hop le!\n";
    }
}

/*
INPUT:
    fout: luồng ghi file

OUTPUT:
    Xuất thông tin khách hàng loại B

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Xuat() của lớp KhachHang
*/
void KhachHangLoaiB::Xuat(ofstream& fout) const {
    KhachHang::Xuat(fout);
}

/*
INPUT:
    Không có

OUTPUT:
    Phần trăm khuyến mãi của khách hàng loại B

HƯỚNG GIẢI THUẬT:
    - Tính:
        khuyến mãi = số năm thân thiết * 5%
    - Nếu > 50% thì gán = 50%
    - Trả về phần trăm khuyến mãi
*/
double KhachHangLoaiB::TinhPhanTramKhuyenMai() const {

    double km = soNamThanThiet * 0.05;

    if(km > 0.5)
        km = 0.5;

    return km;
}

/*
INPUT:
    Không có

OUTPUT:
    Số tiền khách hàng loại B phải trả

HƯỚNG GIẢI THUẬT:
    - Tính tiền hàng
    - Tính phần trăm khuyến mãi
    - Trừ khuyến mãi
    - Cộng VAT 10%
    - Trả về kết quả
*/
double KhachHangLoaiB::TinhTienPhaiTra() const {

    double tien =
        soLuongHang * donGiaHang;

    tien = tien * (1 - TinhPhanTramKhuyenMai());

    return tien * 1.1;
}