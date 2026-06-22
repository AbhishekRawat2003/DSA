#include <iostream>
using namespace std;
int picked;
int guess(int mid) {
    if (mid > picked) return -1;
    else if (mid < picked) return 1;
    return 0;
}

class Solution {
public:
    void playGame(int n) {
        int attempts = 0;
        while (true) {
            int myGuess;
            cin >> myGuess;

            if (myGuess < 1 || myGuess > n) {
                cout << "Sirf 1 se " << n << " ke beech guess karo!\n";
                continue;
            }

            attempts++;
            int result = guess(myGuess);

            if (result == 0) {
                cout << "\nSahi jawab! Number " << picked << " tha.\n";
                cout << "Tumne " << attempts << " attempts mein dhundha!\n";
                break;
            } else if (result == -1) {
                cout << "Zyada hai! Chota guess karo.\n";
            } else {
                cout << "Kam hai! Bada guess karo.\n";
            }
        }
    }
};

int main() {
    int n;
    cout << "Range batao (1 se kitne tak?): ";
    cin >> n;
    srand(time(0));
    picked = (rand() % n) + 1;
    Solution s;
    s.playGame(n);
    return 0;
}