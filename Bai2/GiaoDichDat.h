#ifndef GIAODICHDAT_H
#define GIAODICHDAT_H

#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
private:
    char loaiDat;

public:
    GiaoDichDat();
    ~GiaoDichDat();

    void Nhap();
    void Xuat() const;
    double TinhThanhTien() const;
};

#endif