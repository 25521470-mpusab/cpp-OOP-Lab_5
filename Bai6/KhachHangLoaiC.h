#ifndef KHACHHANGLOAIC_H
#define KHACHHANGLOAIC_H

#include "KhachHang.h"

class KhachHangLoaiC : public KhachHang {
public:
    KhachHangLoaiC();
    ~KhachHangLoaiC();

    void Nhap(ifstream&) override;
    void Xuat(ofstream&) const override;

    double TinhTienPhaiTra() const override;
};

#endif