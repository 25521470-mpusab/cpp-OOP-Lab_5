#ifndef CONGTYPHANMEM_H
#define CONGTYPHANMEM_H

#include "LapTrinhVien.h"
#include "KiemChungVien.h"

class CongTyPhanMem {
private:
    int soLuong;
    NhanVien** dsNhanVien;

public:
    CongTyPhanMem();
    ~CongTyPhanMem();

    void NhapDanhSach();
    void XuatDanhSach() const;

    double TinhLuongTrungBinh() const;

    void XuatDSNVLuongThapHonTrungBinh() const;

    void TimNVLuongCaoNhat() const;

    void TimNVLuongThapNhat() const;

    void TimLapTrinhVienLuongCaoNhat() const;

    void TimKiemChungVienLuongThapNhat() const;
};

#endif