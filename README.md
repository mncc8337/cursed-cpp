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
| `VIETNAMESE_STANDARD_LIBS` | some `<algorithm>` names, like `std::tìm` |
| `VIETNAMESE_MISC` | `thư_viện_chuẩn` and `chương_trình_chính` |

nothing turns on by itself. `VIETNAMESE_KEYWORDS` still includes types so old code
doesn't suddenly forget what an integer is.

the header brings in `<cstddef>` + `<string>` for types, `<iostream>` for streams,
and `<algorithm>` for algorithms when needed. include your other headers first
where possible. macros don't understand personal space.

streams and algorithms still need `std::` or a suitable `using` declaration.
you can enable another group and include the header again. each group has its own
guard. `#undef VIETNAMESE_KEYWORDS` won't undo the aliases you already enabled.

### how much of c++ did this happen to

- all 81 c++23 keyword spellings + the 11 alternative operator words (`and`, `or`, etc.).
  `final` and `override` are here too. modules have a catch, see below.
- all standard fundamental types: the integers, signed/unsigned versions, character
  types, floats, `void`, `bool`, and `std::nullptr_t`. `xâu` is `std::string` as a bonus.
- the five operator groups in the table above. things like `[]`, `()`, `?:`, `.`
  and `->` still use their normal syntax. pointers, references and arrays do too.
- aliases are sorted inside each group by unicode code point, using nfc text.
  case matters. this isn't Vietnamese dictionary order.

this is **c++23**, not every keyword ever invented. no promise about c++26,
compiler-specific types, experimental keywords, or the entire standard library.
the [full alias list](docs/aliases.md) is over there if you want to count them.

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

### nerd font lol

there's an optional [VS Code thing](editors/vscode/README.md) that puts icons before
the translated keywords, types and operators. the icons only live in the editor.
your actual source, clipboard and compiler still get the Vietnamese words.

1. install a [Nerd Font](https://www.nerdfonts.com/font-downloads), e.g. FiraCode Nerd Font.
2. set your VS Code font to its installed family name:

   ```json
   {
     "editor.fontFamily": "'FiraCode Nerd Font Mono', monospace"
   }
   ```

3. run **Extensions: Install from VSIX...** and pick
   `editors/vscode/cursed-cpp-nerd-font-0.1.0.vsix` from the full project.
   only have the extension source? its readme has the run/package instructions.
4. open a c++ file. **Cursed C++: Toggle Nerd Font Icons** turns it on/off.

changing the font alone won't replace words with icons. most nerd font icons use
private-use unicode characters, which aren't valid portable c++23 identifiers,
so putting them in `#define` names wasn't going to end well.

the extension skips comments, strings, character literals and preprocessor
directive lines. it doesn't resolve symbols or evaluate `#if`, so an ordinary
variable with the same name, or a word in an inactive branch, can get an icon too.

### things that were a bit too cursed

- `đảo_bit_thêm` was `~=`. that operator doesn't exist. use `x gán_bằng đảo_bit x`.
- `nhãn` was `label`. also not a keyword. just write `name:`.
- `đồng_bộ_hóa` was `synchronized`. experimental transactional-memory stuff, not standard c++23.
- `và_bit_thêm` was defined twice. once is probably enough.

those three bad/nonstandard aliases are gone; the other old aliases still work.
`số_nguyên_dương` still means `unsigned int`, including zero. the name is doing its
best. `số_nguyên_không_dấu` is the less misleading version. `số_nguyên_lớn` is still
`long long`, and `số_thực_lớn` is still `long double`.

### does it even work

from the full project root, with python 3.9+ and g++:

```sh
python3 tests/run.py
```

set `CXX` if you want another compatible compiler. this checks keyword spellings,
sorting, unicode normalization, feature flags, repeated includes, and c++20/c++23
programs using the types, operators, concepts, casts and coroutines.
module builds aren't covered.

the icon thing has tests too. node.js 18+:

```sh
cd editors/vscode
npm test
```

those check the scanner and a mocked editor. you still have to look at VS Code to
see whether your installed font renders the icons. the tests do not have eyes.

changed an alias? run these from the project root to update the list and editor vocabulary:

```sh
python3 tools/update_reference.py
python3 tools/update_reference.py --check
```

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
- [x] use nerd font for keywords lol (optional VS Code decorations)

### the boring links

[keywords](https://timsong-cpp.github.io/cppwp/n4950/lex.key) ·
[types](https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental) ·
[unicode rules](https://timsong-cpp.github.io/cppwp/n4950/lex.name) ·
[module rules](https://timsong-cpp.github.io/cppwp/n4950/cpp.module) ·
[import rules](https://timsong-cpp.github.io/cppwp/n4950/cpp.import) ·
[editor decorations](https://code.visualstudio.com/api/references/vscode-api#DecorationRenderOptions) ·
[nerd font glyphs](https://www.nerdfonts.com/cheat-sheet)

### license

MIT. see [LICENSE](LICENSE).
