#ifndef CONGTYBDS_H
#define CONGTYBDS_H

#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichChungCu.h"

class CongTyBDS {
private:
    GiaoDich** dsGiaoDich;
    int soLuong;

public:
    CongTyBDS();
    ~CongTyBDS();

    void NhapDanhSach();
    void XuatDanhSach() const;

    double TongSoLuongDat() const;
    int TongSoLuongNhaPho() const;
    int TongSoLuongChungCu() const;
    
    double TinhTrungBinhThanhTienChungCu() const;

    void TimGDNhaPhoGiaTriCaoNhat() const;
    void XuatDSGiaoDichThang12_2024() const;
};

#endif