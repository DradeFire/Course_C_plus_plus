#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t N, R;
    uint64_t sum = 0, W, H, D;
    cin >> N >> R;

    for (size_t i = 0; i < N; i++)
    {
        cin >> W >> H >> D;
        sum += W * H * D * R;
    }

    cout << sum << endl;

    return 0;
}