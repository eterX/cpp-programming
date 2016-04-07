
# 2.7 Chars

Even though the char data type is an integer (and thus follows all of the normal integer rules), we typically work with chars in a different way than normal integers. A char variable holds a 1-byte integer. However, instead of interpreting the value of the char as an integer, the value of a char variable is typically interpreted as an ASCII character.

**ASCII** stands for American Standard Code for Information Interchange, and it defines a particular way to represent English characters (plus a few other symbols) as numbers between 0 and 127 (called a code or code point). For instance, the character ‘a’ is code 97. ‘b’ is code 98. Characters are always placed between single quotes.

```
$ man ascii
```

Here’s a full table of ASCII characters:

```
ASCII(7)             BSD Miscellaneous Information Manual             ASCII(7)

NAME
     ascii -- octal, hexadecimal and decimal ASCII character sets

DESCRIPTION
     The octal set:

     000 nul  001 soh  002 stx  003 etx  004 eot  005 enq  006 ack  007 bel
     010 bs   011 ht   012 nl   013 vt   014 np   015 cr   016 so   017 si
     020 dle  021 dc1  022 dc2  023 dc3  024 dc4  025 nak  026 syn  027 etb
     030 can  031 em   032 sub  033 esc  034 fs   035 gs   036 rs   037 us
     040 sp   041  !   042  "   043  #   044  $   045  %   046  &   047  '
     050  (   051  )   052  *   053  +   054  ,   055  -   056  .   057  /
     060  0   061  1   062  2   063  3   064  4   065  5   066  6   067  7
     070  8   071  9   072  :   073  ;   074  <   075  =   076  >   077  ?
     100  @   101  A   102  B   103  C   104  D   105  E   106  F   107  G
     110  H   111  I   112  J   113  K   114  L   115  M   116  N   117  O
     120  P   121  Q   122  R   123  S   124  T   125  U   126  V   127  W
     130  X   131  Y   132  Z   133  [   134  \   135  ]   136  ^   137  _
     140  `   141  a   142  b   143  c   144  d   145  e   146  f   147  g
     150  h   151  i   152  j   153  k   154  l   155  m   156  n   157  o
     160  p   161  q   162  r   163  s   164  t   165  u   166  v   167  w
     170  x   171  y   172  z   173  {   174  |   175  }   176  ~   177 del

     The hexadecimal set:

     00 nul   01 soh   02 stx   03 etx   04 eot   05 enq   06 ack   07 bel
     08 bs    09 ht    0a nl    0b vt    0c np    0d cr    0e so    0f si
     10 dle   11 dc1   12 dc2   13 dc3   14 dc4   15 nak   16 syn   17 etb
     18 can   19 em    1a sub   1b esc   1c fs    1d gs    1e rs    1f us
     20 sp    21  !    22  "    23  #    24  $    25  %    26  &    27  '
     28  (    29  )    2a  *    2b  +    2c  ,    2d  -    2e  .    2f  /
     30  0    31  1    32  2    33  3    34  4    35  5    36  6    37  7
     38  8    39  9    3a  :    3b  ;    3c  <    3d  =    3e  >    3f  ?
     40  @    41  A    42  B    43  C    44  D    45  E    46  F    47  G
     48  H    49  I    4a  J    4b  K    4c  L    4d  M    4e  N    4f  O
     50  P    51  Q    52  R    53  S    54  T    55  U    56  V    57  W
     58  X    59  Y    5a  Z    5b  [    5c  \    5d  ]    5e  ^    5f  _
     60  `    61  a    62  b    63  c    64  d    65  e    66  f    67  g
     68  h    69  i    6a  j    6b  k    6c  l    6d  m    6e  n    6f  o
     70  p    71  q    72  r    73  s    74  t    75  u    76  v    77  w
     78  x    79  y    7a  z    7b  {    7c  |    7d  }    7e  ~    7f del

     The decimal set:

       0 nul    1 soh    2 stx    3 etx    4 eot    5 enq    6 ack    7 bel
       8 bs     9 ht    10 nl    11 vt    12 np    13 cr    14 so    15 si
      16 dle   17 dc1   18 dc2   19 dc3   20 dc4   21 nak   22 syn   23 etb
      24 can   25 em    26 sub   27 esc   28 fs    29 gs    30 rs    31 us
      32 sp    33  !    34  "    35  #    36  $    37  %    38  &    39  '
      40  (    41  )    42  *    43  +    44  ,    45  -    46  .    47  /
      48  0    49  1    50  2    51  3    52  4    53  5    54  6    55  7
      56  8    57  9    58  :    59  ;    60  <    61  =    62  >    63  ?
      64  @    65  A    66  B    67  C    68  D    69  E    70  F    71  G
      72  H    73  I    74  J    75  K    76  L    77  M    78  N    79  O
      80  P    81  Q    82  R    83  S    84  T    85  U    86  V    87  W
      88  X    89  Y    90  Z    91  [    92  \    93  ]    94  ^    95  _
      96  `    97  a    98  b    99  c   100  d   101  e   102  f   103  g
     104  h   105  i   106  j   107  k   108  l   109  m   110  n   111  o
     112  p   113  q   114  r   115  s   116  t   117  u   118  v   119  w
     120  x   121  y   122  z   123  {   124  |   125  }   126  ~   127 del

FILES
     /usr/share/misc/ascii

HISTORY
     An ascii manual page appeared in Version 7 AT&T UNIX.
```

Codes 0-31 are called the unprintable chars, and they’re mostly used to do formatting and control printers. Most of these are obsolete now.

Codes 32-127 are called the printable characters, and they represent the letters, numbers, and punctuation that most computers use to display basic English text.

The following two initializations both initialize the char with integer value 97:

```
char ch1(97); // initialize with integer 97
char ch2('a'); // initialize with code point for 'a' (97)
```

One word of caution: be careful not to mix up character (keyboard) numbers with actual numbers. The following two initializations are not the same

```
char ch(5); // initialize with integer 5
char ch('5'); // initialize with code point for '5' (53)
```

## Printing chars

When using cout to print a char, cout outputs the char variable as an ASCII character instead of a number:

```
#include <iostream>

int main()
{
    char ch(97); // even though we're initializing ch with an integer
    std::cout << ch; // cout prints a character
    return 0;
}
```

This produces the result:

a

We can also output char literals directly:

```
cout << 'b';
```

This produces the result:

b


Note: The fixed width integer int8_t is usually treated the same as a signed char in C++, so it will generally print as a char instead of an integer.


## Printing chars as integers via type casting

If we want to output a char as a number instead of a character, we have to tell cout to print the char as if it were an integer. One (poor) way to do this is by assigning the char to an integer, and printing the integer:

```
#include <iostream>

int main()
{
    char ch(97);
    int i(ch); // assign the value of ch to an integer
    std::cout << i; // print the integer value
    return 0;
}
```

However, this is clunky. A better way is to use a type cast. A **type cast** creates a value of one type from a value of another type. To convert between fundamental data types (for example, from a char to an int, or vice versa), we use a type cast called a **static cast**.

The syntax for the static cast looks a little funny:

```
static_cast<new_type>(expression)
```

static_cast takes the value from an expression as input, and converts it into whatever fundamental type new_type represents (e.g. int, boolean, char, double).

Here’s using a static cast to create an integer value from our char value:

```
#include <iostream>

int main()
{
    char ch(97);
    std::cout << ch << std::endl;
    std::cout << static_cast<int>(ch) << std::endl;
    std::cout << ch << std::endl;
    return 0;
}
```

This results in:

a
97
a

It’s important to note that static_cast takes an expression as input. When we pass in a variable, that variable is evaluated to produce its value, which is then converted to the new type. The variable is not affected by casting its value. In the above case, ch is still a char, and still holds the same value.

Also note that static casting doesn’t do any range checking, so if you cast an integer that is too big to fit into a char, you’ll overflow your char.

We’ll talk more about static casts and the different types of casts in a future lesson.


## Inputting chars

The following program asks the user to input a character, then prints out both the character and its ASCII code:

```
#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: ";

    char ch;
    std::cin >> ch;
    std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;

    return 0;
}
```

Here’s the output from one run:

Input a keyboard character: q
q has ASCII code 113

Note that even though cin will let you enter multiple characters, ch will only hold 1 character. Consequently, only the first input character is placed in ch. The rest of the user input is left in the input buffer that cin uses, and can be accessed with subsequent calls to cin.

You can see this behavior in the following example:

```
#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)

    char ch;
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;

    return 0;
}
```

Input a keyboard character: abcd
a has ASCII code 97
b has ASCII code 98

## Char size, range, and default sign

Char is defined by C++ to always be one byte in size. By default, a char may be signed or unsigned (though it’s usually signed). If you’re using chars to hold ASCII characters, you don’t need to specify a sign (since both signed and unsigned chars can hold values between 0 and 127).

If you’re using a char to hold small integers, you should always specify whether it is signed or unsigned. A signed char can hold a number between -128 and 127. An unsigned char can hold a number between 0 and 255.

## Escape sequences

C++ has some characters that have special meaning. These characters are called escape sequences. An **escape sequence** starts with a ‘\’ (backslash) , and then a following letter or number.

The most common escape sequence is ‘\n’, which can be used to embed a newline in a string of text:

```
#include <iostream>

int main()
{
    std::cout << "First line\nSecond line" << std::endl;
    return 0;
}
```

This outputs:

```
First line
Second line
```

Another commonly used escape sequence is ‘\t’, which embeds a tab:

```
#include <iostream>

int main()
{
    std::cout << "First part\tSecond part";
    return 0;
}
```

Which outputs:

First part        Second part

Here’s a table of all of the escape sequences:

| **Name** | **Symbol** | **Meaning** |
|-:-|-:-|-:-|
| Alert | \a | Makes an alert, such as a beep |
| Backspace | \b | Moves the cursor back one space |
| Formfeed | \f | Moves the cursor to next logical page |
| Newline | \n | Moves cursor to next line |
| Carriage return | \r | Moves cursor to the begining of line |
| Horizontal tab | \t | Prints a horizontal tab |
| Vertical tab | \v | Prints a vertical tab |
| Single quote | \' | Prints a single quote |
| Double quote | \" | Prints a double quote |
| Backslash | \\ | Prints a backslash |
| Question mark | \? | Prints a question mark |
| Octal number | \(number) | Translates into char represented by octal |
| Hex number | \x(number) | Translates into char represented by hex number |

Here are some examples:

```
#include <iostream>

int main()
{
    std::cout << "\"This is quoted text\"\n";
    std::cout << "This string contains a single backslash \\" << std::endl;
    std::cout << "6F in hex is char \'\x6F\'" << std::endl;
    return 0;
}
```


Prints:

"This is quoted text"
This string contains a single backslash \
6F in hex is char 'o'


## Newline(\n) vs std::endl -- which should you use ?

You may have noticed in the last example that we can use \n to move the cursor to the next line, which appears to duplicate the functionality of std::endl. However, they are slightly different.

When std::cout is used for output, the output may be buffered -- that is, std::cout may not send the text to the output device immediately (for performance reasons). Both ‘\n’ and std::endl will move the cursor to the next line. In addition, std::endl will also ensure that any queued output is actually output before continuing.

So when should you use ‘\n’ vs std::endl? The short answer is:

- Use std::endl when you need to ensure your output is output immediately (e.g. when writing a record to a file, or when updating a progress bar). Note that this may have a performance cost, particularly if writing to the output device is slow (e.g. when writing a file to a disk).
- Use ‘\n’ in other cases.

(Administrative note: Throughout the rest of this tutorial, we’ve used std::endl;. We’re in the process of converting over to ‘\n’ because for console output, this is almost always the better choice.)

## What about the other char types, wchar_t, char16_t, and char32_t?

wchar_t should be avoided in almost all cases (except when interfacing with the Windows API). Its size is implementation defined, and is not reliable. It has largely been deprecated.

Much like ASCII maps the integers 0-127 to American English characters, other character encoding standards exist to map integers (of varying sizes) to characters in other languages. The most well-known mapping outside of ASCII is the Unicode standard, which maps over 110,000 integers to characters in many different languages. Because Unicode contains so many code points, a single Unicode code point needs 32-bits to represent a character (called UTF-32). However, Unicode characters can also be encoded using multiple 16-bit or 8-bit characters (called UTF-16 and UTF-8 respectively).

char16_t and char32_t were added to C++11 to provide explicit support for 16-bit and 32-bit Unicode characters (8-bit Unicode characters are already supported by the normal char type).

You won’t need to use char16_t or char32_t unless you’re planning on making your program Unicode compatible and you are using 16-bit or 32-bit Unicode characters. Unicode and localization is generally outside the scope of these tutorials, so we won’t cover it further.

## What’s the different between putting symbols in single and double quotes?

As you learned above, chars are always put in single quotes (e.g. ‘a’, ‘+’, ‘5’). A char can only represent one symbol (e.g. the letter a, the plus symbol, the number 5). Something like this is illegal:

```
char ch('56'); // a char can only hold one symbol
```

Text put between double quotes is called a string (e.g. “Hello, world!”). A string is a collection of sequential characters (and thus, a string can hold multiple symbols).

For now, you’re welcome to use string literals in your code:

```
std::cout << "Hello, world!"; // "Hello, world!" is a string literal
```

However, string variables are a little more complex than chars or the fundamental data types, so we’ll reserve discussion of those until later.
