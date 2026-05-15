#include "CongTy.h"

int main() {
    CongTy ct;

    ct.NhapDanhSach();

    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    ct.XuatDanhSach();

    cout << "\nTong luong cong ty phai tra: "
         << ct.TinhTongLuong() << endl;

    ct.TimNVSanXuatLuongThapNhat();

    ct.TimNVVanPhongLonTuoiNhat();

    return 0;
}