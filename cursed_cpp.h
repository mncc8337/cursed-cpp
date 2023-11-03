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
    #define đẩy_bit_qua_bên_phải_thêm >>=
    #define đẩy_bit_qua_bên_trái_thêm <<=
    #define và_bit_thêm &=
    #define hoặc_bit_thêm |=
    #define đảo_bit_thêm ~=
    #define không_giống_bit_thêm ^=
    #define và_bit_thêm &=

    // bitwise operators
    #define đẩy_bit_qua_bên_phải >>
    #define đẩy_bit_qua_bên_trái <<
    #define và_bit &
    #define hoặc_bit |
    #define đảo_bit ~ 
    #define không_giống_bit ^

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
    #define nhãn label
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
    #define đánh_số enum
    #define phép_toán operator 
    #define bạn friend
    #define khái_niệm concept
    #define định_nghĩa_dạng typedef
    #define thông_tin_dạng typeid 
    #define tên_dạng typename
    #define ghi_đè override 
    #define mô_đun module
    #define cuối_cùng final
    #define kích_cỡ_của sizeof
    #define biến_động volatile
    #define nghịch compl
    #define không_loại_trừ noexcept 
    #define luồng_cục_bộ thread_local
   //exprimental kws
   #define đồng_bộ_hóa synchronized 
    // data types
    #define số_nguyên int
    #define số_nguyên_nhỏ short int
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
    #define biến_đổi mutable
    #define con_trỏ_rỗng nullptr

#endif

#ifdef VIETNAMESE_MISC
    #define thư_viện_chuẩn std
    #define chương_trình_chính main
#endif
