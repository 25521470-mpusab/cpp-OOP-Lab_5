#ifndef NHANVIENVANPHONG_H
#define NHANVIENVANPHONG_H

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLam;

public:
    NhanVienVanPhong();
    ~NhanVienVanPhong();

    void Nhap();
    void Xuat() const;
    double TinhLuong() const;
};

#endif