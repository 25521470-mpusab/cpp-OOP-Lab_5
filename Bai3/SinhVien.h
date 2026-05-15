#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>
using namespace std;

class SinhVien {
protected:
    string mSSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTrungBinh;

public:
    SinhVien();
    virtual ~SinhVien();

    virtual void Nhap();
    virtual void Xuat() const;

    virtual bool DuDieuKienTotNghiep() const = 0;

    double getDiemTrungBinh() const; // cho class ngoài (QuanLySV) lấy thông tin
};

#endif