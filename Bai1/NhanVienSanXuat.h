#ifndef NHANVIENSANXUAT_H
#define NHANVIENSANXUAT_H

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    NhanVienSanXuat();
    ~NhanVienSanXuat();

    void Nhap();
    void Xuat() const;
    double TinhLuong() const;
};

#endif