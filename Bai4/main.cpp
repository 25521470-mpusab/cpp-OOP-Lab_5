#include "CongTyPhanMem.h"

int main() {

    CongTyPhanMem ct;

    ct.NhapDanhSach();

    ct.XuatDanhSach();

    // cho dễ so sánh bằng mắt 
    cout << "\nLuong trung binh: "
         << ct.TinhLuongTrungBinh() << endl;

    ct.XuatDSNVLuongThapHonTrungBinh();

    ct.TimNVLuongCaoNhat();

    ct.TimNVLuongThapNhat();

    ct.TimLapTrinhVienLuongCaoNhat();

    ct.TimKiemChungVienLuongThapNhat();

    return 0;
}