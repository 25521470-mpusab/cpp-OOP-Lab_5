#ifndef GIAODICH_H
#define GIAODICH_H
#include <iostream>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string maGiaoDich;
    string ngayGiaoDich;
    double donGia;
    double dienTich;

public:
    GiaoDich();
    virtual ~GiaoDich();

    virtual void Nhap();
    virtual void Xuat() const;

    int getThang() const;
    int getNam() const;

    virtual double TinhThanhTien() const = 0;
};

#endif