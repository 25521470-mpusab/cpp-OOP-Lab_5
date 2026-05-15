#include "GiaoDich.h"
#include <iomanip>

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo giao dịch mặc định:
        - mã rỗng
        - ngày rỗng
        - đơn giá = 0
        - diện tích = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho các thuộc tính
*/
GiaoDich::GiaoDich() {
    maGiaoDich = "";
    ngayGiaoDich = "";
    donGia = 0;
    dienTich = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng giao dịch

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý thêm
*/
GiaoDich::~GiaoDich() {
}

/*
INPUT:
    Thông tin giao dịch từ bàn phím

OUTPUT:
    Giao dịch hợp lệ

ĐIỀU KIỆN:
    - đơn giá > 0
    - diện tích > 0

HƯỚNG GIẢI THUẬT:
    - Nhập mã giao dịch
    - Nhập ngày giao dịch
    - Kiểm tra đơn giá
    - Kiểm tra diện tích
*/
void GiaoDich::Nhap() {
    cin.ignore();

    cout << "Nhap ma giao dich: ";
    getline(cin, maGiaoDich);

    cout << "Nhap ngay giao dich (dd/mm/yyyy): ";
    getline(cin, ngayGiaoDich);

    do {
        cout << "Nhap don gia: ";
        cin >> donGia;

        if(donGia <= 0)
            cout << "Don gia phai > 0!\n";

    } while(donGia <= 0);

    do {
        cout << "Nhap dien tich: ";
        cin >> dienTich;

        if(dienTich <= 0)
            cout << "Dien tich phai > 0!\n";

    } while(dienTich <= 0);
    }

/*
INPUT:
    Thông tin giao dịch hiện tại

OUTPUT:
    Xuất thông tin giao dịch và thành tiền

HƯỚNG GIẢI THUẬT:
    - Xuất từng thuộc tính
    - Gọi hàm đa hình TinhThanhTien()
*/
void GiaoDich::Xuat() const {
    cout << "Ma GD: " << maGiaoDich << endl;
    cout << "Ngay GD: " << ngayGiaoDich << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Thanh tien: "
         << fixed << setprecision(0)
         << TinhThanhTien() << endl;
}

/*
INPUT:
    Chuỗi ngày giao dịch dạng dd/mm/yyyy

OUTPUT:
    Tháng giao dịch

HƯỚNG GIẢI THUẬT:
    - Cắt chuỗi lấy vị trí tháng
    - Chuyển sang số nguyên
*/
int GiaoDich::getThang() const {
    return stoi(ngayGiaoDich.substr(3, 2));
}

/*
INPUT:
    Chuỗi ngày giao dịch dạng dd/mm/yyyy

OUTPUT:
    Năm giao dịch

HƯỚNG GIẢI THUẬT:
    - Cắt chuỗi lấy vị trí năm
    - Chuyển sang số nguyên
*/
int GiaoDich::getNam() const {
    return stoi(ngayGiaoDich.substr(6, 4));
}