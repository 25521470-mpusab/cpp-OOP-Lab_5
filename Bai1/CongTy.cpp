#include "CongTy.h"

/*
INPUT:
    Không có

OUTPUT:
    - Khởi tạo:
        + danh sách nhân viên rỗng
        + số lượng = 0

HƯỚNG GIẢI THUẬT:
    - Gán con trỏ danh sách bằng NULL
    - Gán số lượng bằng 0
*/
CongTy::CongTy() {
    dsNhanVien = NULL;
    soLuong = 0;
}

/*
INPUT:
    Không có

OUTPUT:
    - Giải phóng vùng nhớ động

HƯỚNG GIẢI THUẬT:
    - Duyệt mảng con trỏ nhân viên
    - Giải phóng từng nhân viên
    - Giải phóng mảng động
*/
CongTy::~CongTy() {
    for (int i = 0; i < soLuong; i++) {
        delete dsNhanVien[i];
    }
    delete[] dsNhanVien;
}

/*
INPUT:
    - Số lượng nhân viên
    - Loại nhân viên
    - Thông tin từng nhân viên

OUTPUT:
    - Lưu danh sách nhân viên công ty

HƯỚNG GIẢI THUẬT:
    - Nhập số lượng nhân viên > 0
    - Cấp phát mảng động con trỏ nhân viên
    - Chọn loại nhân viên:
        + sản xuất
        + văn phòng
    - Tạo object phù hợp bằng new
    - Gọi đa hình hàm Nhap()
*/
void CongTy::NhapDanhSach() {
   do{
    cout << "Nhap so luong nhan vien (>0): ";
    cin >> soLuong;

    if(soLuong <= 0)
        cout << "So luong khong hop le!\n";
    }
    
    while(soLuong <= 0);

    dsNhanVien = new NhanVien*[soLuong];

    for (int i = 0; i < soLuong; i++) {
        int loai;

        cout << "\nNhap nhan vien thu " << i + 1 << endl;
        cout << "\n1. Nhan vien san xuat\n";
        cout << "2. Nhan vien van phong\n";
        cout << "Chon loai nhan vien: ";
        cin >> loai;

        if(loai == 1){
            dsNhanVien[i] = new NhanVienSanXuat;
        }
        else{
            dsNhanVien[i] = new NhanVienVanPhong;
        }

        dsNhanVien[i]->Nhap();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    - Xuất danh sách nhân viên

HƯỚNG GIẢI THUẬT:
    - Duyệt mảng nhân viên
    - Gọi đa hình hàm Xuat()
*/
void CongTy::XuatDanhSach() const {
    cout << "\nDanh sách nhân viên\n";
    for (int i = 0; i < soLuong; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        dsNhanVien[i]->Xuat();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    - Trả về tổng lương công ty phải trả

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách nhân viên
    - Cộng lương từng nhân viên
*/
double CongTy::TinhTongLuong() const {
    double tong = 0;

    for (int i = 0; i < soLuong; i++) {
        tong += dsNhanVien[i]->TinhLuong();
    }

    return tong;
}

/*
INPUT:
    Không có

OUTPUT:
    - Xuất nhân viên sản xuất có lương thấp nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách nhân viên
    - Dùng dynamic_cast kiểm tra có phải NV sản xuất
    - So sánh lương để tìm nhỏ nhất
*/
void CongTy::TimNVSanXuatLuongThapNhat() const {

    NhanVienSanXuat* minNV = NULL;

    for(int i = 0; i < soLuong; i++) {

        NhanVienSanXuat* temp =
            dynamic_cast<NhanVienSanXuat*>(dsNhanVien[i]);

        if(temp != NULL){

            if(minNV == NULL ||
               temp->TinhLuong() < minNV->TinhLuong()) {

                minNV = temp;
            }
        }
    }

    if(minNV == NULL){
        cout << "Khong co nhan vien san xuat!\n";
    }
    else{
        cout << "\nNhan vien san xuat luong thap nhat:\n";
        minNV->Xuat();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    - Xuất nhân viên văn phòng lớn tuổi nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách nhân viên
    - Dùng dynamic_cast kiểm tra có phải NV văn phòng
    - So sánh tuổi để tìm lớn nhất
*/
void CongTy::TimNVVanPhongLonTuoiNhat() const {

    NhanVienVanPhong* maxNV = NULL;

    for(int i = 0; i < soLuong; i++) {

        NhanVienVanPhong* temp =
            dynamic_cast<NhanVienVanPhong*>(dsNhanVien[i]);

        if(temp != NULL){

            if(maxNV == NULL ||
               temp->TinhTuoi() > maxNV->TinhTuoi()) {

                maxNV = temp;
            }
        }
    }

    if(maxNV == NULL){
        cout << "Khong co nhan vien van phong!\n";
    }
    else{
        cout << "\nNhan vien van phong tuoi lon nhat:\n";
        maxNV->Xuat();
    }
}