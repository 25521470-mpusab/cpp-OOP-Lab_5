#include "GiaoDichDat.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo giao dịch đất mặc định

HƯỚNG GIẢI THUẬT:
    - Gán loại đất mặc định = 'C'
*/
GiaoDichDat::GiaoDichDat() {
    loaiDat = 'C';
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng giao dịch đất
*/
GiaoDichDat::~GiaoDichDat() {
}

/*
INPUT:
    Thông tin giao dịch đất

OUTPUT:
    Giao dịch đất hợp lệ

ĐIỀU KIỆN:
    - loại đất chỉ được:
        + A
        + B
        + C

HƯỚNG GIẢI THUẬT:
    - Gọi nhập lớp cha
    - Kiểm tra loại đất
*/
void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();

    do {
        cout << "Nhap loai dat (A/B/C): ";
        cin >> loaiDat;

        loaiDat = toupper(loaiDat);

        if(loaiDat != 'A' && loaiDat != 'B' && loaiDat != 'C')
            cout << "Loai dat khong hop le!\n";

    } while(loaiDat != 'A' && loaiDat != 'B' && loaiDat != 'C');
}

/*
INPUT:
    Thông tin giao dịch đất

OUTPUT:
    Xuất giao dịch đất

HƯỚNG GIẢI THUẬT:
    - Gọi xuất lớp cha
    - Xuất loại đất
*/
void GiaoDichDat::Xuat() const {
    GiaoDich::Xuat();
    cout << "Loai dat: " << loaiDat << endl;
}

/*
INPUT:
    Diện tích, đơn giá, loại đất

OUTPUT:
    Thành tiền giao dịch đất

HƯỚNG GIẢI THUẬT:
    - Nếu loại A:
        nhân 1.5
    - Nếu loại B/C:
        tính bình thường
*/
double GiaoDichDat::TinhThanhTien() const {
    if(loaiDat == 'A')
        return dienTich * donGia * 1.5;

    return dienTich * donGia;
}