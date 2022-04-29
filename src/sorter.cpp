#include "sorter.h"

Sorter::Sorter()  { };
Sorter::~Sorter() { };

void Sorter::selectionSort(std::vector<int>& numbers){
    // 선택 정렬
    // worst, avg, best
    // O(n^2) O(n^2) O(n)
    // 맨 앞부터 탐색하며, 가장 작은 값을 찾아간다. 가장 작은 값의 위치와 맨 첫 칸과 데이터를 바꾼다.
    int n = numbers.size();
    for(int i = 0; i < n; ++i) {
        // i : 현재 인덱스
        // idx_min : 최소인덱스
        // min_val : 최소값
        int& num_cur = numbers[i];
        int min_val = num_cur;
        int idx_min = i;

        for(int j = i + 1; j < n; ++j) {
            if(numbers[j] < min_val) {
                min_val = numbers[j];
                idx_min = j;
            }
        }
        int temp;
        SWAP(numbers[i], numbers[idx_min], temp);
    }
};

void Sorter::insertionSort(std::vector<int>& numbers){
    // 삽입 정렬
    // worst, avg, best
    // O(n^2) O(n^2) O(n)
    // 두번째부터 탐색하며, 현재 인덱스 이전의 모든 값과 비교를 하는데,
    // 현재 키 값보다 비교하는 값이 여전히 클 경우 그 값을 뒤로 밀며 돈다.
    // while문이 끝나면 현재 j의 위치는 key보다 작은 값을 가지므로,
    // j + 1 위치에 key를 넣어준다.
    int n = numbers.size();
    
    for(int i = 1; i < n; ++i) {
        int j = i-1;
        int key = numbers[i];
        while(j >= 0 && key < numbers[j]){
            numbers[j+1] = numbers[j];
            --j;
        }
        numbers[++j] = key;
    }
};

void Sorter::bubbleSort(std::vector<int>& numbers){
    // 버블 정렬
    // worst, avg, best
    // O(n^2) O(n^2) O(n)
    // 맨처음과 두번째를 비교한다. 뒷 놈이 작은경우 앞으로 넘겨줌.
    // 이걸 끝까지 반복한다. 반복하면 맨 뒤에 현재 제일 큰 놈이 가 있다. 
    // 다음 로테이션에서는 n-1 번째 원소까지 보면 된다.

    int n = numbers.size()-1;
    while(n >= 0){
        for(int j = 0; j < n; ++j)
        {
            int temp;
            if(numbers[j+1] < numbers[j]) SWAP(numbers[j+1],numbers[j],temp);
        }
        --n;
    }
};

void Sorter::mergeSort(std::vector<int>& numbers){
    // 머지 정렬
    // worst, avg, best
    // O(nlogn) O(n logn) O(nlogn)
    // Divide and conquer
    // divide : 배열의 크기가 0 또는 1이 될때 까지 한다.
    // conquer 때 다시 배열을 합치는데, 이 때 비교를 수행해서 정렬한다.
    // 이 때 배열은 항상 정렬 된 상태이다. 
    // 따라서 정렬을
    int n = numbers.size();
    mergeSortSubRoutine(numbers,0,n-1);
};

void Sorter::mergeSortSubRoutine(std::vector<int>& numbers, int s, int e){
    if(e - s > 0) { // 아직 더 쪼갤 수 있다. 쪼갰으면 다시 더 쪼개러 들어가자.
        // Divide!
        int m = (s + e)/2;
        mergeSortSubRoutine(numbers, s,   m); // 만약 들어왔는데 더 쪼갤 수 없으면 그냥 나가진다. 
        mergeSortSubRoutine(numbers, m+1, e); // 만약 들어왔는데 더 쪼갤 수 없으면 그냥 나가진다. 

        // Compare and merge
        std::vector<int> tmp; tmp.reserve(e-s+1);
        int i0 = s;
        int i1 = m+1;

        while(i0 <= m && i1 <= e){
            if(numbers[i0] < numbers[i1]) tmp.push_back(numbers[i0++]);
            else tmp.push_back(numbers[i1++]);
        }
        while(i0 <= m) tmp.push_back(numbers[i0++]);
        while(i1 <= e) tmp.push_back(numbers[i1++]);

        // copy 
        int* ptr = numbers.data() + s;
        for(int i = 0; i < tmp.size(); ++i) *(ptr++) = tmp[i];
        
    }
};

