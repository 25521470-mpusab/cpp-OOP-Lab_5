#ifndef KHACHHANGLOAIA_H
#define KHACHHANGLOAIA_H

#include "KhachHang.h"

class KhachHangLoaiA : public KhachHang {
public:
    KhachHangLoaiA();
    ~KhachHangLoaiA();

    void Nhap(ifstream&) override;
    void Xuat(ofstream&) const override;

    double TinhTienPhaiTra() const override;
};

#endif