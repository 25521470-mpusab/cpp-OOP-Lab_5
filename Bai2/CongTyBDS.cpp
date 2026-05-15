#include "CongTyBDS.h"
#include <iomanip>

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo công ty:
        - danh sách giao dịch rỗng
        - số lượng = 0

HƯỚNG GIẢI THUẬT:
    - Gán con trỏ danh sách = NULL
    - Gán số lượng = 0
*/
CongTyBDS::CongTyBDS() {
    dsGiaoDich = NULL;
    soLuong = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Giải phóng toàn bộ bộ nhớ động của danh sách giao dịch

HƯỚNG GIẢI THUẬT:
    - Duyệt từng giao dịch và delete
    - Delete mảng con trỏ
*/
CongTyBDS::~CongTyBDS() {
    for(int i = 0; i < soLuong; i++) {
        delete dsGiaoDich[i];
    }

    delete[] dsGiaoDich;
}

/*
INPUT:
    Danh sách giao dịch nhập từ bàn phím

OUTPUT:
    Tạo danh sách các giao dịch hợp lệ

ĐIỀU KIỆN:
    - số lượng > 0
    - loại giao dịch chỉ được:
        + 1: đất
        + 2: nhà phố
        + 3: chung cư

HƯỚNG GIẢI THUẬT:
    - Nhập số lượng giao dịch
    - Cấp phát mảng động
    - Với mỗi giao dịch:
        + chọn loại
        + tạo object tương ứng bằng đa hình
        + gọi hàm Nhap()
*/
void CongTyBDS::NhapDanhSach() {
    do {
        cout << "Nhap so luong giao dich: ";
        cin >> soLuong;

        if(soLuong <= 0)
            cout << "So luong phai > 0!\n";

    } while(soLuong <= 0);

    dsGiaoDich = new GiaoDich*[soLuong];

    for(int i = 0; i < soLuong; i++) {

        int loai;

        cout << "\nNhap giao dich thu " << i + 1 << endl;
        cout << "1. Giao dich dat\n";
        cout << "2. Giao dich nha pho\n";
        cout << "3. Giao dich chung cu\n";
        cout << "Chon loai: ";
        cin >> loai;

        if(loai == 1)
            dsGiaoDich[i] = new GiaoDichDat;
        else if(loai == 2)
            dsGiaoDich[i] = new GiaoDichNhaPho;
        else
            dsGiaoDich[i] = new GiaoDichChungCu;

        dsGiaoDich[i]->Nhap();
    }
}

/*
INPUT:
    Danh sách giao dịch hiện tại

OUTPUT:
    Xuất toàn bộ thông tin giao dịch

HƯỚNG GIẢI THUẬT:
    - Duyệt từng giao dịch
    - Gọi hàm Xuat() bằng đa hình
*/
void CongTyBDS::XuatDanhSach() const {
    cout << "\n===== DANH SACH GIAO DICH =====\n";
 for(int i = 0; i < soLuong; i++) {
        cout << "\nGiao dich thu " << i + 1 << endl;
        dsGiaoDich[i]->Xuat();
    }
}

/*
INPUT:
    Danh sách giao dịch

OUTPUT:
    Tổng số lượng giao dịch đất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast kiểm tra giao dịch đất
    - Đếm số lượng
*/
double CongTyBDS::TongSoLuongDat() const {
    int dem = 0;

    for(int i = 0; i < soLuong; i++) {
        if(dynamic_cast<GiaoDichDat*>(dsGiaoDich[i]))
            dem++;
    }

    return dem;
}

/*
INPUT:
    Danh sách giao dịch

OUTPUT:
    Tổng số lượng giao dịch nhà phố

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast kiểm tra giao dịch nhà phố
    - Đếm số lượng
*/
int CongTyBDS::TongSoLuongNhaPho() const {
    int dem = 0;

    for(int i = 0; i < soLuong; i++) {
        if(dynamic_cast<GiaoDichNhaPho*>(dsGiaoDich[i]))
            dem++;
    }

    return dem;
}

/*
INPUT:
    Danh sách giao dịch

OUTPUT:
    Tổng số lượng giao dịch chung cư

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast kiểm tra giao dịch chung cư
    - Đếm số lượng
*/
int CongTyBDS::TongSoLuongChungCu() const {
    int dem = 0;

    for(int i = 0; i < soLuong; i++) {
        if(dynamic_cast<GiaoDichChungCu*>(dsGiaoDich[i]))
            dem++;
    }

    return dem;
}

/*
INPUT:
    Danh sách giao dịch chung cư

OUTPUT:
    Giá trị trung bình thành tiền giao dịch chung cư

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Lọc các giao dịch chung cư
    - Tính tổng thành tiền
    - Chia cho số lượng
*/
double CongTyBDS::TinhTrungBinhThanhTienChungCu() const {
    double tong = 0;
    int dem = 0;

    for(int i = 0; i < soLuong; i++) {

        GiaoDichChungCu* temp =
            dynamic_cast<GiaoDichChungCu*>(dsGiaoDich[i]);

        if(temp != NULL) {
            tong += temp->TinhThanhTien();
            dem++;
        }
        }

    if(dem == 0)
        return 0;

    return tong / dem;
}

/*
INPUT:
    Danh sách giao dịch nhà phố

OUTPUT:
    Giao dịch nhà phố có giá trị cao nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Lọc giao dịch nhà phố
    - So sánh thành tiền để tìm lớn nhất
*/
void CongTyBDS::TimGDNhaPhoGiaTriCaoNhat() const {

    GiaoDichNhaPho* maxGD = NULL;

    for(int i = 0; i < soLuong; i++) {

        GiaoDichNhaPho* temp =
            dynamic_cast<GiaoDichNhaPho*>(dsGiaoDich[i]);

        if(temp != NULL) {

            if(maxGD == NULL ||
               temp->TinhThanhTien() > maxGD->TinhThanhTien()) {

             maxGD = temp;
            }
        }
    }

    if(maxGD == NULL)
        cout << "Khong co giao dich nha pho!\n";
    else {
        cout << "\nGiao dich nha pho co gia tri cao nhat:\n";
        maxGD->Xuat();
    }
}

/*
INPUT:
    Danh sách giao dịch

OUTPUT:
    Các giao dịch diễn ra trong tháng 12 năm 2024

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Kiểm tra tháng = 12 và năm = 2024
    - Xuất giao dịch phù hợp
*/
void CongTyBDS::XuatDSGiaoDichThang12_2024() const {

    cout << "\n===== GIAO DICH THANG 12/2024 =====\n";

    bool timThay = false;

    for(int i = 0; i < soLuong; i++) {

        if(dsGiaoDich[i]->getThang() == 12 &&
           dsGiaoDich[i]->getNam() == 2024) {

            dsGiaoDich[i]->Xuat();
            cout << endl;

            timThay = true;
        }
    }

    if(!timThay){
        cout << "Khong co giao dich trong thang 12/2024.\n";
    }
}