#ifdef VIETNAMESE_OPERATORS
    // arithmetic operators
    #define cộng +
    #define tăng_lên ++
    #define trừ -
    #define giảm_xuống --
    #define nhân *
    #define chia /
    #define chia_lấy_dư %

    // assignment operators
    #define gán_bằng =
    #define cộng_thêm +=
    #define trừ_thêm -=
    #define nhân_thêm *=
    #define chia_thêm /=
    #define chia_lấy_dư_thêm %=
    // more_here

    // bitwise operators
    #define đẩy_bit_qua_bên_phải >>
    #define đẩy_bit_qua_bên_phải_thêm >>=
    #define đẩy_bit_qua_bên_trái <<
    #define đẩy_bit_qua_bên_trái_thêm <<=
    #define và_bit &
    #define hoặc_bit |
    #define phủ_định_bit ~ 
    #define hoặc_bit_loại_trừ ^

    // more_here

    // comparison operators
    #define bằng ==
    #define khác !=
    #define bé_hơn <
    #define bé_hơn_hoặc_bằng <=
    #define lớn_hơn >
    #define lớn_hơn_hoặc_bằng >=

    // logical operators
    #define và &&
    // #define và and
    #define hoặc ||
    // #define hoặc or
    #define không_phải !
    // #define không_phải not
#endif

#ifdef VIETNAMESE_KEYWORDS
    // keywords
    #define trong_khi while
    #define cho for
    #define nếu if
    #define nếu_không_thì else
    #define so_sánh switch
    #define trường_hợp case
    #define tiếp_tục continue
    #define phá break
    #define thử try
    #define bắt catch
    #define lớp class
    #define cấu_trúc struct
    #define hằng_số const
    #define làm do
    #define trả_về return
    #define dùng using
    #define không_gian_tên namespace
    #define tư private
    #define ảo virtual
    #define công public 
    #define tự_động auto
    #define đi_đến goto
    #define được_bảo_vệ protected
    #define hợp_nhất union
    #define ném_trả throw
    #define tĩnh static
    #define nội_tuyến inline
    #define bên_ngoài extern
    #define xuất export
    #define nhập import
    #define kiểu_mẫu template
    #define rõ_ràng explicit
    #define liệt_kê enum
    #define phép_toán operator 
    // data types
    #define số_nguyên int
    #deifne số_nguyên_nhỏ short int
    #define số_nguyên_lớn long long
    #define số_nguyên_dương unsigned int
    #define số_thực float
    #define số_thực_lớn long double
    #define kí_tự char
    #define kí_tự_rộng wchar_t
    #define xâu std::string
    #define đúng_sai bool
    #define ĐÚNG true
    #define SAI false
    
    #define vô_định void

#endif

#ifdef VIETNAMESE_MISC
    #define thư_viện_chuẩn std
    #define chương_trình_chính main
#endif
