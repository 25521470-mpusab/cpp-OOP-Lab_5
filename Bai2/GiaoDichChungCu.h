#ifndef GIAODICHCHUNGCU_H
#define GIAODICHCHUNGCU_H

#include "GiaoDich.h"

class GiaoDichChungCu : public GiaoDich {
private:
    string maCan;
    int viTriTang;

public:
    GiaoDichChungCu();
    ~GiaoDichChungCu();

    void Nhap();
    void Xuat() const;
    double TinhThanhTien() const;
};

#endif