int majorityElement(int* nums, int numsSize) {
    int num;
    int count = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == num) {
            continue;
        }
        num = nums[i];
        
        for(int j = 0; j < numsSize; j++) {
            if(nums[j] == num) {
                count++;
            }
        }
        if(count > (numsSize / 2)) {
            break;
        }
        count = 0;
    }
    return num;
}

OUTPUT:
Input: [3,2,3]
Output: 3
