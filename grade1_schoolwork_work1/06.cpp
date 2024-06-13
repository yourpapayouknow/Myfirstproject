#include <iostream>
#include <string>
using namespace std;

int interleave(string& a, string& b);

int main()
{
    string a;
    string b;
    int ret;

    cin >> a >> b;
    ret = interleave(a, b);

    cout << a << endl << ret << endl;
}
// 在此处补充你的代码
int interleave(string& a, string& b)
{
    int la, lb;
    la = a.length(); lb = b.length();
    string c(la + lb, ' ');
    int index = 0;
    if (la >= lb)
    {
        for (int i = 0; i < la || i < lb; ++i) {
            if (i < lb) {
                c[index++] = a[i];
            }
            if (i < lb) {
                c[index++] = b[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < la || i < lb; ++i) {
            if (i < la) {
				c[index++] = a[i];
			}
            if (i < la) {
				c[index++] = b[i];
			}
		}
	}
    int result = (la - lb);
    
    a = c;
   
    return la - lb;
}