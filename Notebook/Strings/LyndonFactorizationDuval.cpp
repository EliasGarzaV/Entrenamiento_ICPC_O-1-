/*
A string is called simple (or a Lyndon word), if it is strictly smaller than any of its own nontrivial suffixes. Examples of simple strings are:  
$a$ ,  
$b$ ,  
$ab$ ,  
$aab$ ,  
$abb$ ,  
$ababb$ ,  
$abcd$ . It can be shown that a string is simple, if and only if it is strictly smaller than all its nontrivial cyclic shifts.

Next, let there be a given string "s". 
The Lyndon factorization of the string  "s"  is a factorization  
s = w_1 w_2 ... w_k , where all strings  
w_i  are simple, and they are in non-increasing order  
w_1 >= w_2 >= ... >= w_k

It can be shown, that for any string such a factorization exists and that it is unique.


The Duval algorithm constructs the Lyndon factorization in  O(n)  time using  
O(1)  additional memory.
*/

vector<string> duval(string const& s) {
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}


/*
Finding the smallest cyclic shift
Let there be a string  
s . We construct the Lyndon factorization for the string  
s + s  (in  O(n)  time). We will look for a simple string in the factorization, which starts at a position less than  
n  (i.e. it starts in the first instance of  
s ), and ends in a position greater than or equal to  
n  (i.e. in the second instance) of  
s ). It is stated, that the position of the start of this simple string will be the beginning of the desired smallest cyclic shift. This can be easily verified using the definition of the Lyndon decomposition.

The beginning of the simple block can be found easily - just remember the pointer  
$i$  at the beginning of each iteration of the outer loop, which indicated the beginning of the current pre-simple string.
*/



string min_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}