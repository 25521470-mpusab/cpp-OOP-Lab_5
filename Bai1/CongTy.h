#ifndef CONGTY_H
#define CONGTY_H
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"

class CongTy {
private:
    NhanVien** dsNhanVien; // mảng động chứa các con trỏ NhanVien
    int soLuong;

public:
    CongTy();
    ~CongTy();

    void NhapDanhSach();
    void XuatDanhSach() const;

    double TinhTongLuong() const;

    void TimNVSanXuatLuongThapNhat() const;
    void TimNVVanPhongLonTuoiNhat() const;
};

#endif