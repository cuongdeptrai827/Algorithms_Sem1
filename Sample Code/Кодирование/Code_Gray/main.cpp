// Gray code
/*
 Gray 1:
 0
 1
 Gray 2:
 00
 01
 11
 10
 Gray 3:
 000
 001
 011
 010
 110
 111
 101
 100

 Quy luật của mã Gray thứ n là :
 1. Sao chép và đảo ngược toàn bộ gray thứ n-1
 2. Nửa đầu thêm 0, nửa sau thêm 1

 Như vậy muốn tính gray thứ n, ta cần tính mã gray thứ n - 1.
 */

#include <iostream>
#include <vector>

using namespace std;


