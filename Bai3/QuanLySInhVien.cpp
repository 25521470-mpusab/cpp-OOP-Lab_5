#include "QuanLySinhVien.h"

/*
INPUT:
    Không có

OUTPUT:
    Khởi tạo:
        - số lượng sinh viên = 0
        - danh sách sinh viên rỗng

HƯỚNG GIẢI THUẬT:
    - Gán soLuong = 0
    - Gán con trỏ dsSinhVien = NULL
*/
QuanLySinhVien::QuanLySinhVien() {
    soLuong = 0;
    dsSinhVien = NULL;
}

/*
INPUT:
    Không có

OUTPUT:
    Giải phóng toàn bộ vùng nhớ động của danh sách sinh viên

HƯỚNG GIẢI THUẬT:
    - Duyệt từng phần tử trong danh sách
    - delete từng đối tượng sinh viên
    - delete[] mảng con trỏ
*/
QuanLySinhVien::~QuanLySinhVien() {

    for(int i = 0; i < soLuong; i++) {
        delete dsSinhVien[i];
    }

    delete[] dsSinhVien;
}

/*
INPUT:
    - Số lượng sinh viên
    - Loại sinh viên
    - Thông tin từng sinh viên

OUTPUT:
    Danh sách sinh viên được nhập đầy đủ

HƯỚNG GIẢI THUẬT:
    - Nhập số lượng > 0
    - Cấp phát mảng động con trỏ
    - Với mỗi sinh viên:
        + Chọn loại sinh viên
        + Nếu là Cao Đẳng:
            tạo đối tượng SinhVienCaoDang
        + Nếu là Đại Học:
            tạo đối tượng SinhVienDaiHoc
        + Gọi hàm Nhap() bằng đa hình
*/

void QuanLySinhVien::NhapDanhSach() {

    do {
        cout << "Nhap so luong sinh vien: ";
        cin >> soLuong;

        if(soLuong <= 0)
            cout << "So luong phai > 0!\n";

    } while(soLuong <= 0);

     dsSinhVien = new SinhVien*[soLuong];

    for(int i = 0; i < soLuong; i++) {

        int loai;

        cout << "\nNhap sinh vien thu " << i + 1 << endl;
        cout << "1. Sinh vien Cao Dang\n";
        cout << "2. Sinh vien Dai Hoc\n";
        cout << "Chon loai: ";
        cin >> loai;

        if(loai == 1)
            dsSinhVien[i] = new SinhVienCaoDang;
        else
            dsSinhVien[i] = new SinhVienDaiHoc;

        dsSinhVien[i]->Nhap();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Xuất toàn bộ danh sách sinh viên

HƯỚNG GIẢI THUẬT:
    - Duyệt từng sinh viên trong danh sách
    - Gọi hàm Xuat() bằng đa hình
*/
void QuanLySinhVien::XuatDanhSach() const {

    cout << "\n===== DANH SACH SINH VIEN =====\n";

    for(int i = 0; i < soLuong; i++) {

        cout << "\nSinh vien thu " << i + 1 << endl;
        dsSinhVien[i]->Xuat();
    }
    }

/*
INPUT:
    Không có

OUTPUT:
    Danh sách sinh viên đủ điều kiện tốt nghiệp

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách sinh viên
    - Kiểm tra DuDieuKienTotNghiep()
    - Nếu đúng:
        xuất sinh viên
*/
void QuanLySinhVien::XuatDSDuDKTotNghiep() const {

    cout << "\n===== DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP =====\n";

    bool timThay = false;

    for(int i = 0; i < soLuong; i++) {

        if(dsSinhVien[i]->DuDieuKienTotNghiep()) {
            dsSinhVien[i]->Xuat();
            cout << endl;
            timThay = true;
        }
    }

    if(!timThay)
        cout << "Khong co sinh vien nao du dieu kien!\n";
}

/*
INPUT:
    Không có

OUTPUT:
    Danh sách sinh viên không đủ điều kiện tốt nghiệp

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách sinh viên
    - Nếu DuDieuKienTotNghiep() = false:
        xuất sinh viên
*/
void QuanLySinhVien::XuatDSKhongDuDKTotNghiep() const {

    cout << "\n===== DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP =====\n";

    bool timThay = false;

    for(int i = 0; i < soLuong; i++) {

        if(!dsSinhVien[i]->DuDieuKienTotNghiep()) {
            dsSinhVien[i]->Xuat();
            cout << endl;
            timThay = true;
        }
    }

    if(!timThay)
        cout << "Tat ca sinh vien deu du dieu kien tot nghiep!\n";
}

/*
INPUT:
    Không có

OUTPUT:
    Sinh viên Đại Học có điểm trung bình cao nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast để ép kiểu sang SinhVienDaiHoc
    - So sánh điểm trung bình
    - Lưu sinh viên có DTB lớn nhất
*/
void QuanLySinhVien::TimSVDaiHocDTBCaoNhat() const {

    SinhVienDaiHoc* maxSV = NULL;

    for(int i = 0; i < soLuong; i++) {

        SinhVienDaiHoc* temp =
            dynamic_cast<SinhVienDaiHoc*>(dsSinhVien[i]);

        if(temp != NULL) {

            if(maxSV == NULL ||
               temp->getDiemTrungBinh() > maxSV->getDiemTrungBinh()) {

                maxSV = temp;
            }
        }
    }

     if(maxSV == NULL)
        cout << "Khong co sinh vien Dai Hoc!\n";
    else {
        cout << "\nSinh vien Dai Hoc co DTB cao nhat:\n";
        maxSV->Xuat();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Sinh viên Cao Đẳng có điểm trung bình cao nhất

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Dùng dynamic_cast sang SinhVienCaoDang
    - So sánh DTB
    - Lưu sinh viên có DTB lớn nhất
*/
void QuanLySinhVien::TimSVCaoDangDTBCaoNhat() const {

    SinhVienCaoDang* maxSV = NULL;

    for(int i = 0; i < soLuong; i++) {

        SinhVienCaoDang* temp =
            dynamic_cast<SinhVienCaoDang*>(dsSinhVien[i]);

        if(temp != NULL) {

            if(maxSV == NULL ||
               temp->getDiemTrungBinh() > maxSV->getDiemTrungBinh()) {

                maxSV = temp;
            }
        }
    }

    if(maxSV == NULL) cout << "Khong co sinh vien Cao Dang!\n";
    else {
        cout << "\nSinh vien Cao Dang co DTB cao nhat:\n";
        maxSV->Xuat();
    }
}

/*
INPUT:
    Không có

OUTPUT:
    Số lượng sinh viên Cao Đẳng không đủ điều kiện tốt nghiệp

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Ép kiểu sang SinhVienCaoDang
    - Nếu không đủ điều kiện:
        tăng biến đếm
    - Trả về kết quả
*/
int QuanLySinhVien::DemSVKhongDuDKTotNghiepCaoDang() const {

    int dem = 0;

    for(int i = 0; i < soLuong; i++) {

        SinhVienCaoDang* temp =
            dynamic_cast<SinhVienCaoDang*>(dsSinhVien[i]);

        if(temp != NULL &&
           !temp->DuDieuKienTotNghiep()) {

            dem++;
        }
    }

    return dem;
}

/*
INPUT:
    Không có

OUTPUT:
    Số lượng sinh viên Đại Học không đủ điều kiện tốt nghiệp

HƯỚNG GIẢI THUẬT:
    - Duyệt danh sách
    - Ép kiểu sang SinhVienDaiHoc
    - Nếu không đủ điều kiện:
        tăng biến đếm
    - Trả về kết quả
*/
int QuanLySinhVien::DemSVKhongDuDKTotNghiepDaiHoc() const {
  int dem = 0;

    for(int i = 0; i < soLuong; i++) {

        SinhVienDaiHoc* temp =
            dynamic_cast<SinhVienDaiHoc*>(dsSinhVien[i]);

        if(temp != NULL &&
           !temp->DuDieuKienTotNghiep()) {

            dem++;
        }
    }

    return dem;
}