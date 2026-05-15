#ifndef CONGTYXYZ_H
#define CONGTYXYZ_H

#include "KhachHangLoaiA.h"
#include "KhachHangLoaiB.h"
#include "KhachHangLoaiC.h"

class CongTyXYZ {
private:
    KhachHang** dsKhachHang;
    int tongSoKhachHang;

public:
    CongTyXYZ();
    ~CongTyXYZ();

    void NhapDSKHTuFile(string);
    void XuatKQRaFile(string) const;

    double TinhTongSoTienCongTyThuDuoc() const;
};

#endif