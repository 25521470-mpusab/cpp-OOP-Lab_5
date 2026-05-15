#include "CongTyXYZ.h"

int main() {

    CongTyXYZ ct;

    // Nhập dữ liệu từ file input
    ct.NhapDSKHTuFile("XYZ.INP");

    // Xuất kết quả ra file output
    ct.XuatKQRaFile("XYZ.OUT");

    return 0;
}