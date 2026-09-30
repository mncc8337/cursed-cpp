# cursed-cpp-extended

an updated header that translates even more c++ keywords, types and operators into Vietnamese<br>
now you can write `số_nguyên_lớn_không_dấu` instead of `unsigned long long int`.

### why it is cursed?

all the translated words are unicode characters. yes<br>
should i translate numbers, too?

### how to use

put `cursed_cpp.h` next to your source file. save both as utf-8, with nfc-normalized
Vietnamese characters. define the bits you want **before** including the header.

```cpp
#define VIETNAMESE_KEYWORDS
#define VIETNAMESE_OPERATORS
#define VIETNAMESE_MISC
#include "cursed_cpp.h"

số_nguyên chương_trình_chính() {
    số_nguyên total gán_bằng 2 cộng 3;
    nếu (total bằng 5) {
        trả_về 0;
    }
    trả_về 1;
}
```

save that as `example.cpp`. use a compiler with c++20 or newer support:

```sh
g++ -std=c++23 -Wall -Wextra -pedantic-errors example.cpp -o example
```

then `./example`. on windows, use `-o example.exe` and run `.\example.exe` in powershell.

it's just `#define`. the compiler still sees regular c++. same grammar, same
operator precedence, same bugs in your program.

### switches

| define this | get this |
|---|---|
| `VIETNAMESE_KEYWORDS` | keywords, alternative operator words, and types |
| `VIETNAMESE_TYPES` | just the types |
| `VIETNAMESE_OPERATORS` | arithmetic, assignment, comparison, logical and bitwise operators. `<=>` too |
| `VIETNAMESE_OBJECTS` | stream names, like `std::kí_tự_đầu_ra` |
| `VIETNAMESE_STANDARD_LIBS` | library types grouped by header, plus some `<algorithm>` names like `std::tìm` |
| `VIETNAMESE_MISC` | `thư_viện_chuẩn` and `chương_trình_chính` |
| `VIETNAMESE_COROUTINES` | coroutine protocol names, like `lời_hứa` and `nhả_giá_trị`; include `<coroutine>` yourself |

nothing turns on by itself. `VIETNAMESE_KEYWORDS` still includes types so old code
doesn't suddenly forget what an integer is.

the header brings in `<cstddef>` + `<string>` for types, `<iostream>` for streams,
and `<algorithm>` for algorithms when needed. `VIETNAMESE_STANDARD_LIBS` also
brings in the library-type headers. include your other headers first
where possible. macros don't understand personal space.

library aliases are unqualified: `xâu` becomes `string`, and
`con_trỏ_rỗng_dạng` becomes `nullptr_t`. use `std::xâu`, `std::con_trỏ_rỗng_dạng`,
or a suitable `using` declaration, just like the streams and algorithms.
the library types live in their own section, grouped by header. `VIETNAMESE_TYPES`
and `VIETNAMESE_KEYWORDS` still enable them; `VIETNAMESE_STANDARD_LIBS` does too.

```cpp
#define VIETNAMESE_STANDARD_LIBS
#include "cursed_cpp.h"

std::xâu lời_chào = "xin chào thế giới!";
std::con_trỏ_rỗng_dạng không_có_gì = nullptr;
```

you can enable another group and include the header again. each group has its own
guard. `#undef VIETNAMESE_KEYWORDS` won't undo the aliases you already enabled.

### how much of c++ did this happen to

- all 81 c++23 keyword spellings + the 11 alternative operator words (`and`, `or`, etc.).
  `final` and `override` are here too. modules have a catch, see below.
- all standard fundamental types: the integers, signed/unsigned versions, character
  types, floats, `void`, `bool`, and `std::nullptr_t`. `std::xâu` names `std::string` as a bonus.
- the five operator groups in the table above. things like `[]`, `()`, `?:`, `.`
  and `->` still use their normal syntax. pointers, references and arrays do too.
- aliases are sorted inside each group by unicode code point, using nfc text.
  case matters. this isn't Vietnamese dictionary order.

this is **c++23**, not every keyword ever invented. no promise about c++26,
compiler-specific types, experimental keywords, or the entire standard library.
the full alias list is in [cursed_cpp.h](cursed_cpp.h) if you want to count them.

### the annoying bits

`nhập` and `mô_đun` expand to `import` and `module`, but macros don't portably create
module/import directives. keep the actual `module`, `import` and `export` spellings
on those lines. yes, this part still has to be in english.

```cpp
export module demo;
import another_module;
```

same deal with `#include`, `#define`, etc. those stay as they are.
`thanh_ghi` expands to `register`, which is still reserved but can't be used as a
variable storage specifier in c++17+. having a translation doesn't bring it back.

### does it even work

build the included example directly. no extra scripts needed:

```sh
g++ -std=c++23 -Wall -Wextra -pedantic-errors example.cpp -o example
./example
```

c++20 works too. on windows, build with `-o example.exe` and run `.\example.exe`.
if VS Code complains about concepts or coroutines, check that IntelliSense and
your actual compiler both use c++20 or newer.

save the source as utf-8. if Vietnamese output looks broken in windows cmd,
run `chcp 65001` before the example and use a font with Vietnamese glyphs.
with MSVC, also compile with `/utf-8`. changing the terminal doesn't change
how an already-built executable encoded its strings.

### todo

- [x] translate all arithmetic operators
- [x] translate all comparison operators
- [x] translate all bitwise operators
- [x] translate all assignment operators
- [x] translate all logical operators
- [x] translate all keywords (c++23 spellings. modules are still annoying)
- [x] translate all data types (standard fundamental types)
- [x] sort keywords in lexicographic order (inside each group)
- [ ] support other languages (nah)
- [ ] use nerd font for keywords lol

### the boring links

[keywords](https://timsong-cpp.github.io/cppwp/n4950/lex.key) ·
[types](https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental) ·
[unicode rules](https://timsong-cpp.github.io/cppwp/n4950/lex.name) ·
[module rules](https://timsong-cpp.github.io/cppwp/n4950/cpp.module) ·
[import rules](https://timsong-cpp.github.io/cppwp/n4950/cpp.import)

### license

MIT. see [LICENSE](LICENSE).
