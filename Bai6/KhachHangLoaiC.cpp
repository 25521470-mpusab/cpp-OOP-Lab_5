#include "KhachHangLoaiC.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo khách hàng loại C

HƯỚNG GIẢI THUẬT:
    - Không xử lý thêm
*/
KhachHangLoaiC::KhachHangLoaiC() {
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng khách hàng loại C

HƯỚNG GIẢI THUẬT:
    - Không xử lý thêm
*/
KhachHangLoaiC::~KhachHangLoaiC() {
}

/*
INPUT:
    fin: luồng đọc file

OUTPUT:
    Nhập thông tin khách hàng loại C

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Nhap() của lớp KhachHang
*/
void KhachHangLoaiC::Nhap(ifstream& fin) {
    KhachHang::Nhap(fin);
}

/*
INPUT:
    fout: luồng ghi file

OUTPUT:
    Xuất thông tin khách hàng loại C

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Xuat() của lớp KhachHang
*/
void KhachHangLoaiC::Xuat(ofstream& fout) const {
    KhachHang::Xuat(fout);
}

/*
INPUT:
    Không có

OUTPUT:
    Số tiền khách hàng loại C phải trả

HƯỚNG GIẢI THUẬT:
    - Tính:
        tiền = số lượng hàng * đơn giá hàng * 50%
    - Cộng VAT 10%
    - Trả về kết quả
*/
double KhachHangLoaiC::TinhTienPhaiTra() const {

    double tien =
        soLuongHang * donGiaHang * 0.5;

    return tien * 1.1;
}