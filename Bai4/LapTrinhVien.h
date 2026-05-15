#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H

#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
private:
    int soGioLamThem;

public:
    LapTrinhVien();
    ~LapTrinhVien();

    void Nhap();
    void Xuat() const;
    double TinhLuong() const;
};

#endif