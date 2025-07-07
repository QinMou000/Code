class Solution {
    public:
        int iceBreakingGame(int num, int target) {
            // list<int> ls;
            // for (int i = 0; i < num; i++)
            //     ls.push_back(i);
            // auto it = ls.begin();
            // int cnt = 1;
            // while (ls.size() != 1) {
            //     if (cnt == target) {
            //         it = ls.erase(it);
            //         cnt = 1;
            //     } else {
            //         cnt++;
            //         it++;
            //     }
            //     if (it == ls.end())
            //         it = ls.begin();
            // }
            // return *ls.begin();
            int p = 0;
            for(int i = 2; i <= num; i++)
            {
                p = (p + target) % i; // 理解这个公式
            }
            return p;
        }
    };