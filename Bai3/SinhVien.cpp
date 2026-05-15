#include "SinhVien.h"
#include <iomanip>

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - MSSV rỗng
        - họ tên rỗng
        - địa chỉ rỗng
        - tổng tín chỉ = 0
        - điểm trung bình = 0

HƯỚNG GIẢI THUẬT:
    - Gán giá trị mặc định cho toàn bộ thuộc tính
*/
SinhVien::SinhVien() {
    mSSV = "";
    hoTen = "";
    diaChi = "";
    tongTinChi = 0;
    diemTrungBinh = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    Hủy đối tượng sinh viên

HƯỚNG GIẢI THUẬT:
    - Không cần xử lý do không cấp phát động
*/
SinhVien::~SinhVien() {
}

/*
INPUT:
    - MSSV
    - Họ tên
    - Địa chỉ
    - Tổng tín chỉ
    - Điểm trung bình

OUTPUT:
    Thông tin sinh viên được nhập hợp lệ

HƯỚNG GIẢI THUẬT:
    - Nhập MSSV, họ tên, địa chỉ bằng getline
    - Kiểm tra tổng tín chỉ >= 0
    - Kiểm tra điểm trung bình thuộc [0,10]
*/
void SinhVien::Nhap() {
    cin.ignore();

    cout << "Nhap MSSV: ";
    getline(cin, mSSV);

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
     cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    do {
        cout << "Nhap tong tin chi: ";
        cin >> tongTinChi;

        if(tongTinChi < 0)
            cout << "Tong tin chi phai >= 0!\n";

    } while(tongTinChi < 0);

    do {
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;

        if(diemTrungBinh < 0 || diemTrungBinh > 10)
            cout << "Diem trung binh phai tu 0 -> 10!\n";

    } while(diemTrungBinh < 0 || diemTrungBinh > 10);
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất toàn bộ thông tin sinh viên

HƯỚNG GIẢI THUẬT:
    - In lần lượt:
        + MSSV
        + Họ tên
        + Địa chỉ
        + Tổng tín chỉ
        + Điểm trung bình
*/
void SinhVien::Xuat() const {
    cout << "MSSV: " << mSSV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Tong tin chi: " << tongTinChi << endl;

    cout << "Diem trung binh: "
         << fixed << setprecision(2)
         << diemTrungBinh << endl;
}

/*
INPUT:
    Không có

OUTPUT:
    Trả về điểm trung bình sinh viên

HƯỚNG GIẢI THUẬT:
    - Trả về thuộc tính diemTrungBinh
*/
double SinhVien::getDiemTrungBinh() const {
    return diemTrungBinh;
}
