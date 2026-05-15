#ifndef SINHVIENDAIHOC_H
#define SINHVIENDAIHOC_H

#include "SinhVien.h"

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    SinhVienDaiHoc();
    ~SinhVienDaiHoc();

    void Nhap();
    void Xuat() const;

    bool DuDieuKienTotNghiep() const;
};

#endif