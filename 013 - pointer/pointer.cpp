#include "pointer.h"

void update(int* a, int* b) {
    // 1. a 또는 b 가 nullptr 이면 즉시 반환한다.
    if (a == nullptr || b == nullptr) {
        return;  // 여기서 반환
    }
    
    // 2. 두 정수의 원래 값을 보존할 임시 변수를 만든다.
    int tempA = *a;
    int tempB = *b;
    
    // 3. *a 에는 두 수의 합을 저장한다.
    *a = tempA + tempB;
    
    // 4. *b 에는 원래 첫 번째 수에서 원래 두 번째 수를 뺀 값을 저장한다.
    *b = tempA - tempB;
}