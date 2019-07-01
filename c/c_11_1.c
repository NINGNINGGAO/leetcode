#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize - 1;
    int res = 0;
    
    while (i < j) {
        int temp1 = min(height[i],height[j]);
        int temp2 = temp1 * (j - i);
        res = max(res, temp2);
        height[i] < height[j] ? i++ : j--;
    }
    return res;
}
