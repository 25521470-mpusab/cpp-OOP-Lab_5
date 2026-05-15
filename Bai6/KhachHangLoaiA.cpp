#include "KhachHangLoaiA.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo khách hàng loại A

HƯỚNG GIẢI THUẬT:
    - Không xử lý thêm
*/
KhachHangLoaiA::KhachHangLoaiA() {
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng khách hàng loại A

HƯỚNG GIẢI THUẬT:
    - Không xử lý thêm
*/
KhachHangLoaiA::~KhachHangLoaiA() {
}

/*
INPUT:
    fin: luồng đọc file

OUTPUT:
    Nhập thông tin khách hàng loại A

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Nhap() của lớp KhachHang
*/
void KhachHangLoaiA::Nhap(ifstream& fin) {
    KhachHang::Nhap(fin);
}

/*
INPUT:
    fout: luồng ghi file

OUTPUT:
    Xuất thông tin khách hàng loại A

HƯỚNG GIẢI THUẬT:
    - Gọi hàm Xuat() của lớp KhachHang
*/
void KhachHangLoaiA::Xuat(ofstream& fout) const {
    KhachHang::Xuat(fout);
}

/*
INPUT:
    Không có

OUTPUT:
    Số tiền khách hàng loại A phải trả

HƯỚNG GIẢI THUẬT:
    - Tính:
        tiền = số lượng hàng * đơn giá hàng * 1.1
    - Trả về kết quả
*/
double KhachHangLoaiA::TinhTienPhaiTra() const {
    return soLuongHang * donGiaHang * 1.1;
}