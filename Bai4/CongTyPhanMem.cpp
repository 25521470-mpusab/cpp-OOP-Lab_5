#include "CongTyPhanMem.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - số lượng nhân viên = 0
        - danh sách nhân viên rỗng

HƯỚNG GIẢI THUẬT:
    - Gán soLuong = 0
    - Gán dsNhanVien = NULL
*/
CongTyPhanMem::CongTyPhanMem() {
    soLuong = 0;
    dsNhanVien = NULL;
}

/*
INPUT:
    Không có

OUTPUT:
    Giải phóng toàn bộ vùng nhớ động

HƯỚNG GIẢI THUẬT:
    - Duyệt từng nhân viên
    - delete từng đối tượng
    - delete[] mảng con trỏ
*/
CongTyPhanMem::~CongTyPhanMem() {

    for(int i = 0; i < soLuong; i++) {
        delete dsNhanVien[i];
    }

    delete[] dsNhanVien;
}

/*
INPUT:
    - số lượng nhân viên
    - loại nhân viên
    - thông tin từng nhân viên

OUTPUT:
    Danh sách nhân viên được nhập đầy đủ

HƯỚNG GIẢI THUẬT:
    - Nhập số lượng > 0
    - Cấp phát mảng động con trỏ
    - Với mỗi nhân viên:
        + chọn loại
        + tạo đối tượng phù hợp
        + gọi Nhap() bằng đa hình
*/
void CongTyPhanMem::NhapDanhSach() {

    do {
        cout << "Nhap so luong nhan vien: ";
        cin >> soLuong;

        if(soLuong <= 0)
            cout << "So luong phai > 0!\n";

    } while(soLuong <= 0);

    dsNhanVien = new NhanVien*[soLuong];

    for(int i = 0; i < soLuong; i++) {

        int loai;

        cout << "\nNhap nhan vien thu " << i + 1 << endl;
        cout << "1. Lap trinh vien\n";
        cout << "2. Kiem chung vien\n";
        cout << "Chon loai: ";
        cin >> loai;

        if(loai == 1)
            dsNhanVien[i] = new LapTrinhVien;
        else
            dsNhanVien[i] = new KiemChungVien;

        dsNhanVien[i]->Nhap();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất toàn bộ danh sách nhân viên

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Gọi hàm Xuat() bằng đa hình
*/
void CongTyPhanMem::XuatDanhSach() const {

    cout << "\n===== DANH SACH NHAN VIEN =====\n";

    for(int i = 0; i < soLuong; i++) {

        cout << "\nNhan vien thu " << i + 1 << endl;
        dsNhanVien[i]->Xuat();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Trả về lương trung bình của công ty

HƯỚNG GIẢI THUẬT:
    - Tính tổng lương tất cả nhân viên
    - Chia cho số lượng nhân viên
*/
double CongTyPhanMem::TinhLuongTrungBinh() const {

    double tong = 0;

    for(int i = 0; i < soLuong; i++) {
        tong += dsNhanVien[i]->TinhLuong();
    }

    return tong / soLuong;
}

/*
INPUT:
    Không có

OUTPUT:
    Danh sách nhân viên có lương thấp hơn lương trung bình

HƯỚNG GIẢI THUẬT:
    - Tính lương trung bình
    - Duyệt danh sách
    - Nếu lương nhân viên < lương trung bình:
        xuất nhân viên
*/
void CongTyPhanMem::XuatDSNVLuongThapHonTrungBinh() const {

    double luongTB = TinhLuongTrungBinh();

    cout << "\n===== NHAN VIEN LUONG THAP HON TRUNG BINH =====\n";

    for(int i = 0; i < soLuong; i++) {

        if(dsNhanVien[i]->TinhLuong() < luongTB) {
            dsNhanVien[i]->Xuat();
            cout << endl;
        }
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Nhân viên có lương cao nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - So sánh lương
    - Lưu vị trí nhân viên có lương lớn nhất
*/
void CongTyPhanMem::TimNVLuongCaoNhat() const {

    int max = 0;

    for(int i = 1; i < soLuong; i++) {

        if(dsNhanVien[i]->TinhLuong() >
           dsNhanVien[max]->TinhLuong()) {

            max = i;
        }
    }

    cout << "\nNhan vien luong cao nhat:\n";
    dsNhanVien[max]->Xuat();
}

/*
INPUT:
    Không có

OUTPUT:
    Nhân viên có lương thấp nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - So sánh lương
    - Lưu vị trí nhân viên có lương nhỏ nhất
*/
void CongTyPhanMem::TimNVLuongThapNhat() const {

    int min = 0;

    for(int i = 1; i < soLuong; i++) {

        if(dsNhanVien[i]->TinhLuong() <
           dsNhanVien[min]->TinhLuong()) {

            min = i;
        }
    }

    cout << "\nNhan vien luong thap nhat:\n";
    dsNhanVien[min]->Xuat();
}

/*
INPUT:
    Không có

OUTPUT:
    Lập trình viên có lương cao nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast sang LapTrinhVien
    - So sánh lương
    - Lưu lập trình viên có lương lớn nhất
*/
void CongTyPhanMem::TimLapTrinhVienLuongCaoNhat() const {

    LapTrinhVien* maxLTV = NULL;

    for(int i = 0; i < soLuong; i++) {

        LapTrinhVien* temp =
        dynamic_cast<LapTrinhVien*>(dsNhanVien[i]);

        if(temp != NULL) {

            if(maxLTV == NULL ||
               temp->TinhLuong() > maxLTV->TinhLuong()) {

                maxLTV = temp;
            }
        }
    }

    if(maxLTV == NULL)
        cout << "Khong co lap trinh vien!\n";
    else {
        cout << "\nLap trinh vien luong cao nhat:\n";
        maxLTV->Xuat();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Kiểm chứng viên có lương thấp nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast sang KiemChungVien
    - So sánh lương
    - Lưu kiểm chứng viên có lương nhỏ nhất
*/
void CongTyPhanMem::TimKiemChungVienLuongThapNhat() const {

    KiemChungVien* minKCV = NULL;

    for(int i = 0; i < soLuong; i++) {

        KiemChungVien* temp =
        dynamic_cast<KiemChungVien*>(dsNhanVien[i]);

        if(temp != NULL) {

            if(minKCV == NULL ||
               temp->TinhLuong() < minKCV->TinhLuong()) {

                minKCV = temp;
            }
        }
    }

    if(minKCV == NULL)
        cout << "Khong co kiem chung vien!\n";
    else {
        cout << "\nKiem chung vien luong thap nhat:\n";
        minKCV->Xuat();
    }
}