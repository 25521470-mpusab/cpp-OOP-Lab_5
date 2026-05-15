#ifndef GIAODICHNHAPHO_H
#define GIAODICHNHAPHO_H

#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha;
    string diaChi;

public:
    GiaoDichNhaPho();
    ~GiaoDichNhaPho();

    void Nhap();
    void Xuat() const;
    double TinhThanhTien() const;
};

#endif