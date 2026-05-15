#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void Nhap();
    virtual void Xuat() const;

    int TinhTuoi() const;
    virtual double TinhLuong() const = 0;
};

#endif