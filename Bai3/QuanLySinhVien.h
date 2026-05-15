#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H

#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"

class QuanLySinhVien {
private:
    int soLuong;
    SinhVien** dsSinhVien;

public:
    QuanLySinhVien();
    ~QuanLySinhVien();

    void NhapDanhSach();
    void XuatDanhSach() const;

    void XuatDSDuDKTotNghiep() const;
    void XuatDSKhongDuDKTotNghiep() const;

    void TimSVDaiHocDTBCaoNhat() const;
    void TimSVCaoDangDTBCaoNhat() const;

    int DemSVKhongDuDKTotNghiepCaoDang() const;
    int DemSVKhongDuDKTotNghiepDaiHoc() const;
};
#endif