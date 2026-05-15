#include "GiaoDichChungCu.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo giao dịch chung cư mặc định

HƯỚNG GIẢI THUẬT:
    - Mã căn rỗng
    - Vị trí tầng = 0
*/
GiaoDichChungCu::GiaoDichChungCu() {
    maCan = "";
    viTriTang = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng giao dịch chung cư
*/
GiaoDichChungCu::~GiaoDichChungCu() {
}

/*
INPUT:
    Thông tin giao dịch chung cư

OUTPUT:
    Giao dịch chung cư hợp lệ

ĐIỀU KIỆN:
    - tầng >= 0

HƯỚNG GIẢI THUẬT:
    - Gọi nhập lớp cha
    - Nhập mã căn
    - Kiểm tra vị trí tầng
*/
void GiaoDichChungCu::Nhap() {
    GiaoDich::Nhap();

    cin.ignore();

    cout << "Nhap ma can: ";
    getline(cin, maCan);

    do {
        cout << "Nhap vi tri tang: ";
        cin >> viTriTang;

        if(viTriTang < 0)
            cout << "Tang phai >= 0!\n";

    } while(viTriTang < 0);
}

/*
INPUT:
    Thông tin giao dịch chung cư

OUTPUT:
    Xuất giao dịch chung cư

HƯỚNG GIẢI THUẬT:
    - Gọi xuất lớp cha
    - Xuất mã căn và tầng
*/
void GiaoDichChungCu::Xuat() const {
    GiaoDich::Xuat();
    cout << "Ma can: " << maCan << endl;
    cout << "Vi tri tang: " << viTriTang << endl;
}

/*
INPUT:
    Diện tích, đơn giá, vị trí tầng

OUTPUT:
    Thành tiền giao dịch chung cư

HƯỚNG GIẢI THUẬT:
    - Nếu tầng = 1:
        nhân hệ số 2
    - Nếu tầng >= 15:
        nhân hệ số 1.2
    - Ngược lại:
        tính bình thường
*/
double GiaoDichChungCu::TinhThanhTien() const {
    if(viTriTang == 1){
        return dienTich * donGia * 2;
    }
    if(viTriTang >= 15) {
        return dienTich * donGia * 1.2;
    }
    return dienTich * donGia;
}