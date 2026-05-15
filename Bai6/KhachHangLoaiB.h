#ifndef KHACHHANGLOAIB_H
#define KHACHHANGLOAIB_H

#include "KhachHang.h"

class KhachHangLoaiB : public KhachHang {
private:
    int soNamThanThiet;

public:
    KhachHangLoaiB();
    ~KhachHangLoaiB();

    double TinhPhanTramKhuyenMai() const;

    void Nhap(ifstream&) override;
    void Xuat(ofstream&) const override;

    double TinhTienPhaiTra() const override;
};

#endif