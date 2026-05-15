#include "KhachHang.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - tên khách hàng rỗng
        - số lượng hàng = 0
        - đơn giá hàng = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho các thuộc tính
*/
KhachHang::KhachHang() {
    tenKhachHang = "";
    soLuongHang = 0;
    donGiaHang = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng khách hàng

HƯỚNG GIẢI THUẬT:
    - Không xử lý gì thêm
*/
KhachHang::~KhachHang() {
}

/*
INPUT:
    fin: luồng đọc file input

OUTPUT:
    Nhập:
        - tên khách hàng
        - số lượng hàng
        - đơn giá hàng

HƯỚNG GIẢI THUẬT:
    - Đọc tên khách hàng bằng getline
    - Đọc số lượng hàng
    - Đọc đơn giá hàng
    - Kiểm tra dữ liệu hợp lệ:
        + số lượng hàng > 0
        + đơn giá hàng > 0
*/
void KhachHang::Nhap(ifstream& fin) {
    getline(fin >> ws, tenKhachHang); // cin.ignore
    fin >> soLuongHang;
    fin >> donGiaHang;

    if(soLuongHang <= 0 || donGiaHang <= 0){
        cout << "Du lieu file khong hop le!\n";
    }
}

/*
INPUT:
    fout: luồng ghi file output

OUTPUT:
    Xuất:
        - tên khách hàng
        - số tiền phải trả

HƯỚNG GIẢI THUẬT:
    - Xuất tên khách hàng
    - Gọi hàm TinhTienPhaiTra()
    - Xuất số tiền phải trả
*/
void KhachHang::Xuat(ofstream& fout) const {
    fout << tenKhachHang << endl;
    fout << TinhTienPhaiTra() << endl;
}