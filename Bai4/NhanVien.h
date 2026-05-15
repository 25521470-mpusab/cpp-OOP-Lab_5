#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string maNhanVien;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    double luongCoBan;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void Nhap();
    virtual void Xuat() const;
    virtual double TinhLuong() const = 0;
};

#endif