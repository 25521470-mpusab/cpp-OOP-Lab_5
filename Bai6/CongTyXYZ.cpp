#include "CongTyXYZ.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - số lượng nhân viên = 0
        - danh sách nhân viên rỗng

HƯỚNG GIẢI THUẬT:
    - Gán soLuong = 0
    - Gán dsNhanVien = NULL
*/
CongTyXYZ::CongTyXYZ() {
    dsKhachHang = NULL;
    tongSoKhachHang = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Giải phóng toàn bộ vùng nhớ động của danh sách khách hàng

HƯỚNG GIẢI THUẬT:
    - Duyệt qua từng phần tử trong mảng con trỏ
    - delete từng đối tượng khách hàng
    - delete[] mảng con trỏ dsKhachHang
*/
CongTyXYZ::~CongTyXYZ() {

    for(int i = 0; i < tongSoKhachHang; i++) {
        delete dsKhachHang[i];
    }

    delete[] dsKhachHang;
}

/*
INPUT:
    tenFile: tên file input chứa danh sách khách hàng

OUTPUT:
    Đọc dữ liệu khách hàng từ file và lưu vào danh sách

HƯỚNG GIẢI THUẬT:
    - Mở file input
    - Đọc số lượng khách hàng loại A, B, C
    - Tính tổng số khách hàng
    - Cấp phát mảng động con trỏ KhachHang
    - Tạo đối tượng đúng loại:
        + KhachHangLoaiA
        + KhachHangLoaiB
        + KhachHangLoaiC
    - Gọi hàm Nhap() bằng đa hình
    - Đóng file
*/
void CongTyXYZ::NhapDSKHTuFile(string tenFile) {

    ifstream fin(tenFile);

    int x, y, z;

    fin >> x >> y >> z;

    tongSoKhachHang = x + y + z;

    dsKhachHang = new KhachHang*[tongSoKhachHang];

    int k = 0;

    for(int i = 0; i < x; i++) {
        dsKhachHang[k] = new KhachHangLoaiA;
        dsKhachHang[k]->Nhap(fin);
        k++;
    }

    for(int i = 0; i < y; i++) {
        dsKhachHang[k] = new KhachHangLoaiB;
        dsKhachHang[k]->Nhap(fin);
        k++;
    }

    for(int i = 0; i < z; i++) {
        dsKhachHang[k] = new KhachHangLoaiC;
        dsKhachHang[k]->Nhap(fin);
        k++;
    }

    fin.close();
}

/*
INPUT:
    Không có

OUTPUT:
    Tổng số tiền công ty thu được từ tất cả khách hàng

HƯỚNG GIẢI THUẬT:
    - Khởi tạo biến tổng = 0
    - Duyệt danh sách khách hàng
    - Cộng tiền phải trả của từng khách hàng
    - Trả về tổng
*/
double CongTyXYZ::TinhTongSoTienCongTyThuDuoc() const {

    double tong = 0;

    for(int i = 0; i < tongSoKhachHang; i++) {
        tong += dsKhachHang[i]->TinhTienPhaiTra();
    }

    return tong;
}

/*
INPUT:
    tenFile: tên file output

OUTPUT:
    Xuất:
        - thông tin từng khách hàng
        - số tiền phải trả
        - tổng số tiền công ty thu được

HƯỚNG GIẢI THUẬT:
    - Mở file output
    - Duyệt danh sách khách hàng
    - Gọi hàm Xuat() bằng đa hình
    - Xuất tổng số tiền công ty thu được
    - Đóng file
*/
void CongTyXYZ::XuatKQRaFile(string tenFile) const {

    ofstream fout(tenFile);

    for(int i = 0; i < tongSoKhachHang; i++) {
        dsKhachHang[i]->Xuat(fout);
    }

    fout<<"\n Tong so tien cong ty thu duoc la: ";
    fout << TinhTongSoTienCongTyThuDuoc();

    fout.close();
}