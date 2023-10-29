// test program
#include <iostream>
#define VIETNAMESE_OPERATORS
#define VIETNAMESE_KEYWORDS
#define VIETNAMESE_MISC
#include "cursed_cpp.h"

dùng không_gian_tên thư_viện_chuẩn;

vô_định sàng_số_nguyên_tố(số_nguyên max) {
    đúng_sai sàng[max cộng 1];
    cho(số_nguyên i gán_bằng 2; i bé_hơn_hoặc_bằng max; i tăng_lên) {
        nếu(không_phải(sàng[i])) {
            cho(số_nguyên k gán_bằng i nhân 2; k bé_hơn_hoặc_bằng max; k cộng_thêm i)
                sàng[k] gán_bằng ĐÚNG;
            cout đẩy_bit_qua_bên_trái i đẩy_bit_qua_bên_trái ' ';
        }
    }
    cout đẩy_bit_qua_bên_trái '\n';
}

vô_định dãy_fibonacci(số_nguyên max gán_bằng 5, số_nguyên k gán_bằng 1, số_nguyên_lớn a gán_bằng 1, số_nguyên_lớn b gán_bằng 1) {
    nếu(k lớn_hơn max) {
        cout đẩy_bit_qua_bên_trái '\n';
        trả_về;
    }

    cout đẩy_bit_qua_bên_trái a đẩy_bit_qua_bên_trái ' ';
    dãy_fibonacci(max, k cộng 1, b, a cộng b);
}

số_nguyên chương_trình_chính() {
    cout đẩy_bit_qua_bên_trái "xin chào thế giới!" đẩy_bit_qua_bên_trái endl;

    sàng_số_nguyên_tố(200);
    dãy_fibonacci(35);

    trả_về 0;
}