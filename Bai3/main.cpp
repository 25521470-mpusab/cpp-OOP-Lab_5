#include "QuanLySinhVien.h"

int main() {

    QuanLySinhVien ql;

    ql.NhapDanhSach();

    ql.XuatDanhSach();

    ql.XuatDSDuDKTotNghiep();

    ql.XuatDSKhongDuDKTotNghiep();

    ql.TimSVDaiHocDTBCaoNhat();

    ql.TimSVCaoDangDTBCaoNhat();

    cout << "\nSo SV Cao Dang khong du dieu kien tot nghiep: "
         << ql.DemSVKhongDuDKTotNghiepCaoDang()
         << endl;

    cout << "So SV Dai Hoc khong du dieu kien tot nghiep: "
         << ql.DemSVKhongDuDKTotNghiepDaiHoc()
         << endl;

    return 0;
}