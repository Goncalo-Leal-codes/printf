# printf

function that recreates the standard library printf (conversions (cspdiuxX%) flags(-O.*)).

Overview:

1 - Initialize "var" variable to be used with the va_arg and va_end macros

2 - Create a struct where we save information that will be used in the moment of printing (flags, minimum width, precision and string)

3 - Go over the string given as the first argument. If we find a % character we first see if it a valid conversion (follows the format identifiers order):
    1st - flags
    2nd - minimum width
    3rd - precision (after period)

4 - Analyze again the characters after % (up until we find a possible conversion sign) and get all the information inside the struct.

5 - Once we get to the conversion sign we will do the apropriate conversion (e.g. int to str in the case of %d and %i).

6 - Finally we will print the string converted variable with the specification given by flags, minimum width and precision.

E.g. 
In the case of %d:

 - A minimum width of 10 means that we will need to print at least 10 characters.
 - If we have a integer variable = 100 then we have 7 spare characters that we need to print.
 - These can be zeros and or spaces. These are determined by the flags and the precision.
 - Precision in this case refers to the number of digits.
 - If we had only the the zero flag then all the characters on the left would be zeros.
 - If we had a minus sign then there would be no zeros and all the extra characters would be spaces and printed after we print the variable string.

As you can see there are many rules that we need to take into consideration. Send me an email at gonaloleal@gmail.com if you need some links of websites that helped me understand.
