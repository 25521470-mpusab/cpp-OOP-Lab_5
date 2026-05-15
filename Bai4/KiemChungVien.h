#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H

#include "NhanVien.h"

class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    KiemChungVien();
    ~KiemChungVien();

    void Nhap();
    void Xuat() const;
    double TinhLuong() const;
};

#endif