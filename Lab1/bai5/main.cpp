#include<iostream>
#include<string>
using namespace std;

bool palindrome(string word) {
    return word == string(word.rbegin(), word.rend());
}
bool checker(string word){
    int b= word.length() -1;
    int a=0;
    if (palindrome(word)) {
        return true;
    }
    else{
        while(a<b){
            if (word[a]==word[b]){
                b--;
                a++;
            }
            else {
                string word1 = word.substr(0,  a) + word.substr(a + 1, word.length() - 1 - a);
                string word2 = word.substr(0,  b) + word.substr(b + 1, word.length() - 1 - b);
                if ( (palindrome(word1)) || (palindrome(word2)) ) {
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
}

int main(){
    unsigned int N;
    cin >> N;
    string word;
    cin >> word;

    if (checker(word) == true)
        cout << "YES";
    else
        cout << "NO";

    return 0;

}