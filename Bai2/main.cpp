#include "CongTyBDS.h"
#include <iomanip>

int main() {

    CongTyBDS ct;

    ct.NhapDanhSach();

    ct.XuatDanhSach();

    cout << "\nTong giao dich dat: "
         << ct.TongSoLuongDat() << endl;

    cout << "Tong giao dich nha pho: "
         << ct.TongSoLuongNhaPho() << endl;

    cout << "Tong giao dich chung cu: "
         << ct.TongSoLuongChungCu() << endl;

    cout << "\nTrung binh thanh tien chung cu: "
         << fixed << setprecision(0)
         << ct.TinhTrungBinhThanhTienChungCu()
         << endl;

    ct.TimGDNhaPhoGiaTriCaoNhat();

    ct.XuatDSGiaoDichThang12_2024();

    return 0;
}