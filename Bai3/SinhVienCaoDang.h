#ifndef SINHVIENCAODANG_H
#define SINHVIENCAODANG_H

#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTotNghiep;

public:
    SinhVienCaoDang();
    ~SinhVienCaoDang();

    void Nhap();
    void Xuat() const;

    bool DuDieuKienTotNghiep() const;
};

#endif