// c++ but you have to type more
// vietnamese aliases for c++23. yes, these are all macros
// see README.md if the compiler starts complaining
// sorted by unicode code point inside each group. looks weird, still sorted

#if defined(VIETNAMESE_KEYWORDS) || defined(VIETNAMESE_TYPES) || defined(VIETNAMESE_STANDARD_LIBS)
#include <cstddef>
#include <string>
#endif

#if defined(VIETNAMESE_OBJECTS)
#include <iostream>
#endif

#if defined(VIETNAMESE_STANDARD_LIBS)
#include <algorithm>
#endif
// Vietnamese: operators
// replacing one character with several words. efficiency.
#if defined(VIETNAMESE_OPERATORS) && !defined(CURSED_CPP_VIETNAMESE_OPERATORS_INCLUDED)
#define CURSED_CPP_VIETNAMESE_OPERATORS_INCLUDED
#define bé_hơn <
#define bé_hơn_hoặc_bằng <=
#define bằng ==
#define chia /
#define chia_lấy_dư %
#define chia_lấy_dư_thêm %=
#define chia_thêm /=
#define cộng +
#define cộng_thêm +=
#define giảm_xuống --
#define gán_bằng =
#define hoặc ||
#define hoặc_bit |
#define hoặc_bit_thêm |=
#define khác !=
#define không_giống_bit ^
#define không_giống_bit_thêm ^=
#define không_phải !
#define lớn_hơn >
#define lớn_hơn_hoặc_bằng >=
#define nhân *
#define nhân_thêm *=
#define so_sánh_ba_chiều <=>
#define trừ -
#define trừ_thêm -=
#define tăng_lên ++
#define và &&
#define và_bit &
#define và_bit_thêm &=
#define đảo_bit ~
#define đẩy_bit_qua_bên_phải >>
#define đẩy_bit_qua_bên_phải_thêm >>=
#define đẩy_bit_qua_bên_trái <<
#define đẩy_bit_qua_bên_trái_thêm <<=

#endif // CURSED_CPP_VIETNAMESE_OPERATORS_INCLUDED

// Vietnamese: keywords
#if defined(VIETNAMESE_KEYWORDS) && !defined(CURSED_CPP_VIETNAMESE_KEYWORDS_INCLUDED)
#define CURSED_CPP_VIETNAMESE_KEYWORDS_INCLUDED
// register is still reserved. no, you can't use it for variables in c++17+
#define SAI false
#define biến_đổi mutable
#define biến_động volatile
#define biểu_thức_hằng constexpr
#define bên_ngoài extern
#define bạn friend
#define bắt catch
#define cho for
#define con_trỏ_này this
#define con_trỏ_rỗng nullptr
#define cuối_cùng final
#define công public
#define căn_chỉnh_của alignof
#define căn_chỉnh_theo alignas
#define cấu_trúc struct
#define dùng using
#define ghi_đè override
#define hằng_số const
#define hợp_ngữ asm
#define hợp_nhất union
#define khai_báo_kiểu decltype
#define khái_niệm concept
#define không_gian_tên namespace
#define không_loại_trừ noexcept
#define khẳng_định_tĩnh static_assert
#define khởi_tạo_hằng constinit
#define kiểu_mẫu template
#define kích_cỡ_của sizeof
#define luồng_cục_bộ thread_local
#define làm do
#define lớp class
#define mô_đun module
#define mặc_định default
#define mới new
#define nhập import
#define ném_trả throw
#define nếu if
#define nếu_không_thì else
#define nội_tuyến inline
#define phá break
#define phép_toán operator
#define rõ_ràng explicit
#define so_sánh switch
#define thanh_ghi register
#define thông_tin_dạng typeid
#define thử try
#define tiếp_tục continue
#define trong_khi while
#define trường_hợp case
#define trả_về return
#define tên_dạng typename
#define tính_hằng consteval
#define tĩnh static
#define tư private
#define tự_động auto
#define xuất export
#define xóa delete
#define yêu_cầu requires
#define ép_kiểu_hằng const_cast
#define ép_kiểu_tái_diễn_giải reinterpret_cast
#define ép_kiểu_tĩnh static_cast
#define ép_kiểu_động dynamic_cast
#define ĐÚNG true
#define đi_đến goto
#define đánh_số enum
#define được_bảo_vệ protected
#define định_nghĩa_dạng typedef
#define đồng_chờ co_await
#define đồng_nhường co_yield
#define đồng_trả_về co_return
#define ảo virtual

#endif // CURSED_CPP_VIETNAMESE_KEYWORDS_INCLUDED

// Vietnamese: types
#if (defined(VIETNAMESE_TYPES) || defined(VIETNAMESE_KEYWORDS)) && !defined(CURSED_CPP_VIETNAMESE_TYPES_INCLUDED)
#define CURSED_CPP_VIETNAMESE_TYPES_INCLUDED
#define có_dấu signed
#define dài long
#define không_dấu unsigned
#define kí_tự char
#define kí_tự_có_dấu signed char
#define kí_tự_không_dấu unsigned char
#define kí_tự_rộng wchar_t
#define kí_tự_utf16 char16_t
#define kí_tự_utf32 char32_t
#define kí_tự_utf8 char8_t
#define ngắn short
#define số_nguyên int
#define số_nguyên_có_dấu signed int
#define số_nguyên_dài long int
#define số_nguyên_dài_không_dấu unsigned long int
#define số_nguyên_dương unsigned int
#define số_nguyên_không_dấu unsigned int
#define số_nguyên_lớn long long
#define số_nguyên_lớn_không_dấu unsigned long long int
#define số_nguyên_nhỏ short int
#define số_nguyên_nhỏ_không_dấu unsigned short int
#define số_thực float
#define số_thực_kép double
#define số_thực_lớn long double
#define vô_định void
#define đúng_sai bool

#endif // CURSED_CPP_VIETNAMESE_TYPES_INCLUDED

// Vietnamese: library types
#if (defined(VIETNAMESE_STANDARD_LIBS) || defined(VIETNAMESE_TYPES) || defined(VIETNAMESE_KEYWORDS)) && !defined(CURSED_CPP_VIETNAMESE_LIBRARY_TYPES_INCLUDED)
#define CURSED_CPP_VIETNAMESE_LIBRARY_TYPES_INCLUDED
// <cstddef>
#define con_trỏ_rỗng_dạng nullptr_t
// <string>
#define xâu string
#endif // CURSED_CPP_VIETNAMESE_LIBRARY_TYPES_INCLUDED

// Vietnamese: objects
#if defined(VIETNAMESE_OBJECTS) && !defined(CURSED_CPP_VIETNAMESE_OBJECTS_INCLUDED)
#define CURSED_CPP_VIETNAMESE_OBJECTS_INCLUDED
#define kí_tự_ghi_nhật_kí clog
#define kí_tự_lỗi cerr
#define kí_tự_rộng_ghi_nhật_kí wclog
#define kí_tự_rộng_lỗi wcerr
#define kí_tự_rộng_đầu_ra wcout
#define kí_tự_rộng_đầu_vào wcin
#define kí_tự_đầu_ra cout
#define kí_tự_đầu_vào cin

#endif // CURSED_CPP_VIETNAMESE_OBJECTS_INCLUDED

// Vietnamese: standard libs
#if defined(VIETNAMESE_STANDARD_LIBS) && !defined(CURSED_CPP_VIETNAMESE_STANDARD_LIBS_INCLUDED)
#define CURSED_CPP_VIETNAMESE_STANDARD_LIBS_INCLUDED
#define không_khớp mismatch
#define không_tồn_tại_trong none_of
#define tìm find
#define tìm_kiếm search
#define tìm_kiếm_n search_n
#define tìm_kết_thúc find_end
#define tìm_nếu find_if
#define tìm_nếu_không find_if_not
#define tìm_đầu_tiên find_first_of
#define tất_cả_trong all_of
#define tồn_tại_trong any_of
#define với_mỗi for_each
#define với_mỗi_n for_each_n
#define đếm count
#define đếm_nếu count_if

#endif // CURSED_CPP_VIETNAMESE_STANDARD_LIBS_INCLUDED

// Vietnamese: misc
// main and std were apparently too readable
#if defined(VIETNAMESE_MISC) && !defined(CURSED_CPP_VIETNAMESE_MISC_INCLUDED)
#define CURSED_CPP_VIETNAMESE_MISC_INCLUDED
#define chương_trình_chính main
#define thư_viện_chuẩn std

#endif // CURSED_CPP_VIETNAMESE_MISC_INCLUDED

#if defined(VIETNAMESE_COROUTINES) && !defined(CURSED_CPP_VIETNAMESE_COROUTINES_INCLUDED)
#define CURSED_CPP_VIETNAMESE_COROUTINES_INCLUDED

#define lấy_máy get_return_object
#define lỗi_chưa_bắt unhandled_exception
#define lời_hứa promise_type
#define nghỉ_cuối final_suspend
#define nghỉ_đầu initial_suspend
#define nhả_giá_trị yield_value
#define trả_về_rỗng return_void

#endif // CURSED_CPP_VIETNAMESE_COROUTINES_INCLUDED