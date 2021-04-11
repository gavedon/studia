#include <iostream>
#include <vector>
#include <algorithm>
#define ULL unsigned long long

std::vector<std::pair<ULL, ULL> > str_vec;
unsigned int nr_of_diff_st;
ULL length, one_type_str_nr;

int main() {

    scanf("%u", &nr_of_diff_st);
    for(unsigned int k=1; k<=nr_of_diff_st; k++ ) {
        scanf("%llu %llu", &length, &one_type_str_nr);
        while(!(length & 1)) {
            length >>= 1;
            one_type_str_nr <<= 1;
        }
        str_vec.emplace_back(length, one_type_str_nr);
    }
    std::sort(str_vec.begin(), str_vec.end());
    unsigned int count=0;
    for(unsigned int i=0; i < nr_of_diff_st; i++) {
        while(str_vec[i].first == str_vec[i+1].first) {
            str_vec[i+1].second += str_vec[i].second;
            i++;
        }
        while(str_vec[i].second) { count+= (str_vec[i].second & 1); str_vec[i].second>>=1;}
    }
    printf("%u", count);
    return 0;
}