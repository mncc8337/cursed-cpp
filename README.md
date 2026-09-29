# cursed-cpp

A header that translates C++ keywords, types, and operators into Vietnamese.
Still cursed. Now with C++23 vocabulary, sorted aliases, and optional Nerd Font icons.

## Quick start

Copy `cursed_cpp.h` next to your source file. Save both as **UTF-8**, using
NFC-normalized Vietnamese characters. Enable the groups you want before including it:

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

Build the included example with a C++20 or newer compiler:

```sh
g++ -std=c++23 -Wall -Wextra -pedantic-errors example.cpp -o example
```

Run `./example` on Linux/macOS or `.\example.exe` in Windows PowerShell
(add `-o example.exe` to the build command on Windows).

The header performs preprocessor substitution. It does not change C++ grammar,
operator precedence, type sizes, runtime behavior, or the compiler's feature support.
Use the original English spellings in preprocessor directives such as `#include`.

## Feature flags

| Flag | Enables |
|---|---|
| `VIETNAMESE_KEYWORDS` | Keywords, alternative operator tokens, contextual spellings, and types for backward compatibility |
| `VIETNAMESE_TYPES` | Type aliases only |
| `VIETNAMESE_OPERATORS` | Arithmetic, assignment, comparison, logical, and bitwise operators, including `<=>` |
| `VIETNAMESE_OBJECTS` | Standard stream names, e.g. `std::kí_tự_đầu_ra` |
| `VIETNAMESE_STANDARD_LIBS` | The existing selection of `<algorithm>` names, e.g. `std::tìm` |
| `VIETNAMESE_MISC` | `thư_viện_chuẩn` → `std`, `chương_trình_chính` → `main` |

All groups are opt-in. The header supplies `<cstddef>` and `<string>` for type
aliases, `<iostream>` for streams, and `<algorithm>` for algorithm aliases when
the corresponding group is enabled. Include other standard/third-party headers
before this one where possible, because these aliases are macros with global reach.
Stream and algorithm aliases remain **unqualified** to preserve existing usage;
write `std::kí_tự_đầu_ra` or use an appropriate `using` declaration.

Each group has its own include guard. Re-including the header after enabling
another group works. Undefining an enable flag does not undo already-defined aliases.

## Coverage and ordering

- All **81 keyword spellings in C++23 N4950 Table 5**, plus the **11 alternative
  operator tokens in Table 6**, have aliases. `register` is covered as a reserved
  spelling; it cannot be used as a variable storage specifier in C++17 and later.
- `final` and `override` are included. The old `import` and `module` spelling
  aliases are retained, subject to the module limitation below.
- All standard fundamental types are covered: `bool`; character types including
  `char8_t`, `char16_t`, and `char32_t`; every standard signed/unsigned integer
  type; `float`, `double`, `long double`; `void`; and `std::nullptr_t`.
  `xâu` is an additional convenience alias for `std::string`, not a fundamental type.
- Pointer, reference, array, function, and user-defined types use normal C++
  declarator syntax together with the translated type names. Implementation-specific
  extended types and the entire standard library are outside this checklist's scope.
- Each feature group is sorted lexicographically by the alias's **Unicode code
  points after NFC normalization**. This is deterministic, case-sensitive ordering,
  not Vietnamese dictionary collation.
- C++26 additions and experimental extensions are outside this C++23 target.

See the [complete alias reference](docs/aliases.md). Examples of new aliases:

| Vietnamese | C++ |
|---|---|
| `biểu_thức_hằng` | `constexpr` |
| `tính_hằng` | `consteval` |
| `khởi_tạo_hằng` | `constinit` |
| `khẳng_định_tĩnh` | `static_assert` |
| `yêu_cầu` | `requires` |
| `đồng_chờ`, `đồng_nhường`, `đồng_trả_về` | `co_await`, `co_yield`, `co_return` |
| `ép_kiểu_tĩnh` | `static_cast` |
| `kí_tự_utf8` | `char8_t` |
| `số_thực_kép` | `double` |
| `số_nguyên_dài` | `long int` |
| `số_nguyên_lớn_không_dấu` | `unsigned long long int` |
| `con_trỏ_rỗng_dạng` | `std::nullptr_t` |

### Module limitation

C++ recognizes module and import directives during preprocessing. A macro that
expands to `module` or `import` does not portably create the required directive.
Use literal `module`, `import`, and `export` on module/import directive lines, for example:

```cpp
export module demo;
import another_module;
```

`nhập` and `mô_đun` remain spelling aliases for compatibility; they are **not a
portable way to declare or import modules**. The keyword coverage check verifies
spellings, while the compilation tests cover ordinary declarations and expressions,
not a complete module build. Translated macros also do not replace `#define`,
`#include`, or other preprocessing directives.

## Nerd Font icons

The optional [VS Code companion](editors/vscode/README.md) displays Nerd Font icons
before translated keywords, types, and operators. Source text stays unchanged,
and copying or compiling it uses the ordinary Vietnamese aliases.

1. Install a [Nerd Font](https://www.nerdfonts.com/font-downloads), such as
   FiraCode Nerd Font.
2. Set VS Code's `editor.fontFamily` to the installed family:

   ```json
   {
     "editor.fontFamily": "'FiraCode Nerd Font Mono', monospace"
   }
   ```

3. In VS Code, run **Extensions: Install from VSIX...** and select the included
   `editors/vscode/cursed-cpp-nerd-font-0.1.0.vsix`. If you only have the source,
   follow the companion README to run or package it.
4. Open a C++ file. Use **Cursed C++: Toggle Nerd Font Icons** to switch the
   decorations on or off.

Most Nerd Font icons occupy Unicode private-use code points, which are not valid
portable C++23 identifiers. Editor decorations provide the visual effect without
introducing invalid macro names. A font change alone cannot turn a word into an icon.
The companion is a lexical highlighter, not a language server; it can also decorate
an ordinary identifier that happens to match an alias, or a token in an inactive `#if`
branch. It skips comments, string/character literals, and preprocessing directive lines.

## Compatibility fixes

Valid Vietnamese aliases from the supplied header are preserved, including the
stream and algorithm additions. These invalid/nonstandard entries were removed:

| Old entry | Reason and replacement |
|---|---|
| `đảo_bit_thêm` → `~=` | C++ has no `~=` operator. Write `x gán_bằng đảo_bit x` or `x = ~x`. |
| `nhãn` → `label` | `label` is not a C++ keyword. Define a jump label with `name:`. |
| `đồng_bộ_hóa` → `synchronized` | This belongs to experimental transactional-memory work, not standard C++23. |

The duplicate `và_bit_thêm` definition was also removed. The existing
`số_nguyên_dương` still means `unsigned int` for compatibility, which includes zero;
the new `số_nguyên_không_dấu` is a more precise synonym. The existing
`số_nguyên_lớn` still means `long long`, and `số_thực_lớn` still means `long double`.

## Validation and maintenance

From the project root, with Python 3.9+ and GCC (or a compatible compiler):

```sh
python3 tests/run.py
```

Set `CXX` to a different compiler executable if needed. The tests check the fixed
C++23 keyword list, alias ordering and normalization, independent feature flags,
repeated inclusion, and executable C++20/C++23 examples. The feature test exercises
all fundamental types, operators, concepts, casts, inheritance, and coroutines.

For the optional companion, with Node.js 18+:

```sh
cd editors/vscode
npm test
```

These tests cover the scanner and a mocked VS Code decoration lifecycle. Actual
font rendering must be checked in VS Code with a Nerd Font installed.

After changing aliases in the header, regenerate the reference and editor vocabulary:

```sh
python3 tools/update_reference.py
python3 tools/update_reference.py --check
```

## Todo

- [x] translate all arithmetic operators
- [x] translate all comparison operators
- [x] translate all bitwise operators
- [x] translate all assignment operators
- [x] translate all logical operators
- [x] translate all keywords (C++23 spelling coverage; module caveat above)
- [x] translate all data types (standard fundamental types)
- [x] sort keywords in lexicographic order (within feature groups)
- [ ] support other languages (nah)
- [x] use nerd font for keywords lol (optional VS Code decorations)

## References

- [C++23 keywords and alternative tokens, N4950](https://timsong-cpp.github.io/cppwp/n4950/lex.key)
- [Fundamental types](https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental)
- [Identifiers and Unicode requirements](https://timsong-cpp.github.io/cppwp/n4950/lex.name)
- [Module directives](https://timsong-cpp.github.io/cppwp/n4950/cpp.module)
- [Import directives](https://timsong-cpp.github.io/cppwp/n4950/cpp.import)
- [VS Code decoration API](https://code.visualstudio.com/api/references/vscode-api#DecorationRenderOptions)
- [Nerd Fonts glyph reference](https://www.nerdfonts.com/cheat-sheet)

## License

MIT; see [LICENSE](LICENSE).
