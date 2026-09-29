// test program. it got worse.
// g++ -std=c++23 -Wall -Wextra -pedantic-errors example.cpp -o example

#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#define VIETNAMESE_OPERATORS
#define VIETNAMESE_KEYWORDS
#define VIETNAMESE_OBJECTS
#define VIETNAMESE_MISC
#include "cursed_cpp.h"

dùng không_gian_tên thư_viện_chuẩn;

vô_định sàng_số_nguyên_tố(số_nguyên max) {
    nếu (max bé_hơn 2) {
        kí_tự_đầu_ra đẩy_bit_qua_bên_trái '\n';
        trả_về;
    }

    vector<đúng_sai> sàng(ép_kiểu_tĩnh<size_t>(max) cộng 1, SAI);
    sàng[0] gán_bằng sàng[1] gán_bằng ĐÚNG;

    cho (số_nguyên i gán_bằng 2; i bé_hơn_hoặc_bằng max chia i; i tăng_lên) {
        nếu (không_phải sàng[i]) {
            cho (số_nguyên_lớn k gán_bằng ép_kiểu_tĩnh<số_nguyên_lớn>(i) nhân i;
                 k bé_hơn_hoặc_bằng max; k cộng_thêm i) {
                sàng[ép_kiểu_tĩnh<size_t>(k)] gán_bằng ĐÚNG;
            }
        }
    }

    cho (size_t i gán_bằng 2; i bé_hơn sàng.size(); i tăng_lên) {
        nếu (không_phải sàng[i]) {
            kí_tự_đầu_ra đẩy_bit_qua_bên_trái i đẩy_bit_qua_bên_trái ' ';
        }
    }
    kí_tự_đầu_ra đẩy_bit_qua_bên_trái '\n';
}

kiểu_mẫu <tên_dạng T>
khái_niệm số_đếm = integral<T>;

kiểu_mẫu <số_đếm... CácSố>
tính_hằng số_nguyên_lớn cộng_hết(CácSố... số) {
    trả_về (0LL cộng ... cộng ép_kiểu_tĩnh<số_nguyên_lớn>(số));
}

khẳng_định_tĩnh(cộng_hết() bằng 0);
khẳng_định_tĩnh(cộng_hết(1, 2, 3, 4, 5) bằng 15);

kiểu_mẫu <số_nguyên MôĐun>
lớp số_vòng {
    khẳng_định_tĩnh(MôĐun lớn_hơn 0);

    tư:
        số_nguyên_lớn giá_trị;

    công:
        biểu_thức_hằng rõ_ràng số_vòng(số_nguyên_lớn n gán_bằng 0)
            : giá_trị((n chia_lấy_dư MôĐun cộng MôĐun) chia_lấy_dư MôĐun) {}

        bạn biểu_thức_hằng số_vòng phép_toán cộng(số_vòng a, số_vòng b) {
            trả_về số_vòng(a.giá_trị cộng b.giá_trị);
        }

        bạn biểu_thức_hằng số_vòng phép_toán nhân(số_vòng a, số_vòng b) {
            trả_về số_vòng(a.giá_trị nhân b.giá_trị);
        }

        biểu_thức_hằng đúng_sai phép_toán bằng(hằng_số số_vòng&) hằng_số = mặc_định;

        bạn ostream& phép_toán đẩy_bit_qua_bên_trái(ostream& luồng, số_vòng n) {
            trả_về luồng đẩy_bit_qua_bên_trái n.giá_trị;
        }
};

kiểu_mẫu <tên_dạng T>
    yêu_cầu yêu_cầu(T a) {
        T{1};
        { a nhân a } -> same_as<T>;
    }
biểu_thức_hằng T lũy_thừa(T cơ_số, số_nguyên_lớn_không_dấu số_mũ) {
    T kết_quả{1};
    trong_khi (số_mũ lớn_hơn 0) {
        nếu (số_mũ và_bit 1) {
            kết_quả gán_bằng kết_quả nhân cơ_số;
        }
        cơ_số gán_bằng cơ_số nhân cơ_số;
        số_mũ đẩy_bit_qua_bên_phải_thêm 1;
    }
    trả_về kết_quả;
}

dùng số_khó_đọc = số_vòng<1'000'000'007>;
khẳng_định_tĩnh(lũy_thừa(số_khó_đọc{2}, 10) bằng số_khó_đọc{1024});
khẳng_định_tĩnh(lũy_thừa(số_khó_đọc{2}, 0) bằng số_khó_đọc{1});
khẳng_định_tĩnh(số_vòng<7>{-1} cộng số_vòng<7>{2} bằng số_vòng<7>{1});

lớp máy_nhả_số {
    công:
        // the compiler wants these exact english names. i tried.
        cấu_trúc promise_type {
            số_nguyên_lớn hiện_tại gán_bằng 0;
            exception_ptr lỗi;

            máy_nhả_số get_return_object() {
                trả_về máy_nhả_số{
                    coroutine_handle<promise_type>::from_promise(*con_trỏ_này)
                };
            }

            suspend_always initial_suspend() không_loại_trừ { trả_về {}; }
            suspend_always final_suspend() không_loại_trừ { trả_về {}; }

            suspend_always yield_value(số_nguyên_lớn n) không_loại_trừ {
                hiện_tại gán_bằng n;
                trả_về {};
            }

            vô_định return_void() không_loại_trừ {}
            vô_định unhandled_exception() không_loại_trừ {
                lỗi gán_bằng current_exception();
            }
        };

        dùng tay_cầm = coroutine_handle<promise_type>;

        rõ_ràng máy_nhả_số(tay_cầm h) không_loại_trừ : khung(h) {}
        máy_nhả_số(hằng_số máy_nhả_số&) = xóa;
        máy_nhả_số& phép_toán gán_bằng(hằng_số máy_nhả_số&) = xóa;

        máy_nhả_số(máy_nhả_số&& máy_cũ) không_loại_trừ
            : khung(exchange(máy_cũ.khung, tay_cầm{})) {}

        ~máy_nhả_số() {
            nếu (khung) khung.destroy();
        }

        đúng_sai tiếp() {
            nếu (không_phải khung hoặc khung.done()) trả_về SAI;
            khung.resume();
            nếu (khung.promise().lỗi) rethrow_exception(khung.promise().lỗi);
            trả_về không_phải khung.done();
        }

        số_nguyên_lớn đọc() hằng_số {
            trả_về khung.promise().hiện_tại;
        }

    tư:
        tay_cầm khung;
};

máy_nhả_số fibonacci_lười(số_nguyên số_lượng) {
    nếu (số_lượng bé_hơn 0 hoặc số_lượng lớn_hơn 92) {
        ném_trả out_of_range("0..92 thoi. long long cung co gioi han.");
    }

    số_nguyên_lớn a gán_bằng 0, b gán_bằng 1;
    cho (số_nguyên i gán_bằng 0; i bé_hơn số_lượng; i tăng_lên) {
        đồng_nhường b;
        nếu (i cộng 1 bé_hơn số_lượng) {
            tự_động tiếp_theo gán_bằng a cộng b;
            a gán_bằng b;
            b gán_bằng tiếp_theo;
        }
    }
    đồng_trả_về;
}

vô_định dãy_fibonacci(số_nguyên max gán_bằng 5) {
    tự_động máy gán_bằng fibonacci_lười(max);
    trong_khi (máy.tiếp()) {
        kí_tự_đầu_ra đẩy_bit_qua_bên_trái máy.đọc() đẩy_bit_qua_bên_trái ' ';
    }
    kí_tự_đầu_ra đẩy_bit_qua_bên_trái '\n';
}

số_nguyên chương_trình_chính() {
    kí_tự_đầu_ra đẩy_bit_qua_bên_trái "xin chào thế giới!\n";

    kí_tự_đầu_ra đẩy_bit_qua_bên_trái "\n[1] primes <= 200. the normal part.\n";
    sàng_số_nguyên_tố(200);

    kí_tự_đầu_ra đẩy_bit_qua_bên_trái "\n[2] a compile-time fold for 1 + ... + 5\n";
    kí_tự_đầu_ra đẩy_bit_qua_bên_trái cộng_hết(1, 2, 3, 4, 5) đẩy_bit_qua_bên_trái '\n';

    kí_tự_đầu_ra đẩy_bit_qua_bên_trái "\n[3] 2^100 mod 1000000007\n";
    biểu_thức_hằng tự_động đáp_án gán_bằng lũy_thừa(số_khó_đọc{2}, 100);
    khẳng_định_tĩnh(đáp_án bằng số_khó_đọc{976371285});
    kí_tự_đầu_ra đẩy_bit_qua_bên_trái đáp_án đẩy_bit_qua_bên_trái '\n';

    kí_tự_đầu_ra đẩy_bit_qua_bên_trái "\n[4] fibonacci, but it pauses after every number\n";
    dãy_fibonacci(35);

    trả_về 0;
}
